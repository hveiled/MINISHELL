/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hveiled <hveiled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:50:54 by hveiled           #+#    #+#             */
/*   Updated: 2021/05/05 17:45:22 by hveiled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (-1);
	if (len == 0)
		return (0);
	while (s1[i] != '\0' && s2[i] != '\0' && i < len && s1[i] == s2[i])
		i++;
	if (i == len)
		return (0);
	return (((unsigned char)s1[i]) - ((unsigned char)s2[i]));
}
