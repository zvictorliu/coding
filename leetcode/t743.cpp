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
         // ���㵽���нڵ�����·��������ģ�����������û�У����Ǿ����ܵ����ʱ��
         // �����������Ǿ��ǲ��ܴ������нڵ�
         // floyd�㷨
        vector<vector<int>> dist(n+1, vector<int> (n+1, INT_MAX));
        // todo ��ʼ��
        for (auto time : times){
            dist[time[0]][time[1]] = time[2];
        }
        for (int i = 0; i < n+1; i++){ // ��������0
            dist[i][i] = 0;
        }
        // todo �������·��
        for (int r = 1; r < n+1; r++){
            for (int i = 1; i < n+1; i++){
                for (int j = 1; j < n+1; j++){
                    if (dist[i][r] != INT_MAX && dist[r][j] != INT_MAX){// ���������Ҫ���ж�
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
