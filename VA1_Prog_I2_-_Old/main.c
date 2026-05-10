#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    char nome[50];
    int especialidade, idade, experiencia;
    float salario;
    float adicional;
    char continuar;

    do{

    system("cls");
    printf("================================================\n");
    printf("Bem-vindo ao sistema de folha de pagamento da Construtora Legal!\n");
    printf("================================================\n\n");
    
    printf("Digite o nome do funcionário: ");
    scanf(" %[^\n]s", nome);
    printf("Digite a especialidade do funcionário (1-pedreiro, 2-pintor, 3-hidráulica, 4-eletricista): ");
    scanf("%d", &especialidade);
    printf("Digite a idade do funcionário: ");
    scanf("%d", &idade);
    printf("Digite os anos de experiência do funcionário: ");
    scanf("%d", &experiencia);

    // Calculos
    switch(especialidade) {
        case 1:
            salario = 1100.00; // salário para pedreiro
            break;
        case 2:
            salario = 1250.00; // salário para pintor
            break;
        case 3:
            salario = 1300.00; // salário para hidráulica
            break;
        case 4:
            salario = 1400.00; // salário para eletricista
            break;
    }
    
    if(experiencia > 0) salario += experiencia * 70.00; // Adicional de R$ 70,00 por ano de experiência

    if(idade > 45) {adicional = salario * 0.08; salario *= 1.08;} // Adicional de 8% para funcionários com mais de 45 anos

    // Resultados

    printf("\n\n================================================\n");
    printf("Construtora Legal\n");
    printf("Salário do Funcionário %s \n", nome);
    printf("Valor Total: R$ %.2f\n", salario);
    printf("Recebeu R$ %.2f pela experiência.\n", experiencia * 70.00);
    if(idade > 45) printf("Recebeu adicional de R$ %.2f por ter mais de 45 anos.\n", adicional);
    printf("================================================\n\n");

    printf("Deseja calcular o salário de outro funcionário? (s/n): ");
    scanf(" %c", &continuar);
    } while (continuar == 's' || continuar == 'S');
}