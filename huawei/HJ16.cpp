#include <iostream>
using namespace std;

int main() {
    
    int N, m;
    cin >> N >> m;

    char arr[60][3]; // 3行60列

    for (int i = 0; i < m; i++){
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
        // 价格行，权重行，属性行，同时i+1也是编号
    }

    // 太tm多东西了
    

    return 0;
}