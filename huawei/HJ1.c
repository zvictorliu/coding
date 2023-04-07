#include <stdio.h>

int gettotal(int n);

int main(){
    int n = 0;
    int out_arr[10] = {0};
    int cnt = -1;
    do
    {
        scanf("%d", &n);
        if (n < 0) return -1;
        if (n == 0) break;
        cnt++;
        out_arr[cnt] = gettotal(n);
    } while (1);

    for (int i = 0; i <= cnt; i++){
        printf("%d\n", out_arr[i]);
    }

    return 0;

}

int gettotal(int n){
    switch (n)
    {
        case 1:
            return 0;
        case 2:
        case 3:
            return 1;
        default:
            break;
    }
    return n / 3 + gettotal(n / 3 + n % 3);
}