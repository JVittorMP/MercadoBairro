#include <stdio.h>
#include "Menus.h"
#include "Funcoes.h"
#include "Registros.h"

// Função 1
void Incluir_Produtos(){
    Produto NovoProduto; // É necessario alocar dinamicamente? Acho que não.
    FILE *arqv;
    arqv = fopen("../Produtos.dat", "ab");
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

// Função 2
void Alterar_Produto(){
    int pos; // Variável para guardar a posição
    Produto alt;
    bool Saida = false;
    char confirma;

    pos = Identificar_Produto(); // Uso da Função para Identificar a Posição do Produto no Arquivo
    FILE *arqv;
    arqv = fopen("../Produtos.dat", "r+b");
    if(pos == 0){
        printf("\n"); // Pula Linha Para Separar os 'Printf'
        printf("Produto não Cadastrado! \n\n");
        while(!Saida)
        {
            printf("Deseja retornar ao menu? (S/N) ");
            scanf(" %c", &confirma);
            if(confirma == 'S' || confirma == 's')
                Saida = true;
        }
    }
    else // Troca da informação do Produto
    {
        fseek(arqv, sizeof(Produto)*(pos-1), SEEK_SET);
        fread(&alt, sizeof(Produto), 1, arqv);
        Troca(&alt); // Seleção da Informação a ser alterada
        fseek(arqv, sizeof(Produto)*(pos-1), SEEK_SET);
        fwrite(&alt, sizeof(Produto), 1, arqv);
        fflush(arqv);
    }
    fclose(arqv);
    Limpar_Tela();
    Menu_Produto();
}

void Troca(Produto *pont){ // Altera os valores no registro
    int aux;
    printf(" 1. Identificação \n 2. Setor \n 3. Nome \n");
    printf(" 4. Preço \n 5. Validade \n 6. Estoque \n 9. Sair \n\n");
    printf("Qual informação deseja alterar? ");
    scanf(" %d", &aux);
    Limpar_Tela();
    switch(aux){
        case 1:
            printf("Insira o novo id: ");
            scanf(" %d", &pont->id);
            break;
        case 2:
            printf("Insira o novo setor: ");
            scanf(" %[^\n]s", &pont->setor);
            break;
        case 3:
            printf("Insira o novo nome: ");
            scanf(" %[^\n]s", &pont->nome);
            break;
        case 4:
            printf("Insira o novo preço: ");
            scanf(" %lf", &pont->preco);
            break;
        case 5:
            printf("Insira a nova validade (dia/mês/ano): ");
            scanf(" %d/%d/%d", &pont->validade.dia, &pont->validade.mes, &pont->validade.ano);
            break;
        case 6:
            printf("Insira o novo : ");
            scanf(" %d", &pont->estoque);
            break;
        case 9:
            break;
    }
}

int Identificar_Produto(){
    int aux = 1; // Identifica a Posição do Produto no Arquivo
    int id_prod;
    Produto Ident;
    FILE *arqv;
    arqv = fopen("../Produtos.dat", "rb");
    if(arqv != NULL)
    {
        printf("Insira o ID do produto que deseja alterar: ");
        scanf(" %d", &id_prod);
        while(!feof(arqv))
        {
            fread(&Ident, sizeof(Produto), 1, arqv);
            if(Ident.id == id_prod)
            {
                fclose(arqv);
                return aux; // Devolve a Posição
            }
            aux++;
        }
        fclose(arqv);
        return 0; // ID não identificado
    }
    else
    {
        fclose(arqv);
        return 0; // Arquivo Não Existe
    }
}
