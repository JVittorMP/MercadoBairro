#include "Funcoes.h"
#include "Menus.h"
#include "Registros.h"

// Função 3 - Cadastrar e Alterar Dados de Clientes
void Cadastrar_Clientes(){
    Clientes NovoCliente;
    FILE *arqv;
    arqv = fopen("../Clientes.dat", "ab");
    printf("Insira as informações do cliente: \n\n");
    if(arqv != NULL)
    {
        printf("CPF: ");
        scanf(" %[^\n]s", NovoCliente.CPF);
        printf("Nome: ");
        scanf(" %[^\n]s", NovoCliente.nome);
        printf("Data de Nascimento (dia/mês/ano): ");
        scanf(" %d/%d/%d", &NovoCliente.nascimento.dia, &NovoCliente.nascimento.mes, &NovoCliente.nascimento.ano);
        printf("Idade: ");
        scanf(" %d", &NovoCliente.idade);
        printf("Endereço: ");
        scanf(" %[^\n]s", NovoCliente.endereco);
        printf("Cidade: ");
        scanf(" %[^\n]s", NovoCliente.cidade);
        printf("Estado (UF): ");
        scanf(" %[^\n]s", NovoCliente.estado);
        printf("Pontos: ");
        scanf(" %d", &NovoCliente.pontos);
    }
    fwrite(&NovoCliente, sizeof(Clientes), 1, arqv);
    fclose(arqv);
    Limpar_Tela();
    Menu_Principal();
}

void Alterar_Clientes(){
    int pos; // Variável para guardar a posição
    char CPF_cliente[13];
    printf("Insira o CPF do cliente que deseja alterar: ");
    scanf(" %[^\n]", &CPF_cliente);
    if(ProcuraCliente(CPF_cliente)); // Verifica se o cliente existe
    {
        Clientes alt;
        pos = Identificar_Cliente(); // Identifica a posição do cliente no arquivo
    }
    else
        printf("Cliente não encontrado!");
}

int Identificar_Cliente(char CPF[13]){
    FILE *arqv;
    Clientes Ident;
    int aux;
    arqv = fopen("../Clientes.dat", "rb");
    if(arqv !=  NULL)
    {
        while(!feof(arqv))
        {
            fread(&Ident, sizeof(Clientes), 1, arqv);
            if(Ident.CPF == CPF)
            {
                fclose(arqv);
                return aux; // Devolve a Posição
            }
            aux++;
        }
    }
}

// Função 5
float ValorTotalDasVendas (char cpf[13]) {
    FILE *venda;
    Vendas info;
    float total = 0;

    venda = fopen("../Vendas.dat", "rb");
    if (venda == NULL)
        printf("Erro na abertura do arquivo de vendas");
    else {
        while (fread(&info, sizeof(Vendas), 1, venda) != 0) {
            if (strcmp(info.CPF, cpf) == 0)
                total += info.valor_total;
        }
    }
    return (total);
}
