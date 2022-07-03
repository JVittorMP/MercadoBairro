#include "Funcoes.h"
#include "Registros.h"

// Exibe os Produtos Registrados
void Exib_Produtos(){
    Produto pol;
    FILE *arqv;
    arqv = fopen("../Produtos.dat","rb");
    if(arqv != NULL)
    {
        while(!feof(arqv))
        {
            fread(&pol, sizeof(Produto), 1, arqv);
            printf(" ID: %d", pol.id);
            printf(" Setor: %s", pol.setor);
            printf(" Nome: %s", pol.nome);
            printf(" Preço: %.2lf", pol.preco);
            printf(" Validade: %d/%d/%d", pol.validade.dia, pol.validade.mes, pol.validade.ano);
            printf(" Estoque: %d", pol.estoque);
        }
    }
    fclose(arqv);
    Sair_Menu();
}

// Exibe os Clientes Registrados
void Exib_Clientes(){
    Clientes pol;
    FILE *arqv;
    arqv = fopen("../Clientes.dat","rb");
    if(arqv != NULL)
    {
        while(!feof(arqv))
        {
            fread(&pol, sizeof(Clientes), 1, arqv);
            printf(" CPF: %s", pol.CPF);
            printf(" Nome: %s", pol.nome);
            printf(" Data de Nascimento: %d/%d/%d", pol.nascimento.dia, pol.nascimento.mes, pol.nascimento.ano);
            printf(" Idade: %d", pol.idade);
            printf(" Endereço: %s | %s - %s", pol.endereco, pol.cidade, pol.estado);
            printf(" Pontuação: %d", pol.pontos);
        }
    }
    fclose(arqv);
    Sair_Menu();
}

// Exibe as Vendas Registradas
void Exib_Vendas(){
    Vendas pol;
    FILE *arqv;
    arqv = fopen("../Vendas.dat","rb");
    if(arqv != NULL)
    {
        while(!feof(arqv))
        {
            fread(&pol, sizeof(Vendas), 1, arqv);
            printf(" ID: %d", pol.id_vendas);
            printf(" CPF Cliente: %s", pol.CPF);
            printf(" Data da Compra: %d/%d/%d", pol.compra.dia, pol.compra.mes, pol.compra.ano);
            printf(" Valor Total: %.2f", pol.valor_total);
            printf(" Quantidade de Produtos: %d", pol.quant_prod);
        }
    }
    fclose(arqv);
    Sair_Menu();
}