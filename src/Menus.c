#include "Funcoes.h"
#include "Menus.h"
#include "Registros.h"

void Menu_Principal(){
    int menu;
    printf("Menu Principal \n\n");
    printf(" 1. Vendas \n 2. Clientes \n 3. Produtos \n");
    printf(" 4. Exibição \n 9. Sair \n\n");
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
        case 4: // Menu Exibição
            Menu_Exib();
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
        case 1: // Registrar Nova Venda
            break;
        case 2: // Listar a Venda do Cliente
            break;
        case 9: // Retornar para o Menu Principal
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
        case 1: // Cadastro dos Clientes
            Cadastrar_Clientes();
            break;
        case 2: // Atualizar Pontuação do Clientes
            break;
        case 3: // Atualizar Informações dos Clientes
            break;
        case 4: // Clientes Entre 18 e 25 Anos
            Clientes_18_25();
            break;
        case 5: // Clientes Acima de 1000 Pontos
            Listar_Clientes();
            break;
        case 9: // Retornar para o Menu Principal
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
        case 1: // Cadastrar Novos Produtos
            Incluir_Produtos();
            break;
        case 2: // Alterar Informações dos Produtos
            Alterar_Produto();
            break;
        case 3: // Mostrar Estoque por Setor
            Estoque_Setor();
            break;
        case 4: // Mostrar Produtos com Estoque Baixo
            Baixo_Estoque();
            break;
        case 9: // Retornar para o Menu Principal
            Menu_Principal();
            break;
    }
}

void Menu_Exib(){
    int menu;
    printf("Menu de Exibição \n\n");
    printf(" 1. Exibir Produtos \n 2. Exibir Clientes \n");
    printf(" 3. Exibir Vendas \n 9. Sair \n\n");
    printf("Insira a opção desejada: ");
    scanf(" %d", &menu);
    Limpar_Tela();
    switch(menu){
        case 1: // Exibir Produtos
            Exib_Produtos();
            break;
        case 2: // Exibir Clientes
            Exib_Clientes();
            break;
        case 3: // Exibir Vendas
            Exib_Vendas();
            break;
        case 9:
            Menu_Principal();
            break;
    }
}