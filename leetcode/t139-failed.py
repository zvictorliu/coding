class Solution:
    str = ""
    List = {}
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        if len(s) == 0:
            return True
        n = len(wordDict)
        while n:
            n -= 1
            head = wordDict[0]
            del(wordDict[0])
            wordDict.append(head)

            tmp = s
            while tmp:
                flag = False
                for item in wordDict:
                    if (tmp[:len(item)] == item):
                        tmp = tmp[len(item):]
                        flag = self.wordBreak(tmp, wordDict)
                        if (flag == False):
                            break
                        else:
                            return True
                if (flag == False):
                    break
        return False     
        
