#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        // ÿ�β�һ����ѡ���ģ���һ����Χ���ǿ���Ԥ���Է���û�п���Ӯ��
        // ���ż�������п��ܻ��䣬���¸�������Ȼ����������������ķ�֧
        // ���Ӯ�Ľ��һ���� ���պ����㣬��ǰ�涼������
        // 
        // vector<int> dp(maxChoosableInteger+1);
        // dp[0] = 0;
        // for (int i = 1; i <= maxChoosableInteger; i++){
        //     for (int j = 1; j <= maxChoosableInteger; j++){
        //         if (i < j) dp[j] = dp[j-1] + i;
        //         else {
        //             dp[j] = (j*(j+1))/2;
        //         } 
        //     }
        //     if (dp[maxChoosableInteger] >= desiredTotal) {
        //         if (i % 2 == 0) return false;
        //         else return true;
        //     }
        // }
        // return false;
    }
};

int main() {

    Solution res;
    
    
    return 0;
}
