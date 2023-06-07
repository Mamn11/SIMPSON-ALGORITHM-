#include <stdio.h>
#include <math.h>
#define f(x) (x * cos(x)) // Digite a função da integral que você deseja calcular.

int main(void) {
    float intervalo1, intervalo2, h, temp, sum = 0;
    int quantSubIntervalos;

    printf("Insira os intervalos da integral\n");
    scanf("%f %f", &intervalo1, &intervalo2); //Insira os intervalos desejados da integral.

    do {
        printf("Digite o número de divisões do intervalo (deve ser um número múltiplo de 2)\n");
        scanf("%d", &quantSubIntervalos); // Se certifique que o número de sub intervalos seja múltiplo de 2.

        if (quantSubIntervalos % 2 != 0) {
            printf("Por favor, insira um número múltiplo de 2.\n");
        }
    } while (quantSubIntervalos % 2 != 0);

    h = (intervalo2 - intervalo1) / quantSubIntervalos; // Calculando a largura de cada subintervalo.
    temp = intervalo1 + h;

    while (temp < intervalo2) { //resumindo os segmentos de área individuais.

        sum += (4 * f(temp) + 2 * f(temp + h));
        temp += 2 * h;
    }

    sum = (h / 3) * (sum + f(intervalo1) - f(intervalo2)); //formula
    printf("Resultado da Integral = %f\n", sum);

    return 0;
}