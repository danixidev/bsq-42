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
