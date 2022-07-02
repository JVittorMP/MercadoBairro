#include <stdio.h>
#include <stdlib.h>
#include "Funcoes.h"
#include "Menus.h"
#include "Registros.h"

void Menu_Principal(){
    int menu;
    printf("Menu Principal \n\n");
    printf(" 1. Vendas \n 2. Clientes \n 3. Produtos \n 9. Sair \n\n");
    printf("Insira a opção desejada: ");
    scanf(" %d", &menu);
    Limpar_Tela();
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
    printf("Menu Vendas \n\n");
    printf(" 1. Nova Venda \n 2. Listar Venda do Cliente \n 9. Sair \n\n");
    printf("Insira a opção desejada: ");
    scanf(" %d", &menu);
    Limpar_Tela();
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
    printf("Menu Clientes \n\n");
    printf(" 1. Cadastrar Novo Cliente \n 2. Atualizar Pontuação \n");
    printf(" 3. Atualizar Cliente \n 4. Listar Clientes entre 18 e 25 anos \n");
    printf(" 5. Listar Clientes Acima de 1000 Pontos \n 9. Sair \n\n");
    printf("Insira a opção desejada: ");
    scanf(" %d", &menu);
    Limpar_Tela();
    switch(menu){
        case 1:
            Cadastrar_Clientes();
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
    printf("Menu Produtos \n\n");
    printf(" 1. Cadastrar Novo produto \n 2. Atualizar Informações \n");
    printf(" 3. Estoque por Setor \n 4. Produtos com Estoque Baixo \n 9. Sair \n\n");
    printf("Insira a opção desejada: ");
    scanf(" %d", &menu);
    Limpar_Tela();
    switch(menu){
        case 1:
            Incluir_Produtos();
            break;
        case 2:
            Alterar_Produto();
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
