#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <limits>
using namespace std;

class Solution1 { // Prim 算法
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // 构建邻接矩阵，然后求最小生成树
        int N = points.size();
        vector<vector<int>> Manhattan(N, vector<int> (N));
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                Manhattan[i][j] = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
            }
        }
        // Prim 算法
        vector<int> lowcost(N);
        // vector<int> adjvex(N, 0);
        int result = 0;
        // 从v0开始
        lowcost = Manhattan[0];
        // 遍历剩余节点
        while (1){
            int idx, minVal = INT_MAX;
            for (int i = 1; i < N; i++){
                // 找最小的
                if (lowcost[i] > 0 && lowcost[i] < minVal) {
                    minVal = lowcost[i];
                    idx = i;
                }
            }
            if (minVal == INT_MAX) return result;
            // 修改lowcost 更新最短距离
            lowcost[idx] = 0;
            result += minVal;
            for (int i = 0; i < N; i++){
                if (lowcost[i] > 0 && Manhattan[idx][i] < lowcost[i]) lowcost[i] = Manhattan[idx][i];
            }
        }
        return result;
    }
};

class Solution { // Kruskal 算法
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        //todo 构造边集
        // 不太好构造，算了
    }
};

int main() {

    // Solution res;
    
    return 0;
}
