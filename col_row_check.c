/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_row_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezaimaki <ezaimaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 11:04:27 by ezaimaki          #+#    #+#             */
/*   Updated: 2026/08/22 20:13:59 by ezaimaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_row(char *grid, char *row, int row_num);
int	ft_check_row_back(char *grid, char *row, int row_num);
int	ft_check_col(char *grid, char *col, int col_num);
int	ft_check_col_back(char *grid, char *col, int col_num);

//returns 1 if placement ok, 0 if not
int	ft_check_row(char *grid, char *row, int row_num)
{
	int		counter;
	int		vis_ammount;
	char	visible;

	counter = row_num * 4;
	visible = grid[counter];
	vis_ammount = 1;
	while (counter < (row_num * 4) + 4)
	{
		if (visible < grid[counter])
		{
			vis_ammount++;
			visible = grid[counter];
		}
		counter++;
	}
	if (row[row_num] == vis_ammount + '0')
		return (1);
	return (0);
}

int	ft_check_row_back(char *grid, char *row, int row_num)
{
	int		counter;
	int		vis_ammount;
	char	visible;

	counter = (row_num * 4) + 3;
	visible = grid[counter];
	vis_ammount = 1;
	while (counter >= row_num * 4)
	{
		if (visible < grid[counter])
		{
			vis_ammount++;
			visible = grid[counter];
		}
		counter--;
	}
	if (row[row_num + 4] == vis_ammount + '0')
		return (1);
	return (0);
}

int	ft_check_col(char *grid, char *col, int col_num)
{
	int		counter;
	int		vis_ammount;
	char	visible;

	counter = col_num;
	visible = grid[col_num];
	vis_ammount = 1;
	while (counter <= col_num + 12)
	{
		if (visible < grid[counter])
		{
			vis_ammount++;
			visible = grid[counter];
		}
		counter += 4;
	}
	if (col[col_num] == vis_ammount + '0')
		return (1);
	return (0);
}

int	ft_check_col_back(char *grid, char *col, int col_num)
{
	int		counter;
	int		vis_ammount;
	char	visible;

	counter = col_num + 12;
	visible = grid[col_num + 12];
	vis_ammount = 1;
	while (counter >= col_num)
	{
		if (visible < grid[counter])
		{
			vis_ammount++;
			visible = grid[counter];
		}
		counter -= 4;
	}
	if (col[col_num + 4] == vis_ammount + '0')
		return (1);
	return (0);
}
