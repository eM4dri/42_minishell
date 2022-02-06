/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:56:49 by emadriga          #+#    #+#             */
/*   Updated: 2022/02/06 13:32:02 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSIONS_H
# define EXPANSIONS_H
/**
 * * Given str expand character tilde (~) to their value
 * @param str			str to expand it content
 * @return				str expanded
*/
char	*expanse_tilde(const char *str);
/**
 * * Given str expand env variables ($ followed by characters) to their values
 * @param str			str to expand it content
 * @return				str expanded
*/
char	*ft_expand(const char *str);
/**
 * * Given str expand env variables to their values for heredoc
 * @param maloc_str		malloc str to expand it content
 * @return				str expanded
*/
char	*ft_expand_heredoc(char *malloc_str);
/**
 * * Given str expand env variables ($ followed by characters) to their values
 * * Input str should come malloc
 * @param malloc_str	str to expand it content
 * @param is_heredoc	is called from heredoc
 * @return				str expanded
*/
char	*recursive_expand(char *malloc_str, int is_heredoc);
#endif
