#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <limits>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int N = nums.size();
        vector<int> dp(N+1, 0);
        dp[0] = 0;
        dp[1] = nums[0];
        for (int i = 2; i < N+1; i++){
            dp[i] = max(dp[i-1], dp[i-2]+nums[i-1]);
        }

        return dp[N];
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        int N = nums.size();
        int k_2 = 0, k_1 = 0, k;
        for (int i = 0; i < N; i++){
            k = max(k_1, k_2 + nums[i]);
            k_2 = k_1;
            k_1 = k;
        }
        return k;
    }
};

int main() {

    // Solution res;
    
    return 0;
}
