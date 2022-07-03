#include "Funcoes.h"
#include "Registros.h"

void Exib_Produtos(){
    Produto pol;
    FILE *arqv;
    arqv = fopen("../Produtos.dat","rb");
    if(arqv != NULL)
    {
        printf("\t| ID \t| Setor \t| Nome \t| Preço \t| Validade \t| Estoque \t| \n");
        while(!feof(arqv))
        {
            fread(&pol, sizeof(Produto), 1, arqv);
            printf("\t| %d \t| %s \t| %s \t| %.2lf \t", pol.id, pol.setor, pol.nome, pol.preco);
            printf("| %d/%d/%d \t| %d \n", pol.validade.dia, pol.validade.mes, pol.validade.ano, pol.estoque);
        }
    }
    fclose(arqv);
    Sair_Menu();
}

void Exib_Clientes(){
    Clientes pol;
    FILE *arqv;
    arqv = fopen("../Clientes.dat","rb");
    if(arqv != NULL)
    {
        printf("\t| CPF \t| Nome \t| Data de Nascimento \t| idade \t| Endereço \t| Cidade \t| Estado \t| Pontos \t|");
        while(!feof(arqv))
        {
            fread(&pol, sizeof(Clientes), 1, arqv);
            printf("\t| %s \t| %s \t| %d/%d/%d \t", pol.CPF, pol.nome, pol.nascimento.dia, pol.nascimento.mes, pol.nascimento.ano);
            printf("| %d \t| %s \t| %s \t| %s \t| %d \t|", pol.idade, pol.endereco, pol.cidade, pol.estado, pol.pontos);
        }
    }
    fclose(arqv);
    Sair_Menu();
}

void Exib_Vendas(){
    Vendas pol;
    FILE *arqv;
    arqv = fopen("../Vendas.dat","rb");
    if(arqv != NULL)
    {
        printf("\t| ID \t| CPF do Cliente \t| Data da Compra \t| Valor Total \t| Quantidade de Produtos \t|");
        while(!feof(arqv))
        {
            fread(&pol, sizeof(Vendas), 2, arqv);
            printf("\t| %d \t| %s \t| %d/%d/%d \t", pol.id_vendas, pol.CPF, pol.compra.dia, pol.compra.mes, pol.compra.ano);
            printf("| %.2f \t| %d \t|", pol.valor_total, pol.quant_prod);
        }
    }
    fclose(arqv);
    Sair_Menu();
}