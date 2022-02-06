/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 00:43:55 by jvacaris          #+#    #+#             */
/*   Updated: 2022/02/06 17:06:40 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/param.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <errno.h>
# include <termios.h>
# include "libft.h"
# include "constants.h"
# include "dtos.h"
# include "functions/builtins.h"
# include "functions/errors.h"
# include "functions/expansions.h"
# include "functions/heredocs.h"
# include "functions/paths.h"
# include "functions/processes.h"
# include "functions/quotes.h"
# include "functions/signals.h"
# include "functions/tokens.h"
# include "functions/utils.h"

t_var	g_var;

#endif
