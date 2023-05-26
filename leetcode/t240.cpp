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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // ���ֲ���һ���������еģ�ȡ�½磬ע���������
        // ��������ʲô�����أ����ֲ�һ�����ǵ�һ�в��ҵ����������棬������һ��ֻ��һ��
        // ���ǿ���ȷ������һ�࣬һֱ����������ȥ
        // �ĸ��ǵ�����
        // ����̫�鷳��
        // �����������ÿ�ж��ֶ��ǿ��Թ���
        int r1 = 0,r2 = matrix.size()-1,c1 = 0,c2 = matrix[0].size()-1;

        while (r1 < r2-1 || c1 < c2-1){ // �������ֹ����
            //! ����͵������ĵ��Ƕ��ֲ���
            // ������
            if (matrix[(r1+r2)/2][c1] < target) r1 = (r1+r2)/2;
            else if (matrix[(r1+r2)/2][c1] > target) r2 = (r1+r2)/2;
            else return true;
            // ������
            if (matrix[r1][(c1+c2)/2] < target) c1 = (c1+c2) / 2;
            else if (matrix[r1][(c1+c2)/2] > target) c2 = (c1+c2) / 2;
            else return true;

            // ������
            if (matrix[(r1+r2)/2][c2] < target) r1 = (r1+r2)/2;
            else if (matrix[(r1+r2)/2][c2] > target) r2 = (r1+r2)/2;
            else return true;
            // ������
            if (matrix[r2][(c1+c2)/2] < target) c1 = (c1+c2) / 2;
            else if (matrix[r2][(c1+c2)/2] > target) c2 = (c1+c2) / 2;
            else return true;
        }

        if (matrix[r1][c1] == target || matrix[r1][c2] == target || matrix[r2][c1] == target || matrix[r2][c2] == target) return true;
        return false;
    }
};

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Z�ֲ��ң����ú��к��е��ϸ��������
        int x = 0, y = matrix[0].size()-1;
        while (x < matrix.size() && y >= 0){
            if (matrix[x][y] == target) return true;

            if (matrix[x][y] > target) { // �±ߣ��ұ߶�������
                y--; // ȥ���Ҳ�
            } 
            else { // �ϣ��󶼲�����
                x++; // ȥ���ϲ�
            }
        }

        return false;
    }
};

int main() {

    vector<vector<int>> matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    int target = 5;
    Solution res;
    cout << res.searchMatrix(matrix, target) << endl;
    
    return 0;
}
