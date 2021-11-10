/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_2d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hveiled <hveiled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:39:05 by ehande            #+#    #+#             */
/*   Updated: 2021/05/04 11:20:03 by hveiled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arr.h"
#include "../libft/libft.h"

void	free_2d(char ***input)
{
	int	i;

	i = 0;
	while ((*input)[i])
		free((*input)[i++]);
	free(*input);
	*input = NULL;
}
