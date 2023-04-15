#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class Solution{
public:
    int max_str(string str){
        int N = str.length();
        vector<int> dp(N, 1);
        //i号字符，找到左侧相同处，若构成回文则可以
        // 左边没有，则为1
        // 左边有，则最大值为：i-1时结果，构成回文长度i-j+1 最大值
        for (int i = 1; i < N; i++){
            int max_len = dp[i-1];
            for (int j = 0; j < i; j++)
            {
                if (str[i] == str[j]){
                    // 判断是否是回文(这并不是最好的办法，实际上应该用dp来确定是不是回文)
                    bool flag = true;
                    for (int k = j; k < i+j-k; k++){
                        if (str[k] != str[i+j-k]) {
                            flag = false;
                            break;
                        }
                    }

                    if (flag) {
                        max_len = max(max_len, i-j+1);
                        break;
                    }

                }
            }
            dp[i] = max_len;
        }

        return dp[N-1];

    }

};

int main() {

    string str;
    cin >> str;
    Solution res;
    cout << res.max_str(str) << endl;
    
    return 0;
}
