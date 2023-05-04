#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        // 每次不一定是选最大的，在一定范围内是可以预见对方有没有可能赢的
        // 如果偶数次中有可能会输，则下个奇数必然不可能是这种情况的分支
        // 如果赢的结果一定是 最终和满足，而前面都不满足
        // 
        // vector<int> dp(maxChoosableInteger+1);
        // dp[0] = 0;
        // for (int i = 1; i <= maxChoosableInteger; i++){
        //     for (int j = 1; j <= maxChoosableInteger; j++){
        //         if (i < j) dp[j] = dp[j-1] + i;
        //         else {
        //             dp[j] = (j*(j+1))/2;
        //         } 
        //     }
        //     if (dp[maxChoosableInteger] >= desiredTotal) {
        //         if (i % 2 == 0) return false;
        //         else return true;
        //     }
        // }
        // return false;
    }
};

int main() {

    Solution res;
    
    
    return 0;
}
