#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <limits>
#include <deque>
using namespace std;

class Solution1 { // 超时
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // 单调队列+普通队列
        queue<int> q1,q2;
        vector<int> maxVal;
        if (k == 1) return nums;
        q1.push(nums[0]);
        for (int i = 1; i < k; i++){
            if (nums[i] >= q1.back()) q1.push(nums[i]);
            else q2.push(nums[i]);
        }
        maxVal.push_back(q1.back());
        for (int i = k; i < nums.size(); i++){
            // 删除第一个
            if (q2.empty() || q1.front() == nums[i-k] || q2.front() != nums[i-k]){
                q1.pop();
            }
            else {
                q2.pop();
            }

            if (q1.empty()) {
                int sz = q2.size();
                q1.push(q2.front());
                q2.pop();
                while (--sz){
                    int f = q2.front();
                    q2.pop();
                    if (f >= q1.back()) q1.push(f);
                    else q2.push(f);
                }
            }

            // 加入新的 q1不可能为空
            if (nums[i] >= q1.back()) {
                q1.push(nums[i]);
            }
            else {
                q2.push(nums[i]);
            }

            maxVal.push_back(q1.back());
        }

        return maxVal;
    }
};

class Solution { // 优先队列，只需考虑最大值在不在窗口中即可，队列里有被移除的元素也无所谓
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // 单调队列，也是如此，只是找最大值的方法不一样
        if (k == 1) return nums;
        vector<int> maxVal;
        deque<int> dq; // 还有现成的数据结构可以用
        for (int i = 0; i < k; i++){
            while (!dq.empty() && nums[dq.back()] <= nums[i]){ //这里要取等于，从最后的最大值开始的递减序列
                dq.pop_back();
            }
            dq.push_back(i);
        }

        maxVal.push_back(nums[dq.front()]);
        for (int j = k; j < nums.size(); j++){
            while (!dq.empty() && nums[dq.back()] <= nums[j]) {
                dq.pop_back();
            }
            dq.push_back(j);

            while (j - dq.front() >= k) {
                dq.pop_front();
            }

            maxVal.push_back(nums[dq.front()]);
        }

        return maxVal;
    }
};

int main() {

    vector<int> nums = {1,3,1,2,0,5};
    int k = 3;
    Solution res;
    res.maxSlidingWindow(nums, k);
    
    return 0;
}
