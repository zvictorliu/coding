#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int N = nums.size();
        for (int i = 0; i < N; i++){ // k可能很大
            for (int j = i+1;  j < N && (j <= i+k); j++){
                if (nums[i] == nums[j]) return true;
            }
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