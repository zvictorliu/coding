#include <iostream>
#include <vector>
using namespace std;

class Solution{

public:
    int path_cnt(int n, int m){
        vector<vector<int>> dp(n+2, vector<int> (m+2, 0)); // 要留出一个空行
        for (int i = 1; i < n+2; i++) dp[i][1] = 1;
        for (int j = 1; j < m+2; j++) dp[1][j] = 1;

        for (int i = 2; i <= n+1; i++){
            for (int j = 2; j <= m+1; j++){
                dp[i][j] = dp[i-1][j-1]*2 + dp[i-2][j] + dp[i][j-2]; // 左边，上变，对角过来
            }
        }

        return dp[n+1][m+1];
    }

};

int main() {
    int n,m;
    cin >> n >> m;
    Solution res;
    cout << res.path_cnt(n, m) << endl;
    
    return 0;
}
