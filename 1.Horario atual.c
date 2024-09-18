#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    time_t tempo;
    time(&tempo);
    struct tm *tempo0 = localtime(&tempo);


    printf("Horario atual: %02d:%02d:%02d", tempo0->tm_hour, tempo0->tm_min, tempo0->tm_sec);

    return 0;
}
