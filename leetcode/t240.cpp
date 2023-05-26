#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <limits>
using namespace std;

class Solution1 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // 二分查找一个不在其中的，取下界，注意特殊情况
        // 和那种有什么区别呢？这种不一定就是第一行查找到的列数下面，甚至不一定只有一个
        // 但是可以确定在这一侧，一直这样搜索下去
        // 四个角的坐标
        // 这样太麻烦了
        // 逐个搜索或者每行二分都是可以过的
        int r1 = 0,r2 = matrix.size()-1,c1 = 0,c2 = matrix[0].size()-1;

        while (r1 < r2-1 || c1 < c2-1){ // 这里的终止条件
            //! 不能偷懒，真的得是二分查找
            // 更新行
            if (matrix[(r1+r2)/2][c1] < target) r1 = (r1+r2)/2;
            else if (matrix[(r1+r2)/2][c1] > target) r2 = (r1+r2)/2;
            else return true;
            // 更新列
            if (matrix[r1][(c1+c2)/2] < target) c1 = (c1+c2) / 2;
            else if (matrix[r1][(c1+c2)/2] > target) c2 = (c1+c2) / 2;
            else return true;

            // 更新行
            if (matrix[(r1+r2)/2][c2] < target) r1 = (r1+r2)/2;
            else if (matrix[(r1+r2)/2][c2] > target) r2 = (r1+r2)/2;
            else return true;
            // 更新列
            if (matrix[r2][(c1+c2)/2] < target) c1 = (c1+c2) / 2;
            else if (matrix[r2][(c1+c2)/2] > target) c2 = (c1+c2) / 2;
            else return true;
        }

        if (matrix[r1][c1] == target || matrix[r1][c2] == target || matrix[r2][c1] == target || matrix[r2][c2] == target) return true;
        return false;
    }
};

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Z字查找，利用好行和列的严格大于性质
        int x = 0, y = matrix[0].size()-1;
        while (x < matrix.size() && y >= 0){
            if (matrix[x][y] == target) return true;

            if (matrix[x][y] > target) { // 下边，右边都不可能
                y--; // 去除右侧
            } 
            else { // 上，左都不可能
                x++; // 去除上侧
            }
        }

        return false;
    }
};

int main() {

    vector<vector<int>> matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    int target = 5;
    Solution res;
    cout << res.searchMatrix(matrix, target) << endl;
    
    return 0;
}
