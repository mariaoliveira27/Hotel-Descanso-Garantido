/*
 ============================================================================
 Name        : Hotel descanso garantido
 Author      : Maria Clara Gomes
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h> //Fazeer o relogio funcionar
#include <string.h>

enum cargo{
	RECEPCIONISTA,
	AUXILIARDELIMPEZA,
	GARCOM,
	GERENTE
};

struct funcionario{
	int codigo;
	char nome[100];
	int telefone;
	enum cargo cargo;
	float salario;
};
struct cliente{
	int codigoC;
	char nomeC[100];
	char endereco[100];
	int telefoneC;
};
struct estadia{
	int estadia;
	float checkin;
	float checkout;
	float horacheckin;
	float horacheckout;
	int diarias;
	int codigoC;
	int numeroQuarto;
};
enum statusQuarto{
	LIVRE,
	OCUPADO
};
struct quarto{
	int numeroQuarto;
	int quantidadeDeHospede;
	float valorDiaria;
	enum statusQuarto statusQuarto;
};
typedef struct{
	int ano;
	short mes;
	short dia;
} Data;

int relogio(){
	// ponteiro para struct que armazena data e hora
	struct tm *data_hora_atual;

	// variável do tipo time_t para armazenar o tempo em segundos
	time_t segundos;

	// obtendo o tempo em segundos
	time(&segundos);

	// para converter de segundos para o tempo local
	// utilizamos a função localtime
	data_hora_atual = localtime(&segundos);

	printf("\nHora ........: %d:", data_hora_atual->tm_hour); // hora
	printf("%d:", data_hora_atual->tm_min);					  // minuto

	/* Obtendo os valores da struct data_hora_atual
	 e formatando a saída de dados no formato dia/mes/ano

	 Para não ficar um printf muito longo em uma única
	 linha de comando, quebrei a impressão em 3 partes
	 sendo uma informação em cada linha
	 */
	// dia do mês
	printf("\nData ........: %d/", data_hora_atual->tm_mday);
	printf("%d/", data_hora_atual->tm_mon + 1);		   // mês
	printf("%d\n\n", data_hora_atual->tm_year + 1900); // ano

	return 0;
}
// Gerar codigo aleatorio para funcionarios e clientes
int gerarCodigo(){
}
// Cadastro de cliente
int cadastroCliente(){
	struct cliente clie;
	printf("Insira o nome do cliente:");
	fgets(clie.nomeC,100,stdin);
	clie.nomeC[strcspn(clie.nomeC,"\n")] = 0;
	printf("Insira o endereço:");
	fgets(clie.endereco,100,stdin);
	clie.endereco[strcspn(clie.endereco,"\n")] = 0;

	printf("Insira o número de telefone:");
	scanf("%d", &clie.telefoneC);
	
}
// Cadastro de funcionarios
struct funcionario cadastroFuncionario(){
	struct funcionario func;
	printf("Insira o nome do funcionario:");
	fgets(func.nome, 100, stdin);
	func.nome[strcspn(func.nome, "\n")] = 0;

	printf("Insira o telefone:");
	scanf("%d", &func.telefone);

	while (getchar() != '\n');

	printf("Insira o cargo do funcionario:");
	fgets(func.cargo, 100, stdin);
	func.cargo[strcspn(func.cargo, "\n")] = 0;

	printf("Insira o salario do funcionario:");
	scanf("%f", &func.salario);

	return func;
}

// Função para ver o status dos quartos
void statusDoQuarto(int n){
	printf("Digite a quantidade de quartos do hotel:");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		if ()
	}
}
// Calcular o valor da diaria
float calcularDiaria(){
}
// Verificar se se a quaantidade de hospede da no quarto
int quantidadeDeHospede(int hospedes){
	printf("Digite a quantidade de hospedes");
	scanf("%d", &hospedes);
	for (int i = 0; i <= hospedes; i++)
	{
		if (i <= hospedes)
		{
			printf("O quarto disponivel para essa quantidade de pessoas")
		}
	}
}
// trancar as informaçoes confdencias de clientes e funcionarios
void exibirInformacoes(){

}
	// quartos do hotel
	int quartosDoHotel(){
	enum LIVRE;
	enum OCUPADO;
	struct quarto netuno;
	struct quarto urano;
	struct quarto saturno;
	struct quarto jupiter;
	struct quarto marte;
	struct quarto terra;
	struct quarto venus;
	struct quarto mercurio;

	netuno.numeroQuarto = 1;
	netuno.quantidadeDeHospede = 2;
	netuno.valorDiaria = 200.90;
	netuno.statusQuarto = LIVRE;

	urano.numeroQuarto = 2;
	urano.quantidadeDeHospede = 3;
	urano.valorDiaria = 230.00;
	urano.statusQuarto = LIVRE;

	saturno.numeroQuarto = 3;
	saturno.quantidadeDeHospede = 5;
	saturno.valorDiaria = 330.00;
	saturno.statusQuarto = LIVRE;

	jupiter.numeroQuarto = 4;
	jupiter.quantidadeDeHospede = 7;
	jupiter.valorDiaria = 400.00;
	jupiter.statusQuarto = LIVRE;

	marte.numeroQuarto = 5;
	marte.quantidadeDeHospede = 4;
	marte.valorDiaria = 500.00;
	marte.statusQuarto = LIVRE;

	terra.numeroQuarto = 6;
	terra.quantidadeDeHospede = 4;
	terra.valorDiaria = 550.00;
	terra.statusQuarto = LIVRE;

	venus.numeroQuarto = 7;
	venus.quantidadeDeHospede = 2;
	venus.valorDiaria = 600.00;
	venus.statusQuarto = LIVRE;

	mercurio.numeroQuarto = 8;
	mercurio.quantidadeDeHospede = 1;
	mercurio.valorDiaria = 1000.00;
	mercurio.statusQuarto = LIVRE;
}

int main(){
	FILE *arquivo = fopen("cadastro_Hotel.txt", "w");
}
