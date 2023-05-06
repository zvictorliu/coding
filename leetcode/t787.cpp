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
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // 多了个限制k个中转站，那么用diji...就更合适了
        vector<vector<int>> dist(n, vector<int> (n, 10001)); // 避免溢出就不用INT_MAX了
        // todo 初始化
        for (auto flight : flights){
            dist[flight[0]][flight[1]] = flight[2];
        }
        for (int i = 0; i < n; i++){ // 到自身是0
            dist[i][i] = 0;
        }

        vector<int> lowcost = dist[src];
        vector<int> path_cnt (n, 0);
        vector<int> visited (n, 0);

        visited[src] = 1;
        for (int m = 0; m < n; m++)
        {
            int minPrice = 10001;
            int idx = 0;
            for (int i = 0; i < n; i++){
                if (visited[i] == 0 && lowcost[i] < minPrice){
                    minPrice = lowcost[i];
                    idx = i;
                }
            }
            visited[idx] = 1;
            if (minPrice == 10001) break;
            else {
                for (int i = 0; i < n; i++){
                    if (visited[i] == 0 && lowcost[i] > lowcost[idx]+dist[idx][i]){
                        if (path_cnt[i] + path_cnt[idx] + 1 < k) { // 这里没办法了，问题在于要回退到前面走不是最短的路径
                            lowcost[i] = lowcost[idx]+dist[idx][i];
                            path_cnt[i] += (path_cnt[idx]+1);
                        }                        
                    }
                }
            }
        }

        if (lowcost[dst] != 10001) return lowcost[dst];
        return -1;
        
    }
};

class Solution { // 要用新的算法bellman ford，专门针对限制数量的算法
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> prices(n, INT_MAX);
        prices[src] = 0;
        for (int i = 0; i < k+1; i++){
            vector<int> tmp = prices; // 不能受其它边的影响
            for (auto flight : flights){
                if (tmp[flight[0]] != INT_MAX){
                    prices[flight[1]] = min(prices[flight[1]], tmp[flight[0]]+flight[2]);
                }
                 
            }
        }
        if (prices[dst] != INT_MAX) return prices[dst];
        return -1;
    }
};

int main() {

    Solution res;
    vector<vector<int>> edges = {{0,1,20},{1,2,20},{2,3,30},{3,4,30},{4,5,30},{5,6,30},{6,7,30},{7,8,30},{8,9,30},{0,2,9999},{2,4,9998},{4,7,9997}};
    int src = 0, dst = 9, n = 10;
    int k = 4;
    cout << res.findCheapestPrice(n, edges, src, dst, k) << endl;
    
    return 0;
}
