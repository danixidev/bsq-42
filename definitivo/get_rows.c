#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(char *str);
int ft_count_digits(int number);

/*
Función para imprimir primera línea que hay dentro de mi archivo.
Abro con función 'open' mi archivo.

Condiciones: 
- si en mi archivo hay -1 filas = "Error". Esto significa que la función 'read' no me ha podido leer el archivo.
- si en mi archivo hay filas = Inicio bucle. Si mi read > 0 entonces es que puede leer lo que hay dentro del archivo.

    - Bucle: lee dentro de mi archivo, mi fila e imprime los caracteres siempre que el contenido del archivo > 0. 
            - Si los caracteres son == a n --> sal del bucle.
            - Si no, escribe los caracteres de uno en uno.

PASO 1: LEER EL ARCHIVO E IMPRIMIR LA PRIMERA LÍNEA. 
PASO 2: LO QUE HE IMPRESO, LO ALMACENO EN UN STRING.
PASO 3: AL STRING QUE TENGO, LE QUITO LOS ÚLTIMOS 3 CARACTERES.
PASO 4: EL STRING FINAL LO METO EN LA FUNCIÓN ATOI = Nº FILAS (LO TRANSFORMO EN UN INT).       
*/

struct Legend {
    int rows;
    char space;
    char block;
    char solution;
};

char *set_size(const char *nombreArchivo)
{
	int		file;
	char	caracter;
	int		index;

	file = open(nombreArchivo, O_RDONLY);
	if (file == -1) 
		write(1, "Error al abrir el archivo\n", 26);
	else
	{
		index = 0;
        while(read(file, &caracter, 1) > 0)
        {
            if(caracter == '\n')
                break;
            index++;
        }
		close(file);
	}
    return ((char*)malloc(index * sizeof(char)));
}

char *ft_strcut(char *str)
{
    int size;
    int index;

    size = 0;
    index = 0;
    while (str[size] != '\0')
        size++;

    size = size - 3;
    while (index <= size)
    {
        if(index == size)
            str[index] = '\0';
        index++;
    }
    return (str);
}

struct Legend get_legend(const char *nombreArchivo)
{
	int		file;
	char	caracter;
	int		index;
    char    *str;
    struct Legend legend;
    
    str = set_size(nombreArchivo);
	file = open(nombreArchivo, O_RDONLY);
	if (file == -1) 
		write(1, "Error al abrir el archivo\n", 26);
	else
	{	
		index = 0;
        while(read(file, &caracter, 1) > 0)
        {
            if(caracter == '\n')
                break;
            else
                str[index] = caracter;
            index++;
        }
		close(file);
	}
    legend.rows = ft_atoi(ft_strcut(str));
    legend.space = str[ft_count_digits(legend.rows)];
    legend.block = str[ft_count_digits(legend.rows) + 1];
    legend.solution = str[ft_count_digits(legend.rows) + 2];
    return (legend);
}

int main()
{
    struct Legend legend = get_legend("test.txt");
    printf("%c", legend.space);
    printf("%c", legend.block);
    printf("%c", legend.solution);
    return (0);
}
