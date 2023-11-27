#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>


int *convert_to_array(const char *nombreArchivo)
{
	int		file;
	char	caracter;
	int	*contents;
	int		index;
	int		count;

	file = open(nombreArchivo, O_RDONLY);
	contents = 0;
	count = 0;
	if (file == -1)
		write(1, "Error al abrir el archivo\n", 26);
	else
	{
		contents = (int*)malloc(243 * sizeof(int));
		index = 0;
		while(read(file, &caracter, 1) > 0)
		{
			if(caracter != '\n')
				contents[count++] = caracter - '0';
			index++;
		}
		close(file);
	}
	return contents;
}