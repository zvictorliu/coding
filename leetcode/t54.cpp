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
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // 还是比较适合单向DFS，同时需要记录是否访问过了
        // 由于题目给了数值的限定范围，所以就不需要单独开数组了
        // 感觉会死循环出不来，这应该不是合理解法

        // 还是通过修改边界做到的
        vector<int> res;
        if (matrix.size() == 0) return res; // 特殊情况
        int uLim = 0;
        int lLim = 0;
        int rLim = matrix[0].size()-1;
        int dLim = matrix.size()-1;
        while (1) { 
            // 向右搜索到底
            for (int i = lLim; i <= rLim; i++) res.push_back(matrix[uLim][i]);
            // 降低上界，判断是否交错
            if ((++uLim) > dLim) break;
            // 向下搜索
            for (int i = uLim; i <= dLim; i++) res.push_back(matrix[i][rLim]);
            if ((--rLim) < lLim) break;
            // 向左搜索
            for (int i = rLim; i >= lLim; i--) res.push_back(matrix[dLim][i]);
            if ((--dLim) < uLim) break;
            // 向上搜索
            for (int i = dLim; i >= uLim; i--) res.push_back(matrix[i][lLim]);
            if ((++lLim) > rLim) break;
        }

        return res;
    }

};

int main() {

    // Solution res;
    
    return 0;
}
