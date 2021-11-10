/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hveiled <hveiled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 15:08:42 by hveiled           #+#    #+#             */
/*   Updated: 2021/05/06 22:34:29 by hveiled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	close_input(t_msh *msh)
{
	int	i;

	i = -1;
	while (msh->line[++i])
	{
		if (msh->line[i] == '\'' && msh->pf & SNGL)
			return (0);
		if (msh->line[i] == '\"' && msh->pf & DBL)
			return (0);
	}
	return (1);
}

void	get_arg_dop(t_msh *msh)
{
	write(1, "> ", 2);
	shell_prompt(msh, 0, 0, 0);
}

int	is_end(t_msh *msh)
{
	char	ch;
	char	pf;

	pf = msh->pf;
	ch = msh->line[0];
	return (((ch == ' ' || ch == ';' || ch == '|'
				|| ch == '<' || ch == '>')
			&& !(pf & DBL) && !(pf & SNGL)));
}

char	get_flags(char ch, char **line)
{
	del_at_index(line, 0);
	return (ch);
}

int	check_flags(char pf)
{
	return (pf & SNGL || pf & DBL || pf & SNGL || pf & SHL);
}
