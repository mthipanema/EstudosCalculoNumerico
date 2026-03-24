#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// f(x) = x^2 - 4x - 9
double f(double x) {
    return pow(x, 2) - 4*x - 9;
}

// Derivada de f(x) ==> f'(x) = 2x - 4
double df(double x) {
    return 2*x - 4;
}                                                  

// Metodo da Bissecao
void bissecao(double a, double b, double tol, int max_iter) {
    printf("\n--- Metodo da Bissecao ---\n");
    printf("Intervalo inicial: [%.4f, %.4f]\n", a, b);
    printf("Tolerancia: %.4f\n", tol);
    printf("Iteracoes máximas: %d\n\n", max_iter);    
    double c;
    int iter = 0;   
    printf("Iter\ta\t\tb\t\tc\t\tf(a)\t\tf(b)\t\tf(c)\n");    
    while (iter < max_iter) {
        c = (a + b) / 2.0;
        double fa = f(a);
        double fb = f(b);
        double fc = f(c);  
        printf("%d\t%.4f\t\t%.4f\t\t%.4f\t\t%.4f\t\t%.4f\t\t%.4f\n", iter + 1, a, b, c, fa, fb, fc);              
        if (f(a) * fc < 0) {
            b = c;
        } else {
            a = c;
        }    
        iter++;
    }
    
    printf("\nNumero maximo de Iteracoes atingido!\n");
    printf("Aproximacao final: x = %.4f\n", c);
}

// Metodo de Newton-Raphson
void newton_raphson(double x0, double tol, int max_iter) {
    printf("\n--- Metodo DE NEWTON-RAPHSON ---\n");
    printf("Aproximacao inicial: %.4f\n", x0);
    printf("Tolerancia: %.4f\n", tol);
    printf("Iteracoes máximas: %d\n\n", max_iter);
    double x = x0;
    int iter = 0;
    printf("Iter\tx\t\tf(x)\t\tf'(x)\t\tXn+1\n");
    printf("------------------------------------------------------------------------------------\n");
    
    while (iter < max_iter) {
        double fx = f(x);
        double dfx = df(x);
        double x_novo = x - fx / dfx;     
        printf("%d\t%.4f\t\t%.4f\t\t%.4f\t\t%.4f\n", iter + 1, x, fx, dfx, x_novo);
        x = x_novo;
        iter++;
    }
    printf("\nNumero maximo de Iteracoes atingido!\n");
    printf("Aproximacao final: x = %.4f\n", x);
}

// Metodo da Secante
void secante(double x0, double x1, double tol, int max_iter) {
    printf("\n--- Metodo DA SECANTE ---\n");
    printf("Aproximacoes iniciais: x0 = %.4f, x1 = %.4f\n", x0, x1);
    printf("Tolerancia: %.4f\n", tol);
    printf("Iteracoes máximas: %d\n\n", max_iter);
    int iter = 0;
    printf("Iter\tx(n-1)\t\tx(n)\t\tf(x(n-1))\t\tf(x(n))\t\tx+1\n");
    printf("------------------------------------------------------------------------------------\n");
    
    while (iter < max_iter) {
        double fx0 = f(x0);
        double fx1 = f(x1);
        double x2 = x1 - fx1 * (x1 - x0) / (fx1 - fx0);        
        printf("%d\t%.4f\t\t%.4f\t\t%.4f\t\t%.4f\t\t%.4f\n",iter + 1, x0, x1, fx0, fx1, x2);
        x0 = x1;
        x1 = x2;
        iter++;
    }
    printf("\nNumero maximo de Iteracoes atingido!\n");
    printf("Aproximacao final: x = %.4f\n", x1);
}

// Menu case
void menu() {
    printf("\nFuncao atual: f(x) = x^2 - 4x - 9\n");
    printf("\n1. Metodo da Bissecao\n");
    printf("2. Metodo de Newton-Raphson\n");
    printf("3. Metodo da Secante\n");
    printf("0. Sair\n");
    printf("\nEscolha uma opcao: ");
}

// --- Main ---
int main() {
    int opcao;
    double a, b, x0, x1, tol;
    int max_iter;    
    do {
        menu();
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                printf("\nMetodo da Bissecao selecionado.\n");
                printf("Digite o intervalo [a, b]: ");
                scanf("%lf %lf", &a, &b);
                printf("Digite a tolerancia: ");
                scanf("%lf", &tol);
                printf("Digite o Numero maximo de iteracoes: ");
                scanf("%d", &max_iter);
                bissecao(a, b, tol, max_iter);
                break;
                
            case 2:
                printf("\nMetodo de Newton-Raphson selecionado.\n");
                printf("Digite a Aproximacao inicial x0: ");
                scanf("%lf", &x0);
                printf("Digite a Tolerancia: ");
                scanf("%lf", &tol);
                printf("Digite o Numero maximo de Iteracoes: ");
                scanf("%d", &max_iter);
                newton_raphson(x0, tol, max_iter);
                break;
                
            case 3:
                printf("\nMetodo da Secante selecionado.\n");
                printf("Digite as duas Aproximacoes iniciais x0 e x1: ");
                scanf("%lf %lf", &x0, &x1);
                printf("Digite a Tolerancia: ");
                scanf("%lf", &tol);
                printf("Digite o Numero maximo de Iteracoes: ");
                scanf("%d", &max_iter);
                secante(x0, x1, tol, max_iter);
                break;
                
            case 0:
                printf("\nEncerrando programa...\n");
                break;
                
            default:
                printf("\nOpção inválida! Tente novamente.\n");
        }
        
        if (opcao != 0) {
            printf("\nPressione Enter para continuar...");
            getchar();
        }
        
    } while(opcao != 0);
    
    return 0;
}