#include <unistd.h>

int		ft_grid(char *str, char *grid);
int		ft_check_input(int argc, char **argv);
void	ft_printchar(char *str);

//creates grid array and initialises all values to '0'
//checks input validity
//builds grid
int	main(int argc, char *argv[])
{
	char	grid[16];
	int		i;

	i = 0;
	while (i < 16)
	{
		grid[i] = '0';
		i++;
	}
	if (ft_check_input(argc, argv) == 0)
	{
		write (1, "Error\n", 6);
		return (1);
	}
	if (ft_grid(argv[1], grid) == 1)
		ft_printchar(grid);
	else
	{
		write (1, "Error\n", 6);
		return (1);
	}
}
