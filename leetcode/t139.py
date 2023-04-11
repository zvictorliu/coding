class Solution:
    str = ""
    List = []
    def wordBreak(self, s: str, wordDict: List) -> bool:
        # DP
        N = len(s)
        dp = [False] * (N + 1) 
        dp[0] = True
        for i in range(0, N):
            for j in range(i + 1, N + 1):
                if (dp[i] & (s[i:j] in wordDict)): #i:j [i,j-1]
                    dp[j] = True

        return dp[N]
    
s = "catsandog"
wordDict = ["cats","dog","sand","and","cat"]

res = Solution()
result = res.wordBreak(s, wordDict)
print(result)

# result = Solution.wordBreak(None, s, wordDict)
# print(result)

