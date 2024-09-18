#include <stdio.h>
#include <time.h>
int main()
{
    int conversao;
    time_t tempo;
    struct tm *tempo0;

    time(&tempo);
    tempo0 = localtime(&tempo);

    printf("Hora atual: %02d:%02d:%02d\n", tempo0->tm_hour, tempo0->tm_min, tempo0->tm_sec);

    tempo0->tm_hour*= 120;
    tempo0->tm_min*= 60;
    conversao = tempo0->tm_hour + tempo0->tm_min + tempo0->tm_sec;

    printf("Hora convertida em segundos: %02d segundos", conversao);
    return 0;
}
