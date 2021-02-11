/*
Para cada um dos consumidores de energia elétrica de uma cidade é informado
 o número da conta e o total de KW consumido no mês. Sabendo-se que o custo
 do KW é de R$ 1,75, fazer um algoritmo para:
 • Armazenar e listar o número da conta, o total de KW consumidos e o valor a
 pagar de cada consumir cadastrado;
 • Listar o número da conta, o total de KW consumidos e o valor a pagar do
 consumidor que mais gastou e o que menos gastou;
 • Mostrar a média de consumo da cidade;
 • Mostrar o número de consumidores que ultrapassaram o consumo de 170 KW;
 Armazene as informações em estruturas de vetores e/ou matrizes. Na tela, deve
 existir um MENU que pergunta ao usuário se ele deseja cadastrar um novo
 consumidor ou listar alguma informação (maior, menor, média, etc.).
*/

#include<stdio.h>
#include<stdlib.h>
#define line 5 // numero de cadastros
void menu(); //funcao que imprime o menu principal
void erro(int op1); //funcao que controla o erro de entra no menu
void cad(); //funcao de cadastro
void list(); //funcao para listar
int cadastro[line], kw[line], op, x; //variaveis inteiras
float valor[line]; //variavel ponto flutiante
int main()
{
	do
	{
		menu();
		scanf_s("%d", &op);
		erro(op);
		switch (op)
		{
		case 1:
			cad();
			break;
		case 2:
			list();
			break;
		default:
			break;
		}
		printf("\nMenu tecle 1 para sair outro valor: ");
		scanf_s("%d", &op);
	} while (op == 1);
	system("pause");
	return 0;
}
//funcao cadastro
void cad()
{
	static int a;
	do
	{
		printf("\nDigite o numero do cadastro: \n");
		scanf_s("%d", &cadastro[a]);
		printf("\nDigite o numero de kW consumido: \n");
		scanf_s("%d", &kw[a]);
		valor[a] = (1.75 * kw[a]);
		a++;
		printf("\nPara cadastrar digite 1 para sair digite outro valor: \n");
		scanf_s("%d", &x);
	} while (x == 1);
}
// funcao listar
void list()
{
	int somavetor, maior, b;
	float media;
	do
	{
		printf("\n");
		printf("\n");
		printf("\n");
		printf("**************************** MENU **************************** \n");
		printf("* * \n");
		printf("* 1 - LISTAR * \n");
		printf("* * \n");
		printf("* 2 - MEDIA * \n");
		printf("* * \n");
		printf("*3 - NUMERO DE CONSUMIDORES QUE ULTRAPASSOU 170 KW * \n");
		printf("* * \n");
		printf("* 4 - SAIR * \n");
		printf("* * \n");
		printf("************************************************************** \n");
		printf("\n");
		printf("\n");
		printf("\n");
		scanf_s("%d", &b);
		switch (b)
		{
		case 1:
			for (int i = 0; i < line; i++)
			{
				printf("\nCadastro: %d\nkW: %d\nValor: %.2f", cadastro[i], kw[i], valor[i]);
				printf("\n");
			}break;
		case 2:
			somavetor = 0;
			for (int j = 0; j < line; j++)
			{
				somavetor = somavetor + kw[j];
			}
			media = somavetor / line; // para a media ser correta ( numero de cadastros == line)
			printf("Media: %.2f", media);
			break;
		case 3:
			maior = 0;
			for (int k = 0; k < line; k++)
			{
				if (kw[k] > 170)
				{
					maior++;
				}
			}printf("\nNumero de pessoas que consumiu mais de 170 kW: %d", maior);
			printf("\n");
		default:
			break;
		}
		printf("\nPara continuar digite 1 . Para voltar ao MENU digite outro valor: ");
		scanf_s("%d", &op);
	} while (op == 1);
}
// funcao menu
void menu()
{
	printf("\n");
	printf("\n");
	printf("\n");
	printf("**************************** MENU **************************** \n");
	printf("* * \n");
	printf("* 1 - CADASTRAR * \n");
	printf("* * \n");
	printf("* 2 - LISTAR * \n");
	printf("* * \n");
	printf("************************************************************** \n");
	printf("\n");
	printf("\n");
	printf("\n");
}
// caso entrada nao compativel com programa
void erro(int op1)
{
	if ((op1 < 1) || (op1 > 2))
	{
		printf("Erro, digite um numero do menu:");
	}
}