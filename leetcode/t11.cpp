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
    int maxArea(vector<int>& height) {
        // 正反各搜索一次
        int N = height.size();
        int maxA = 0;
        for (int i = 0; i < N; i++){
            for (int j = N-1; j > i; j--){
                if (height[j] >= height[i]){
                    maxA = max(maxA, height[i]*(j-i-1));
                    break;
                }
            }
            for (int k = 0; k < i; k++){
                if (height[k] >= height[i]){
                    maxA = max(maxA, height[i]*(i-k-1));
                    break;
                }
            }
        }
        // for (int i = N-1; i >= 0; i--){
        //     for (int j = 0; j < i; j++){
        //         if (height[j] >= height[i]){
        //             maxA = max(maxA, height[i]*(i-j-1));
        //             break;
        //         }
        //     }
        // }
        return maxA;
    }
};

int main() {

    // Solution res;
    
    return 0;
}
