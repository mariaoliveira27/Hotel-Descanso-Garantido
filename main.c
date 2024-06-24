#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

enum cargo {
    RECEPCIONISTA,
    AUXILIAR_DE_LIMPEZA,
    GARCOM,
    GERENTE
};

enum statusQuarto {
    LIVRE,
    OCUPADO
};

struct funcionario {
    char codigo[6];  // Ajustado para 6 caracteres
    char nome1[100];
    char telefone[20];
    enum cargo cargo;
    float salario;
};

struct cliente {
    char codigoC[6];
    char nomeC[100];
    char endereco[100];
    char telefoneC[20];
};

struct quarto {
    int numeroQuarto;
    int quantidadeDeHospede;
    float valorDiaria;
    enum statusQuarto statusQuarto;
};

struct estadia {
    char codigoE[7]; // Ajustado para 7 caracteres
    char codigoC[6];
    int numeroQuarto;
    int diaEntrada, mesEntrada, anoEntrada;
    int diaSaida, mesSaida, anoSaida;
    int diarias;
};

// Function prototypes
void gerarCodigo(char *codigo, int tamanho);
struct cliente cadastroCliente();
struct funcionario cadastroFuncionario();
void exibirCliente(struct cliente clie);
void exibirFuncionario(struct funcionario func);
void inicializarQuartos(struct quarto quartos[]);
void cadastrarEstadia(struct estadia estadias[], int *totalEstadias, struct cliente clientes[], int totalClientes, struct quarto quartos[], int totalQuartos);
void exibirEstadias(struct estadia estadias[], int totalEstadias);
void verificarDisponibilidade(struct quarto quartos[], int totalQuartos);
void gravarEstadiasClientesFuncionariosEmArquivo(struct estadia estadias[], int totalEstadias, struct cliente clientes[], int totalClientes, struct funcionario funcionarios[], int totalFuncionarios);

void gerarCodigo(char *codigo, int tamanho) {
    const char caracteres[] = "0123456789";
    int numCaracteres = strlen(caracteres);
    for (int i = 0; i < tamanho - 1; i++) {
        codigo[i] = caracteres[rand() % numCaracteres];
    }
    codigo[tamanho - 1] = '\0';
}

struct cliente cadastroCliente() {
    struct cliente clie;
    printf("Insira o nome do cliente: ");
    fgets(clie.nomeC, sizeof(clie.nomeC), stdin);
    clie.nomeC[strcspn(clie.nomeC, "\n")] = '\0';

    printf("Insira o endereço: ");
    fgets(clie.endereco, sizeof(clie.endereco), stdin);
    clie.endereco[strcspn(clie.endereco, "\n")] = '\0';

    printf("Insira o número de telefone: ");
    fgets(clie.telefoneC, sizeof(clie.telefoneC), stdin);
    clie.telefoneC[strcspn(clie.telefoneC, "\n")] = '\0';

    gerarCodigo(clie.codigoC, sizeof(clie.codigoC)); // Ajustado para 6 caracteres
    printf("O código do cliente é: %s\n", clie.codigoC);

    return clie;
}

struct funcionario cadastroFuncionario() {
    struct funcionario func;
    printf("Insira o nome do funcionário: ");
    fgets(func.nome1, sizeof(func.nome1), stdin);
    func.nome1[strcspn(func.nome1, "\n")] = '\0';

    printf("Insira o telefone: ");
    fgets(func.telefone, sizeof(func.telefone), stdin);
    func.telefone[strcspn(func.telefone, "\n")] = '\0';

    char cargoStr[50];
    printf("Insira o cargo do funcionário (RECEPCIONISTA, AUXILIAR DE LIMPEZA, GARCOM, GERENTE): ");
    fgets(cargoStr, sizeof(cargoStr), stdin);
    for (int i = 0; i < strlen(cargoStr); i++) {
        cargoStr[i] = toupper(cargoStr[i]);
    }
    cargoStr[strcspn(cargoStr, "\n")] = '\0';

    if (strcmp(cargoStr, "RECEPCIONISTA") == 0) {
        func.cargo = RECEPCIONISTA;
    } else if (strcmp(cargoStr, "AUXILIAR DE LIMPEZA") == 0) { // Ajustado para "AUXILIAR DE LIMPEZA"
        func.cargo = AUXILIAR_DE_LIMPEZA;
    } else if (strcmp(cargoStr, "GARCOM") == 0) {
        func.cargo = GARCOM;
    } else if (strcmp(cargoStr, "GERENTE") == 0) {
        func.cargo = GERENTE;
    } else {
        printf("Cargo inválido!\n");
        exit(1);
    }

    printf("Insira o salário do funcionário: ");
    scanf("%f", &func.salario);
    while (getchar() != '\n');

    gerarCodigo(func.codigo, sizeof(func.codigo)); // Ajustado para 6 caracteres
    printf("O código do funcionário é: %s\n", func.codigo);

    return func;
}

void exibirCliente(struct cliente clie) {
    printf("Cliente cadastrado:\n");
    printf("Nome: %s\n", clie.nomeC);
    printf("Endereço: %s\n", clie.endereco);
    printf("Telefone: %s\n", clie.telefoneC);
    printf("Código: %s\n", clie.codigoC);
}

