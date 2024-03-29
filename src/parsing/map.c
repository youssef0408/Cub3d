/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 22:49:31 by yothmani          #+#    #+#             */
/*   Updated: 2024/03/29 01:08:12 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
			if (str[x][y] == '1' || str[x][y] == '0' || str[x][y] == 32)
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

bool check_first_row(char **str)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (str[x] && str[x][y])
	{
        y = 0;
		while (str[x][y] == 32)
			y++;
		if (str[x][y] != '1')
		{
			printf("Map is not closed!\n");
			return false;
		}
        else
            x++;
	}
    return true;
}


int	main(void)
{
	char	*str[4];

	str[0] = "          1  0  1  11111";
	str[1] = "  01 0 111N01";
	str[2] = "     1 011111";
	str[3] = NULL;
	if (is_char_valid(str) && check_first_row(str))
		printf("Map is valid\n");
	else
		printf("Map is invalid\n");
	return (0);
}
