###################################
#   Makefile para compilar los    #
#   programas einserta e eextrae  #
###################################
GCC=gcc
GCC_OPTS=-O3 -lm
LOCAL_PATH=include

bas:	esc.o wav.o
	$(GCC) -o inserta esconde.o wav.o -I $(LOCAL_PATH) $(GCC_OPTS) einserta.c
	$(GCC) -o extraer esconde.o wav.o -I $(LOCAL_PATH) $(GCC_OPTS) eextraer.c

esc.o:	esconde.c $(LOCAL_PATH)/esconde.h
	$(GCC) esconde.c -c -I $(LOCAL_PATH) $(GCC_OPTS)
wav.o:	wav.c $(LOCAL_PATH)/wav.h
	$(GCC) wav.c -c -I $(LOCAL_PATH) $(GCC_OPTS)

clean:
	rm -f *.o inserta extraer
