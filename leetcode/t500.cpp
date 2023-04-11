#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        int N = words.size();
        vector<int> q(N, 0);
        vector<string> keyboard = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
        int cnt[3] = {0, 0, 0};

        // 初步分类
        for (int i = 0; i < N; i++){
            char cap = words[i][0];
            if (cap >= 'A' && cap <= 'Z') cap -= ('A' - 'a');
            for (int j = 0; j < 3; j++){
                if (keyboard[j].find(cap) != string::npos) 
                {
                    q[i] = j;
                    cnt[j] ++;
                }
            }
        }

        // 逐个排除
        for (int i = 0; i < N; i++){
            int len = words[i].size();
            for (int j = 1; j < len; j++){
                char ch = words[i][j];
                if (ch >= 'A' && ch <= 'Z') ch -= ('A' - 'a');
                if ( keyboard[q[i]].find(ch) == string::npos ) {
                    cnt[q[i]] --;
                    q[i] = -1;
                    break;
                }
                
                
            }
        }

        int total = cnt[0] + cnt[1] + cnt[2];

        vector<string> res(total);
        if (total == 0) return res;

        int k = 0;
        for (int i = 0; i < N; i++){
            if (q[i] != -1) {
                res[k++] = words[i];
            }
        }

        return res;

    }
};


int main() {

    vector<string> words = {"Aasdfghjkl", "Qwertyuiop", "zZxcvbnm"};
    Solution res;
    vector<string> result = res.findWords(words);
    
    for (auto &str : result){
        cout << str << " ";
    }
    cout << endl;

    return 0;
}
