#include <iostream>
#include <vector>
using namespace std;

class Solution{

public:
    void mazePath(vector<vector<int>> &maze){
        vector<vector<int>> path;
        int x = 0, y = 0;
        dfs(maze,x,y,path);

        int n = path.size();
        for (int i = 0; i < n; i++){
            cout << '(' << path[i][0] << ',' << path[i][1] << ')' << endl;
        }
    }
    void dfs(vector<vector<int>> &maze, int x, int y, vector<vector<int>> &path){
        if ((x == maze.size() - 1) && (y == maze[0].size() - 1)){
            vector<int> pos = {x,y};
            path.push_back(pos);
            return;
        }

        if (x < maze.size() && y < maze[0].size()){
            vector<int> pos = {x,y};
            path.push_back(pos);
            if (maze[x][y] == 0)  {
                dfs(maze, x+1, y, path);
                dfs(maze, x, y+1, path);
                // 能走到这里说明堵死了
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
    res.mazePath(data);
    
    return 0;
}
