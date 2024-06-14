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
#include <time.h>//Fazeer o relogio funcionar
#include <string.h>

struct cargo{
	char recepcionista;
	char auxiliarDeLimpeza;
	char garcom;
	char gerente;
};
struct funcionario{
	int codigo;
	char nome;
	int telefone;
	char cargo;
	float salario;
};
struct cliente{
	int codigoC;
	char nomeC;
	char endereco;
	int telefoneC;
};
struct estadia{
	int estadia;
	int checkin;
	int checkout;
	int horacheckin;
	int horacheckout;
	int diarias;
	int codigoC;
	int numeroQuarto;
};
struct quarto{
	int numeroQuarto;
	int quantidadeDeHospede;
	float valorDiaria;
	char status;
};
typedef struct {
    int ano;
    short mes;
    short dia;
} Data
int relogio(){
    //ponteiro para struct que armazena data e hora
    struct tm *data_hora_atual;

    //variável do tipo time_t para armazenar o tempo em segundos
    time_t segundos;

    //obtendo o tempo em segundos
    time(&segundos);

    //para converter de segundos para o tempo local
    //utilizamos a função localtime
    data_hora_atual = localtime(&segundos);


    printf("\nHora ........: %d:", data_hora_atual->tm_hour); //hora
    printf("%d:", data_hora_atual->tm_min); //minuto


    /* Obtendo os valores da struct data_hora_atual
     e formatando a saída de dados no formato dia/mes/ano

    Para não ficar um printf muito longo em uma única
    linha de comando, quebrei a impressão em 3 partes
    sendo uma informação em cada linha
    */
    //dia do mês
    printf("\nData ........: %d/", data_hora_atual->tm_mday);
    printf("%d/", data_hora_atual->tm_mon + 1); //mês
    printf("%d\n\n", data_hora_atual->tm_year + 1900); //ano

    return 0;
}
//Gerar codigo aleatorio para funcionarios e clientes
int gerarCodigo(){

}
//Cadastro de cliente
int cadastroCliente(){
	printf("Insira o nome do cliente:");
	scanf("%c",&nomeC);
	printf("Insira o endereço:");
	scanf("%c",&endereco);
	printf("Insira o número de telefone:");
	scanf("%d",&telefoneC);
	printf("O codigo do cliente é:" gerarCodigo);
}
//Cadastro de funcionarios
int cadastroFuncionario(){
	printf("Insira o nome do funcionario:");
	scanf("%c",&nome);
	printf("Insira o telefone:");
	scanf("%d",&telefone);
	printf("Insira o cargo do funcionario:");
	scanf("%c", &cargo);
	printf("Insira o salario do funcionario:");
	scanf("%f",&salario);
	printf("O codigo do funcionario é:" gerarCodigo);
}
//Função para ver o status dos quartos
void statusDoQuarto(int n){
	printf("Digite a quantidade de quartos do hotel:");
	scanf("%d",&n);
	for(int i = 0; i<n; i++){
		if()
	}
}
//Calcular o valor da diaria
float calcularDiaria(){


}
//Verificar se se a quaantidade de hospede da no quarto
int quantidadeDeHospede(int hospedes){
	printf("Digite a quantidade de hospedes");
	scanf("%d", &hospedes);
	for(int i = 0; i<=hospedes;i++){
		if(i<= hospedes){
			printf("O quarto disponivel para essa quantidade de pessoas")
		}
	}
}
