#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int divide(int a, int b) { // ���ַ�
        // ��ѧ�ϵĽ����ȥ��С����
        // ԭ���������˼���������
        // ��������żӼ��㣬������ش����Ӽ�һ��Ҳ����ʱ���ˣ��������������
        // �����ͳһΪһ����������Խ������
        // ҪС�� -2^31-1 �� 2^31������ȡ���ǲ��Ծ���

        // ���������
        if (a == 0) return 0;
        if (a == INT_MIN) {
            if (b == 1) return a;
            if (b == -1) return INT_MAX;
        }
        if (b == INT_MIN) {
            return a == INT_MIN ? 1 : 0;
        }

        // ͳһ��ab��С��0���������ᵼ��-INT_MIN
        bool flag = false;
        if (a > 0) {
            a = -a;
            flag = !flag;
        }
        if (b > 0) {
            b = -b;
            flag = !flag; // ��������
        }


        
    }
};

class Solution2 { //ͨ��λ�����ٶȸ��죬��λ��Ч�ڳ˳�2
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
