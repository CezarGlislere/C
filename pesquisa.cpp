/*
Uma certa empresa fez uma pesquisa de mercado para saber se as pessoas
gostaram ou n�o do seu �ltimo produto lan�ado. Para isto, coletou o sexo do
entrevistado e a sua resposta (sim ou n�o). Sabendo que foram entrevistadas
150 pessoas, fazer um algoritmo que calcule e mostre ao final:
� O n�mero de pessoas que responderam sim;
� O n�mero de pessoas que responderam n�o;
� A percentagem de pessoas do sexo feminino que responderam sim;
� A percentagem de pessoas do sexo masculino que responderam n�o;
Para a resposta SIM/N�O. Utilize uma vari�vel do tipo CHAR, que armazena S
ou N, ou use uma vari�vel do tipo INT que armazena 1 (para SIM) e 2 (para N�O).
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// AS ENTRADAS DO PROGRAMA DEVEM SER: m PARA MASCULINO, f PARA FEMININO, s PRA SIM, n PARA NAO.
int main() {
	//declara��o das vari�veis
	int masc[3] = { 0 }, fem[3] = { 0 }, ret1, ret2, ret3, i;
	char m[2] = "m", sim[2] = "s", sexo[2] = " ", s[2] = " ", op[2] = " ", op2[2] = " ";
	float x, y, w, z;
	printf("**************************************** PESQUISA DE OPINIAO ****************************************\n");
	//inicio do la�o for feito para contar quantas pessoas participaram da pesquisa
	for (i = 0; i < 150; i++) //para testar o programa � possivel colocar um valor menor que 150
	{
		printf("\nSexo: ");
		gets_s(sexo); //gets faz a fun��o do scanf_s para uma string
		ret1 = strcmp(m, sexo); //compara��o entre strings
		if (ret1 == 0) //condicional feita a partir do resultado da compara��o
		{
			masc[0]++;
			printf("Gostou do produto? ");
			gets_s(op);
			printf("______________________\n");
			ret2 = strcmp(op, sim);
			if (ret2 == 0)
			{
				masc[1]++;
			}
			else
			{
				masc[2]++;
			}
		}
		else
		{
			fem[0]++;
			printf("Gostou do produto? ");
			gets_s(op2);
			printf("______________________\n");
			ret3 = strcmp(sim, op2);
			if (ret3 == 0)
			{
				fem[1]++;
			}
			else
			{
				fem[2]++;
			}
		}
	}
	// transforma��o para float
	x = masc[1];
	y = masc[2];
	w = fem[1];
	z = fem[2];
	//Impress�o dos resultados
	printf("\n************************************************************************************************************************\n");
	printf("O numero de pessoas que respondeu SIM foi: %d\n", masc[1] + fem[1]);
	printf("O numero de pessoas que respondeu NAO foi: %d\n", masc[2] + fem[2]);
	printf("\n************************************************************************************************************************\n");
	printf("%.2f %% dos HOMENS gostou do produto.\n\n", 100 * (x / masc[0]));
	printf("%.2f %% dos HOMENS nao gostou do produto.\n\n", 100 * (y / masc[0]));
	printf("%.2f %% das MULHERES gostou do produto.\n\n", 100 * (w / fem[0]));
	printf("%.2f %% dos MULHERES nao gostou do produto.\n\n", 100 * (z / fem[0]));
	printf("************************************************************************************************************************\n");
	system("pause");
	return 0;
}