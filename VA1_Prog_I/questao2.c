// Aluno: Fernando Antonio Soares de Almeida
// Polo: Jo„o Pessoa

// Uma fazenda especializada na venda de cavalos deseja desenvolver um sistema
// para calcular o pre√ßo de seus animais. O valor do cavalo depende da ra√ßa, da idade e da
// finalidade do animal. Para cada cavalo, dever√£o ser informadas as seguintes
// informaÁıes: RaÁa (1 ‚Äì Quarto de Milha/ 2 ‚Äì Mangalarga Marchador/3 ‚Äì √ùrabe), Idade
// do animal (em anos) e Finalidade do animal (1 ‚Äì esporte/ 2 ‚Äì trabalho/ 3 ‚Äì reprodu√ß√£o).
// A quantidade de cavalos √© desconhecida.

// Ra√ßa | at√© de 2 anos | Mais de 2 anos
// 1-Quarto de Milha | R$ 7.000,00 | R$ 5.500,00
// 2-Mangalarga Marchador | R$ 9.000,00 | R$ 6.000,00
// 3-√ùrabe | R$ 18.000,00 | R$ 15.000,00

// Finalidade | Acr√©scimo
// 1-Esporte | 15%
// 2-Trabalho | 20%
// 3-Reprodu√ß√£o | 30%

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>


void main (){

        setlocale(LC_ALL, "Portuguese");

        int continuar = 1;
        int raca, idade, finalidade;
        float preco;

        do{
        system("cls");
        printf("==================================================\n");
        printf("    C·lculo do PreÁo dos Cavalos\n");
        printf("==================================================\n\n");

        printf("Digite a raÁa do cavalo (1-Quarto de Milha/ 2-Mangalarga Marchador/3-¡rabe): ");
        do{scanf("%d", &raca);} while(raca < 1 || raca > 3);
        printf("Digite a idade do cavalo (em anos): ");
        do{scanf("%d", &idade);} while(idade < 0);
        printf("Digite a finalidade do cavalo (1-Esporte/ 2-Trabalho/ 3-ReproduÁ„o): ");
        do{scanf("%d", &finalidade);} while(finalidade < 1 || finalidade > 3);
        
        // Calculo do preÁo
        switch (raca)
        {
            case 1: // Quarto de Milha
                if(idade <= 2) preco = 7000;
                else preco = 5500;
                break;
            case 2: // Mangalarga Marchador
                if(idade <= 2) preco = 9000;
                else preco = 6000;
                break;
            case 3: // ¡rabe
                if(idade <= 2) preco = 18000;
                else preco = 15000;
                break;
        }
        switch (finalidade)
        {
            case 1: preco *= 1.15; break; // Esporte
            case 2: preco *= 1.20; break; // Trabalho
            case 3: preco *= 1.30; break; // ReproduÁ„o
        }

        printf("\nO preÁo do cavalo È: R$ %.2f\n\n", preco);
        printf("Deseja calcular o preÁo de outro cavalo? (1-sim/0-n„o): ");
        do{scanf("%d", &continuar);} while (continuar != 0 && continuar != 1);

        } while (continuar == 1);

}