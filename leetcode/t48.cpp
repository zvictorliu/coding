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
    void rotate(vector<vector<int>>& matrix) {
        // 这种题的套路一般是翻转，虽然暴力也可以
        // 要想到对角线翻转+上下翻转就是90°
        int N = matrix.size(); 
        if (N == 1) return;
        // vector应该不能直接赋值
        // todo 对角线翻转
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N - i-1; j++){
                swap(matrix[i][j], matrix[N-j-1][N-i-1]);
            }
        }

        // todo 上下翻转
        for (int i = 0; i < N / 2; i++) {
            for (int j = 0; j < N; j++){
                swap(matrix[i][j], matrix[N-i-1][j]);
            }
        }

    }
};

int main() {

    // Solution res;
    
    return 0;
}
