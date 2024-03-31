/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 22:49:31 by yothmani          #+#    #+#             */
/*   Updated: 2024/03/31 00:49:52 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	is_white_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

bool	is_char_valid(char **str)
{
	int	has_direction;
	int	x;
	int	y;

	has_direction = 0;
	x = 0;
	while (str[x])
	{
		y = 0;
		while (str[x][y])
		{
			if (str[x][y] == '1' || str[x][y] == '0'
				|| is_white_space(str[x][y]))
				y++;
			else if (str[x][y] == 'N' || str[x][y] == 'S' || str[x][y] == 'E'
				|| str[x][y] == 'W')
			{
				has_direction++;
				y++;
			}
			else
			{
				printf("Invalid character was found: %c\n", str[x][y]);
				return (false);
			}
		}
		x++;
	}
	if (has_direction != 1)
	{
		printf("Only one start point is permitted! You have %d\n",
			has_direction);
		return (false);
	}
	return (true);
}

bool	is_map_closed(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j] && str[i][j] != '\n')
		{
			if ((i == 0 || !str[i + 1]) && (str[i][j] != '1'
					&& !is_white_space(str[i][j])))
			{
				printf("Error at index [%d][%d]\n", i, j);
				return (false);
			}
			if ((j == 0 || !str[i][j + 1]) && (str[i][j] != '1'
					&& !is_white_space(str[i][j])))
			{
				printf("Error at index [%d][%d]\n", i, j);
				return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

int	main(void)
{
	char	*str[15];

	str[0] = "			1111111111111111111111111";
	str[1] = "			1000000000110000000000001";
	str[2] = "			1011000001110000000000001";
	str[3] = "			1001000000000000000000001";
	str[4] = "111111111011000001110000000000001";
	str[5] = "100000000011000001110111111111111";
	str[6] = "11110111111111011100000010001";
	str[7] = "11110111111111011101010010001";
	str[8] = "11000000110101011100000010001";
	str[9] = "10000000000000001100000010001";
	str[10] = "10000000000000001101010010001";
	str[11] = "11000001110101011111011110N0111";
	str[12] = "11110111 1110101 101111010001";
	str[13] = "11111111 1111111 111111111111";
	str[14] = NULL;
	if (is_char_valid(str) && is_map_closed(str))
		printf("Map is valid\n");
	else
		printf("Map is invalid\n");
	return (0);
}
