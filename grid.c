int		ft_grid(char *str, char *grid);
void	ft_parse_str(char *str, char *input);
int		ft_build_grid(char *grid, char *col, char *row, int i);
int		ft_check_row(char *grid, char *row, int row_num);
int		ft_check_row_back(char *grid, char *row, int row_num);
int		ft_check_col(char *grid, char *col, int col_num);
int		ft_check_col_back(char *grid, char *col, int col_num);
int		ft_check_visibility(char *grid, char **input, int i, char j);

//separates input into column and row numbers (in separate arrays)
// returns 0 if no solution, 1 if solution exists AND grid gets filled
int	ft_grid(char *str, char *grid)
{
	char	input[16];
	char	col[8];
	char	row[8];
	int		i;

	ft_parse_str(str, input);
	i = 0;
	while (i < 16)
	{
		if (i < 8)
			col[i] = input[i];
		else
			row[i - 8] = input[i];
		i++;
	}
	if (ft_build_grid(grid, col, row, 0) == 0)
		return (0);
	else
		return (1);
}

//returns 0 if no solutions, 1 if solution exists and fills grid with correct numbers
int	ft_build_grid(char *grid, char *col, char *row, int i)
{
	char	j;
	char	*input[2];

	input[0] = col;
	input[1] = row;
	j = '1';
	if (i == 16)
		return (1);
	while (j <= '4')
	{
		if (ft_check_visibility(grid, input, i, j) == 0
			|| ft_build_grid(grid, col, row, i + 1) == 0)
		{
			grid[i] = '0';
			j++;
			continue ;
		}
		else
			return (1);
	}
	return (0);
}

//checks if current char number(j) already exists in current row + column
//if not, places it in current position
//if a row or column is full, checks if input visibility matches
//returns 1 if success, 0 if something doesn't fit
int	ft_check_visibility(char *grid, char **input, int i, char j)
{
	if (j == grid[(i / 4) * 4] || j == grid[(i / 4) * 4 + 1]
		|| j == grid[(i / 4) * 4 + 2] || j == grid[(i / 4) * 4 + 3]
		|| j == grid[i % 4] || j == grid[(i % 4) + 4]
		|| j == grid[(i % 4) + 8] || j == grid[(i % 4) + 12])
		return (0);
	grid[i] = j;
	if (i / 4 == 3)
	{
		if (ft_check_col(grid, input[0], i % 4) == 0
			|| ft_check_col_back(grid, input[0], i % 4) == 0)
			return (0);
	}
	if (i % 4 == 3)
	{
		if (ft_check_row (grid, input[1], i / 4) == 0
			|| ft_check_row_back (grid, input[1], i / 4) == 0)
			return (0);
	}
	return (1);
}
