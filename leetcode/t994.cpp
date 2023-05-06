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
        // �͵�����񣬵���ͬʱ��ʼ��ɢ���ö��л������
        // һ�鸯�õ�������ӵķ�ʽ���ܳ��ӵĴ������Ƿ������������������������ ��size���漯��
        // �����dfs�͸о���̫��Ū��
        // ����bfsҪ����̫��������ƺ�������ͻ�Ϊ�ǵ�����񣬶��ǲ�������

        // �������������û�����ӣ�û�������ӵ�������������
        int time = -1;
        queue<vector<int>> orangeQ;
        // todo ��ʼ��
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
                grid[x][y] = 0; // �����0
                vector<vector<int>> adjOranges = {{x-1,y},{x+1,y},{x,y-1},{x,y+1}};
                for (vector<int> adjO : adjOranges){
                    if (adjO[0] >= 0 && adjO[0] < m && adjO[1] >= 0 && adjO[1] < n){
                        if (grid[adjO[0]][adjO[1]] == 1){
                            orangeQ.push(adjO);
                            grid[adjO[0]][adjO[1]] = 2; // ! ��Ҫ
                        }
                    }
                }
            }
        }
        // ����Ƿ���1���������ӵ����
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == 1){
                    return -1;
                }
            }
        }
        if (time == -1) return 0; // һ��ʼ��û�������ӵ������������ں���

        return time; // �ʼ����
        

        
    }
};


int main() {

    Solution res;
    vector<vector<int>> grid = {{2,2},{1,1},{0,0},{2,0}};
    cout << res.orangesRotting(grid) << endl;
    
    return 0;
}
