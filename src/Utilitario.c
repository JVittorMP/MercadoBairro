#include "Funcoes.h"
#include "Menus.h"

void Limpar_Tela(){
    system("cls");
}

void Separar_Tela(){
    printf ("\n#####################################################\n\n");
}

void Sair_Menu(){
    bool sair = false;
    char confirm;
    while(!sair){
        printf("Deseja retornar ao menu principal? (S/N): ");
        scanf(" %c", &confirm);
        if(confirm == 's' || confirm == 'S')
            sair = true;
        printf("\n");
    }
    Menu_Principal();
}