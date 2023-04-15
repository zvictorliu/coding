#include <iostream>
#include <vector>
using namespace std;

class Solution{

public:
    int distance(string &str1, string &str2){
        int N = str1.length();
        int M = str2.length();

        vector<vector<int>> dp(N+1, vector<int> (M+1, 0));
        // 初始化
        dp[0][0] = 0;
        for (int i = 1; i <= N; i++) {
            dp[i][0] = i;
        }
        for (int j = 1; j <= M; j++){
            dp[0][j] = j;
        }

        for (int i = 1; i <= N; i++){
            for (int j = 1; j <= M; j++){
                // 如果字符相同，则应该是dp[i-1][j-1]
                // 如果字符不同：删除str1 删除str2 修改str1为str2 中最小的那个
                if (str1[i-1] == str2[j-1]) dp[i][j] = dp[i-1][j-1];
                else{
                    int min_step = 1024;
                    min_step = min(min_step, dp[i-1][j] + 1);
                    min_step = min(min_step, dp[i][j-1] + 1);
                    min_step = min(min_step, dp[i-1][j-1] + 1);

                    dp[i][j] = min_step;
                }
            }
        }
        
        return dp[N][M];
    }

};

int main() {

    string str1,str2;
    cin >> str1 >> str2;

    Solution res;
    cout << res.distance(str1, str2) << endl;
    
    return 0;
}
