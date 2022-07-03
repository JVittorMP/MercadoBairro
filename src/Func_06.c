#include "Funcoes.h"
#include "Registros.h"

void ListarVendas() {
    FILE *venda;
    Vendas compra;
    int opcao, cont = 0;
    char cpf[13], nome[30];

    printf (" 1. CPF \n 2. Nome \n\n Deseja acessar por: ");
    scanf ("%d", &opcao);
    Limpar_Tela();
    switch (opcao)
    {
        case 1:
            printf ("Digite CPF: ");
            scanf (" %[^\n]s", cpf);
            break;
        case 2:
            printf ("Digite nome: ");
            scanf (" %[^\n]s", nome);
            CPFdoCliente (nome, cpf);
            break;
        default:
            printf ("Opção inválida!\n\n");
            break;
    }
    Separar_Tela();
    if (strlen(cpf) < 13)
        printf ("Não foi possível acessar lista.\n\n");
    else {
        venda = fopen ("../Vendas.dat", "rb");
        if (venda == NULL)
            printf ("Erro na bertura do arquivo de vendas.\n\n");
        else {
            while (fread(&compra, sizeof(Vendas), 1, venda) != 0) {
                if (strcmp(compra.CPF, cpf) == 0) {
                    printf ("Data: %d/%d/%d\n", compra.compra.dia, compra.compra.mes, compra.compra.ano);
                    printf ("Valor: %f\n", compra.valor_total);
                    printf ("Quantidade de produtos: %d\n", compra.quant_prod);
                    cont++;
                    Separar_Tela();
                }
            }
            fclose(venda);
            Sair_Menu();
            if (cont == 0)
                printf ("Cliente não encontrado.\n\n");
        }
    }
}

void CPFdoCliente (char nome[30], char *cpf[13]) {
    FILE *cliente;
    Clientes info;
    bool encontrado = false;

    cliente = fopen ("../Clientes.dat", "rb");
    if (cliente == NULL)
        printf ("Erro na abertura do arquuivo de clientes.\n\n");
    else {
        while ((!encontrado) && (fread(&info, sizeof(Clientes), 1, cliente) != 0)) {
            if (strcmp(info.nome, nome) == 0)
                encontrado = true;
        }
    }
    fclose(cliente);
    strcpy(cpf, info.CPF);
}
