#include <stdio.h>
#include <string.h>
#include "Funcoes.h"
#include "Registros.h"

float ValorTotalDasVendas (char cpf[13]) {
    FILE *venda;
    Vendas info;
    float total = 0;

    venda = fopen("Vendas.dat", "rb");
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
