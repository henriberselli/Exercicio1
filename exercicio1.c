#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define LOOP  5

int in_dados (int couter);


int main (int argc, char **argv)
{
	int i;
	int vetor[LOOP];

	for (i = 0; i < LOOP; i++) vetor[i] = in_dados (i);
	printf ("Valores digitados:\n");
	for (i = 0; i<LOOP; i++) printf ("%d - %d\n", i+1, vetor[i]);
}

int in_dados (int couter)
{
	int i, ok = 0;
	char text[3];

	do
	{
		printf ("Entre com o %d elemento do vetor\n", couter+1);
		gets (text);
		for (i=0; i<strlen(text); i++)
		{
			if (isdigit (text[i]) !=0) ok = 1;
			else ok = 0;
		}
		if (ok ==0) printf ("Nao eh um numero valido!!!\n");
		else system ("clear");
	} while (ok == 0);
	return (atoi(text));
}
