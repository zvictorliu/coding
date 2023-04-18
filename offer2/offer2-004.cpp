#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //利用unordered_map提供的哈希表，不需要考虑那么多
        //自己写哈希表就会因为数组不是正整数而难做
        // for (auto [num, occ]: freq) 这种类似于python的写法要学会
        unordered_map<int,int> freq_cnt; //可以理解为空的
        int N = nums.size();
        for (int i = 0; i < N; i++){
            ++freq_cnt[nums[i]]; //这样访问一下就相当于添加进去了，而且初始化为0
        }
        for (auto [n, f]: freq_cnt){ //有警告，但是能跑
            if (f == 1) return n;
        }

        return 0;
    }
};

// 还有一种位运算的做法，循环31次，每一位不是0就是1，由于出现三次，将每一位之和求出，如果答案的这一位是0，则和为3的倍数，
// 如果答案的这一位是1，则和%3为1
// 只是要注意把这一位修改的技巧，可看官方题解

int main(){
    vector<int> nums;
    int n;
    while (cin >> n) {
        nums.push_back(n);
    }

    Solution res;
    cout << res.singleNumber(nums) << endl;

    return 0;
}