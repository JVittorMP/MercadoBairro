#include "Funcoes.h"
#include "Registros.h"

// Função 7
void Listar_Pont_1000(){
    Clientes aux;
    FILE *arqv;
    arqv = fopen("../Clientes.dat", "rb");
    printf("Clientes com mais de 1000 pontos: \n\n");
    if(arqv != NULL)
    {
        printf("| Nome \t| Pontuação \t|");
        while(1)
        {
            fread(&aux, sizeof(Clientes), 1, arqv);
            if(feof(arqv))
                break;
            if(aux.pontos > 1000)
                printf("| %s \t| %d \t|", aux.nome, aux.pontos);
        }
    }
    else
        printf("Falha na Abertura do Arquivo");
    fclose(arqv);
}

// Função 8
void Baixo_Estoque(){
    Produto aux;
    FILE *arqv;
    arqv = fopen("../Produtos.dat", "rb");
    if(arqv != NULL)
    {
        printf("| Id \t| Setor \t| Nome \t| Preço \t| Validade \t| Estoque \t|");
        while(1)
        {
            fread(&aux, sizeof(Produto), 1, arqv);
            if(feof(arqv))
                break;
            if(aux.estoque < 5)
            {
                printf("| %d \t| %s \t| %s \t| %.2lf \t", aux.id, aux.setor, aux.nome, aux.preco);
                printf("| %d/%d/%d \t| %d \t|", aux.validade.dia, aux.validade.mes, aux.validade.ano, aux.estoque);
            }
        }
    }
    else
        printf("Falha na Abertura do Arquivo");
    fclose(arqv);
}

// Função 9
void Clientes_18_25(){
    Clientes aux;
    int total = 0;
    FILE *arqv;
    arqv = fopen("../Clientes.dat", "rb");
    printf("Clientes com mais de 1000 pontos: \n\n");
    if(arqv != NULL)
    {
        printf("| Nome \t| Idade \t|");
        while(1)
        {
            fread(&aux, sizeof(Clientes), 1, arqv);
            if(feof(arqv))
                break;
            if(aux.idade > 17 && aux.idade < 26)
            {
                printf("| %s \t| %d \t|", aux.nome, aux.idade);
                total++;
            }
        }
    }
    else
        printf("Falha na Abertura do Arquivo");
    fclose(arqv);
    printf("Total de clientes entre 18 e 25 anos: %d", total);
}

// Função 10
void Estoque_Setor(){
    int valor;
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
                printf("| %d \t| %s \t| %s \t| %.2lf \t", aux.id, aux.setor, aux.nome, aux.preco);
                printf("| %d/%d/%d \t| %d \t|", aux.validade.dia, aux.validade.mes, aux.validade.ano, aux.estoque);
            }
        }
    }
}