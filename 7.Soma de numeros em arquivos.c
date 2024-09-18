#include <stdio.h>

void func_arquivos(const char *arquivo1, const char *arquivo2, const char *arquivo_saida) {
    FILE *arq1 = fopen(arquivo1, "r");
    FILE *arq2 = fopen(arquivo2, "r");
    FILE *saida = fopen(arquivo_saida, "w");

    if (arq1==NULL || arq2==NULL || saida==NULL) {
        printf("Erro ao abrir os arquivos");
        return;
    }

    int num1, num2;

    while (fscanf(arq1, "%d", &num1)!=EOF && fscanf(arq2, "%d", &num2)!=EOF) {
        fprintf(saida, "%d\n", num1 + num2);
    }

    if (fscanf(arq1, "%d", &num1)!=EOF || fscanf(arq2, "%d", &num2)!=EOF) {
        printf("Os arquivos não têm o mesmo número de linhas.\n");
    }

    fclose(arq1);
    fclose(arq2);
    fclose(saida);
}

int main() {
    func_arquivos("arquivo1.txt", "arquivo2.txt", "resultado.txt");
    printf("A soma dos valores dos dois arquivos foi armazenada em 'resultado.txt'.\n");
    return 0;
}
