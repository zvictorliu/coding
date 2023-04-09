#include <iostream>
using namespace std;

int main()
{
    char arr[1000];
    int hcnt[35] = {0};
    char ch;
    cin.getline(arr, 1001);
    cin >> ch;

    for (int i = 0; arr[i] != '\0'; i++){
        int idx;
        if ( arr[i] >= '0' && arr[i] <='9') idx = arr[i] - '0';
        else if (arr[i] >= 'A' && arr[i] <= 'Z') idx = arr[i] - 'A' + 10;
        else if (arr[i] >= 'a' && arr[i] <= 'z') idx = arr[i] - 'a' + 10;
        else continue;
        hcnt[idx] ++;

    }

    int idx = -1;
    if ( ch >= '0' && ch <='9') idx = ch - '0';
    else if (ch >= 'A' && ch <= 'Z') idx = ch - 'A' + 10;
    else if (ch >= 'a' && ch <= 'z') idx = ch - 'a' + 10;

    if (idx != -1) cout << hcnt[idx] << endl;
    
    return 0;
}