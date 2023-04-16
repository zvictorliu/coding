#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution{

public:
    bool isEnglishChar(char ch){
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <='Z')) return true;
        return false;
    }
    int hashFunc(char ch){
        if (ch >= 'a' && ch <= 'z') return ch-'a';
        return ch-'A';
    }

    string sortedStr(string &str){
        int N = str.length();
        vector<queue<int>> hashArr(26);
        for (int i = 0; i < N; i++){
            char ch = str[i];
            if (isEnglishChar(ch)){
                int idx = hashFunc(ch);
                hashArr[idx].push(ch);
            }
        }

        int idx = 0;
        for (int j = 0; j < N; j++){
            if (isEnglishChar(str[j])){
                while (hashArr[idx].size() == 0){
                    idx++;
                }
                str[j] = hashArr[idx].front();
                hashArr[idx].pop();
            }
        }

        return str;
    }

};

int main() {
    string str;
    getline(cin, str);

    Solution res;
    cout << res.sortedStr(str) << endl;
    
    return 0;
}
