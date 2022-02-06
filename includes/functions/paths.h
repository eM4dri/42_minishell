/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 16:04:39 by emadriga          #+#    #+#             */
/*   Updated: 2022/02/06 16:06:29 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATHS_H
# define PATHS_H
/**
 * * Gets path from a given command
 * @param raw_cmd	posible command to process
**/
char	*get_path(const char *raw_cmd);
/**
* *	Checks whether a given path corresponds to file or directory
* @param path		path
* @return			FILE 1/DIRECTORY 0
**/
int		ft_is_directory(const char *path);
#endif
