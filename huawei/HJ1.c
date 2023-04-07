#include <stdio.h>
#include <string.h>

int main(){
    char arr[5000] = {'\0'};
    while (fgets(arr, 5000, stdin))
    {
        char *token, *p;
        token = strtok(arr, " \n");
        while ((token = strtok(NULL, " \n")))
        {
            p = token;
        }
        printf("%d\n", strlen(p));
    }
    


    return 0;
}