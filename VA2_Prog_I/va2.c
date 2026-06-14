// Aluno: Fernando Antonio Soares de Almeida
// Polo: João Pessoa - PB

// Segunda VA de Programação I

// 1. (10,0) Faça um programa modularizado, em linguagem C, para corrigir uma prova de múltipla
// escolha. A prova possui 5 questões, cada uma com alternativas A, B, C, D ou E. Cada questão vale
// 2,0 pontos, totalizando 10,0 pontos. A nota mínima para aprovação é 7,0.
// O programa deve apresentar as seguintes operações:
// a) Cadastrar gabarito: Ler e armazenar o gabarito da prova, contendo as respostas corretas das
// cinco questões.
// b) Cadastrar respostas da turma: Ler o nome de cada aluno e suas respostas para as cinco
// questões. A turma possui quantidade desconhecida de alunos. Os dados dos alunos devem ser
// armazenados em um vetor de registros.
// c) Listagem geral de notas: Apresentar, em formato de tabela, o nome, as respostas dadas e a
// nota obtida por cada aluno cadastrado.
// d) Relatório estatístico: Apresentar um relatório estatístico com informações gerais sobre o
// desempenho da turma.
// e) Relatório estatístico: Apresentar os dados solicitados conforme tela detalhada na página a
// seguir.

// Compilador
// gcc.exe (tdm64-1) 9.2.0
// Copyright (C) 2019 Free Software Foundation, Inc.
// This is free software; see the source for copying conditions.  There is NO
// warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

struct aluno
{
    char nome[50];
    char respostas[5];
    int nota;
};

struct aluno turma[100];

int totalalunos = 0;
int totalerros[5] = {0, 0, 0, 0, 0};
int questaoerrada = 0;

char gabarito[5] = {' ', ' ', ' ', ' ', ' '};

void telainicial();
void tela_cadastro_gabarito();
void tela_cadastro_respostas();
void tela_listagem_geral_notas();
void tela_relatorio_estatistico();

int main()
{
    setlocale(LC_ALL, "Portuguese");
    telainicial();
    return 0;
}

void telainicial()
{
    int opcao;

    do
    {
        system("cls");

        printf("Escola Legal - Correção de Provas\n\n\n");
        printf("Opções:\n\n");
        printf("1. Cadastrar gabarito\n");
        printf("2. Cadastrar respostas da turma\n");
        printf("3. Listagem geral de notas\n");
        printf("4. Relatório estatístico\n");
        printf("0. Sair\n\n");

        printf("Informe a opção desejada: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            tela_cadastro_gabarito();
            break;
        case 2:
            tela_cadastro_respostas();
            break;
        case 3:
            tela_listagem_geral_notas();
            break;
        case 4:
            tela_relatorio_estatistico();
            break;
        case 0:
            printf("\n\nSaindo...\n");
            break;
        default:
            printf("Opção inválida!");
            break;
        }
    } while (opcao != 0);
}

void tela_cadastro_gabarito()
{
    system("cls");

    printf("Escola Legal - Correção de Provas\n\n\n");
    printf("Cadastrar Gabarito\n");

    printf("Resposta da questão 1: ");
    scanf(" %c", &gabarito[0]);
    printf("Resposta da questão 2: ");
    scanf(" %c", &gabarito[1]);
    printf("Resposta da questão 3: ");
    scanf(" %c", &gabarito[2]);
    printf("Resposta da questão 4: ");
    scanf(" %c", &gabarito[3]);
    printf("Resposta da questão 5: ");
    scanf(" %c", &gabarito[4]);

    printf("\n\nGabarito cadastrado com sucesso!\n");
    printf("Tecle enter para retornar ao menu de opções");
    system("pause");
}

void tela_cadastro_respostas()
{
    int continuar = 1;

    do
    {
        system("cls");
        printf("Escola Legal - Correção de Provas\n\n\n");
        printf("Cadastrar Gabarito\n");

        printf("Nome do aluno: ");
        scanf(" %[^\n]", &turma[totalalunos].nome);

        printf("Resposta da questão 1: ");
        scanf(" %c", &turma[totalalunos].respostas[0]);
        printf("Resposta da questão 2: ");
        scanf(" %c", &turma[totalalunos].respostas[1]);
        printf("Resposta da questão 3: ");
        scanf(" %c", &turma[totalalunos].respostas[2]);
        printf("Resposta da questão 4: ");
        scanf(" %c", &turma[totalalunos].respostas[3]);
        printf("Resposta da questão 5: ");
        scanf(" %c", &turma[totalalunos].respostas[4]);

        int i;
        turma[totalalunos].nota = 0;

        for (i = 0; i < 5; i++)
        {
            if (turma[totalalunos].respostas[i] == gabarito[i])
            {
                turma[totalalunos].nota += 2;
            }
            else
            {
                totalerros[i]++;
            }
        }

        totalalunos++;

        printf("\n\nDeseja cadastrar outro aluno(1-sim/0-não)? \n");

        do
        {
            scanf("%d", &continuar);
        } while (continuar != 0 && continuar != 1);

    } while (continuar == 1);
}

void tela_listagem_geral_notas()
{
    system("cls");
    printf("Escola Legal - Correção de provas\n\n\n");
    printf("Listagem geral de notas\n\n");
    printf(" Nome\t\t\t Respostas\t\t Nota\n");
    printf("-------------------------------------------------------------\n");

    int i;

    for (i = 0; i < totalalunos; i++)
    {
        printf(" %s\t\t\t", turma[i].nome);
        int j;
        for (j = 0; j < 5; j++)
        {
            printf(" %c ", turma[i].respostas[j]);
        }
        printf("\t\t %d\n", turma[i].nota);
    }

    printf("\n\nTecle enter para retornar ao menu");
    system("pause");
}

void tela_relatorio_estatistico()
{
    int reprovados = 0;
    int notamaisalta = 0;
    int notamaisbaixa = 10;

    float mediaturma = 0.0f;
    float percentualaprovados = 0.0f;

    system("cls");

    printf("Escola Legal - Correção de provas\n\n\n");
    printf("Relatório estatístico\n");
    printf("-------------------------------------------------------------\n");

    if (totalalunos > 0)
    {
        int i;
        for (i = 0; i < totalalunos; i++)
        {
            mediaturma += turma[i].nota;

            if (turma[i].nota < 7)
            {
                reprovados++;
            }

            if (turma[i].nota > notamaisalta)
            {
                notamaisalta = turma[i].nota;
            }

            if (turma[i].nota < notamaisbaixa)
            {
                notamaisbaixa = turma[i].nota;
            }
        }
        mediaturma = mediaturma / totalalunos;
        percentualaprovados = ((float)totalalunos - (float)reprovados) * 100.0f / (float)totalalunos;

        int j = 0;
        for (i = 0; i < 5; i++)
        {
            if (totalerros[i] > j)
            {
                j = totalerros[i];
                questaoerrada = i;
            }
        }
    }

    printf("Média das notas da turma: %.2f\n", mediaturma);
    printf("Quanditade de alunos reprovados: %d\n", reprovados);
    printf("Percentual de alunos aprovados: %.2f%%\n", percentualaprovados);
    printf("Nota mais alta: %d\n", notamaisalta);
    printf("Nota mais baixa: %d\n", notamaisbaixa);
    printf("Qual questão os alunos erraram mais: %d\n", questaoerrada + 1);
    printf("\n-------------------------------------------------------------\n");
    printf("Tecle enter para voltar ao menu");
    system("pause");
}