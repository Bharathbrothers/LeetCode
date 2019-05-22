class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        def isValidRow(board: List[List[str]]) -> bool:
            for row in board:
                if isValid(row) == False:
                    return False
            return True

        def isValidCol(board: List[List[str]]) -> bool:
            for col in zip(*board):
                if isValid(col) == False:
                    return False
            return True

        def isValidSquare(board: List[List[str]]) -> bool:
            for i in (0, 3, 6):
                for j in (0, 3, 6):
                    square = [board[x][y]
                              for x in range(i, i + 3) for y in range(j, j + 3)]
                    if isValid(square) == False:
                        return False
            return True

        def isValid(list: List[str]) -> bool:
            res = [i for i in list if i != '.']
            return len(res) == len(set(res))

        return isValidRow(board) and isValidCol(board) and isValidSquare(board)
