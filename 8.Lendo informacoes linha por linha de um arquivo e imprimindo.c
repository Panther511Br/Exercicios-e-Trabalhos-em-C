#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[100];
    int matricula;
    double nota;
} Aluno;

int main(){
    FILE *arquivo;
    Aluno alunos[10];
    char linha[150];
    int i = 0;

    //Abre o arquivo para leitura
    arquivo = fopen("texto.txt", "r");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    //Le cada linha do arquivo e armazena as informacoes na struct
    while(fgets(linha, sizeof(linha), arquivo)!=NULL && i<=10){
        char *token;
        //Lendo o numero
        token = strtok(linha, ";");
        strcpy(alunos[i].nome, token);

        //Lendo a matricula
        token = strtok(NULL, ";");
        alunos[i].matricula = atoi(token);

        //Lendo a nota
        token = strtok(NULL, ";");
        alunos[i].nota = atof(token);
        i++;
    }

    //Fecha o arquivo
    fclose(arquivo);

    //Imprimindo as informacoes
    for(i=0; i<=10; i++){
        printf("Nome: %s\n", alunos[i].nome);
        printf("Matricula: %d\n", alunos[i].matricula);
        printf("Nota: %.2f\n", alunos[i].nota);
    }

    return 0;
}
