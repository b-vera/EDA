#include <stdio.h>
#include <string.h>

int main(){
    char *str1;
    char *str2;
    str1 = "zafari";
    str2 = "alemania";
    int str3 = strcmp(str1,str2);

    printf("%d\n",str3);
    return 0;
}
