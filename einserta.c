#include <stdio.h>
#include <stdlib.h>

#include "wav.h"
#include "esconde.h"

int main(int argc, char *argv[])
{
	int a, tamn;
	int tama;
	int16_t *samples=NULL;
	char *datosa;

	if (argc !=5)
	{
		printf("Error. Numero de argumentos invalidos\n");
		printf("Uso: ./einserta <archivo_huesped> <archivo_a_esconder> <nombre_del archivo_a_ esconder> <nombre_archivo_modificado> \n");
		return -1;

	}

	FILE *arc= fopen(argv[2], "rb");
	wavread(argv[1], &samples);
	fseek(arc, 0L, SEEK_END);
	tama= ftell(arc);
	rewind(arc);
	a= GuardarI(tamn, samples, 0);
	a= GuardarCs(argv[3], samples, a, tamn);
	a= GuardarI(tama, samples, a);
	datosa = (char *) malloc(sizeof(char)*tama);
	fread(datosa,tama,1, arc);
	a= GuardarCs(datosa, samples, a, tama);
	wavwrite(argv[4], samples);
	free(header);
	free(samples);
	free(datosa);
	fclose(arc);
	return 0;
}

