# GuardameWaV
Esconde cualquier tipo de archivo en un archivo de audio .wav

Programa que esconde un archivo cualquiere en un archivo de audio con extensión .wav utilizando la técnica del bit menos significativo (LSB).

Notas:

  La versión publicada no la he probado en sistemas Windows, funciona bien en cualquier distribución de Linux.

  Para leer los archivos wav utilice la propuesta de: https://www.daniweb.com/programming/software-development/threads/340334/reading-audio-file-in-c, modificando solamente algunas partes principalmente la asignación de memoria dinámica.

  El programa supone que el archivo huesped es más grande que el archivo a esconder.

