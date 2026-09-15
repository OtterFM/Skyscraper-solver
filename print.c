#include <unistd.h>

void	ft_printchar(char *str);

//prints the grid
void	ft_printchar(char *str)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		write (1, &str[i], 1);
		if (i > 0 && (i + 1) % 4 == 0)
		{
			write (1, "\n", 1);
		}
		else
		{
			write (1, " ", 1);
		}
		i++;
	}
}
