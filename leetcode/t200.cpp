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
    int numIslands(vector<vector<char>>& grid) { // DFS����
        // dfs����Ϊ1�Ľڵ㣬���ʵ��ĵ��춼�޸�Ϊ0��֮����ٴ���������˱��ͳ������
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
        // �߽����
        if (x >= grid.size() || y >= grid[0].size()) return;
        if (x < 0 || y < 0) return;
        if (grid[x][y] == '0') return;
        // ��û
        grid[x][y] = '0';
        // Ӧ��ֻ��Ҫ��������������
        dfs(x+1, y, grid);
        dfs(x-1, y, grid);
        dfs(x, y+1, grid);
        dfs(x, y-1, grid);
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) { // bfs ����
        // ��dfsһ����ֻ������������������bfsint islandCnt = 0;
        int islandCnt = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == '1'){
                    islandCnt ++;
                    // bfs �ڵ�������Ϊһ������
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
