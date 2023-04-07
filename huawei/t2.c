#include <stdio.h>
#include <stdlib.h>
int main(){
    int N = 0;
    int num = 0;
    int p[501] = {0};
    scanf("%d", &N);
    // int *num_arr = (int *) malloc(500);
    
    while (N--)
    {
        scanf("%d", &num);
        if (num < 1) return -1;
        if (p[num] == 0) p[num] = num;
    }

    for (int i=0; i <= 500; i++){
        if (p[i] == 0) continue;
        printf("%d\n", i);
    }
    
    return 0;
}