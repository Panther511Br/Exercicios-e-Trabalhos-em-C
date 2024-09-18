#include <stdio.h>
#include <string.h>
#include <ctype.h>

//funcao que converte string para minuscula
void convert_menor(char *str){
    for(int t =0; str[t]; t++){
        str[t] = tolower(str[t]);
    }
}

//funcao que conta as repeticoes da palavra
int contagem(char *texto, char *palavra){
    int contagem = 0;
    char *pont = texto;
    int len_palavra = strlen(palavra);

    while ((pont = strstr(pont, palavra)) !=NULL){
        contagem++;
        pont = pont + len_palavra;
    }
    return contagem;
}

int main(){
    char texto[100];
    char palavra[50];

    printf("Digite uma frase: ");
    fgets(texto, 100, stdin);

    printf("Digite uma palavra do texto: ");
    scanf("%s", palavra);

    convert_menor(texto);
    convert_menor(palavra);
    int quantidade = contagem(texto, palavra);

    printf("A palavra %s aparece %d vezes.\n", palavra, quantidade);
    return 0;
}
