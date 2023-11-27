#include <stdio.h>

char *get_file_contents(const char *nombreArchivo);
int	get_size(const char *file_name, int *rows, int *columns);

int main(int argc, char *argv[]) {
	int	count;

	count = 1;
	while(argc > count)
	{
		printf("%s\n\n", get_file_contents(argv[count]));
		count++;
	}
}
