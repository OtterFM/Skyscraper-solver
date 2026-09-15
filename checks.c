int		ft_check_input(int argc, char **argv);
void	ft_parse_str(char *str, char *input);

//checks that input is a string 31 chars long, alternating between spaces and a number between 1-4 
int	ft_check_input(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 2)
	{
		return (0);
	}
	while (argv[1][i] != '\0')
	{
		if (i % 2 == 1)
		{
			if (argv[1][i] != ' ')
				return (0);
		}
		else
		{
			if (!(argv[1][i] == '1' || argv[1][i] == '2'
					|| argv[1][i] == '3' || argv[1][i] == '4'))
				return (0);
		}
		i++;
	}
	if (i != 31)
		return (0);
	return (1);
}

//string is parsed and the char numbers are put in an array
void	ft_parse_str(char *str, char *input)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (i % 2 == 0)
		{
			input[j] = str[i];
			j++;
		}
		i++;
	}
}
