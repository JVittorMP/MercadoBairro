#include <stdio.h>
#include <string.h>
#include "Funcoes.h"
#include "Registros.h"

// Função 3 - Cadastrar e Alterar Dados de Clientes
void Cadastrar_Clientes(){
    Clientes NovoCliente;
    FILE *arqv;
    arqv = fopen("../Clientes.dat", "ab");
    printf("Insira as informações do cliente: \n\n");
    if(arqv != NULL)
    {
        printf("CPF: ");
        scanf(" %[^\n]s", NovoCliente.CPF);
        printf("Nome: ");
        scanf(" %[^\n]s", NovoCliente.nome);
        printf("Data de Nascimento (dia/mês/ano): ");
        scanf(" %d/%d/%d", &NovoCliente.nascimento.dia, &NovoCliente.nascimento.mes, &NovoCliente.nascimento.ano);
        printf("Idade: ");
        scanf(" %d", &NovoCliente.idade);
        printf("Endereço: ");
        scanf(" %[^\n]s", NovoCliente.endereco);
        printf("Cidade: ");
        scanf(" %[^\n]s", NovoCliente.cidade);
        printf("Estado (UF): ");
        scanf(" %[^\n]s", NovoCliente.estado);
        printf("Pontos: ");
        scanf(" %d", NovoCliente.pontos);
    }
    fwrite(&NovoCliente, sizeof(Clientes), 1, arqv);
    fclose(arqv);
}

void Alterar_Clientes(){

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
