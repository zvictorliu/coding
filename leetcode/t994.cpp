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
    int orangesRotting(vector<vector<int>>& grid) {
        // 和岛屿很像，但是同时开始扩散，用队列或许更好
        // 一组腐烂的橘子入队的方式？能出队的次数就是分钟数，这或许又是拓扑排序？ 用size代替集合
        // 如果是dfs就感觉不太好弄了
        // 但是bfs要搜索太多遍了了似乎，这个和华为那道题好像，都是层数问题

        // 两种特殊情况：没有橘子，没有烂橘子但是有新鲜橘子
        int time = -1;
        queue<vector<int>> orangeQ;
        // todo 初始化
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == 2){
                    orangeQ.push({i,j});
                }
            }
        }

        while (!orangeQ.empty())
        {
            time ++;
            int sz = orangeQ.size();
            for (int i = 0; i < sz; i++){
                int x = orangeQ.front()[0];
                int y = orangeQ.front()[1];
                orangeQ.pop();
                grid[x][y] = 0; // 都变成0
                vector<vector<int>> adjOranges = {{x-1,y},{x+1,y},{x,y-1},{x,y+1}};
                for (vector<int> adjO : adjOranges){
                    if (adjO[0] >= 0 && adjO[0] < m && adjO[1] >= 0 && adjO[1] < n){
                        if (grid[adjO[0]][adjO[1]] == 1){
                            orangeQ.push(adjO);
                            grid[adjO[0]][adjO[1]] = 2; // ! 重要
                        }
                    }
                }
            }
        }
        // 检查是否有1即还有橘子的情况
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == 1){
                    return -1;
                }
            }
        }
        if (time == -1) return 0; // 一开始就没有烂橘子的情况，必须放在后面

        return time; // 最开始不算
        

        
    }
};


int main() {

    Solution res;
    vector<vector<int>> grid = {{2,2},{1,1},{0,0},{2,0}};
    cout << res.orangesRotting(grid) << endl;
    
    return 0;
}
