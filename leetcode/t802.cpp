#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // 出度为0是终端节点
        // graph[i]中都是终端节点的是安全节点
        // 终端节点一定是安全节点
        // 如果去掉第一层终端节点，新产生的终端节点在原来的图上一定是都连向终端节点的，因此也一定是安全节点
        // 如果去掉第二层终端节点，新产生的终端节点在原来的图上，一定有连向第二层的，那么就不是安全节点
        // 所以应该就只是前两层的终端节点？还是都是？好吧，这也算
        vector<int> res;
        int N = graph.size();
        vector<int> degree(N);
        queue<int> terminals;
        // todo 还需要一个入的graph
        vector<vector<int>> parents(N);
        for (int i = 0; i < N; i++){
            degree[i] = graph[i].size();
            if (degree[i] == 0) terminals.push(i);
            for (auto cd : graph[i]){
                parents[cd].push_back(i);
            }
        }
        

        int cnt = 0;
        while (cnt !=2 && !terminals.empty()){ //只看前两层
            int sz = terminals.size();
            for (int i = 0; i < sz; i++){
                int tml = terminals.front();
                terminals.pop();
                res.push_back(tml);
                degree[tml] --;
                for (auto neibor : parents[tml]){
                    degree[neibor]--;
                    if (degree[neibor] == 0) terminals.push(neibor);
                }
            }
            cnt ++;
        }
        sort(res.begin(), res.end());
        return res;

    }
};

int main() {

    
    
    return 0;
}
