#include "Funcoes.h"
#include "Registros.h"

// Exibe os Produtos Registrados
void Exib_Produtos(){
    Produto pol;
    FILE *arqv;
    arqv = fopen("../Produtos.dat","rb");
    if(arqv != NULL)
    {
        while(1)
        {
            fread(&pol, sizeof(Produto), 1, arqv);
            if(feof(arqv))
                break;
            printf(" ID: %d \n Setor: %s \n", pol.id, pol.setor);
            printf(" Nome: %s \n Preço: %.2lf \n", pol.nome, pol.preco);
            printf(" Validade: %d/%d/%d \n", pol.validade.dia, pol.validade.mes, pol.validade.ano);
            printf(" Estoque: %d \n\n", pol.estoque);
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
        while(1)
        {
            fread(&pol, sizeof(Clientes), 1, arqv);
            if(feof(arqv))
                break;
            printf(" CPF: %s \n Nome: %s \n", pol.CPF, pol.nome);
            printf(" Data de Nascimento: %d/%d/%d \n", pol.nascimento.dia, pol.nascimento.mes, pol.nascimento.ano);
            printf(" Idade: %d \n", pol.idade);
            printf(" Endereço: %s | %s - %s \n", pol.endereco, pol.cidade, pol.estado);
            printf(" Pontuação: %d \n\n", pol.pontos);
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
        while(1)
        {
            fread(&pol, sizeof(Vendas), 1, arqv);
            if(feof(arqv))
                break;
            printf(" ID: %d \n CPF Cliente: %s \n", pol.id_vendas, pol.CPF);
            printf(" Data da Compra: %d/%d/%d \n", pol.compra.dia, pol.compra.mes, pol.compra.ano);
            printf(" Valor Total: %.2f \n", pol.valor_total);
            printf(" Quantidade de Produtos: %d \n\n", pol.quant_prod);
        }
    }
    fclose(arqv);
    Sair_Menu();
}

// Exibe os Itens de Uma Venda a Partir do ID
void Exib_Itens(){
    ItensCompra pol;
    int id_vendas;
    bool imprimeCPF = true;
    printf("Insira o ID da compra: ");
    scanf(" %d", &id_vendas);
    FILE *arqv;
    arqv = fopen("../ItensCompra.dat", "rb");
    if(arqv != NULL)
    {
        Limpar_Tela();
        printf(" ID da Venda: %d \n", id_vendas);
        while(fread(&pol, sizeof(ItensCompra), 1, arqv) != 0)
        {
            if(id_vendas == pol.id_venda)
            {
                if(imprimeCPF)
                {
                    printf(" CPF do Cliente: %s \n\n", pol.CPF);
                    imprimeCPF = false;
                }
                printf(" ID do Produto: %d \n Quantidade: %d \n", pol.id_prod, pol.quant);
                printf(" Valor Unidade: %.2f \n Valor Total: %.2f \n\n", pol.valor_uni, pol.valor_total);
            }
        }
    }
    fclose(arqv);
    Sair_Menu();
}