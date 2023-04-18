#include <iostream>
#include <stack>
#include <queue> // 没想到01也是不认的，只能用队列了
#include <cmath>
using namespace std;

class Solution{

public:
    string checkIP(string &str){
        queue<int> digits;
        int N = str.length();
        int cnt = 0;
        for (int i = 0; i <= N; i++){
            if (i == N || str[i] == '.'){
                int sum = 0;
                int p = digits.size();
                int len = p;
                if (digits.empty()) return "NO";
                while (!digits.empty()){
                    int dgt = digits.front();
                    if (p == len ) {
                        if (p != 1 && dgt == 0)
                        return "NO";
                    }
                    sum += (dgt * pow(10, --p));
                    digits.pop();
                }
                if (sum > 255) return "NO";
                cnt ++;
            }
            else {
                if (str[i] >= '0' && str[i] <= '9'){
                    digits.push(str[i] - '0');
                }
                else {
                    return "NO";
                }
            }
        }
        if (cnt != 4) return "NO";
        return "YES";
    }

};

int main() {

    Solution res;
    string ipadd;
    cin >> ipadd;
    cout << res.checkIP(ipadd) << endl;
    
    return 0;
}
