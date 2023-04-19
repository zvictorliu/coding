#include <iostream>
#include <stack>
using namespace std;

class Solution { // 可以优化为从尾部遍历，这样就不需要栈了，对结果可以使用reverse函数
public:
    string addBinary(string a, string b) {
        stack<int> aStk,bStk,resStk;
        int m = a.length();
        int n = b.length();
        for (int i = 0; i < max(m, n); i++){
            if (i < m) aStk.push(a[i] - '0');
            if (i < n) bStk.push(b[i] - '0');
        }

        int cplmnt = 0;
        while (!aStk.empty() || !bStk.empty()){
            int num1 = 0, num2 = 0, res = 0;
            if (!aStk.empty()) {
                num1 = aStk.top();
                aStk.pop();
            }

            if (!bStk.empty()) {
                num2 = bStk.top();
                bStk.pop();
            }

            res = (num1 + num2 + cplmnt);
            cplmnt = res / 2;
            res %= 2;

            resStk.push(res);
        }

        string result;
        if (cplmnt) result.push_back('1');
        while (!resStk.empty()) {
            result.push_back(resStk.top() + '0');
            resStk.pop();
        }
        return result;
    }
};

int main(){

    string a,b;
    cin >> a >> b;
    Solution res;
    cout << res.addBinary(a, b) << endl;
}