/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:32:22 by emadriga          #+#    #+#             */
/*   Updated: 2022/02/06 12:52:43 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H
# include "dtos.h"

/**
 * * Redirect to proper builtin
 * @param argv		arguments vector
*/
void	ft_builtins(char **argv);
/**
 * * This should recreate the bash funtion "cd".
 * * Shall change the working directory of the current shell execution
 * @param argv	vector of arguments containing records to add
*/
void	ft_cd(char **argv);
/**
 * * This should recreate the bash funtion "echo".
 * @param list	vector of arguments containing records to echoed
*/
void	ft_echo(char **argv);
/**
 * * Initialize minishel enviroment variables list from input list
 * @param env_vector	input enviroment vector at exec ./minishell
 * @param env_list		output enviroment list returned
*/
void	init_ms_env(char **env_vector, t_str **env_list);
/**
 * * This should recreate the bash funtion "env".
 * * Returms enviroment variables list
 * @param argv		vector of arguments (ERROR if not null)
*/
void	ft_env(char **argv);
/**
 * * This should recreate the stdlib.h funtion "getenv".
 * * Searches the environment list to find the environment variable name, \
 * * and returns a pointer to the corresponding value string
 * @param str		new str to look for
*/
char	*ft_getenv(const char *str);
/**
 * * This should recreate the bash funtion "exit".
 * * Causes normal process termination and the status is returned
 * @param argv	vector of arguments
*/
void	ft_exit(char **argv);
/**
 * * This should recreate the bash funtion "export".
 * * Returns ENV alphabetically-sorted
 * * Add records (through argumment vector) to enviroment variables list
 * @param argv	vector of arguments containing records to add
*/
void	ft_export(char **argv);
/**
 * * This should recreate the bash funtion "pwd".
 * * Returms current working directory
 * @param argv		vector of arguments (ERROR if not null)
*/
void	ft_pwd(char **argv);
/**
 * * This should recreate the bash funtion "unset".
 * * Remove enviroment record passed on argumment vector.
 * @param env_list	enviroment list
 * @param argv	vector of arguments containing records to remove
*/
void	ft_unset(char **argv);
#endif
