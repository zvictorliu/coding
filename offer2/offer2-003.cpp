#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        // ����
        // ż��
        // �о����Զ�̬�滮
        vector<int> dp(n+1);
        for (int i = 0; i <= n; i++){
            if (i == 0) dp[i] = 0;
            else if (i == 1) dp[i] = 1;
            else {
                if (i % 2 == 0) dp[i] = dp[i/2];
                if (i % 2 == 1) dp[i] = dp[i/2] + 1;
            }
        }
        return dp;
    }
};

int main(){
    int n;
    cin >> n;
    Solution res;
    res.countBits(n);
    return 0;
}