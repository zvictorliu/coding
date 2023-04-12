#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (int i = 0; i < s.length(); i++){
            switch (s[i])
            {
                case '(':
                    stk.push(s[i]);
                    break;
                case ')':
                    if (stk.empty()) return false;
                    if (stk.top() == '(') stk.pop();
                    else return false;
                    break;
                case '[':
                    stk.push(s[i]);
                    break;
                case ']':
                    if (stk.empty()) return false;
                    if (stk.top() == '[') stk.pop();
                    else return false;
                    break;
                case '{':
                    stk.push(s[i]);
                    break;
                case '}':
                    if (stk.empty()) return false;
                    if (stk.top() == '{') stk.pop();
                    else return false;
                    break;
                default:
                    break;
            }   
        }
        if (stk.empty()) return true;
        return false;

    }
};

int main(){

    string s;
    Solution res;

    cin >> s;
    cout << res.isValid(s) << endl;


    return 0;
}