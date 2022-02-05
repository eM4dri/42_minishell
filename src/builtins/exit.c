/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 15:35:41 by emadriga          #+#    #+#             */
/*   Updated: 2022/02/05 13:40:24 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#define EXIT_NUM_REQUIRED "exit: {0}: numeric argument required\n"
#define EXIT_ARG_EXCEEDED "exit: too many arguments\n"
#define EXIT_MAX_INPUT_LEN 19

/**
 * * Return exit status from a number given
 * * 0 is returned for bigger numbers than INT_MAX
 * @param str_nbr	string number to get exit status
*/
static int	get_exit_status(const char *str_nbr, int is_negative)
{
	unsigned int	nbr;
	unsigned int	result;

	nbr = 0;
	while (*str_nbr >= '0' && *str_nbr <= '9' && nbr < INT_MAX)
		nbr = 10 * nbr + (int)(*str_nbr++ - '0');
	if (nbr > INT_MAX)
		nbr = 0;
	result = nbr % UCHAR_MAX;
	if (is_negative)
		return (UCHAR_MAX - result + 1);
	return (result);
}

/**
 * * This should recreate the bash funtion "exit".
 * * Causes normal process termination and the status is returned
 * @param argv	vector of arguments
*/
void	ft_exit(char **argv)
{
	int		i;
	char	*str;

	str = argv[1];
	if (argv[1] == NULL)
		exit(EXIT_SUCCESS);
	i = 0;
	if (*str == '-')
		str++;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] != '\0' || i > EXIT_MAX_INPUT_LEN)
		log_error_free(ft_strreplace(EXIT_NUM_REQUIRED, "{0}", argv[1]), 255);
	else if (argv[2] != NULL)
	{
		log_error(EXIT_ARG_EXCEEDED, 1);
		return ;
	}
	else
		g_var.current_status = get_exit_status(str, *argv[1] == '-');
	lst_str_free(&g_var.env);
	exit(g_var.current_status);
}
