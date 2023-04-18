#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int divide(int a, int b) { // 二分法
        // 数学上的结果，去掉小数点
        // 原来简单题的意思是你想简单了
        // 不能真的嗯加减算，如果是特大数加减一次也不少时间了，特殊情况当利用
        // 最好是统一为一种情况，最后对结果处理
        // 要小心 -2^31-1 和 2^31，下限取反是不对劲的

        // 特殊情况：
        if (a == 0) return 0;
        if (a == INT_MIN) {
            if (b == 1) return a;
            if (b == -1) return INT_MAX;
        }
        if (b == INT_MIN) {
            return a == INT_MIN ? 1 : 0;
        }

        // 统一成ab均小于0，这样不会导致-INT_MIN
        bool flag = false;
        if (a > 0) {
            a = -a;
            flag = !flag;
        }
        if (b > 0) {
            b = -b;
            flag = !flag; // 负负得正
        }


        
    }
};

class Solution2 { //通过位运算速度更快，移位等效于乘除2
public:
    int divide(int a, int b) {
        
        
        
    }
};

int main() {

    Solution res;
    int a,b;
    cin >> a >> b;
    cout << res.divide(a, b) << endl;
    // cout << res.solutionFunc() << endl;
    
    return 0;
}
