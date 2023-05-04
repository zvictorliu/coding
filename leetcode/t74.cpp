#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // 两次二分查找，第一次不是准确的值，好像容易出问题
        int row, l = 0, m, r = matrix.size() - 1;
        while (l <= r) {
            m = (l + r + 1) >> 1;
            if (matrix[m][0] == target) return true;
            if (matrix[m][0] > target) r = m - 1;
            else l = m + 1;
        }

        row = (r > 0) ? r : 0;
        l = 0;
        r = matrix[row].size() - 1;
        while (l <= r) {
            m = (l + r + 1) >> 1;
            if (matrix[row][m] == target) return true;
            if (matrix[row][m] > target) r = m - 1;
            else l = m + 1;
        }
        return false;

    }
};

int main() {

    Solution res;
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,50}};
    int target = 11;
    cout << res.searchMatrix(matrix, target) << endl;
    return 0;
}
