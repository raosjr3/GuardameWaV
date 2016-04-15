#include <inttypes.h>
#include <math.h>
#include <stdlib.h>

int GuardarI(int valor, int16_t *datos, int pos)
{
	int ib, a, b, mask1=1, iv=pos, el=valor;
	for(ib=0;ib<(sizeof(int)*8);ib++)
	{
		a = datos[iv] & mask1;
		b = el & mask1;
		if ((a && b) || (!a && !b)) 
			datos[iv] = datos[iv];
		if (!a && b )
			datos[iv] = datos[iv]+1;
		if (a && !b)
			datos[iv] = datos[iv]-1;
		el>>=1;
		iv++;
	}
	return iv;
}

int GuardarC(char valor, int16_t *datos, int pos)
{
	int ib, a, b, mask1=1, iv=pos;
	char el= valor;
	for(ib=0;ib<(sizeof(char)*8);ib++)
	{
		a = datos[iv] & mask1;
		b = el & mask1;
		if ((a && b) || (!a && !b)) 
			datos[iv] = datos[iv];
		if (!a && b )
			datos[iv] = datos[iv]+1;
		if (a && !b)
			datos[iv] = datos[iv]-1;
		el>>=1;
		iv++;
	}
	return iv;
}

int GuardarCs(char *valor, int16_t *datos, int pos, int lon1)
{
	int ib, a, b, mask1=1, iv=pos, c;
	int lon = lon1;
	char el;
	for(c =0; c<lon; c++)
	{
		el= valor[c];
		for(ib=0;ib<(sizeof(char)*8);ib++)
		{
			a = datos[iv] & mask1;
			b = el & mask1;
			if ((a && b) || (!a && !b)) 
				datos[iv] = datos[iv];
			if (!a && b )
				datos[iv] = datos[iv]+1;
			if (a && !b)
				datos[iv] = datos[iv]-1;
			el>>=1;
			iv++;
		}
	}
	return iv;
}

int *ValorI(int16_t *num, int pos)
{
	int *re = malloc(sizeof(int)*2);
	int iv=pos;
	int a; int res=0;
	int mask2= 1;
	for(a=0; a<(sizeof(int)*8); a++)
	{
		if(num[iv] & mask2)
			res = res+ pow(2, a);
		iv++;
	}
	re[0]= iv;
	re[1] = res;
	return re;
}

char ValorC(int16_t *num, int pos)
{
	int a, res=0, iv=pos;
	int mask2= 1;
	for(a=0; a<(sizeof(char)*8); a++)
	{
		if(num[iv] & mask2)
			res = res+ pow(2, a);
		iv++;
	}
	return (char) res;
}
