#ifndef AV2_FUNCAO4_H
#define AV2_FUNCAO4_H

// Bibliotecas Básicas
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Funções de Utilidade
void Limpar_Tela();
void Separar_Tela();
void Sair_Menu();

void NovaVenda();
bool ProcuraCliente();
int DefinirIdentificacaoDaVenda();
void AdicionarItemCompra();
void MostrarProduto();
void ReduzirEstoque();
void ListarVendas();
void CPFdoCliente();
float ValorTotalDasVendas();

// Funções de Clientes
void Cadastrar_Clientes();
void Alterar_Clientes();
void Listar_Pont_1000();
void Clientes_18_25();
int Identificar_Cliente();

// Funções de Produtos
void Incluir_Produtos();
void Alterar_Produto();
void Troca();
int Identificar_Produto();
void Baixo_Estoque();
void Estoque_Setor();

// Funções de Exibição
void Exib_Produtos();
void Exib_Clientes();
void Exib_Vendas();

#endif
