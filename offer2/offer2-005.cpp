#include <vector>
#include <iostream>
// #include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        // ����Զ�������ʽ��Ȼ����ң�
        // sort(words.begin(), words.end(), cmp);
        // int N = words.size();
        // // ����β��ң���̨��������Ҳû��������
        // return 0;
        int N = words.size();
        vector<int> masks(N, 0);
        for (int i = 0; i < N; i++){
            int m = words[i].length();
            for (int j = 0; j < m; j++){
                int mask = (1 << (words[i][j] - 'a'));
                masks[i] |= mask;
            }
        }

        int maxPdct = 0;
        for (int i = 0; i < N; i++){
            for (int j = i+1; j < N; j++){
                if ((masks[i] & masks[j]) == 0) { //����ĸ�غ�
                    maxPdct = max(maxPdct, int(words[i].length()*words[j].length())); //Ҫǿ��ת����
                }
            }
        }
        return maxPdct;
    }

    // static bool cmp(string a, string b){ // ����Ҫ��̬
    //     return a.length() >= b.length() ? true : false;
    // }

    // bool isNoSame(string &a, string &b){
    //     // ��νϿ�Ƚ���û���ظ�Ԫ���أ�
    //     // int m = a.length(), n = b.length();
    //     // for (int i = 0; i < m; i++){
    //     //     for (int j = 0; j < n; j++){
    //     //         if (b[j] == a[i]) return false;
    //     //     }
    //     // }

    //     //λ���㷨
    //     return true;
    // }
};

int main(){
    vector<string> strs = {"a","ab","abc","d","cd","bcd","abcd"};
    Solution res;
    cout << res.maxProduct(strs) << endl;
    return 0;
}

