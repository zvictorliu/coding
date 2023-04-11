#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    bool isRobotBounded(string instructions) {
        int p = 0, q = 0;
        int direction = 0;

        for (int i = 0; i < instructions.length(); i++){
            if (instructions[i] == 'G'){
                updatePos(p, q, direction);
            }
            else if (instructions[i] == 'L'){
                direction --;
            }
            else if (instructions[i] == 'R'){
                direction ++;
                direction %= 4;
            }

            if (direction < 0) direction +=4;
        }

        // 还没有考虑需要循环的
        if (direction == 0 && (p || q)) return false;
        return true;

    }

    void updatePos(int &x, int &y, int direction){
        switch (direction)
        {
        case 0: //north
            y ++;
            break;
        case 1:
            x ++;
            break;
        case 2:
            y --;
            break;
        case 3:
            x --;
        default:
            break;
        }
    }
};

int main(){

    Solution res;
    string instr;
    cin >> instr;

    cout << res.isRobotBounded(instr) << endl;

    return 0;
}