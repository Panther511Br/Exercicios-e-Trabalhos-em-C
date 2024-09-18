#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Funcao que converte string para minuscula
void convert_menor(char *str) {
    for (int t = 0; str[t]; t++) {
        str[t] = tolower(str[t]);
    }
}

// Funcao que conta as repeticoes da palavra
int contagem(char *texto, char *palavra) {
    int contagem = 0;
    char *pont = texto;
    int len_palavra = strlen(palavra);

    while ((pont = strstr(pont, palavra)) != NULL) {
        contagem++;
        pont = pont + len_palavra;
    }
    return contagem;
}

int main() {
    char texto[1000];
    char palavra[50];
    char nome_arquivo[100];
    char linha[1000];

    printf("Digite o nome do arquivo: ");
    scanf("%s", nome_arquivo);

    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Inicializa a string texto
    texto[0] = '\0';

    // Le o conteudo do arquivo linha por linha
    while(fgets(linha, sizeof(linha), arquivo) != NULL){
        strcat(texto, linha);
    }
    fclose(arquivo);

    printf("Digite uma palavra do texto: ");
    scanf("%s", palavra);

    convert_menor(texto);
    convert_menor(palavra);
    int quantidade = contagem(texto, palavra);

    printf("A palavra %s aparece %d vezes.\n", palavra, quantidade);
    return 0;
}
