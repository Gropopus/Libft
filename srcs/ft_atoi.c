/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 11:42:17 by thsembel          #+#    #+#             */
/*   Updated: 2020/09/08 13:59:44 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isspace(const char *str, int i)
{
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	return (i);
}

int		ft_atoi(const char *str)
{
	int		i;
	int		np;
	int		ret;
	long	res;

	np = 1;
	res = 0;
	ret = 1;
	i = ft_isspace(str, 0);
	if (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			np = np * -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		res = res * 10 + (str[i] - '0');
		if (res < 0 && (np == 1))
			ret = -1;
		else if (res < 0 && (np == -1))
			ret = 0;
		i++;
	}
	return (ret == 1 ? res * np : ret);
}
