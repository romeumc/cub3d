/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 13:14:01 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/18 13:17:24 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_extension(char *argv, char *extension)
{
	char	*temp;

	if (ft_strlen(argv) > 4)
		temp = ft_substr(argv, (int)ft_strlen(argv) - 4, 4);
	else
		temp = ft_strdup("");
	if (!ft_strequ(temp, extension))
	{
		free(temp);
		return (0);
	}
	free(temp);
	return (1);
}