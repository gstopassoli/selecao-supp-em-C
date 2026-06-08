#include <stdio.h>
#include <string.h>

int main() {

    int qtdSup;
    int i, j, maior;
    int opcao;

    char supNome[10][30];

    int supPrazo[10];
    float supPreco[10];
    float supQualidade[10];

    float notaPrazo[10];
    float notaPreco[10];
    float notaQualidade[10];
    float notaFinal[10];

    int prioridadePrincipal;
    int prioridadeSecundaria;

    int menorPrazo;
    float menorPreco;
    int maiorPrazo;
    float maiorPreco;

    int pesoPrazo;
    int pesoPreco;
    int pesoQualidade;

    float somaNotas;
    int somaPesos;

    float tempFloat;
    int tempInt;
    char tempNome[30];

                //CADASTRO

    do {
        printf("Quantidade de fornecedores: ");
        scanf("%d", &qtdSup);
        
        if(qtdSup < 1 || qtdSup > 10) {
            printf("Quantidade invalida! Escolha de 1 a 10.\n\n");
        }
    } while(qtdSup < 1 || qtdSup > 10);

    for(i = 0; i < qtdSup; i++) {

        printf("\nFORNECEDOR %d\n", i + 1);

        printf("Nome: ");
        scanf(" %s", supNome[i]);

        printf("Prazo (dias): ");
        scanf("%d", &supPrazo[i]);

        printf("Qualidade (1 a 5): ");
        scanf("%f", &supQualidade[i]);

        printf("Preco: ");
        scanf("%f", &supPreco[i]);
    }

                //PRIORIDADE

    do {

        printf("\n1 - Prazo\n");
        printf("2 - Qualidade\n");
        printf("3 - Preco\n");

        do {
            printf("\nPrioridade principal: ");
            scanf("%d", &prioridadePrincipal);

            if(prioridadePrincipal < 1 || prioridadePrincipal > 3) {
                printf("Esse numero nao existe, tente novamente.\n");
            }

        } while(prioridadePrincipal < 1 || prioridadePrincipal > 3);

        do {
            printf("Prioridade secundaria: ");
            scanf("%d", &prioridadeSecundaria);

            if(prioridadeSecundaria < 1 || prioridadeSecundaria > 3) {
                printf("Esse numero nao existe, tente novamente.\n");
            }

            if(prioridadeSecundaria == prioridadePrincipal) {
                printf("Prioridades nao podem ser iguais, tente novamente.\n");
            }

        } while(
            prioridadeSecundaria < 1 ||
            prioridadeSecundaria > 3 ||
            prioridadeSecundaria == prioridadePrincipal
        );

        pesoPrazo = 1;
        pesoPreco = 1;
        pesoQualidade = 1;

        if(prioridadePrincipal == 1) pesoPrazo = 10;
        if(prioridadePrincipal == 2) pesoQualidade = 10;
        if(prioridadePrincipal == 3) pesoPreco = 10;

        if(prioridadeSecundaria == 1 && pesoPrazo == 1) pesoPrazo = 8;
        if(prioridadeSecundaria == 2 && pesoQualidade == 1) pesoQualidade = 8;
        if(prioridadeSecundaria == 3 && pesoPreco == 1) pesoPreco = 8;

        somaPesos = pesoPrazo + pesoPreco + pesoQualidade;

                //NOTAS

        menorPrazo = supPrazo[0];
        maiorPrazo = supPrazo[0];

        menorPreco = supPreco[0];
        maiorPreco = supPreco[0];

        for(i = 1; i < qtdSup; i++) {

            if(supPrazo[i] < menorPrazo) menorPrazo = supPrazo[i];
            if(supPrazo[i] > maiorPrazo) maiorPrazo = supPrazo[i];

            if(supPreco[i] < menorPreco) menorPreco = supPreco[i];
            if(supPreco[i] > maiorPreco) maiorPreco = supPreco[i];
        }

        for(i = 0; i < qtdSup; i++) {

            if(maiorPrazo == menorPrazo) {
                notaPrazo[i] = 10;
            } else {
                notaPrazo[i] = ((float)(maiorPrazo - supPrazo[i]) / (maiorPrazo - menorPrazo)) * 10;
            }

            if(maiorPreco == menorPreco) {
                notaPreco[i] = 10;
            } else {
                notaPreco[i] = ((float)(maiorPreco - supPreco[i]) / (maiorPreco - menorPreco)) * 10;
            }

            notaQualidade[i] = (supQualidade[i] / 5.0) * 10;

            somaNotas =
                (notaPrazo[i] * pesoPrazo) +
                (notaPreco[i] * pesoPreco) +
                (notaQualidade[i] * pesoQualidade);

            notaFinal[i] = somaNotas / somaPesos;
        }

                //ORDENACAO

        for(i = 0; i < qtdSup - 1; i++) {

            maior = i;

            for(j = i + 1; j < qtdSup; j++) {
                if(notaFinal[j] > notaFinal[maior]) {
                    maior = j;
                }
            }

            tempFloat = notaFinal[i];
            notaFinal[i] = notaFinal[maior];
            notaFinal[maior] = tempFloat;

            strcpy(tempNome, supNome[i]);
            strcpy(supNome[i], supNome[maior]);
            strcpy(supNome[maior], tempNome);

            tempInt = supPrazo[i];
            supPrazo[i] = supPrazo[maior];
            supPrazo[maior] = tempInt;

            tempFloat = supPreco[i];
            supPreco[i] = supPreco[maior];
            supPreco[maior] = tempFloat;

            tempFloat = supQualidade[i];
            supQualidade[i] = supQualidade[maior];
            supQualidade[maior] = tempFloat;
        }

        printf("\nMelhor custo-beneficio: %s\n", supNome[0]);

        for(i = 1; i < qtdSup; i++) {
            printf("\n%d lugar: %s\n", i + 1, supNome[i]);
        }

                //LOOPING

        printf("\nDeseja recalcular ranking?\n");
        printf("1 - Sair\n");
        printf("2 - Trocar Prioridades\n");
        printf("\n");
        scanf("%d", &opcao);

    } while(opcao == 2);

    printf("\nObrigado, volte sempre!\n");

    return 0;
}