#include <stdio.h>
#include <string.h>
#include "Funcoes.h"
#include "Registros.h"

// Função 3
void Cadastrar_Clientes(){
    Produto NovoCliente; // É necessario alocar dinamicamente? Acho que não.
    FILE *arqv;
    arqv = fopen("../Produtos.dat", "ab");
    printf("Insira as informações do produto: \n\n");
    if(arqv != NULL)
    {
        printf("Id: ");
        scanf(" %d", &NovoCliente.id);
        printf("Setor: ");
        scanf(" %[^\n]s", NovoCliente.setor);
        printf("Nome: ");
        scanf(" %[^\n]s", NovoCliente.nome);
        printf("Preço: ");
        scanf(" %lf", &NovoCliente.preco);
        printf("Validade (dia/mês/ano): ");
        scanf(" %d/%d/%d", &NovoCliente.validade.dia, &NovoCliente.validade.mes, &NovoCliente.validade.ano);
        printf("Estoque: ");
        scanf(" %d", &NovoCliente.estoque);
    }
    fwrite(&NovoCliente, sizeof(Produto), 1, arqv);
    fclose(arqv);
}

// Função 5
float ValorTotalDasVendas (char cpf[13]) {
    FILE *venda;
    Vendas info;
    float total = 0;

    venda = fopen("../Vendas.dat", "rb");
    if (venda == NULL)
        printf("Erro na abertura do arquivo de vendas");
    else {
        while (fread(&info, sizeof(Vendas), 1, venda) != 0) {
            if (strcmp(info.CPF, cpf) == 0)
                total += info.valor_total;
        }
    }
    return (total);
}
