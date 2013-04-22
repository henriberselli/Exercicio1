#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define LOOP  5

/*!
\file exercicio1.c
\brief Programa recerente ao exercicio 1 - Sistemas Embarcados
\author Henrique
\date Abril - 2013
*/

//Prototipos
int in_dados (int couter);
void ordenacao (int *valores);
void media_desvio (int *valores);

/*!
\brief Funcao principal.
*/
int main (int argc, char **argv)
{
	int i;
	int vetor[LOOP];
	
	system ("clear");  //Limpa a tela
	for (i = 0; i < LOOP; i++) vetor[i] = in_dados (i);  //Carrega vetor
	printf ("Valores digitados:\n");
	for (i = 0; i<LOOP; i++) printf ("%d - %d\n", i+1, vetor[i]);

	ordenacao (vetor);
	printf ("\nOrddenacao:  ");
	for (i = 0; i < LOOP; i++) printf ("%d  ", vetor[i]);
	printf("\n");

	media_desvio (vetor);

	return (0);
}

/*!
\brief Funcao de entrada de dados.
\param couter numero do elemento a ser inserido.
\return Retorna o valor inserido.
*/
int in_dados (int couter)
{
	int i, ok = 0;
	char text[5];

	do  //Laco para insercao do numero inteiro
	{
		printf ("Entre com o %d elemento do vetor\n", couter+1);
		gets (text);
		for (i=0; i<strlen(text); i++) //Testa se todos digitos sao numeros
		{
			if (isdigit (text[i]) !=0) ok = 1;
			else 
			{
				ok = 0;
				break;
			}
		}
		if (ok ==0) printf ("Nao eh um numero valido!!!\n");
		else system ("clear");
	} while (ok == 0);
	return (atoi(text));
}

/*!
\brief Funcao para ordenar e mostrar os valores inseridos.
\param *valores Endereco do vetor onde estao armazenados os numeros inseridos
*/
void ordenacao (int *valores)
{
	int vetor_aux[LOOP];
	int i, j, k;

	for (i = 0; i < LOOP; i++) //Lista os numeros inseridos
	{
		for (j = 0; j<= i; j++) //Testa se o numero eh menor que os
		{			//numeros ja listados
			if (j == i) vetor_aux[j] = *(valores+i);
			if (*(valores+i) < vetor_aux[j])
			{	//Reorganiza os numeros inseridos
				for (k = i; j < k; k--) vetor_aux[k] = vetor_aux[k-1];
				vetor_aux[j] = *(valores+i);
				break;
			}
		}
	}
	for (i = 0; i < LOOP; i++) *(valores+i) = vetor_aux[i]; //Reescreve os numeros digitados
}

/*!
\brief Funcao para calculo da Media e Desvio Padrao
\param *valores Endereco do vetro onde estao armazenados os numeros inseridos
*/
void media_desvio (int *valores)
{
	int i;
	float desvio, media = 0;
	float soma = 0;

	for (i = 0; i < LOOP; i++) media = media + *(valores+i);
	media = media / LOOP;
	printf ("\nMedia dos valores digitados:  %.2f\n", media);

	for (i = 0; i < LOOP; i++)
	{
		desvio = *(valores+i) - media;
		soma = soma + powf (desvio, 2);
	}
	soma = soma / LOOP;
	desvio = sqrtf (soma);
	printf ("Desvio padrao dos valores digitados:  %.2f\n\n", desvio);
}

