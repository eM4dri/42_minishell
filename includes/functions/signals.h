/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 13:41:51 by emadriga          #+#    #+#             */
/*   Updated: 2022/02/06 13:53:38 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H
/**
 * * Handles signals at forks, different behaviour between father and children
 * @param is_child	bool process is children
*/
void	signal_handler_forks(int is_child);
/**
 * * Handles signals out of forks
*/
void	signal_handler_default(void);
/**
 * * Handles SIGINT signal CTRL+C, end simulation
 * @param signal	signal identifier (see man signal)
*/
void	signal_handler_elephants_sigint(int signal);
/**
 * * Handles SIGINT signal CTRL+C, exit process
 * @param signal	signal identifier (see man signal)
*/
void	signal_handler_process_sigint(int signal);
#endif
