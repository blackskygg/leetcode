class Solution(object):
    directions = [(0, 1), (0, -1), (-1, 0), (1, 0)]
    def _search(self, board, visited, r, c, word, pos):
        if pos == len(word) - 1 and word[pos] == board[r][c]:
            return True

        if word[pos] != board[r][c]:
            return False
            
        for dr, dc in self.directions:
            nr, nc = r+dr, c+dc
            if (0 <= nr < len(board))   \
                and (0 <= nc < len(board[0])) \
                and not visited[nr][nc]:
                
                visited[nr][nc] = True
                if self._search(board, visited, nr, nc, word, pos+1):
                    return True
                visited[nr][nc] = False

        return False
            
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        visited = [ [False for i in xrange(len(board[0]))] for i in xrange(len(board)) ]
        
        for i, row in enumerate(board):
            for j, c in enumerate(row):
                if c == word[0]:
                    visited[i][j] = True
                    if self._search(board, visited, i, j, word, 0):
                        return True
                    visited[i][j] = False
        return False

s = Solution()
print s.exist([
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
],
"SEE")
