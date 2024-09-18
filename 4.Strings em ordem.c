#include <stdio.h>
#include <string.h>
int main(){
    char fruta1[30] = "Laranja";
    char fruta2[30] = "Melancia";
    char fruta3[30] = "Banana";
    char espaco[100];

    if(strcmp(fruta1, fruta2) > 0){
        strcpy(espaco, fruta1);
        strcpy(fruta1, fruta2);
        strcpy(fruta2, espaco);

    }
    if(strcmp(fruta1, fruta3) > 0){
        strcpy(espaco, fruta1);
        strcpy(fruta1, fruta3);
        strcpy(fruta3, espaco);
    }
    if(strcmp(fruta2, fruta3) > 0){
        strcpy(espaco, fruta2);
        strcpy(fruta2, fruta3);
        strcpy(fruta3, espaco);
    }

    printf("Ordem lexografica(alfabetica) das strings:\n");
    printf("%s\n", fruta1);
    printf("%s\n", fruta2);
    printf("%s\n", fruta3);

    return 0;
}
