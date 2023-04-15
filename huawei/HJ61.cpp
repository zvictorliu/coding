#include <iostream>
#include <vector>
using namespace std;

class Solution{

public:
    int distribution(int m, int n){
        vector<vector<int>> dp(m+1, vector<int> (n+1,0)); //m,n要能取到
        for (int i = 0; i <= m; i++){
            for (int j = 1; j <= n; j++){
                if (i == 0 || j==1) dp[i][j] = 1; //没有苹果，或者只有一个盘子，都是只有一种方法
                else if (j > i) dp[i][j] = dp[i][i]; //苹果比盘子少，拿走多的盘子也不影响
                else { //苹果比盘子多
                    // 无空盘子方法，每个盘子必然至少有一个，因此同时拿走一个不影响
                    // 有空盘子方法，至少有一个 则相当于j-1个盘子的问题
                    dp[i][j] = dp[i-j][j] + dp[i][j-1];
                }
                
            }
        }

        return dp[m][n];
    }
};

int main() {
    int m,n;
    cin >> m >> n;
    Solution res;
    cout << res.distribution(m, n) << endl;

    return 0;
}
