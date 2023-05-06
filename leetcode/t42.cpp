#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution_1 {
public:
    int trap(vector<int>& height) {
        // 每行开始遍历
        // 找到第一个1视为有效，之后遇到0则入栈，遇到1则出栈计数，然后还要沉没
        // 确实像华为的第一题
        // try1: 这个算暴力解，会超时，可以稍微优化一下，不知道效果如何
        // try2: 减少层数也 还是超时，得考虑别的算法了
        int water_cnt = 0;
        int N = height.size();
        int max_height = 0;
        int min_height = INT_MAX;
        for (int i = 0; i < N; i++){
            max_height = max(max_height, height[i]);
            min_height = min(min_height, height[i]);
        }
        for (int i = min_height; i < max_height; i++){
            bool flag = false;
            int waters = 0;
            for (int j = 0; j < N; j++){
                if (height[j] == min_height) waters++;
                else {
                    if (!flag) {
                        flag = true;
                        waters = 0;
                    }
                    else {
                        water_cnt += waters;
                        waters = 0;
                    }
                    
                }
                height[j] = (height[j] - 1 >= min_height ) ? (height[j] - 1) : min_height;
            }

        }

        return water_cnt;

        

    }
};

class Solution {
public:
    int trap(vector<int>& height){
        int sum = 0;
        stack<int> stk;
        int N = height.size();
        int current = 0;
        while (current < N){
            while (!stk.empty() && height[current] > height[stk.top()])
            {
                int base = height[stk.top()];
                stk.pop();
                if (stk.empty()) break; // 积不了水
                int len = current - stk.top() - 1; // 距离
                int h = min(height[current], height[stk.top()]) - base; // 两侧最小高度-base
                sum += h*len;
            }
            stk.push(current);
            current++;
        }

        return sum;
    }

};

int main() {

    Solution res;
    vector<int> heights = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << res.trap(heights) << endl;
    
    return 0;
}
