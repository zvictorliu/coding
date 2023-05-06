#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <limits>
using namespace std;

class Solution1 { // Prim �㷨
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // �����ڽӾ���Ȼ������С������
        int N = points.size();
        vector<vector<int>> Manhattan(N, vector<int> (N));
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                Manhattan[i][j] = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
            }
        }
        // Prim �㷨
        vector<int> lowcost(N);
        // vector<int> adjvex(N, 0);
        int result = 0;
        // ��v0��ʼ
        lowcost = Manhattan[0];
        // ����ʣ��ڵ�
        while (1){
            int idx, minVal = INT_MAX;
            for (int i = 1; i < N; i++){
                // ����С��
                if (lowcost[i] > 0 && lowcost[i] < minVal) {
                    minVal = lowcost[i];
                    idx = i;
                }
            }
            if (minVal == INT_MAX) return result;
            // �޸�lowcost ������̾���
            lowcost[idx] = 0;
            result += minVal;
            for (int i = 0; i < N; i++){
                if (lowcost[i] > 0 && Manhattan[idx][i] < lowcost[i]) lowcost[i] = Manhattan[idx][i];
            }
        }
        return result;
    }
};

class Solution { // Kruskal �㷨
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        //todo ����߼�
        // ��̫�ù��죬����
    }
};

int main() {

    // Solution res;
    
    return 0;
}
