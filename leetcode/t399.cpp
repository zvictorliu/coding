#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int nvars = 0;
        unordered_map<string, int> variables;

        int n = equations.size();
        for (int i = 0; i < n; i++) {
            if (variables.find(equations[i][0]) == variables.end()) {
                variables[equations[i][0]] = nvars++;
            }
            if (variables.find(equations[i][1]) == variables.end()) {
                variables[equations[i][1]] = nvars++;
            }
        } // 通过这个，可以给每个变量一个数字编号

        vector<vector<double>> graph(nvars, vector<double>(nvars, -1.0));
        for (int i = 0; i < n; i++) {
            int va = variables[equations[i][0]], vb = variables[equations[i][1]];
            graph[va][vb] = values[i];
            graph[vb][va] = 1.0 / values[i];
        } // 变成编号之后，这个就是传统的距离表了

        // 继续完善距离表，a-b,b-c :: a-c
        for (int k = 0; k < nvars; k++) {
            for (int i = 0; i < nvars; i++) {
                for (int j = 0; j < nvars; j++) {
                    if (graph[i][k] > 0 && graph[k][j] > 0) {
                        graph[i][j] = graph[i][k] * graph[k][j];
                    }
                }
            }
        }

        vector<double> ret;
        for (const auto& q: queries) {
            double result = -1.0;
            if (variables.find(q[0]) != variables.end() && variables.find(q[1]) != variables.end()) {
                int ia = variables[q[0]], ib = variables[q[1]];
                if (graph[ia][ib] > 0) {
                    result = graph[ia][ib];
                }
            }
            ret.push_back(result);
        }
        return ret;
    }
};

int main() {

    Solution res;
    
    return 0;
}
