#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // 猜测用dp，表示以当前字符结尾的最小子数组
        // 状态转移方程？>= target为1，否则：如果dp[i-1]不为0的话就是0，为0的话。。。可能需要一个记录值
        // 然后在其中找最小值(0除外)，如果只有0则返回0
        // 问题 如果前面已经有一个子数组了，其尾部和之后的元素组成新的会不会更好？好像确实，那dp估计不好弄了

        // 滑动窗口法，看上去有点暴力，其实可以接受的

    }
};

int main() {

    Solution res;
    
    return 0;
}
