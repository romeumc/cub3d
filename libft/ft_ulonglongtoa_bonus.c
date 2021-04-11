/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulonglongtoa_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 23:21:30 by rmartins          #+#    #+#             */
/*   Updated: 2021/04/12 00:42:55 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(unsigned long long number)
{
	int	i;

	i = 0;
	while (number != 0)
	{
		number /= 10;
		i++;
	}
	return (i);
}

static void	ft_putnbr_str(unsigned long long nb, char *str, int len)
{
	while (nb != 0)
	{
		len--;
		str[len] = (nb % 10) + '0';
		nb /= 10;
	}
}

char	*ft_ulonglongtoa(unsigned long long n)
{
	int		len;
	char	*str;

	len = get_size(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	ft_putnbr_str(n, str, len);
	str[len] = '\0';
	return (str);
}
