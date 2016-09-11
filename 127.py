import string

class Solution(object):
    def ladderLength(self, beginWord, endWord, wordlist):
        fronts = [{beginWord}, {endWord}]
        flag = 0
        wordlist.discard(beginWord)
        wordlist.discard(endWord)
        n = 2
        while fronts[0] and fronts[1] and not flag:
            if len(fronts[0]) > len(fronts[1]):
                fronts.reverse()

            newlevel = set()
            flag = False
            for word in fronts[0]:
                for i in xrange(len(beginWord)):
                    for ch in string.lowercase:
                        newword = word[:i]+ch+word[i+1:]
                        if newword in fronts[1]:
                            flag = 1
                            break
                        elif newword in wordlist:
                            newlevel.add(newword)
                            wordlist.remove(newword)
            fronts[0] = newlevel
            n=n+1
            
        if not flag:
            return 0
        else:
            return n-1
            