void exibirFuncionario(struct funcionario func) {
    printf("\nFuncionário cadastrado:\n");
    printf("Nome: %s\n", func.nome1);
    printf("Telefone: %s\n", func.telefone);
    printf("Cargo: ");
    switch (func.cargo) {
        case RECEPCIONISTA:
            printf("RECEPCIONISTA\n");
            break;
        case AUXILIAR_DE_LIMPEZA:
            printf("AUXILIAR DE LIMPEZA\n");
            break;
        case GARCOM:
            printf("GARÇOM\n");
            break;
        case GERENTE:
            printf("GERENTE\n");
            break;
        default:
            printf("Indefinido\n");
            break;
    }
    printf("Salário: %.2f\n", func.salario);
    printf("Código: %s\n", func.codigo);
}

void inicializarQuartos(struct quarto quartos[]) {
    struct quarto netuno = {1, 2, 200.90, LIVRE};
    struct quarto urano = {2, 3, 230.00, LIVRE};
    struct quarto saturno = {3, 5, 330.00, LIVRE};
    struct quarto jupiter = {4, 7, 400.00, LIVRE};
    struct quarto marte = {5, 4, 500.00, LIVRE};
    struct quarto terra = {6, 4, 550.00, LIVRE};
    struct quarto venus = {7, 2, 600.00, LIVRE};
    struct quarto mercurio = {8, 1, 750.00, LIVRE};

    quartos[0] = netuno;
    quartos[1] = urano;
    quartos[2] = saturno;
    quartos[3] = jupiter;
    quartos[4] = marte;
    quartos[5] = terra;
    quartos[6] = venus;
    quartos[7] = mercurio;
}

