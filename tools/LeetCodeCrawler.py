import requests
import json
import re
import os
import sys
from requests_toolbelt import MultipartEncoder
from threading import Thread

from secret import *
from config import *
from helper import *

session = requests.Session()


class LeetCodeCrawler():
    def __init__(self):
        self.baseURL = baseURL
        self.loginURL = loginURL

    def login(self, username: str, password: str) -> bool:
        cookies = session.get(baseURL).cookies
        for cookie in cookies:
            if cookie.name == 'csrftoken':
                csrftoken = cookie.value

        params_data = {'csrfmiddlewaretoken': csrftoken,
                       'login': username,
                       'password': password,
                       'next': 'problems'}

        headers = {'User-Agent': user_agent,
                   'Connection': 'keep-alive',
                   'Referer': 'https://leetcode.com/accounts/login/',
                   'origin': 'https://leetcode.com'}

        m = MultipartEncoder(params_data)

        headers['Content-Type'] = m.content_type
        session.post(loginURL, headers=headers, data=m,
                     timeout=10, allow_redirects=False)
        isLogin = session.cookies.get('LEETCODE_SESSION') != None
        return isLogin

    def getPercentage(self, apiURL: str):
        headers = {'User-Agent': user_agent, 'Connection': 'keep-alive'}
        resp = session.get(apiURL, headers=headers, timeout=10)
        resp = json.loads(resp.content.decode('utf-8'))

        return resp['num_solved'], resp['num_total'], resp['ac_easy'], resp['ac_medium'], resp['ac_hard']

    def getProblemsStatAndStatus(self, apiURL: str) -> [dict, list]:
        headers = {'User-Agent': user_agent, 'Connection': 'keep-alive'}
        resp = session.get(apiURL, headers=headers, timeout=10)
        resp = json.loads(resp.content.decode('utf-8'))

        problems = resp['stat_status_pairs']
        problems.reverse()

        return problems

    def getSubmissionStatus(self, graphqlURL: str, slug: str, langs: list) -> dict:
        params = {'operationName': 'Submissions',
                  'variables': {'offset': 0, 'limit': 20, 'lastKey': '', 'questionSlug': slug},
                  'query':
                  '''
                    query Submissions($offset: Int!, $limit: Int!, $lastKey: String, $questionSlug: String!) {
                        submissionList(offset: $offset, limit: $limit, lastKey: $lastKey, questionSlug: $questionSlug) {
                            lastKey
                            hasNext
                            submissions {
                                id
                                statusDisplay
                                lang
                                runtime
                                timestamp
                                url
                                isPending
                                __typename
                            }
                            __typename
                        }
                    }
                    '''
                  }

        jsonData = json.dumps(params).encode('utf8')
        headers = {'User-Agent': user_agent, 'Connection': 'keep-alive', 'Referer': 'https://leetcode.com/accounts/login/',
                   'Content-Type': 'application/json'}
        resp = session.post(graphqlURL, data=jsonData,
                            headers=headers, timeout=10)
        content = resp.json()

        submissions = {}
        for submission in content['data']['submissionList']['submissions']:
            if submission['statusDisplay'] == 'Accepted' and submission['lang'] not in submissions.keys() and submission['lang'] in langs:
                submissions[submission['lang']] = submission

        return submissions

    def getCodeByID(self, submissionID: str) -> str:
        headers = {'User-Agent': user_agent, 'Connection': 'keep-alive',
                   'Content-Type': 'application/json'}
        codeContent = session.get(
            detailURL + submissionID, headers=headers, timeout=1000)
        pattern = re.compile(
            r'submissionCode: \'(?P<code>.*)\',\n  editCodeUrl', re.S)

        m1 = pattern.search(codeContent.text)
        code = m1.groupdict()['code'] if m1 else None
        code = purify(code)

        return code

    def writeREADME(self, problems: list, isWriteCode: bool) -> None:
        if not os.path.exists('../solutions'):
            os.makedirs('../solutions')

        for lang in ['cpp', 'python3']:
            if not os.path.exists('../solutions/' + lang):
                os.makedirs('../solutions/' + lang)

        readme = open('../README.md', 'w')
        try:
            with open('PREFIX.md') as f:
                for line in f:
                    readme.write(line)
        except FileNotFoundError:
            print("No such file or directory: 'PREFIX.md'")

        num_solved, num_total, ac_easy, ac_medium, ac_hard = self.getPercentage(
            apiURL)

        solved = shieldsURL + str(num_solved) + '/' + str(num_total) + '%20=%20' + str(
            round((num_solved / num_total) * 100, 2)) + '%25%20' + 'Solved-blue.svg" />'
        easy = shieldsURL + 'Easy%20' + str(ac_easy) + '-brightgreen.svg" />'
        medium = shieldsURL + 'Medium%20' + str(ac_medium) + '-yellow.svg" />'
        hard = shieldsURL + 'Hard%20' + str(ac_hard) + '-red.svg" />'

        readme.write('\n## Problem Sets\n\n')
        readme.write('<p align="center">\n')
        readme.write(solved + '\n')
        readme.write(easy + '\n')
        readme.write(medium + '\n')
        readme.write(hard + '\n')
        readme.write('</p>\n\n')
        readme.write('|#|Title|Solution|Difficulty|\n')
        readme.write('|:--:|:--|:--:|:--:|\n')

        for problem in problems:
            problemID = str(problem['stat']['frontend_question_id']).zfill(4)

            # print('----------------------------')
            print('Write README.md: ' + problemID)
            readme.write('|' + problemID + '|')
            readme.write('[' + problem['stat']['question__title'] +
                         '](https://leetcode.com/problems/' + problem['stat']['question__title_slug'] + ')|')

            if problem['status'] == 'ac':
                solutions = self.writeSolutions(problem, isWriteCode)
                readme.write(', '.join(solutions))

            readme.write('|')

            if problem['difficulty']['level'] == 1:
                readme.write('Easy')
            elif problem['difficulty']['level'] == 2:
                readme.write('Medium')
            elif problem['difficulty']['level'] == 3:
                readme.write('Hard')

            readme.write('|\n')

    def writeSolutions(self, problem: list, isWriteCode=True) -> list:
        problemID = str(problem['stat']['frontend_question_id']).zfill(4)

        solutions = []
        submissions = self.getSubmissionStatus(
            graphqlURL, problem['stat']['question__title_slug'], ['cpp', 'python3'])

        if 'cpp' in submissions.keys():
            directory = getDirectory('cpp', problemID, '.cpp')
            solutions.append('[C++](' + directory + ')')

            if isWriteCode:
                print('Write solutions: ' + problemID + '.cpp')
                code = self.getCodeByID(submissions['cpp']['id'])

                if type(code) is str:
                    with open('.' + directory, encoding='utf-8', mode='w+') as f:
                        f.write(code)

        if 'python3' in submissions.keys():

            directory = getDirectory('python3', problemID, '.py')
            solutions.append('[Python](' + directory + ')')
            code = self.getCodeByID(submissions['python3']['id'])

            if isWriteCode:
                print('Write solutions: ' + problemID + '.py')
                if type(code) is str:
                    with open('.' + directory, encoding='utf-8', mode='w+') as f:
                        f.write(code)

        # if 'java' in submissions.keys():
        #     directory = getDirectory('java', problemID, '.java')
        #     solutions.append('[Java](' + directory + ')')
        #     code = self.getCodeByID(submissions['java']['id'])

        #     if type(code) is str:
        #         with open('.' + directory, encoding='utf-8', mode='w+') as f:
        #             f.write(code)

        return solutions


if __name__ == '__main__':
    LeetCodeCrawler = LeetCodeCrawler()
    LeetCodeCrawler.login(username, password)
    problems = LeetCodeCrawler.getProblemsStatAndStatus(apiURL)

    if len(sys.argv) < 2:
        LeetCodeCrawler.writeREADME(problems)

    # only crawl a problem
    elif sys.argv[1] == '-p':
        for problem in problems:
            if problem['stat']['frontend_question_id'] == int(sys.argv[2]):
                LeetCodeCrawler.writeSolutions(problem)

    # only crawl in a range
    elif sys.argv[1] == '-r':
        start = int(sys.argv[2])
        end = int(sys.argv[3])
        problems = problems[start - 1: end]

        for problem in problems:
            LeetCodeCrawler.writeSolutions(problem)

    # only crawl readme
    elif sys.argv[1] == '--readme':
        LeetCodeCrawler.writeREADME(problems, False)
