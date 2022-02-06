/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredocs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 16:06:22 by emadriga          #+#    #+#             */
/*   Updated: 2022/02/06 16:10:19 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOCS_H
# define HEREDOCS_H
# include "dtos.h"

/**
 * * Piped fork to handle signals without shuting MS
 * * child retrieves heredoc
 * * father waits for child response or sigint
 * @param key	key to match with STDIN_FILENO
*/
char	*get_heredoc_pipedfork(const char *key);
/**
 * * Get heredoc list from token list with open heredocs
 * @param token_list	token list to go through looking for open heredoc
 * 						to retrieve
 * @param heredoc_list	List of heredocs to return
*/
void	get_heredoc_list(char **token_list, t_str **heredoc_list);
#endif
