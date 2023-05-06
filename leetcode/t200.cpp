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
    int numIslands(vector<vector<char>>& grid) { // DFS方法
        // dfs访问为1的节点，访问到的岛屿都修改为0，之后就再次搜索，如此便可统计数量
        int islandCnt = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == '1'){
                    islandCnt ++;
                    dfs(i, j, grid);
                }
            }
        }

        return islandCnt;
    }
    void dfs(int x, int y, vector<vector<char>>& grid){
        // 边界情况
        if (x >= grid.size() || y >= grid[0].size()) return;
        if (x < 0 || y < 0) return;
        if (grid[x][y] == '0') return;
        // 沉没
        grid[x][y] = '0';
        // 应该只需要往两个方向搜索
        dfs(x+1, y, grid);
        dfs(x-1, y, grid);
        dfs(x, y+1, grid);
        dfs(x, y-1, grid);
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) { // bfs 方法
        // 和dfs一样，只不过搜索方法换成了bfsint islandCnt = 0;
        int islandCnt = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == '1'){
                    islandCnt ++;
                    // bfs 节点坐标作为一个整体
                    vector<int> head = {i,j};
                    queue<vector<int>> nodeQueue;
                    nodeQueue.push(head);

                    while (!nodeQueue.empty())
                    {
                        vector<int> node = nodeQueue.front();
                        grid[node[0]][node[1]] = '0';
                        nodeQueue.pop();
                        vector<vector<int>> adjNodes = {{node[0]-1, node[1]},{node[0]+1, node[1]},{node[0], node[1]-1},{node[0], node[1]+1}};
                        for (auto ajnd : adjNodes){
                            if (ajnd[0] >= 0 && ajnd[0] < m && ajnd[1] >= 0 && ajnd[1] < n){
                                if (grid[ajnd[0]][ajnd[1]] == '1'){
                                    nodeQueue.push(ajnd);
                                }
                            }
                        }
                    }
                }
            }
        }

        return islandCnt;

    }
};

int main() {

    Solution res;
    vector<vector<char>> gird = 
{
  {'1','1','1','1','0'},
  {'1','1','0','1','0'},
  {'1','1','0','0','0'},
  {'0','0','0','0','0'}
};

    cout << res.numIslands(gird) << endl;
    
    return 0;
}
