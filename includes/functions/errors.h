/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:29:07 by emadriga          #+#    #+#             */
/*   Updated: 2023/04/05 16:49:00 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

/**
 * * Log error into STDERR_FILENO & set catched status error
 * @param str_error		Error to log into STDERR_FILENO
 * @param status_error	status error to set
*/
void	log_error(char *str_error, int status_error);
/**
 * * Log error into STDERR_FILENO & set catched status error
 * * Free malloc log error input
 * @param malloc_str_error	Error to log into STDERR_FILENO
 * @param status_error	status error to set
*/
void	log_error_free(char *malloc_str_error, int status_error);
/**
 * * Count amount of pipes present in tokens
 * @param tokens	tokens list
*/
int		count_pipes(char **tokens);

int		ft_rand_eight_module(const char *str);
void	execve_sleep(void);
int		max_pipes_exceeded(char **tokens);
void	ft_search_word(char *to_find);
void	translate_number(int nbr);
#endif
