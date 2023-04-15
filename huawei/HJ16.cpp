#include <iostream>
#include <vector>
using namespace std;

class Solution{

public:
    int max_satification(int N, vector<vector<vector<int>>> data, int m){
        vector<vector<int>> dp(m+1, vector<int> (N+1,0)); 

        for (int i = 1; i <= m; i++){
            for (int j = 0; j <= N; j++){
                // 为方便区分，单独取出来
                int pricePrime = data[i][0][0];
                int priceAtta1 = data[i][0][1];
                int priceAtta2 = data[i][0][2];
                
                int priorPrime = data[i][1][0];
                int priorAtta1 = data[i][1][1];
                int priorAtta2 = data[i][1][2];

                // 不选或放不下 dp[i-1][j]
                // 主，主+附1，主+附2，主+附1+附2
                // 如何找出最大值？

                if (j - pricePrime < 0) dp[i][j] = dp[i-1][j]; // 放不下主件
                else dp[i][j] = max(dp[i-1][j], dp[i-1][j - pricePrime] + pricePrime*priorPrime); // 放得下主件，比较放不放的好
                // 至此主件要不要和能不能要已经考虑完了，后面更新dp[i][j]
                // 考虑附件，如果附件放不下或者不放，则应该还是处于只考虑完主件的情况，dp[i][j]不变
                if (j - pricePrime - priceAtta1 >= 0) dp[i][j] = max(dp[i][j], dp[i-1][j - pricePrime - priceAtta1] + pricePrime*priorPrime + priceAtta1*priorAtta1);
                if (j - pricePrime - priceAtta2 >= 0) dp[i][j] = max(dp[i][j], dp[i-1][j - pricePrime - priceAtta2] + pricePrime*priorPrime + priceAtta2*priorAtta2);
                // 附件1不会影响附件2？附件二时的dp[i][j]也包含了附件1的情况，会替换成最优的
                if (j - priceAtta1 - priceAtta2 - pricePrime >= 0) dp[i][j] = max(dp[i][j], dp[i-1][j - priceAtta1 - priceAtta2 - pricePrime] + priceAtta1*priorAtta1 + priceAtta2*priorAtta2 + pricePrime*priorPrime);
            }

        }

        return dp[m][N]*10;

    }

};

int main() {
    
    int N, m;
    cin >> N >> m;
    vector<vector<vector<int>>> data(m+1, vector<vector<int>> (2, vector<int> (3,0)));
    for (int i = 1; i <= m; i++){ // 也必须是从1开始编号，否则会有些麻烦
        int v,w,p;
        cin >> v >> w >> p;
        if (p == 0){ //主件
            data[i][0][0] = v / 10; // 都是10的整数倍
            data[i][1][0] = w;
        }
        else if (data[p][0][1] == 0){ //第一个附件
            data[p][0][1] = v / 10;
            data[p][1][1] = w;
        }
        else { // 第二个附件
            data[p][0][2] = v / 10;
            data[p][1][2] = w;
        }
    }
    // 且认为有m个主件（原本是附件的改为0）
    Solution res;
    cout << res.max_satification(N / 10, data, m) << endl;


    return 0;
}