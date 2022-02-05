/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_ft_strreplace.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 11:17:42 by emadriga          #+#    #+#             */
/*   Updated: 2022/02/05 11:40:54 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <limits.h>
#define STR "Hola CaracolaA" 

int	main(void)
{
	char	*b;

	printf("%zu\n", ULONG_MAX);
	printf("%zu\t%s\n", ft_strlen(STR), STR);
	b = ft_strreplace(STR, "ola", "OLA");
	printf("%zu\t%s\n", ft_strlen(b), b);
	b = ft_strreplace(STR, "ola", "OLAola");
	printf("%zu\t%s\n", ft_strlen(b), b);
	b = ft_strreplace(STR, "ola", "HE");
	printf("%zu\t%s\n", ft_strlen(b), b);
	b = ft_strreplace(STR, "ola", "HELL");
	printf("%zu\t%s\n", ft_strlen(b), b);
	b = ft_strreplace(STR, "ola", "");
	printf("%zu\t%s\n", ft_strlen(b), b);
	b = ft_strreplace(STR, "W", "OLA");
	printf("%zu\t%s\n", ft_strlen(b), b);
	b = ft_strreplace(NULL, "W", "OLA");
	printf("\t%s\n", b);
	b = ft_strreplace("W", NULL, "OLA");
	printf("\t%s\n", b);
	b = ft_strreplace("asdasdasd", "W", NULL);
	printf("\t%s\n", b);
}
