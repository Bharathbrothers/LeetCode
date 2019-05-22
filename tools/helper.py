def getDirectory(lang, problemID, ext):
    return './solutions/' + lang + '/' + problemID + ext


def purify(code):
    try:
        code = code.replace('\\u000A', '\n')
        code = code.replace('\\u003C', '<')
        code = code.replace('\\u003E', '>')
        code = code.replace('\\u0026', '&')
        code = code.replace('\\u003D', '=')
        code = code.replace('\\u003B', ';')
        code = code.replace('\\u002D', '-')
        code = code.replace('\\u0027', "'")
        code = code.replace('\\u0022', '"')
        code = code.replace('\\u000D', '')
        code = code.replace('\\u005C', '\\')
    except AttributeError:
        return code

    return code
