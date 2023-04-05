/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 12:59:31 by emadriga          #+#    #+#             */
/*   Updated: 2023/04/05 16:49:37 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(const char *str, int fd)
{
	char	*s;

	s = (char *)str;
	if (s != NULL)
		while (*s != '\0')
			ft_putchar_fd(*s++, fd);
}
