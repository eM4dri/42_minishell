/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:53:38 by emadriga          #+#    #+#             */
/*   Updated: 2022/02/08 14:15:35 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUOTES_H
# define QUOTES_H

/**
 * * Piped fork to handle unclosed quotes with signals without shuting MS
 * * child refresh input str with new STDIN_FILENO input
 * * father waits for child response or sigint
 * @param key	key to match with STDIN_FILENO
*/
char	*close_quotes_pipedfork(char *str);
/**
* * Remove quotes from a str given
* * str can be freed if needed
* @param str	str to process
* @param free	boolean handle str free
* @return 		str with quotes removed
*/
char	*remove_quotes(char *str, int free);
/**
* * This function detects if there's quotation marks unclosed through the input
* * given. Quotation marks inside other types of quotation marks are excluded.
* * If all goes well, the value 0 is returned.
* @return 		ERNNO code is returnerd
*/
int		qm_error_detector(char *str);
#endif
