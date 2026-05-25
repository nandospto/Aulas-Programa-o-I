// Aluno: Fernando Antonio Soares de Almeida
// Polo: João Pessoa

// Foi realizada uma pesquisa com pacientes atendidos em uma UPA do município. A
// quantidade de pacientes entrevistada é desconhecida. Para cada pessoa, foram
// coletadas as seguintes informações: Idade, Sexo(1-feminino/2-masculino), Tipo de
// atendimento(1-Clínico Geral, 2-Cardiologista, 3-Ortopedista, 4-Pediatra), Fez algum
// exame(1-sim/0-não)? Faça um programa que leia os dados da pesquisa e apresente os
// seguintes resultados:
// ? Quantidade de pacientes menores de 12 anos;
// ? Quantidade de mulheres que fizeram exame;
// ? Média da idade dos homens que foram ao cardiologista;
// ? Percentual de pessoas que foram ao ortopedista;
// ? Percentual de mulheres com mais de 50 anos;


#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

// void carregarDadosTeste(int *idade, int *sexo, int *tipo_atendimento, int *fez_exame, int *pessoa)
// {
//     // 10 Dados de teste para validar os resultados
//     int idades[] = {10, 55, 60, 35, 8, 40, 25, 42, 65, 30};
//     int sexos[] = {2, 1, 2, 2, 1, 2, 1, 1, 1, 2};             // 1-Fem, 2-Masc
//     int atendimentos[] = {4, 1, 2, 3, 4, 2, 1, 3, 1, 1};     // 1-Clínico, 2-Cardio, 3-Orto, 4-Pediatra
//     int exames[] = {0, 1, 1, 0, 1, 0, 1, 1, 0, 0};           // 1-Sim, 0-Não
    
//     for (int i = 0; i < 10; i++)
//     {
//         idade[i] = idades[i];
//         sexo[i] = sexos[i];
//         tipo_atendimento[i] = atendimentos[i];
//         fez_exame[i] = exames[i];
//     }
//     *pessoa = 10; // Atualiza a contagem global de pacientes
//     printf(">>> DADOS DE TESTE CARREGADOS (10 PACIENTES UPA) <<<\n\n");
// }

void main()
{
    setlocale(LC_ALL, "Portuguese");

    int pessoa = 0;
    int idade[100], sexo[100], tipo_atendimento[100], fez_exame[100];
    int continuar = 1;    

    int menor12 = 0, mulheresfez_exame = 0, homensCardio = 0, totalCardio = 0, totalOrtopedista = 0, mulheres50 = 0;

    // carregarDadosTeste(idade, sexo, tipo_atendimento, fez_exame, &pessoa);

    do
    {
        system("cls");
        printf("==================================================\n");
        printf("    PESQUISA DA UPA MUNICIPAL\n");
        printf("==================================================\n\n");

        printf("Digite a idade: ");
        do
        {
            scanf("%d", &idade[pessoa]);
        } while (idade[pessoa] < 0 || idade[pessoa] > 100);

        printf("Digite o sexo (1-feminino/2-masculino): ");
        do{scanf("%d", &sexo[pessoa]);} while (sexo[pessoa] != 1 && sexo[pessoa] != 2);

        printf("Digite o tipo de atendimento (1-Clínico Geral, 2-Cardiologista, 3-Ortopedista, 4-Pediatra): ");
        do{scanf("%d", &tipo_atendimento[pessoa]);} while (tipo_atendimento[pessoa] < 1 || tipo_atendimento[pessoa] > 4);

        printf("Fez algum fez_exame? (1-sim/0-não): ");
        do{scanf("%d", &fez_exame[pessoa]);} while (fez_exame[pessoa] != 0 && fez_exame[pessoa] != 1);

        printf("Deseja continuar? (1-sim/0-não): ");
        do{scanf("%d", &continuar);} while (continuar != 0 && continuar != 1);
        pessoa++;

    } while (continuar == 1);

    // Calcular os resultados

    for (int i = 0; i < pessoa; i++)
    {
        if (idade[i] < 12)
        {
            menor12++;
        }
        if (sexo[i] == 1 && fez_exame[i] == 1)
        {
            mulheresfez_exame++;
        }
        if (sexo[i] == 2 && tipo_atendimento[i] == 2)
        {
            homensCardio += idade[i];
            totalCardio++;
        }
        if (tipo_atendimento[i] == 3)
        {
            totalOrtopedista++;
        }
        if (sexo[i] == 1 && idade[i] > 50)
        {
            mulheres50++;
        }
    }

    printf("\nResultados\n");
    printf("Quantidade de pacientes menores de 12 anos: %d\n", menor12);
    printf("Quantidade de mulheres que fizeram exame: %d\n", mulheresfez_exame);
    if (totalCardio > 0)
    {
        printf("Média da idade dos homens que foram ao cardiologista: %.2f\n", (float)homensCardio / totalCardio);
    }
    else
    {
        printf("Nenhum homem foi ao cardiologista.\n");
    }
    printf("Percentual de pessoas que foram ao ortopedista: %.2f %%\n", (float)(totalOrtopedista) / pessoa * 100);
    printf("Percentual de mulheres com mais de 50 anos: %.2f %%\n", (float)(mulheres50) / pessoa * 100);

    system("pause");
}