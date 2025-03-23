/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 00:57:11 by schahir           #+#    #+#             */
/*   Updated: 2025/03/23 06:46:37 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	is_valid_number(char *str)
{
	long	value;
	int		i;

	i = 0;
	value = 0;
	if (!str || !*str)
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		value = value * 10 + (str[i] - '0');
		i++;
		if (value > INT_MAX)
			return (0);
	}
	if (str[i] != '\0')
		return (0);
	return (1);
}
