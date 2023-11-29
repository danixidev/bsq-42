int	ft_atoi(char *str)
{
	int	result;
	int	is_negative;
	int	index;

	result = 0;
	is_negative = 0;
	index = 0;
	while(str[index] != '\0')
	{
		if (str[index] == '-')
			is_negative = 1;
		else if (str[index] >= '0' && str[index] <= '9')
		{
			result *= 10;
			result += (str[index] - '0');
		}
		else if(str[index] < '0' || str[index] > '9' || str[index] != '-')
			break;
		index++;
	}
	if(is_negative)
		result = -result;
	return ((int)result);
}

// Función para contar los dígitos de un número entero
int ft_count_digits(int number) 
{
	int counter; 
	
	counter = 0;
    if (number == 0) 
	{
		return 1;
    }
    if (number < 0) 
	{
        number = -number;
    }
    while (number > 0) 
	{
        number /= 10;
        counter++;
    }
    return (counter);
}

// int main() {
//     int number;

//     // Solicitar al usuario que ingrese un número
//     printf("Ingrese un número entero: ");
//     scanf("%d", &number);

//     // Llamada a la función para contar los dígitos
//     int cantidadDigitos = ft_count_digits(number);

//     // Imprimir el resultado
//     printf("El número %d tiene %d dígito(s).\n", number, cantidadDigitos);

//     return (0);
// }