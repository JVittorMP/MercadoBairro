#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "funcoes.h"
#include "Registros.h"

void ListarVendas () {
    FILE *venda;
    Vendas compra;
    int opcao;
    char nome[30], cpf[13] = NULL;

    printf ("Deseja acessar por:\n1.CPF\n2.Nome");
    scanf ("%d", &opcao);
    switch (opcao)
    {
    case 1:
        printf ("Digite CPF: ");
        scanf ("%[^\n]s", cpf);
        break;
    case 2:
        printf ("Digite nome: ");
        scanf (" %[^\n]s", nome);
        CPFdoCliente(nome, &cpf);
        break;
    default:
        printf ("Opção inválida!\n\n");
        break;
    }
    //SEPARAR TELA
    if (cpf == NULL)
        printf ("Não foi possívle acessar lista.\n\n");
    else {
        venda = fopen ("Vendas.dat", "rb");
        if (venda == NULL)
            printf ("Erro na bertura do arquivo de vendas.");
        else {
            while (fread(&compra, sizeof(Vendas), 1, venda) != 0) {
                if (strcmp(compra.CPF, cpf) == 0) {
                    printf ("Data: %d / %d / %d\n", compra.compra.dia, compra.compra.mes, compra.compra.ano);
                    printf ("Valor: %f\n", compra.valor_total);
                    printf ("Quantidade de produtos: %d\n\n", compra.quant_prod);
                    //SEPARAR TELA
                }
            }
            fclose(venda);
        }
    }
}

void CPFdoCliente (char nome[30], char *cpf[13]) {
    FILE *cliente;
    Clientes info = NULL;
    bool encontrado = false;

    cliente = fopen ("Clientes.dat", "rb");
    if (cliente == NULL)
        printf ("Erro na abertura do arquuivo de clientes\n\n");
    else {
        while ((!encontrado) && (fread(&info, sizeof(Clientes), 1, cliente) != 0)) {
            if (strcmp(info.nome, nome) == 0)
                encontrado = true;
        }
    }
    fclose(cliente);
    strcpy(*cpf, info.CPF);
}
