/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 17:18:24 by jvacaris          #+#    #+#             */
/*   Updated: 2022/02/06 17:28:22 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#define LITERAL_PATH "PATH"
#define COMMAND_NOT_FOUND "Error: command {0} not found.\n"
#define PATH_NOT_FOUND "Error: env variable 'PATH' not found.\n"
#define IS_DIRECTORY "{0}: is a directory\n"
#define PERM_DENIED "{0}: Permission denied\n"
#define FILE_NOT_FOUND "{0}: No such file or directory\n"

static char	*ft_strslashjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 2;
	join = ft_calloc(sizeof(char), len);
	if (!join)
		return (0);
	ft_strlcat(join, s1, len);
	ft_strlcat(join, "/", len);
	ft_strlcat(join, s2, len);
	return (join);
}

/**
* *	Checks if a given string has a path format 
* * A str has path format when contains '/'	or it's composed of a single '~')
 * @param str
**/
static int	has_path_format(const char *str)
{
	int	a;

	a = 0;
	while (str[a])
	{
		if (str[a] == '/')
			return (TRUE);
		a++;
	}
	if (a == 1 && str[0] == '~')
		return (TRUE);
	return (FALSE);
}

/**
 * * Gets path from a given command
 * @param command	commmand to look for
 * @param path		env's path
**/
static char	*get_command_path(const char *command, const char	*path)
{
	int		idx;
	char	**path_list;
	char	*result;

	idx = 0;
	path_list = ft_split(path, ':');
	while (path_list[idx])
	{
		result = ft_strslashjoin(path_list[idx++], command);
		if (!access(result, X_OK))
			break ;
		free(result);
		result = NULL;
	}
	array_str_free(&path_list);
	if (result == NULL)
		log_error_free(ft_strreplace(COMMAND_NOT_FOUND, "{0}", command), 127);
	return (result);
}

/**
 * * Gets path from a given command
 * @param raw_cmd	posible command to process
**/
char	*get_path(const char *raw_cmd)
{
	char	*path;

	if (has_path_format(raw_cmd) == TRUE)
	{
		if (access(raw_cmd, F_OK))
			log_error_free(ft_strreplace(FILE_NOT_FOUND, "{0}", raw_cmd), 127);
		else if (!ft_is_directory(raw_cmd))
			log_error_free(ft_strreplace(IS_DIRECTORY, "{0}", raw_cmd), 126);
		else if (access(raw_cmd, X_OK))
			log_error_free(ft_strreplace(PERM_DENIED, "{0}", raw_cmd), 126);
		else
			return (ft_strdup(raw_cmd));
		return (NULL);
	}
	path = ft_getenv(LITERAL_PATH);
	if (!*path)
	{
		log_error(PATH_NOT_FOUND, 1);
		return (NULL);
	}
	return (get_command_path(raw_cmd, path));
}

/**
* *	Checks whether a given path corresponds to file or directory
* @param path		path
* @return			FILE 1/DIRECTORY 0
**/
int	ft_is_directory(const char *path)
{
	struct stat	path_stat;

	stat(path, &path_stat);
	return (S_ISREG(path_stat.st_mode));
}
