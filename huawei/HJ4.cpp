#include <iostream>
#include <cstring>
using namespace std;

int main() {
    
    char out_arr[9];

    char in_arr[108];
    char *p = in_arr;
    cin.getline(in_arr, 101);

    int N = strlen(in_arr);
    p += N;

    int cnt = N / 8;
    if (N % 8) cnt ++;

    for (int i = 0 ; i < 8 * cnt - N; i++){
        *p++ = '0';
    }  
    *p = '\0';
    p = in_arr;

    

    for (int j = 0 ; j < cnt ; j++){
        p = in_arr + j*8;
        strncpy(out_arr, p, 8);
        printf("%s\n", out_arr);
    }


    return 0;
}