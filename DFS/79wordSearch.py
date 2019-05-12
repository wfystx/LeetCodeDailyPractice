class Solution(object):
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        def dfs(word, board, i, j):
            if len(word) == 0:
                return True
            if i < 0 or i >= len(board) or j < 0 or j >= len(board[0]) or board[i][j] != word[0]:
                return False
            temp = board[i][j]
            board[i][j] = '#'
            res = dfs(word[1:], board, i+1, j) or dfs(word[1:], board, i-1, j) or dfs(word[1:], board, i, j+1) or  dfs(word[1:], board, i, j-1)
            board[i][j] = temp
            return res
        
        if not board:
            return False
        for i in range(len(board)):
            for j in range(len(board[0])):
                if dfs(word, board, i, j):
                    return True
        return False