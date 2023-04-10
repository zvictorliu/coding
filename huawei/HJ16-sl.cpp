#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N, m; // N 奖金 m 物品个数
    cin >> N >> m;
    N /= 10; // 由于所有的价格都是10的整倍数，所以可以均除10以简化运算复杂度

    int price, priority, hasAttachments;
    // 使用一个(m+1)X6的数组存储数据，m+1是根据物品编号，0作废；6考虑可能有附件的最多的情况
    vector<vector<int>> data(m+1, vector<int>(6, 0)); // 二维数组，0初始化
    
    for(int i = 1; i <= m; i++){ //按照编号，i=0不要
        cin >> price >> priority >> hasAttachments;
        // 主件
        if(hasAttachments == 0){
            data[i][0] = price/10; //主 价格
            data[i][1] = priority; //主 权重
        }
        // 第一个附件
        else if(data[hasAttachments][2] == 0){ //首次
            data[hasAttachments][2] = price/10; //附1 价格
            data[hasAttachments][3] = priority; // 附1 权重
        }
        // 第二个附件
        else {
            data[hasAttachments][4] = price/10; // 附2 价格
            data[hasAttachments][5] = priority; // 附2 权重
        }
    }

    vector<vector<int>> dp(m+1, vector<int>(N+1, 0)); // 状态的二维数组
    for(int i = 1; i < m+1; i++){ // 第i个物品
        for(int j = 1; j < N+1; j++){ // 重量为j
            // 价格
            int pricePrime = data[i][0];
            int priceAtta1 = data[i][2];
            int priceAtta2 = data[i][4];
            // 权重
            int priorPrime = data[i][1];
            int priorAtta1 = data[i][3];
            int priorAtta2 = data[i][5];
            // 有一些是0

            dp[i][j] = (j >= pricePrime) ? ( max(dp[i-1][j - pricePrime] 
                                            + priorPrime * pricePrime, 
                                            dp[i-1][j]) ) : dp[i-1][j];
            dp[i][j] = j >= (pricePrime + priceAtta1) ? max(dp[i-1][j - pricePrime - priceAtta1]
                                                        + priorPrime * pricePrime 
                                                        + priorAtta1 * priceAtta1, 
                                                        dp[i][j]) : dp[i][j];
            dp[i][j] = j >= (pricePrime + priceAtta2) ? max(dp[i-1][j - pricePrime - priceAtta2]
                                                        + priorPrime * pricePrime 
                                                        + priorAtta2 * priceAtta2, 
                                                        dp[i][j]) : dp[i][j];
            dp[i][j] = j >= (pricePrime + priceAtta1 + priceAtta2) ? 
                                                        max(dp[i-1][j - pricePrime - priceAtta1 - priceAtta2]
                                                        + priorPrime * pricePrime 
                                                        + priorAtta1 * priceAtta1
                                                        + priorAtta2 * priceAtta2, 
                                                        dp[i][j]) : dp[i][j];
        }
    }
    cout << dp[m][N] * 10 <<endl;
    return 0;
}
