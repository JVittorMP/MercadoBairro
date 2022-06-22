#include <stdio.h>
#include "Menus.h"
#include "Registros.h"

void Menu_Principal(){
    int menu;

    // Menu Inicial
    printf(" 1. Vendas \n 2. Clientes \n 3. Produtos \n 9. Sair \n\n");
    printf("Insira a opção desejada: ");
    scanf(" %d \n", &menu);

    switch(menu){
        case 1: // Menu Vendas
            Menu_Vendas();
            break;
        case 2: // Menu Clientes
            Menu_Clientes();
            break;
        case 3: // Menu Produtos
            Menu_Produto();
            break;
        case 9: // Saída do Menu
            break;
        default:
            printf("Comando Inválido!");
    }
}

void Menu_Vendas(){
    int menu;
    printf(" 1. Nova Venda \n Listar Venda do Cliente \n 9. Sair \n\n");
    scanf(" %d \n", &menu);
    switch(menu){
        case 1:
            break;
        case 2:
            break;
        case 9:
            Menu_Principal();
            break;
    }
}

void Menu_Clientes(){
    int menu;
    printf(" 1. Cadastrar Novo Cliente \n 2. Atualizar Pontuação \n");
    printf("3. Atualizar Cliente \n 4. Listar Clientes entre 18 e 25 anos \n");
    printf(" 5. Listar Clientes Acima de 1000 Pontos \n 9. Sair");
    scanf(" %d \n", &menu);
    switch(menu){
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 9:
            Menu_Principal();
            break;
    }
}

void Menu_Produto(){
    int menu;
    printf(" 1. Cadastrar Novo produto \n 2. Atualizar Informações \n");
    printf("3. Estoque por Setor \n 4. Produtos com Estoque Baixo \n 9. Sair");
    scanf(" %d \n", &menu);
    switch(menu){
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 9:
            Menu_Principal();
            break;
    }
}
