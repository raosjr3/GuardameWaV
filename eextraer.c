#include <stdio.h>
#include <stdlib.h>

#include "wav.h"
#include "esconde.h"

int main(int argc, char *argv[])
{
	int b, pa, *pr; 
	char *nom, *datosr;
	int16_t *samples=NULL;
	FILE *arcr;

	wavread(argv[1], &samples);
	pr= ValorI(samples, 0);
	nom= (char *) malloc(sizeof(char)* pr[1]);
	for(b=0; b<pr[1]; b++)
	{
		pa= pr[0]+ (b*8);
		nom[b]=ValorC(samples, pa);
	}
	pa= pr[0]+ (b*8);
	pr = ValorI(samples, pa);
	datosr = (char *) malloc(sizeof(char)* pr[1]);
	for(b=0; b<pr[1]; b++)
	{
		pa= pr[0]+ (b*8);
		datosr[b]=ValorC(samples, pa);
	}
	arcr = fopen(nom, "w");
	printf("Archivo recuperado: %s\n", nom);
	fwrite(datosr,pr[1],1, arcr);
	free(header);
	free(samples);
	free(datosr);
	fclose(arcr);
	return 0;
}

