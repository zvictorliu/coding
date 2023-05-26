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
    void rotate(vector<vector<int>>& matrix) {
        // ���������·һ���Ƿ�ת����Ȼ����Ҳ����
        // Ҫ�뵽�Խ��߷�ת+���·�ת����90��
        int N = matrix.size(); 
        if (N == 1) return;
        // vectorӦ�ò���ֱ�Ӹ�ֵ
        // todo �Խ��߷�ת
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N - i-1; j++){
                swap(matrix[i][j], matrix[N-j-1][N-i-1]);
            }
        }

        // todo ���·�ת
        for (int i = 0; i < N / 2; i++) {
            for (int j = 0; j < N; j++){
                swap(matrix[i][j], matrix[N-i-1][j]);
            }
        }

    }
};

int main() {

    // Solution res;
    
    return 0;
}
