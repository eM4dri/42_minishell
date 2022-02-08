/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 13:33:49 by emadriga          #+#    #+#             */
/*   Updated: 2022/02/08 14:15:15 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENS_H
# define TOKENS_H

/**
 * * Returns token non redir type
 * @param token	token to identify
*/
int		eval_token_non_redir(const char *token);
/**
 * * Returns token redir type
 * @param token	token to identify
*/
int		eval_token_redir(const char *token);
/**
 * * Get tokens from and input string
 * * Token is the minimun divisible item to handle on MiniShell
 * @param input	input to tokenize
 * @return 		array of tokens
*/
char	**get_token_list(char *input);
/**
 * * Detects open pipes & redirections
 * @param array	array of args (input splited in useful tokens)
 * @return 		ERNNO code is returnerd
*/
int		has_pipe_redir_open(char **array);
/**
 * * Eval if input has valid token to process
 * * Token is the minimun divisible item to handle on MiniShell
 * @param input	input to tokenize
 * @return		if input has valid token to process
*/
int		has_token(const char *input);
#endif
