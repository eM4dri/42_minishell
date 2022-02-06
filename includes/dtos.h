/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dtos.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 00:43:55 by jvacaris          #+#    #+#             */
/*   Updated: 2022/02/06 12:50:03 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DTOS_H
# define DTOS_H
# include <unistd.h>
# include <termios.h>

typedef struct s_str
{
	char			*str;
	struct s_str	*next;
}t_str;

typedef struct s_var
{
	t_str			*env;
	int				current_status;
	int				last_status;
	int				waitedheredoc;
	size_t			rng;
	int				elephants;
	struct termios	termios;
}t_var;

typedef struct s_redirection{
	int						type;
	char					*go_to;
	struct s_redirection	*next;
}t_redirection;

typedef struct s_process{
	int						type;
	int						status;
	char					*pathname;
	char					**argv;
	t_str					*args;
	t_redirection			*redir;
	struct s_process		*next;
}t_p;

typedef struct s_fd{
	int	fd[2];
}t_fd;

#endif
