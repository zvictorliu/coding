#include <iostream>
#include <vector>
using namespace std;

class Solution{

public:
    void mazePath(vector<vector<int>> &path){
        int n = path.size();
        for (int i = 0; i < n; i++){
            cout << '(' << path[i][0] << ',' << path[i][1] << ')' << endl;
        }
    }
    void dfs(vector<vector<int>> &maze, int x, int y, vector<vector<int>> &path){
        if ((x == maze.size() - 1) && (y == maze[0].size() - 1)) {
            path.push_back({x,y});
            mazePath(path);
            return; //一旦找到就应该全部退出了，但似乎刹不住车了
        }

        if (x < maze.size() && y < maze[0].size() && x >= 0 && y >= 0){
            vector<int> pos = {x,y};
            // if (!path.empty()){
            //     if (x == path.back()[0] && y == path.back()[1]) return;
            // }
            path.push_back(pos);

            if (maze[x][y] == 0)  {
                maze[x][y] = 1; // 避免死循环
                dfs(maze, x+1, y, path);
                dfs(maze, x, y+1, path);
                dfs(maze, x-1, y, path);
                dfs(maze, x, y-1, path);

                
            }
            path.pop_back();
        }
    }

};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> data(n, vector<int> (m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> data[i][j];
        }
    }

    Solution res;
    vector<vector<int>> path;
    res.dfs(data,0,0,path);
    
    return 0;
}
