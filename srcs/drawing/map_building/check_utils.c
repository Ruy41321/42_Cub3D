/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 20:56:31 by lpennisi          #+#    #+#             */
/*   Updated: 2025/03/16 12:24:50 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

void	remove_consecutives_space(char **lines)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (lines[i])
	{
		j = 0;
		while (lines[i][j])
		{
			if (lines[i][j] == ' ' && lines[i][j + 1] == ' ')
			{
				k = j;
				while (lines[i][k])
				{
					lines[i][k] = lines[i][k + 1];
					k++;
				}
				lines[i][k] = '\0';
			}
			j++;
		}
		i++;
	}
}

void	remove_last_space(char **lines)
{
    int	i;
    int	j;

    i = 0;
    while (lines[i])
    {
        j = ft_strlen(lines[i]) - 1;
        while (j >= 0 && lines[i][j] == ' ')
        {
            lines[i][j] = '\0';
            j--;
        }
        i++;
    }
}

void	remove_extra_space(char **lines)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	while (lines[++i])
	{
		j = 0;
		while (lines[i][j] == ' ')
			j++;
		if (j > 0)
		{
			k = 0;
			while (lines[i][j + k])
			{
				lines[i][k] = lines[i][j + k];
				k++;
			}
			lines[i][k] = '\0';
		}
	}
	remove_consecutives_space(lines);
	remove_last_space(lines);
}

int	are_all_digits(char **splitted)
{
	int	i;
	int	j;

	i = 0;
	while (splitted[i])
	{
		j = 0;
		while (splitted[i][j])
		{
			if (!ft_isdigit(splitted[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_color_format(t_map *raw_map, char *line)
{
	char	**splitted;
	char	*color;

	if (ft_strncmp(line, "F ", 2) == 0 || ft_strncmp(line, "C ", 2) == 0)
	{
		color = ft_strchr(line, ' ') + 1;
		splitted = ft_split(color, ',');
		if (ft_arrlen(splitted) == 3)
		{
			if (!(ft_atoi(splitted[0]) < 0 || ft_atoi(splitted[0]) > 255 || \
			ft_atoi(splitted[1]) < 0 || ft_atoi(splitted[1]) > 255 || \
			ft_atoi(splitted[2]) < 0 || ft_atoi(splitted[2]) > 255) && \
			are_all_digits(splitted))
			{
				if (ft_strncmp(line, "F ", 2) == 0)
					raw_map->f_color = ft_strdup(color);
				else
					raw_map->c_color = ft_strdup(color);
				return (ft_free_matrix(splitted, -1), 0);
			}
		}
		return (ft_free_matrix(splitted, -1), 1);
	}
	return (2);
}
