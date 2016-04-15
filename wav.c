#include "wav.h"

void wavread(char *file_name, int16_t **samples)
{
    int fd;
    if (!file_name)
        errx(1, "Nombre no especificado");
    if ((fd = open(file_name, O_RDONLY)) < 1)
        errx(1, "Error al abrir el archivo");
    if (!header)
        header = (WavHeader*)malloc(sizeof(WavHeader));
    if (read(fd, header, sizeof(WavHeader)) < sizeof(WavHeader))
        errx(1, "Archivo dañado: header");
    if (strncmp(header->chunk_id, "RIFF", 4) ||
        strncmp(header->format, "WAVE", 4))
        errx(1, "No es un archivo wav");
    if (header->audio_format != 1)
        errx(1, "solo soparta condificacion PCM");
    if (*samples) free(*samples);
	    *samples = (int16_t*)malloc(sizeof(int16_t)*header->datachunk_size);
    if (!*samples)
        errx(1, "Error al reservar memoria");
    if (read(fd, *samples, header->datachunk_size) < header->datachunk_size)
        errx(1, "Archivo dañado: samples");
    close(fd);
}
void wavwrite(char *file_name, int16_t *samples)
{
    int fd;
    if (!file_name)
        errx(1, "Archivo no especificado");
    if (!samples)
        errx(1, "Datos no especificados");
    if ((fd = creat(file_name, 0666)) < 1)
        errx(1, "Error al crear el archivo");
    if (write(fd, header, sizeof(WavHeader)) < sizeof(WavHeader))
        errx(1, "Error en el encabezado");
    if (write(fd, samples, header->datachunk_size) < header->datachunk_size)
        errx(1, "Error en los datos");
    close(fd);
}
