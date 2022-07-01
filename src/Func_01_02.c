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
        printf("Preço: ");
        scanf(" %lf", &NovoProduto.preco);
        printf("Validade (dia/mês/ano): ");
        scanf(" %d/%d/%d", &NovoProduto.validade.dia, &NovoProduto.validade.mes, &NovoProduto.validade.ano);
        printf("Estoque: ");
        scanf(" %d", &NovoProduto.estoque);
    }
    fwrite(&NovoProduto, sizeof(Produto), 1, arqv);
    fclose(arqv);
}

void Alterar_Produto(){
    int pos; // Variável para guardar a posição
    Produto alt;
    FILE *arqv;
    arqv = fopen("produtos.dat", "r+wb");
    pos = Identificar_Produto();
    if(pos == 0)
        printf("Produto não cadastrado");
    else{
        fseek(arqv, sizeof(Produto)*(pos-1), SEEK_SET);
        fread(&alt, sizeof(Produto), 1, arqv);
        printf("Deseja alterar para qual nome?");
        scanf(" %d", &alt.id);
        fseek(arqv, sizeof(Produto)*(pos-1), SEEK_SET);
        fwrite(&alt, sizeof(Produto), 1, arqv);
        fflush(arqv);
    }
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
        while(!feof(arqv))
        {
            fread(&Ident, sizeof(Produto), 1, arqv);
            if(Ident.id == id_prod)
            {
                fclose(arqv);
                return aux;
            }
            aux++;
        }
    }
    else
        fclose(arqv);
        return 0; // Retorna 0 caso o produto não esteja cadastrado
}
