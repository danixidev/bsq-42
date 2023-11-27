#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void	get_size(const char *file_name, int *rows, int *columns)
{
	int		file;
	char	caracter;
	int		index;
	int		value;

	file = open(file_name, O_RDONLY);
	if (file == -1)
		write(1, "Error al abrir el archivo\n", 26);
	else
	{
		index = 0;
		value = 0;
		while(read(file, &caracter, 1) > 0)
		{
			if(caracter >= '0' && caracter <= '9')
			{
				value *= 10;
				value += caracter - '0';
			}
			index++;
		}
		*rows = value;
		*columns = ((index - 4) / *rows) - 1;
		close(file);
	}
}

char *get_file_contents(const char *nombreArchivo)
{
	int		file;
	char	caracter;
	char	*contents;
	int		index;
	int		rows;
	int		cols;

	get_size(nombreArchivo, &rows, &cols);
	printf("%d, %d >> ", rows, cols);
	file = open(nombreArchivo, O_RDONLY);
	contents = 0;
	if (file == -1)
		write(1, "Error al abrir el archivo\n", 26);
	else
	{
		contents = (char*)malloc((rows * cols) * sizeof(char));
		index = 0;
		while(read(file, &caracter, 1) > 0)
		{
			contents[index] = caracter;
			index++;
		}
		close(file);
	}
	return contents;
}
