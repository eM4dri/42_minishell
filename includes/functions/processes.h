/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 13:13:59 by emadriga          #+#    #+#             */
/*   Updated: 2022/02/08 14:15:57 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESSES_H
# define PROCESSES_H
# include "dtos.h"

/**
 * * Returns processes to handle with pipes
 * * Every process has needed info to execute later
 * @param tokens	tokens list
 * @param processes	list of process to return
*/
void	get_processes(char **tokens, t_p **processes);
/**
 * * Handle process redirections
 * @param r		process redirection
*/
void	process_redirections(t_redirection *r);
/**
 * * Run processes
 * @param processes	processes to run
 * @param p_count	number of processes to run
*/
void	run_processes(t_p **processes, int p_count);
#endif
