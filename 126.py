import string
from collections import deque

class Solution(object):

    def __init__(self, *args, **kwargs):
        self.minPaths = []
        self.fathers = {}
        self.midSet = []
        self.beginWord = ""
        self.endWord = ""

    def _dfs(self, path, state):
        if state == 0:
            if path[0] == self.beginWord or path[0] == self.endWord:
                self._dfs(path, 1)
            else:
                for u in self.fathers[path[0]]:
                    path.appendleft(u)
                    self._dfs(path, 0)
                    path.popleft()
        elif state == 1:
            if path[-1] == self.beginWord:
                self.minPaths.append([path[i] for i in xrange(len(path)-1, -1, -1)])
                return
            elif path[-1] == self.endWord:
                self.minPaths.append([path[i] for i in xrange(len(path))])
                return
            else:
                for u in self.fathers[path[-1]]:
                    path.append(u)
                    self._dfs(path, 1)
                    path.pop()

    def dfs(self, v, u):
        path = deque()
        path.append(u)
        path.appendleft(v)

        self._dfs(path, 0)

    def dbfs(self, beginWord, endWord, wordlist):
        fronts = [{beginWord}, {endWord}]

        while fronts[0] and fronts[1] and not self.minPaths:
            if len(fronts[0]) > len(fronts[1]):
                fronts.reverse()

            newlevel = set()
            flag = False
            for word in fronts[0]:
                for i in xrange(len(beginWord)):
                    for ch in string.lowercase:
                        newword = word[:i]+ch+word[i+1:]
                        if newword in fronts[1]:
                            self.dfs(word, newword)
                        elif newword in newlevel:
                            self.fathers[newword].append(word)
                        elif newword in wordlist:
                            self.fathers[newword] = [word]
                            newlevel.add(newword)
                            wordlist.remove(newword)
            fronts[0] = newlevel
        return False
            
    def findLadders(self, beginWord, endWord, wordlist):
        """
        :type beginWord: str
        :type endWord: str
        :type wordlist: Set[str]
        :rtype: List[List[int]]
        """
        self.beginWord = beginWord
        self.endWord = endWord
        wordlist.discard(beginWord)
        wordlist.discard(endWord)

        print "AAA"
        if self.dbfs(beginWord, endWord, wordlist):
            self.dfs()

        return [[u for u in l] for l in self.minPaths]

s = Solution()
print s.findLadders("red",
"tax",
{"ted","tex","red","tax","tad","den","rex","pee"})

s = Solution()
print s.findLadders("hot",
"dog",
{"hot","dog","cog","pot","dot"})
