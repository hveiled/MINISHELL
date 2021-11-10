/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehande <ehande@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 15:39:49 by hveiled           #+#    #+#             */
/*   Updated: 2021/05/06 18:23:49 by ehande           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	pip(t_msh *msh, char **line)
{
	msh->cmd->pipe = 1;
	skip_sp_ch(line, '|');
	new_cmd(&(last_cmd(msh->cmd)->next));
}

static void	redir(t_msh *msh, char **line, int *dir, char ch)
{
	skip_sp_ch(line, ch);
	if (**line == '>')
		msh->cmd->dbl_r_redir = 1;
	else
	{
		if (*dir)
		{
			close(open(msh->cmd->file, O_CREAT | O_TRUNC, 0644));
			free(msh->cmd->file);
		}
		*dir = 1;
	}
	skip_sp_ch(line, ch);
	last_cmd(msh->cmd)->file = get_arg(msh, NULL, F_NONE);
}

int	pars_line(t_msh *msh, char **line)
{
	if (**line == ';')
		del_to_index(line, 1);
	while (*line && **line && **line != ';')
	{
		skip_sp_ch(line, ' ');
		if (**line == '|')
			pip(msh, line);
		else if (**line == '<' || **line == '>')
		{
			if ((*line)[0] == '<')
				redir(msh, line, &(last_cmd(msh->cmd)->l_redir), '<');
			else
				redir(msh, line, &(last_cmd(msh->cmd)->r_redir), '>');
		}
		else
			add_l_line(&(last_cmd(msh->cmd)->arg), get_arg(msh, NULL, F_NONE));
	}
	return (1);
}
