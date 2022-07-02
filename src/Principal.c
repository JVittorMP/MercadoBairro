#include <windows.h>
#include "Funcoes.h"
#include "Registros.h"
#include "Menus.h"

int main(){
    SetConsoleOutputCP(65001);
    Menu_Principal();

    // Teste de Impressão (Pode ser utilizado para imprimir os registros em outras funções)
    /*
    Produto *pol;
    pol = (Produto *) malloc(sizeof(Produto) * 2);
    char confirm;
    bool sair = false;
    FILE *arqv;
    arqv = fopen("../Produtos.dat","rb");
    if(arqv != NULL){
        fread(pol, sizeof(Produto), 2, arqv);
        for(int c = 0; c < 2; c++){
            printf(" ID: %d \n Setor: %s \n Nome: %s \n Preço: %.2lf \n", pol[c].id, pol[c].setor, pol[c].nome, pol[c].preco);
            printf(" Validade: %d/%d/%d \n Estoque: %d \n\n", pol[c].validade.dia, pol[c].validade.mes, pol[c].validade.ano, pol[c].estoque);
        }
        while(!sair){
            printf("Deseja encerrar o programa? (S/N) ");
            scanf(" %c", &confirm);
            if(confirm == 's' || confirm == 'S')
                sair = true;
        }
        fclose(arqv);
    }
    */
}
