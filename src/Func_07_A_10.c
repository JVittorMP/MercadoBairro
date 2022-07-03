#include "Funcoes.h"
#include "Registros.h"
#include "Menus.h"
#include <math.h>

// Função 7
void Listar_Pont_1000(){
    Clientes aux;
    FILE *arqv;
    arqv = fopen("../Clientes.dat", "rb");
    printf("Clientes com mais de 1000 pontos: \n\n");
    if(arqv != NULL)
    {
        while(1)
        {
            fread(&aux, sizeof(Clientes), 1, arqv);
            if(feof(arqv))
                break;
            if(aux.pontos > 1000)
            {
                printf("Nome: %s \n", aux.nome);
                printf("Pontuação: %d \n\n", aux.pontos);
            }
        }
    }
    else
        printf("Falha na Abertura do Arquivo");
    fclose(arqv);
    Sair_Menu();
}

// Atualizar Pontuação
void Atualizar_Pont(){
    char CPF_cliente[13];
    int pos;
    float total;
    Clientes NovoCliente;
    printf("Insira o CPF do cliente cuja pontuação deseja atualizar: ");
    scanf(" %[^\n]s", CPF_cliente);
    if(ProcuraCliente(CPF_cliente)) // Verifica se o cliente existe
    {
        total = ValorTotal_Vendas(CPF_cliente);
        pos = Identificar_Cliente(CPF_cliente);
        FILE *arqv;
        arqv = fopen("../Clientes.dat", "r+b");
        fseek(arqv, sizeof(Clientes)*(pos-1), SEEK_SET);
        fread(&NovoCliente, sizeof(Clientes), 1, arqv);
        NovoCliente.pontos = (int) total;
        fseek(arqv, sizeof(Produto)*(pos-1), SEEK_SET);
        fwrite(&NovoCliente, sizeof(Clientes), 1, arqv);
        fclose(arqv);
    }
    Limpar_Tela();
    Menu_Principal();
}

// Função 8
void Baixo_Estoque(){
    Produto aux;
    FILE *arqv;
    arqv = fopen("../Produtos.dat", "rb");
    if(arqv != NULL)
    {
        while(1)
        {
            fread(&aux, sizeof(Produto), 1, arqv);
            if(feof(arqv))
                break;
            if(aux.estoque < 5)
            {
                printf("Nome: %s \n", aux.nome);
                printf("Estoque: %d \n\n", aux.estoque);
            }
        }
    }
    else
        printf("Falha na Abertura do Arquivo");
    fclose(arqv);
    Sair_Menu();
}

// Função 9
void Clientes_18_25(){
    Clientes aux;
    int total = 0;
    FILE *arqv;
    arqv = fopen("../Clientes.dat", "rb");
    printf("Clientes com idade entre 18 e 25 anos: \n\n");
    if(arqv != NULL)
    {
        while(1)
        {
            fread(&aux, sizeof(Clientes), 1, arqv);
            if(feof(arqv))
                break;
            if(aux.idade > 17 && aux.idade < 26)
            {
                printf("Nome: %s \n", aux.nome);
                printf("Idade: %d \n\n", aux.idade);
                total++;
            }
        }
    }
    else
        printf("Falha na Abertura do Arquivo");
    fclose(arqv);
    printf("Total de clientes entre 18 e 25 anos: %d \n", total);
    Sair_Menu();
}

// Função 10
void Estoque_Setor(){
    int valor;
    int total;
    char setor[20];
    Produto aux;
    FILE *arqv;
    arqv = fopen("../Produtos.dat", "rb");
    if(arqv != NULL)
    {
        // Essa parte serve pra evitar que o usuário digite a enntrada errada
        printf(" 1. Higiene e Limpeza \n 2. Bebidas \n");
        printf(" 3. Frios \n 4. Padaria \n 5. Açougue \n\n");
        printf("Selecione o setor desejado: ");
        scanf(" %d", &valor);
        switch(valor){
            case 1:
                strcpy(setor, "Higiene e Limpeza");
                break;
            case 2:
                strcpy(setor, "Bebidas");
                break;
            case 3:
                strcpy(setor, "Frios");
                break;
            case 4:
                strcpy(setor, "Padaria");
                break;
            case 5:
                strcpy(setor, "Açougue");
                break;
        }
        Limpar_Tela();
        while(1)
        {
            fread(&aux, sizeof(Produto), 1, arqv);
            if(feof(arqv))
                break;
            if(strcmp(aux.setor, setor) == 0)
            {
                printf("%s = %d \n", aux.nome, aux.estoque);
                total += aux.estoque;
            }
        }
    }
    printf("Estoque do Setor: %d itens \n\n", total);
    Sair_Menu();
}