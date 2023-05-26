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
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // ���ǱȽ��ʺϵ���DFS��ͬʱ��Ҫ��¼�Ƿ���ʹ���
        // ������Ŀ������ֵ���޶���Χ�����ԾͲ���Ҫ������������
        // �о�����ѭ������������Ӧ�ò��Ǻ���ⷨ

        // ����ͨ���޸ı߽�������
        vector<int> res;
        if (matrix.size() == 0) return res; // �������
        int uLim = 0;
        int lLim = 0;
        int rLim = matrix[0].size()-1;
        int dLim = matrix.size()-1;
        while (1) { 
            // ������������
            for (int i = lLim; i <= rLim; i++) res.push_back(matrix[uLim][i]);
            // �����Ͻ磬�ж��Ƿ񽻴�
            if ((++uLim) > dLim) break;
            // ��������
            for (int i = uLim; i <= dLim; i++) res.push_back(matrix[i][rLim]);
            if ((--rLim) < lLim) break;
            // ��������
            for (int i = rLim; i >= lLim; i--) res.push_back(matrix[dLim][i]);
            if ((--dLim) < uLim) break;
            // ��������
            for (int i = dLim; i >= uLim; i--) res.push_back(matrix[i][lLim]);
            if ((++lLim) > rLim) break;
        }

        return res;
    }

};

int main() {

    // Solution res;
    
    return 0;
}
