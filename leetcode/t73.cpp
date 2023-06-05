#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <limits>
#include <set>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // �ȱ������ҳ�����Ϊ0�ĵ㣬Ȼ�����dfs
        // ÿ������dfsֻ�ܳ�һ����������0�ͱ߽�ֹͣ
        // ���ǲ��У��ᱻ����һ�����������0��ϣ�������������Ϳ��ܻᳬʱ
        // ����������û��ͬ��orͬ�й�ϵ����ô��ʵ���Բ���
        // ����Ӧ�����к��еĳ˻�
        stack<vector<int>> zeroPos;
        set<int> row;
        set<int> col;
        for (int i = 0; i < matrix.size(); i++){
            for (int j = 0; j < matrix[0].size(); j++){
                if (matrix[i][j]==0) {
                    row.emplace(i);
                    col.emplace(j);
                }
            }
        }

        for (int x : row){
            for (int y : col){
                // ! ע��������Ϻ����λ�þͲ�һ����0��
                matrix[x][y] = 0;
                dfs(matrix, x-1, y, 0);
                dfs(matrix, x+1, y, 1);
                dfs(matrix, x, y-1, 2);
                dfs(matrix, x, y+1, 3);
            }
        }
    }

    void dfs(vector<vector<int>>& matrix, int x, int y, int direction){
        if (x < 0 || x > matrix.size()-1 || y < 0 || y > matrix[0].size()-1) return;
        if (matrix[x][y] == 0) return;
        matrix[x][y] = 0;
        switch (direction)
        {
        case 0:
            dfs(matrix, x-1, y, direction);
            break;
        case 1:
            dfs(matrix, x+1, y, direction);
            break;
        case 2:
            dfs(matrix, x, y-1, direction);
            break;
        case 3:
            dfs(matrix, x, y+1, direction);
            break;
        default:
            break;
        }
    }
};
// ��ʵ��ȫ����ȷ���к��к�ֱ��������������������dfs
// ���Ե����ȴ������
// �������õ�һ�к͵�һ������¼�������ǵ�һ�к͵�һ�еģ����б�Ǵ���Ȼ���ٿ��Ƿ��һ�е�һ���й�0
// ������ȥ�ͻ����

int main() {

    vector<vector<int>> matrix = {{3,5,5,6,9,1,4,5,0,5},{2,7,9,5,9,5,4,9,6,8},{6,0,7,8,1,0,1,6,8,1},{7,2,6,5,8,5,6,5,0,6},{2,3,3,1,0,4,6,5,3,5},{5,9,7,3,8,8,5,1,4,3},{2,4,7,9,9,8,4,7,3,7},{3,5,2,8,8,2,2,4,9,8}};
    Solution res;
    res.setZeroes(matrix);
    
    return 0;
}
