#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // int N = nums.size();
        // for (int i = 0; i < N; i++){ // k可能很大，优化在拿尾部去比，就可以早点找到
        //     for (int j = i+1;  j < N && (j <= i+k); j++){
        //         if (nums[i] == nums[j]) return true;
        //     }
        // }

        // return false;
        int N = nums.size();
        unordered_set<int> set;
        for (int i = 0; i < N; i++){
            if (i > k){ //窗长其实是k+1
                set.erase(nums[i - k - 1]);
            }
            if (set.count(nums[i]) != 0){
                return true;
            }
            set.emplace(nums[i]);
        }
        return false; 
    }
};

int main(){

    vector<int> nums = {1,1};
    int k = 3;
    Solution res;

    cout << res.containsNearbyDuplicate(nums, k) << endl;

    return 0;
}