#ifndef __Registros_H__
#define __Registros_H__

// Registro de datas
typedef struct Data{
    int dia;
    int mes;
    int ano;
} Data;

// Registro dos Produtos
typedef struct Produto{
    int id;
    char setor[20];
    char nome[50];
    double preco;
    Data validade;
    int estoque;
} Produto;

// Registro dos Clientes
typedef struct Clientes{
    char CPF[13];
    char nome[50];
    Data nascimento;
    int idade;
    char endereco[50];
    char cidade[50];
    char estado[2];
    int pontos;
} Clientes;

// Registro de Vendas
typedef struct Vendas{
    int id_vendas;
    char CPF[13];
    Data compra;
    float valor_total;
    int quant_prod;
} Vendas;

// Registro de ItensCompra
typedef struct ItensCompra{
    int id_venda;
    char CPF[13];
    int id_prod;
    int quant;
    float valor_uni;
    float valor_total;
} ItensCompra;

#endif
