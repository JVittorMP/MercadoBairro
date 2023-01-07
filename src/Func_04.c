#include "Funcoes.h"
#include "Registros.h"

void NovaVenda(){
    FILE *venda;
    Vendas novo;
    float valor;
    char finalizar_compra = 'n';
    bool itemDisp;

    // Função irá procurar o cliente no arquivo.
    // Se o cliente não existir, haverá um desvio para registra-lo.
    printf("CPF: ");
    scanf(" %[^\n]s", novo.CPF);
    if (!ProcuraCliente (novo.CPF)) {
        Limpar_Tela();
        printf("Novo Cadastro \n\n");
        Cadastrar_Clientes();
        Limpar_Tela ();
    }

    // Procura a identificação da última venda para registrar o novo.
    novo.id_vendas = DefinirIdentificacaoDaVenda();

    printf ("Data Da Venda: ");
    scanf (" %d/%d/%d", &novo.compra.dia, &novo.compra.mes, &novo.compra.ano);
    // Valores iniciais antes de qualquer compra.
    Separar_Tela ();
    novo.valor_total = 0;
    novo.quant_prod = 0;

    while ((finalizar_compra != 's') && (finalizar_compra != 'S')) {
        // Adiciona mais um registro no arquivo ItensCompra e muda por referência a disponibilidade do produto.
        // Dentro desta função há outra função que irá mostrar as informações do produto.
        // Caso o produto esteja disponível, informações serão adicionadas no registro da venda.
        AdicionarItemCompra (novo.id_vendas, novo.CPF, &itemDisp, &valor);
        if (itemDisp) {
            novo.quant_prod++;
            novo.valor_total += valor;
        }
        // O loop continuará até que a compra seja finalizada.
        printf ("Deseja finalizar compra? (S/N)  ");
        scanf (" %c", &finalizar_compra);
        Separar_Tela ();
    }
    // Por fim, a adição de mais um registro Venda ao arquivo, caso haja compra
    if (novo.quant_prod > 0) {
        venda = fopen ("../Vendas.dat", "ab");
        fwrite (&novo, sizeof(struct Vendas), 1, venda);
        fclose(venda);
        printf ("Compra feita com successo! \n\n");
        printf ("O valor total: %.2f\n", novo.valor_total);
    }
    else
        printf("Ocorreu um erro ou a compra foi cancelada.");
    Separar_Tela ();
    Sair_Menu();
}

bool ProcuraCliente(char cpf[13]){
    FILE *cliente;
    Clientes info;
    bool existe = false;

    cliente = fopen ("../Clientes.dat", "rb");
    if (cliente == NULL)
        printf ("Erro ao abrir o arquivo dos clientes.");
    else {
        //Procura o cliente no arquivo.
        while ((!existe) && (fread(&info, sizeof(Clientes), 1, cliente) != 0)) {
            if (strcmp(info.CPF, cpf) == 0)
                existe = true;
        }
    }
    fclose(cliente);
    return (existe);
}

int DefinirIdentificacaoDaVenda(){
    FILE *venda;
    Vendas ultima;
    int id;

    venda = fopen ("../Vendas.dat", "rb");
    // Se o arquivo não existe, será retornado o valor 0.
    if (venda == NULL)
    {
        Limpar_Tela();
        printf("Erro na abertura do arquivo de vendas \n\n");
    }
    // Caso contrário retornará um valor acima da última venda.
    else {
        while (fread(&ultima, sizeof(Vendas), 1, venda) != 0)
            id = ultima.id_vendas;
        fclose(venda);
    }
    while (id < 0) // Caso seja a primeira venda
        id++;
    return (id + 1);
}

void AdicionarItemCompra(int cod, char cpf[13], bool *compraValida, float *preco){
    FILE *compra;
    ItensCompra item;
    int estoque;

    printf ("Código do produto: ");
    scanf (" %d", &item.id_prod);
    printf ("Quantidade de itens do produto: ");
    scanf (" %d", &item.quant);

    // Mostra as informações do produto e sua disponibilidade no estoque.
    MostrarProduto (item.id_prod, &estoque, &item.valor_uni);

    if (estoque < item.quant) {
        printf ("Não há quantidade disponível do produto.");
        *compraValida = false;
        *preco = 0;
    }
    else {
        strcpy (item.CPF, cpf);
        item.id_venda = cod;
        item.valor_total = item.valor_uni * item.quant;
        compra = fopen ("../ItensCompra.dat", "ab");
        fwrite (&item, sizeof(struct ItensCompra), 1, compra);
        fclose(compra);
        ReduzirEstoque (item.id_prod, item.quant);
        *compraValida = true;
        *preco = item.valor_total;
        printf ("Registro da compra do item feito com sucesso!\n\n");
    }
}

void MostrarProduto(int cod, int *estoque, float *valor){
    FILE *produto;
    bool encontrado = false;
    Produto info;

    produto = fopen ("../Produtos.dat","rb");
    *estoque = 0;
    *valor = 0;
    if (produto == NULL)
        printf ("Erro ao abrir o arquivo dos produtos\n\n");
    else {
        // Encontrar o produto no arquivo
        while ((!encontrado) && (fread(&info, sizeof(Produto), 1, produto) != 0)) {
            if (info.id == cod)
                encontrado = true;
        }
        // Irá mostrar as informações do produto se for encontrado.
        if (encontrado) {
            printf ("\nProduto: %s", info.nome);
            printf ("\nValor: %.2f", info.preco);
            printf ("\nEstoque: %d\n\n", info.estoque);
            *estoque = info.estoque;
            *valor = info.preco;
        }
        else
            printf ("Não foi encontrado o produto!\n\n");
    }
}

void ReduzirEstoque(int cod, int red){
    FILE *prod;
    Produto info;
    bool encontrado = false;
    int cont = 0;

    prod = fopen("../Produtos.dat", "r+b");
    if (prod == NULL)
        printf ("Erro de abertura do arquivo \n\n");
    else {
        while ((!encontrado) && (fread(&info, sizeof(Produto), 1, prod) != 0)) {
            if (info.id == cod)
                encontrado = true;
            else
                cont++;
        }
        if (encontrado) {
            info.estoque -= red;
            fseek (prod, sizeof(Produto)*cont, SEEK_SET);
            fwrite (&info, sizeof(Produto), 1, prod);
        }
        else
            printf ("Produto não encontrado.\n\n");
        fclose(prod);
    }
}
