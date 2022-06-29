#include <stdio.h>
#include "Funcoes.h"
#include "Registros.h"

void Incluir_Produtos(){
    Produto NovoProduto; // É necessario alocar dinamicamente? Acho que não.
    FILE *arqv;
    arqv = fopen("Produtos.dat", "ab");
    printf("Insira as informações do produto: \n\n");
    if(arqv != NULL)
    {
        printf("Id: ");
        scanf(" %d", &NovoProduto.id);
        printf("Setor: ");
        scanf(" %[^\n]s", NovoProduto.setor);
        printf("Nome: ");
        scanf(" %[^\n]s", NovoProduto.nome);
        printf("Preço: ")
        scanf(" %lf", &NovoProduto.preco);
        printf("Validade (dia/mês/ano): ");
        scanf(" %d/%d/%d", &NovoProduto.validade.dia, &NovoProduto.validade.mes, &NovoProduto.validade.ano);
        printf("Estoque: ");
        scanf(" %d", &NovoProduto.estoque);
    }
    fwrite(NovoProduto, sizeof(Produto), 1, arqv);
    fclose(arqv);
}

void Alterar_Produto(){
    int pos; // Variável para guardar a posição
}

int Identificar_Produto(){
    int aux = 1; // Identifica a posição
    int id_prod;
    Produto Ident;
    FILE *arqv;
    arqv = fopen("Produtos.dat", "rb");
    if(arqv != NULL)
    {
        printf("Qual produto deseja alterar? (Insira id): ");
        scanf(" %d", &id_prod);
        while(arqv != feof(arqv))
        {
            fread(Ident, sizeof(Produto), 1, arqv);
            if(Ident.id == id_prod)
            {
                return aux;
            }
            aux++;
        }
    }
    else
        return 0; // Retorna 0 caso o produto não esteja cadastrado
}