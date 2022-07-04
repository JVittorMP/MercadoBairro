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
    Clientes alt;
    FILE *arqv;
    printf("Insira o CPF do cliente que deseja alterar: ");
    scanf(" %[^\n]", &CPF_cliente);
    pos = Identificar_Cliente(CPF_cliente); // Identifica a posição do cliente no arquivo
    if(ProcuraCliente(CPF_cliente) && pos == 0) // Verifica se o cliente existe
    {
        arqv = fopen("../Cliente.dat", "r+b");
        fseek(arqv, sizeof(Clientes)*(pos-1), SEEK_SET);
        fread(&alt, sizeof(Produto), 1, arqv);
        Troca_Cliente(&alt); // Seleção da Informação a ser alterada
        fseek(arqv, sizeof(Produto)*(pos-1), SEEK_SET);
        fwrite(&alt, sizeof(Produto), 1, arqv);
        fclose(arqv);
    }
    else printf("Cliente não encontrado!");
    Limpar_Tela();
    Menu_Principal();
}

int Identificar_Cliente(char CPF[13]){
    FILE *arqv;
    Clientes Ident;
    int aux = 1;
    arqv = fopen("../Clientes.dat", "rb");
    if(arqv !=  NULL)
    {
        while(!feof(arqv))
        {
            fread(&Ident, sizeof(Clientes), 1, arqv);
            if(strcmp(Ident.CPF, CPF) == 0)
            {
                fclose(arqv);
                return aux; // Devolve a Posição
            }
            aux++;
        }
    }
    return 0;
}

void Troca_Cliente(Clientes *pont) {
    int aux;
    printf(" 1. CPF \n 2. Nome \n 3. Data de Nascimento \n");
    printf(" 4. Idade \n 5. Endereço \n 6. Cidade \n");
    printf(" 7. Estado \n 8. Pontuação \n 9. Sair \n\n");
    printf("Qual informação deseja alterar? ");
    scanf(" %d", &aux);
    Limpar_Tela();
    switch (aux) {
        case 1:
            printf("Insira o novo CPF: ");
            scanf(" %[^\n]s", &pont->CPF);
            break;
        case 2:
            printf("Insira o novo nome: ");
            scanf(" %[^\n]s", &pont->nome);
            break;
        case 3:
            printf("Insira a nova data de nascimento (dia/mês/ano): ");
            scanf(" %d/%d/%d", &pont->nascimento.dia, &pont->nascimento.mes, &pont->nascimento.ano);
            break;
        case 4:
            printf("Insira a nova idade: ");
            scanf(" %d", &pont->idade);
            break;
        case 5:
            printf("Insira o novo endereço: ");
            scanf(" %[^\n]s", &pont->endereco);
            break;
        case 6:
            printf("Insira a nova cidade: ");
            scanf(" %d", &pont->cidade);
            break;
        case 7:
            printf("Insira o novo estado: ");
            scanf(" %[^\n]s", &pont->estado);
        case 8:
            printf("Insira a nova Pontuação: ");
            scanf(" %d", &pont->pontos);
        case 9:
            break;
    }
}

// Função 5
float ValorTotal_Vendas (char cpf[13]){
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
