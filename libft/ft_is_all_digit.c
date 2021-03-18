/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_all_digit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 13:21:30 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/18 13:22:03 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_is_all_digit(char *str)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(str))
	{
		if (!(ft_isdigit(str[i])))
			return ("0");
		i++;
	}
	return (str);
}
