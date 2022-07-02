#ifndef AV2_FUNCAO4_H
#define AV2_FUNCAO4_H

#include <stdbool.h>
// Funções de Utilidade
void Limpar_Tela();

void NovaVenda();
bool ProcuraCliente();
int DefinirIdentificacaoDaVenda();
void AdicionarItemCompra();
void MostrarProduto();
void ReduzirEstoque();
void ListarVendas();
char CPFDoCliente();
float ValorTotalDasVendas();

// Funções de Clientes
void Cadastrar_Clientes();

// Funções de Produtos
void Incluir_Produtos();
void Alterar_Produto();
void Troca();
int Identificar_Produto();

#endif