void cadastrarEstadia(struct estadia estadias[], int *totalEstadias, struct cliente clientes[], int totalClientes, struct quarto quartos[], int totalQuartos) {
    if (*totalEstadias >= 100) {
        printf("Limite de estadias cadastradas atingido!\n");
        return;
    }

    struct estadia estadia;
    printf("Insira o código do cliente: ");
    fgets(estadia.codigoC, sizeof(estadia.codigoC), stdin);
    estadia.codigoC[strcspn(estadia.codigoC, "\n")] = '\0';

    int encontrado = 0;
    for (int i = 0; i < totalClientes; i++) {
        if (strcmp(estadia.codigoC, clientes[i].codigoC) == 0) {
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Cliente não encontrado!\n");
        return;
    }

    printf("Insira o número do quarto: ");
    scanf("%d", &estadia.numeroQuarto);
    while (getchar() != '\n');

    encontrado = 0;
    for (int i = 0; i < totalQuartos; i++) {
        if (estadia.numeroQuarto == quartos[i].numeroQuarto && quartos[i].statusQuarto == LIVRE) {
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Quarto não encontrado ou ocupado!\n");
        return;
    }

    printf("Data de entrada (DD MM AAAA): ");
    scanf("%d %d %d", &estadia.diaEntrada, &estadia.mesEntrada, &estadia.anoEntrada);
    while (getchar() != '\n');

    printf("Data de saída (DD MM AAAA): ");
    scanf("%d %d %d", &estadia.diaSaida, &estadia.mesSaida, &estadia.anoSaida);
    while (getchar() != '\n');

    estadia.diarias = abs((estadia.diaSaida - estadia.diaEntrada) + 30 * (estadia.mesSaida - estadia.mesEntrada) + 365 * (estadia.anoSaida - estadia.anoEntrada));

    gerarCodigo(estadia.codigoE, sizeof(estadia.codigoE)); // Ajustado para 7 caracteres

    estadias[*totalEstadias] = estadia;
    (*totalEstadias)++;

    for (int i = 0; i < totalQuartos; i++) {
        if (quartos[i].numeroQuarto == estadia.numeroQuarto) {
            quartos[i].statusQuarto = OCUPADO;
            break;
        }
    }

    printf("Estadia cadastrada com sucesso!\n");
}

void exibirEstadias(struct estadia estadias[], int totalEstadias) {
    printf("\nEstadias cadastradas:\n");
    for (int i = 0; i < totalEstadias; i++) {
        printf("Código da estadia: %s\n", estadias[i].codigoE);
        printf("Código do cliente: %s\n", estadias[i].codigoC);
        printf("Número do quarto: %d\n", estadias[i].numeroQuarto);
        printf("Data de entrada: %d/%d/%d\n", estadias[i].diaEntrada, estadias[i].mesEntrada, estadias[i].anoEntrada);
        printf("Data de saída: %d/%d/%d\n", estadias[i].diaSaida, estadias[i].mesSaida, estadias[i].anoSaida);
        printf("Número de diárias: %d\n", estadias[i].diarias);
        printf("-----------------------\n");
    }
}

void verificarDisponibilidade(struct quarto quartos[], int totalQuartos) {
    printf("\nQuartos disponíveis:\n");
    for (int i = 0; i < totalQuartos; i++) {
        if (quartos[i].statusQuarto == LIVRE) {
            printf("Número do quarto: %d\n", quartos[i].numeroQuarto);
            printf("Quantidade de hóspedes: %d\n", quartos[i].quantidadeDeHospede);
            printf("Valor da diária: %.2f\n", quartos[i].valorDiaria);
            printf("-----------------------\n");
        }
    }
}

void gravarEstadiasClientesFuncionariosEmArquivo(struct estadia estadias[], int totalEstadias, struct cliente clientes[], int totalClientes, struct funcionario funcionarios[], int totalFuncionarios) {
    FILE *arquivo;
    arquivo = fopen("estadias.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    fprintf(arquivo, "Estadias cadastradas:\n");
    for (int i = 0; i < totalEstadias; i++) {
        fprintf(arquivo, "Código da estadia: %s\n", estadias[i].codigoE);
        fprintf(arquivo, "Código do cliente: %s\n", estadias[i].codigoC);
        fprintf(arquivo, "Número do quarto: %d\n", estadias[i].numeroQuarto);
        fprintf(arquivo, "Data de entrada: %d/%d/%d\n", estadias[i].diaEntrada, estadias[i].mesEntrada, estadias[i].anoEntrada);
        fprintf(arquivo, "Data de saída: %d/%d/%d\n", estadias[i].diaSaida, estadias[i].mesSaida, estadias[i].anoSaida);
        fprintf(arquivo, "Número de diárias: %d\n", estadias[i].diarias);
        fprintf(arquivo, "-----------------------\n");
    }

    fprintf(arquivo, "\nClientes cadastrados:\n");
    for (int i = 0; i < totalClientes; i++) {
        fprintf(arquivo, "Código do cliente: %s\n", clientes[i].codigoC);
        fprintf(arquivo, "Nome: %s\n", clientes[i].nomeC);
        fprintf(arquivo, "Endereço: %s\n", clientes[i].endereco);
        fprintf(arquivo, "Telefone: %s\n", clientes[i].telefoneC);
        fprintf(arquivo, "-----------------------\n");
    }

    fprintf(arquivo, "\nFuncionários cadastrados:\n");
    for (int i = 0; i < totalFuncionarios; i++) {
        fprintf(arquivo, "Código do funcionário: %s\n", funcionarios[i].codigo);
        fprintf(arquivo, "Nome: %s\n", funcionarios[i].nome1);
        fprintf(arquivo, "Telefone: %s\n", funcionarios[i].telefone);
        fprintf(arquivo, "Cargo: ");
        switch (funcionarios[i].cargo) {
            case RECEPCIONISTA:
                fprintf(arquivo, "RECEPCIONISTA\n");
                break;
            case AUXILIAR_DE_LIMPEZA:
                fprintf(arquivo, "AUXILIAR DE LIMPEZA\n");
                break;
            case GARCOM:
                fprintf(arquivo, "GARÇOM\n");
                break;
            case GERENTE:
                fprintf(arquivo, "GERENTE\n");
                break;
            default:
                fprintf(arquivo, "Indefinido\n");
                break;
        }
        fprintf(arquivo, "Salário: %.2f\n", funcionarios[i].salario);
        fprintf(arquivo, "-----------------------\n");
    }

    fclose(arquivo);
}

int main() {
    srand(time(NULL));  // Inicializa a semente do gerador de números aleatórios

    struct cliente clientes[100];
    struct funcionario funcionarios[100];
    struct quarto quartos[8];  // Ajustado para 8 quartos
    struct estadia estadias[100];
    int totalClientes = 0;
    int totalFuncionarios = 0;
    int totalEstadias = 0;
    int opcao;

    inicializarQuartos(quartos);

    do {
        printf("\nEscolha uma opção:\n");
        printf("1 - Cadastrar cliente\n");
        printf("2 - Cadastrar funcionário\n");
        printf("3 - Cadastrar estadia\n");
        printf("4 - Exibir estadias cadastradas\n");
        printf("5 - Verificar quartos disponíveis\n");
        printf("6 - Gravar estadias, clientes e funcionários em arquivo\n");
        printf("7 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        while (getchar() != '\n');

        switch (opcao) {
            case 1:
                clientes[totalClientes] = cadastroCliente();
                exibirCliente(clientes[totalClientes]);
                totalClientes++;
                break;
            case 2:
                funcionarios[totalFuncionarios] = cadastroFuncionario();
                exibirFuncionario(funcionarios[totalFuncionarios]);
                totalFuncionarios++;
                break;
            case 3:
                cadastrarEstadia(estadias, &totalEstadias, clientes, totalClientes, quartos, sizeof(quartos)/sizeof(quartos[0]));
                break;
            case 4:
                exibirEstadias(estadias, totalEstadias);
                break;
            case 5:
                verificarDisponibilidade(quartos, sizeof(quartos)/sizeof(quartos[0]));
                break;
            case 6:
                gravarEstadiasClientesFuncionariosEmArquivo(estadias, totalEstadias, clientes, totalClientes, funcionarios, totalFuncionarios);
                break;
            case 7:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }

    } while (opcao != 7);

    return 0;
}
