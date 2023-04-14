#include <iostream>
#include <vector>
using namespace std;

class Solution{

public:
    int max_satification(int N, vector<vector<int>> items, int num){
        vector<vector<int>> dp(num, vector<int> (N+1,0)); // 鏄?鍙?浠ュ彇鍒癗鐨?

        for (int i = 0; i < num; i++){
            for (int j = 0; j <= N; j++){
                // dp[i][j] 鏄? 涓嶈?佽?ヤ富浠? 涓? 瑕佷富浠讹紙鍙?瑕佷富浠讹紝涓讳欢+闄勪欢1锛屼富浠?+闄勪欢2锛屼富浠?+闄勪欢1鍜?2锛変腑鏈�浼樼殑缁撴灉


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
            data[p][1].push_back(w); //不过也许并不必要，都默认两个附件，不过就要判断先后了
        }
    }

    // Solution res;
    // cout << res.max_satification(N, items, num) << endl;


    return 0;
}