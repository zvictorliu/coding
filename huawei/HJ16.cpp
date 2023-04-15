#include <iostream>
#include <vector>
using namespace std;

class Solution{

public:
    int max_satification(int N, vector<vector<vector<int>>> data, int m){
        vector<vector<int>> dp(m+1, vector<int> (N+1,0)); 

        for (int i = 1; i <= m; i++){
            for (int j = 0; j <= N; j++){
                // Ϊ�������֣�����ȡ����
                int pricePrime = data[i][0][0];
                int priceAtta1 = data[i][0][1];
                int priceAtta2 = data[i][0][2];
                
                int priorPrime = data[i][1][0];
                int priorAtta1 = data[i][1][1];
                int priorAtta2 = data[i][1][2];

                // ��ѡ��Ų��� dp[i-1][j]
                // ������+��1����+��2����+��1+��2
                // ����ҳ����ֵ��

                if (j - pricePrime < 0) dp[i][j] = dp[i-1][j]; // �Ų�������
                else dp[i][j] = max(dp[i-1][j], dp[i-1][j - pricePrime] + pricePrime*priorPrime); // �ŵ����������ȽϷŲ��ŵĺ�
                // ��������Ҫ��Ҫ���ܲ���Ҫ�Ѿ��������ˣ��������dp[i][j]
                // ���Ǹ�������������Ų��»��߲��ţ���Ӧ�û��Ǵ���ֻ�����������������dp[i][j]����
                if (j - pricePrime - priceAtta1 >= 0) dp[i][j] = max(dp[i][j], dp[i-1][j - pricePrime - priceAtta1] + pricePrime*priorPrime + priceAtta1*priorAtta1);
                if (j - pricePrime - priceAtta2 >= 0) dp[i][j] = max(dp[i][j], dp[i-1][j - pricePrime - priceAtta2] + pricePrime*priorPrime + priceAtta2*priorAtta2);
                // ����1����Ӱ�츽��2��������ʱ��dp[i][j]Ҳ�����˸���1����������滻�����ŵ�
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
    for (int i = 1; i <= m; i++){ // Ҳ�����Ǵ�1��ʼ��ţ��������Щ�鷳
        int v,w,p;
        cin >> v >> w >> p;
        if (p == 0){ //����
            data[i][0][0] = v / 10; // ����10��������
            data[i][1][0] = w;
        }
        else if (data[p][0][1] == 0){ //��һ������
            data[p][0][1] = v / 10;
            data[p][1][1] = w;
        }
        else { // �ڶ�������
            data[p][0][2] = v / 10;
            data[p][1][2] = w;
        }
    }
    // ����Ϊ��m��������ԭ���Ǹ����ĸ�Ϊ0��
    Solution res;
    cout << res.max_satification(N / 10, data, m) << endl;


    return 0;
}