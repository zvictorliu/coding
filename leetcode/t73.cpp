#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <limits>
#include <set>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // 先遍历以找出所有为0的点，然后逐个dfs
        // 每个方向dfs只能朝一个方向，遇到0和边界停止
        // 还是不行，会被从另一个方向过来的0阻断，但如果不这样就可能会超时
        // 如果两个零点没有同行or同列关系，那么其实可以补上
        // 所以应当是行和列的乘积
        stack<vector<int>> zeroPos;
        set<int> row;
        set<int> col;
        for (int i = 0; i < matrix.size(); i++){
            for (int j = 0; j < matrix[0].size(); j++){
                if (matrix[i][j]==0) {
                    row.emplace(i);
                    col.emplace(j);
                }
            }
        }

        for (int x : row){
            for (int y : col){
                // ! 注意这样组合后这个位置就不一定是0了
                matrix[x][y] = 0;
                dfs(matrix, x-1, y, 0);
                dfs(matrix, x+1, y, 1);
                dfs(matrix, x, y-1, 2);
                dfs(matrix, x, y+1, 3);
            }
        }
    }

    void dfs(vector<vector<int>>& matrix, int x, int y, int direction){
        if (x < 0 || x > matrix.size()-1 || y < 0 || y > matrix[0].size()-1) return;
        if (matrix[x][y] == 0) return;
        matrix[x][y] = 0;
        switch (direction)
        {
        case 0:
            dfs(matrix, x-1, y, direction);
            break;
        case 1:
            dfs(matrix, x+1, y, direction);
            break;
        case 2:
            dfs(matrix, x, y-1, direction);
            break;
        case 3:
            dfs(matrix, x, y+1, direction);
            break;
        default:
            break;
        }
    }
};
// 其实完全可以确定行和列后直接整个遍历，无需这样dfs
// 可以单开等大的数组
// 还可以用第一行和第一列来记录，不考虑第一行和第一列的，进行标记处理，然后再看是否第一行第一列有过0
// 如果算进去就会干扰

int main() {

    vector<vector<int>> matrix = {{3,5,5,6,9,1,4,5,0,5},{2,7,9,5,9,5,4,9,6,8},{6,0,7,8,1,0,1,6,8,1},{7,2,6,5,8,5,6,5,0,6},{2,3,3,1,0,4,6,5,3,5},{5,9,7,3,8,8,5,1,4,3},{2,4,7,9,9,8,4,7,3,7},{3,5,2,8,8,2,2,4,9,8}};
    Solution res;
    res.setZeroes(matrix);
    
    return 0;
}
