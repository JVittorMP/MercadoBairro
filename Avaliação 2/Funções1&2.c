#include <stdio.h>
#include "Funcoes.h"
#include "Registros.h"

void IncluirProdutos(){
    Produto NovoProduto;
    FILE *arq1;
    arq1 = fopen("Produtos.dat", "ab");
    printf("Insira as informações: \n\n");
    if(arq1 != NULL)
    {
        printf("Id: \n");
        scanf(" %d", NovoProduto.id)
    }
}
