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
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
         // 计算到所有节点的最短路，其中最长的，如果不是无穷（没有），那就是总的最短时间
         // 如果还是无穷，那就是不能传到所有节点
         // floyd算法
        vector<vector<int>> dist(n+1, vector<int> (n+1, INT_MAX));
        // todo 初始化
        for (auto time : times){
            dist[time[0]][time[1]] = time[2];
        }
        for (int i = 0; i < n+1; i++){ // 到自身是0
            dist[i][i] = 0;
        }
        // todo 计算最短路径
        for (int r = 1; r < n+1; r++){
            for (int i = 1; i < n+1; i++){
                for (int j = 1; j < n+1; j++){
                    if (dist[i][r] != INT_MAX && dist[r][j] != INT_MAX){// 会溢出，需要先判断
                        dist[i][j] = min(dist[i][j], dist[i][r]+dist[r][j]); 
                    }  
                }
            }
        }
        vector<int> res = dist[k];
        res[0] = -1;
        sort(res.begin(), res.end());
        if (res[n] < INT_MAX) return res[n];

        return -1;
    }
};

int main() {

    Solution res;
    vector<vector<int>> times = {{2,1,1}, {2,3,1}, {3,4,1}};
    int n = 4;
    int k = 2;
    cout << res.networkDelayTime(times, n, k) << endl;
    
    return 0;
}
