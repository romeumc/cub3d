/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:38:49 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/18 14:52:41 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_cub3d.h"

void	print_error(char *s1, char *s2)
{
	printf(ANSI_F_RED "Error\n" ANSI_RESET);
	printf(ANSI_F_BRED "%s %s\n" ANSI_RESET, s1, s2);
}
