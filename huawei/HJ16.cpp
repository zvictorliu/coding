#include <iostream>
#include <vector>
using namespace std;

class Solution{

public:
    int max_satification(int N, vector<vector<int>> items, int num){
        vector<vector<int>> dp(num, vector<int> (N+1,0)); // �?�?以取到N�?

        for (int i = 0; i < num; i++){
            for (int j = 0; j <= N; j++){
                // dp[i][j] �? 不�?��?�主�? �? 要主件（�?要主件，主件+附件1，主�?+附件2，主�?+附件1�?2）中最优的结果


            }

        }

        return 0;

    }

};

int main() {
    
    int N, m, num = 0;
    cin >> N >> m;
    vector<vector<vector<int>>> data(m+1, vector<vector<int>> (2, {0}));
    for (int i = 1; i <= m; i++){
        int v,w,p;
        cin >> v >> w >> p;
        if (p == 0){
            data[i][0][0] = v;
            data[i][1][0] = w;
        }
        else {
            data[p][0].push_back(v);
            data[p][1].push_back(w); //����Ҳ������Ҫ����Ĭ������������������Ҫ�ж��Ⱥ���
        }
    }

    // Solution res;
    // cout << res.max_satification(N, items, num) << endl;


    return 0;
}