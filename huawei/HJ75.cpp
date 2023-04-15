#include <iostream>
#include <vector>
using namespace std;

class Solution{

public:
    int max_substr(string &str1, string &str2){
        int N = str1.length();
        int M = str2.length();

        vector<vector<int>> dp(N+1, vector<int> (M+1, 0)); //真的基本都是要+1的
        // dp[i][j] 子串(i-1, j-1)结尾 的最大公共子串长度，最后返回其中的最大一个
        // 如果引入的两个字符不等，则以其结尾便无法构成公共子串，为0
        // 如果相等，则加一
        int max_len = 0;
        for (int i = 1; i <= N; i++){
            for (int j = 1; j <= M; j++){
                if (str1[i-1] == str2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else {
                    dp[i][j] = 0;
                }
                max_len = max(max_len, dp[i][j]);
            }
        }

        return max_len;
    }

};

int main() {

    string str1,str2;
    cin >> str1 >> str2;

    Solution res;
    cout << res.max_substr(str1, str2) << endl;

    return 0;
}
