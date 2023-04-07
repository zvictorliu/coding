#include <stdio.h>

int main(){
    char in_str[10] = {'\0'};
    char *p;
    int str_num[10] = {0};
    int result[10] = {0};
    int cnt = -1;
    int cnt_len = 0;

    while (scanf("%s", in_str) != EOF)
    {
        p = in_str;
        p += 2;
        cnt_len = 0;
        
        cnt++;
        while (*p != '\0')
        {   
            int temp = 0;
            if (*p < 'A' && *p >= '0') temp = (*p) - '0';
            else temp = (*p) - 'A' + 10;
            str_num[cnt_len++] = temp;
            p++;
        }
        
        for (int i = 0; i < cnt_len; i++){
            int b = str_num[i] << ( (cnt_len - i - 1) * 4 );
            result[cnt] += b;
        }

        

    }

    for (int j=0; j <= cnt; j++){
        printf("%d\n", result[j]);
    }
    
    return 0;
}