class Solution(object):
    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        result = []
        step = len(words[0])
        nwords = len(words)
        slen = len(s)
        table = {}     
        for word in words:
                table[word] = table[word] + 1 if word in table else 1    
        for index1 in range(step):
            curr = table.copy() 
            cnt = 0
            index2 = index1
            index3 = index2
            
            while index3 + step <= slen:
                word = s[index3:index3+step]
                index3 += step
                if word in table and curr[word] > 0:
                    curr[word] -= 1;
                    cnt = cnt + 1;
                    
                    if cnt == nwords:
                        cnt = 0
                        result.append(index2)
                        index2 += step
                        index3 = index2
                        curr = table.copy() 
                else:
                    curr = table.copy() 
                    if word in table:
                        index2 += step
                        index3 = index2
                    else:
                        index2 = index3
                    cnt = 0

        
        return result
