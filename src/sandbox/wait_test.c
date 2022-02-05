/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 11:05:47 by emadriga          #+#    #+#             */
/*   Updated: 2022/02/05 11:14:39 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

#define NUM_CHILD 5

int	do_something(int i)
{
	int	ret;

	srand(getpid());
	ret = (rand() % 256);
	if (i % 2)
		sleep(10);
	printf("HIJO: PID  = %d, valor aleatorio calculado %d \n", getpid(), ret);
	return (ret);
}

/*
 * *  Run test
clang -Wall -Wextra -Werror -g3 -fsanitize=address -pedantic 
src/sandbox/wait_test.c -o sandboxtest && ./sandboxtest && rm -rf 
sandboxtest*
*/
int	main(void)
{
	pid_t	pid;
	int		i;
	int		status;

	i = -1;
	while (++i < NUM_CHILD)
	{
		pid = fork();
		if (pid > 0)
			continue ;
		else if (pid == 0)
			exit(do_something(i));
		else
			exit(-1);
	}
	i = -1;
	while (++i < NUM_CHILD)
	{
		pid = wait(&status);
		printf("PADRE de PID  = %d, hijo de PID = %d terminado, st %d \n", \
		getpid(), pid, WEXITSTATUS(status));
	}
	while (1)
		sleep(10);
}
