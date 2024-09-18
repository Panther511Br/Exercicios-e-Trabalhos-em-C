#include <stdio.h>
#include <time.h>

    int func1(int n){
        if (n==0) return 1;
        return func1(n - 1) + func1(n - 1);
    }

    int func2(int n){
        if(n==0) return 1;
        return 2*func1(n - 1);
    }

    int func3(int n){
        if(n==0) return 1;
        int valor = func3(n/2);
        if(n%2==0) return valor * valor;
        else return 2 * valor * valor;
    }

    void func_medir_tempo (int (*func) (int), int n, const char* nome_funcao)
    {   long int tempo_inicial = clock();
        func(n);
        long int tempo_final = clock();

        double tempo_percorrido = (tempo_final - tempo_inicial)/CLOCKS_PER_SEC;
        printf("Tempo de execucao de %s: %f segundos\n", nome_funcao, tempo_percorrido);
    }
int main(){

    int n = 10;

    printf("Numero usado: %d\n", n);

    func_medir_tempo(func1, n, "func1");
    func_medir_tempo(func2, n, "func2");
    func_medir_tempo(func3, n, "func3");

    return 0;
}
