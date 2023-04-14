#include <iostream>
#include <vector>
using namespace std;

class Solution{

public:
    int max_satification(int N, vector<vector<int>> items, int num){
        vector<vector<int>> dp(num, vector<int> (N+1,0)); // 是可以取到N的

        for (int i = 0; i < num; i++){
            for (int j = 0; j <= N; j++){
                // dp[i][j] 是 不要该主件 与 要主件（只要主件，主件+附件1，主件+附件2，主件+附件1和2）中最优的结果


            }

        }

    }

};

int main() {
    
    int N, m, num = 0;
    cin >> N >> m;
    vector<vector<vector<int>>> data(m+1, vector<vector<int>> (2, {0}));
    for (int i = 1; i <= m; i++){
        int p;
        vector<int> it(2,0);
        cin >> it[0] >> it[1] >> p;
        if (p == 0){
            data[i][0][0] = it[0];
            data[i][1][0] = it[1];
        }
        else {
            data[p].push_back(it);
        }
    }

    Solution res;
    // cout << res.max_satification(N, items, num) << endl;


    return 0;
}