#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

void carregarDadosTeste(int *idade, int *sexo, int *item, int *armado, int *sozinho, int *horario, int *total)
    {
        // Definindo 5 casos de teste variados
        int idades[] = {18, 25, 19, 45, 30};
        int sexos[] = {1, 2, 1, 2, 1}; // F, M, F, M, F
        int items[] = {2, 3, 2, 1, 4}; // Celular, Carro, Celular, Carteira, Outros
        int armados[] = {1, 1, 0, 1, 0};
        int sozinhos[] = {0, 1, 1, 0, 1};
        int horarios[] = {3, 2, 3, 4, 1}; // Noite, Tarde, Noite, Madrugada, Manhã

        for (int i = 0; i < 5; i++)
        {
            idade[i] = idades[i];
            sexo[i] = sexos[i];
            item[i] = items[i];
            armado[i] = armados[i];
            sozinho[i] = sozinhos[i];
            horario[i] = horarios[i];
        }
        *total = 5; // Atualiza a contagem global de pessoas
        printf(">>> DADOS DE TESTE CARREGADOS (5 PESSOAS) <<<\n\n");
    }

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int pessoa = 0;
    char continuar = 'S';

    // Variáveis para armazenar os dados
    int idade[100];
    int sexo[100];                   // (1-fem/2-mas)
    int item_roubado[100];           // (1-carteira/2-celular/3-carro/4-outros)
    int assalto_armado[100];         // (0-não/1-sim)
    int assaltante_acompanhado[100]; // sozinho? (0-não/1-sim)
    int horario_assalto[100];        // (1-manhã/2-tarde/3-noite/4-madrugada)

    // Variáveis para os cálculos
    int mulheres_assaltadas_noite = 0;
    int pessoas_menos_20_armadas = 0;
    int perc_pessoas_celular_levado = 0;
    int homens_carro_levado = 0;
    int homens_carro_levado_idade = 0;
    int assaltantes_sozinhos_armados = 0;
    int horario_frequente_assaltos[4] = {0, 0, 0, 0}; // Para contar a frequência de cada horário
    int horario_mais_frequente = 0;

    // carregarDadosTeste(idade, sexo, item_roubado, assalto_armado, assaltante_acompanhado, horario_assalto, &pessoa);

    do
    {
        system("cls");
        printf("==================================================\n");
        printf("    PESQUISA DE SEGURANÇA PÚBLICA - RECIFE        \n");
        printf("==================================================\n\n");

        printf("1. Idade: ");
        do{scanf("%d", &idade[pessoa]);} while (idade[pessoa] < 0 || idade[pessoa] > 100); // Validação de idade

        printf("2. Sexo (1-Fem | 2-Mas): ");
        do{scanf("%d", &sexo[pessoa]);} while (sexo[pessoa] != 1 && sexo[pessoa] != 2); // Validação de sexo

        printf("3. Item Levado (1-Carteira | 2-Celular | 3-Carro | 4-Outros): ");
        do{scanf("%d", &item_roubado[pessoa]);} while(item_roubado[pessoa] < 1 || item_roubado[pessoa] > 4); // Validação de item roubado

        printf("4. Assaltante estava armado? (0-Não | 1-Sim): ");
        do{scanf("%d", &assalto_armado[pessoa]);} while(assalto_armado[pessoa] != 0 && assalto_armado[pessoa] != 1); // Validação de assalto armado

        printf("5. Assaltante estava sozinho? (0-Não | 1-Sim): ");
        do{scanf("%d", &assaltante_acompanhado[pessoa]);} while(assaltante_acompanhado[pessoa] != 0 && assaltante_acompanhado[pessoa] != 1); // Validação de assaltante acompanhado

        printf("6. Horário (1-Manhã | 2-Tarde | 3-Noite | 4-Madrugada): ");
        do{scanf("%d", &horario_assalto[pessoa]);} while(horario_assalto[pessoa] < 1 || horario_assalto[pessoa] > 4); // Validação de horário

        printf("\n--------------------------------------------------\n");
        printf("Dados registrados com sucesso!\n");
        printf("Deseja cadastrar outra pessoa? (S/N): ");
        scanf(" %c", &continuar);
        pessoa++;
    } while (continuar == 'S' || continuar == 's');

    // Dados calculados

    for (int i = 0; i < pessoa; i++)
    {
        if (sexo[i] == 1 && horario_assalto[i] == 3)
            mulheres_assaltadas_noite++;
        if (idade[i] < 20 && assalto_armado[i] == 1)
            pessoas_menos_20_armadas++;
        if (item_roubado[i] == 2)
            perc_pessoas_celular_levado++;
        if (sexo[i] == 2 && item_roubado[i] == 3)
        {
            homens_carro_levado++;
            homens_carro_levado_idade += idade[i];
        }
        if (assaltante_acompanhado[i] == 1 && assalto_armado[i] == 1)
            assaltantes_sozinhos_armados++;
            
        switch (horario_assalto[i])
        {
        case 1:
            horario_frequente_assaltos[0]++;
            break;
        case 2:
            horario_frequente_assaltos[1]++;
            break;
        case 3:
            horario_frequente_assaltos[2]++;
            break;
        case 4:
            horario_frequente_assaltos[3]++;
            break;
        }
    }

    for (int i = 0; i < 4; i++)
    {
        if (horario_frequente_assaltos[i] > horario_frequente_assaltos[horario_mais_frequente])
        {
            horario_mais_frequente = i;
        }
    }

    system("cls");
    printf("\n==================================================\n");
    printf("    RESULTADOS DA PESQUISA DE SEGURANÇA PÚBLICA - RECIFE   \n");
    printf("==================================================\n\n");
    
    printf("Quantidade de mulheres que foram assaltadas à noite: %d\n", mulheres_assaltadas_noite);
    printf("Quantidade de pessoas com menos de 20 anos assaltadas com uso de arma: %d\n", pessoas_menos_20_armadas);
    printf("Percentual de pessoas que tiveram o celular levado: %.2f %% das pessoas\n", (float)(perc_pessoas_celular_levado * 100) / pessoa);
    if(homens_carro_levado > 0) printf("Média da idade dos homens que tiveram o carro levado: %.2f anos\n", (float)(homens_carro_levado_idade) / homens_carro_levado);
    else printf("Média da idade dos homens que tiveram o carro levado: N/A (Nenhum caso registrado)\n");
    printf("Percentual de assaltantes que agiram sozinhos e armados: %.2f %% dos assaltantes\n", (float)(assaltantes_sozinhos_armados * 100) / pessoa);
    printf("Horário com maior frequência de assaltos: ");

    switch (horario_mais_frequente)
    {
    case 0:
        printf("Manhã\n");
        break;
    case 1:
        printf("Tarde\n");
        break;
    case 2:
        printf("Noite\n");
        break;
    case 3:
        printf("Madrugada\n");
        break;
    }

    printf("==================================================\n");
    printf("    FIM DA PESQUISA DE SEGURANÇA PÚBLICA - RECIFE   \n");
    printf("==================================================\n");
    printf("Pressione Enter para sair...");
    system("pause");
    return 0;
}

