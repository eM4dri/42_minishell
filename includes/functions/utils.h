/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 13:16:11 by emadriga          #+#    #+#             */
/*   Updated: 2022/02/08 14:15:26 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "dtos.h"

/**
 * * This function recieves a list of strings (pointer to pointers) and frees
 * * everything, including the main pointer. The last string must be NULL.
 * @param list		array to free
**/
void			array_str_free(char ***list);
/**
 * * Print array of strings
 * @param array	array
*/
void			array_str_print(char **array);
/**
 * * Get size of array of strings
 * @param array	array
*/
int				array_str_get_size(char **array);

/**
 * * Add new node into list at begining
 * @param list		list
 * @param new_node	new node to link
*/
void			lst_process_add_front(t_p **list, t_p *new_node);
/**
 * * Add new node into list at ending
 * @param list		list
 * @param new_node	new node to link
*/
void			lst_process_add_back(t_p **list, t_p *new_node);
/**
 * * Returns malloced node
*/
t_p				*lst_process_new(void);
/**
 * * Free list
 * @param list	list
*/
void			lst_process_free(t_p **list);
/**
 * * Print list
 * @param list
*/
void			lst_process_print(t_p *list);

/**
 * * Add new node into list at begining
 * @param list	list
 * @param new_node	new node to link
*/
void			lst_redir_add_front(t_redirection **list, \
					t_redirection *new_node);
/**
 * * Add new node into list at ending
 * @param list	list
 * @param new_node	new node to link
*/
void			lst_redir_add_back(t_redirection **list, \
					t_redirection *new_node);
/**
 * * Returns malloced node
*/
t_redirection	*lst_redir_new(void);
/**
 * * Free list
 * @param list	list
*/
void			lst_redir_free(t_redirection **list);
/**
 * * Print list
 * @param list
*/
void			lst_redir_print(t_redirection *list);

/**
 * * Add new str into list at alphabeticallly sorted
 * @param list	list
 * @param str	new str to link
*/
void			lst_str_add_sorted(t_str **list, char *str);
/**
 * * Free list
 * @param list	list
*/
void			lst_str_free(t_str **list);
/**
 * * Print list of strings
 * @param list	list
*/
void			lst_str_print(t_str *list);
/**
 * * Delete every matched str of size len from list
 * @param list	list
 * @param str	str to delete
 * @param len	len to match with ft_strncmp
*/
void			lst_str_delete(t_str **list, char *str, size_t len);
/**
 * * Add new str into list at front
 * @param list	list
 * @param str	new str to link
*/
void			lst_str_add_front(t_str **list, char *str);
/**
 * * Add new str into list at back
 * @param list	list
 * @param str	new str to link
*/
void			lst_str_add_back(t_str **list, char *str);
/**
 * * Look for a str on the list returning node if found
 * @param list	list
 * @param str	new str to look for
*/
t_str			*lst_str_get_str(t_str **list, const char *str);
/**
 * * Transform str linked list into array
 * * Returns array of str
 * @param list	str list
*/
char			**lst_str_to_array(t_str **list);
#endif
