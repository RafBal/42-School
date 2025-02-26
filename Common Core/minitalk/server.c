/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:22:07 by rbaldin           #+#    #+#             */
/*   Updated: 2025/02/26 15:15:36 by rbaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handling(int numeric_signal, siginfo_t *i, void *c)
{
	volatile static unsigned char	char_accumulator;
	volatile static size_t			bc;
	volatile static size_t			init;

	(void)c;
	if (init == 0)
	{
		char_accumulator = 0;
		bc = 0;
		init = 1;
	}
	if (numeric_signal == SIGUSR1)
		char_accumulator |= (1 << (7 - bc));
	bc++;
	if (bc == 8)
	{
		ft_printf("%c", char_accumulator);
		if (char_accumulator == '\0')
			ft_printf("\n");
		bc = 0;
		char_accumulator = 0;
	}
	kill(i->si_pid, SIGUSR2);
}

/*
 	void    handling(int numeric_signal, siginfo_t *i, void *c)
The numeric_signal provides the either SIGUSR1 or SIGUSR2.
i is a pointer that contains additional information about the signal.

         if (init == 0)
The init static variable was created to control the proper initialization 
of the character accumulator and bit count, so they are not reset to 
zero whenever the handling function is called.
         char_accumulator <<= 1;                         
         if (numeric_signal == SIGUSR2)         
                 char_accumulator |= 1;         
         bc++; 
 The accumulator moves one bit to the left to assess the new bit value.
 After doing this, it verifies if the signal is 1, and change from 
zero to 1. Then it increments until 8 bits before printing.
	kill(info->si_pid, SIGUSR2);
This acknowledgment informs the client that the current byte has been processed 
before the next one is sent. si_pid; Sending process ID
*/

int	main(void)
{
	pid_t				pid;
	struct sigaction	signal_in_action;

	pid = getpid();
	signal_in_action.sa_flags = SA_SIGINFO;
	signal_in_action.sa_sigaction = handling;
	sigemptyset(&signal_in_action.sa_mask);
	sigaction(SIGUSR1, &signal_in_action, NULL);
	sigaction(SIGUSR2, &signal_in_action, NULL);
	ft_printf("PID from the server = %d\n", pid);
	while (1)
		pause();
	return (0);
}
/*
         signal_in_action.sa_sigaction = handling;
The sigaction struct has a function variable called sa_handler defined as: 
void     (*sa_sigaction)(int, siginfo_t *, void *);
Its objective is to do something with the received signal from the client.
It is considered a better approach than void     (*sa_handler)(int); as it
is more resilient. It allows communication right back to the client.
E.g. to show the message on the server side.

         sigemptyset(&signal_in_action.sa_mask);
The mask is initialized in a way that removes any blockages to signals.
         signal_in_action.sa_flags = SA_SIGINFO;
The SA_SIGINFO flag enables the use of the sa_sigaction function, which 
contains three parameters.

         sigaction(SIGUSR1, &sa, NULL);
         sigcation(SIGUSR2, &sa, NULL);
SIGUSR1 represents bit 0, while SIGUSR2 represents bit 1.
They are both passed and enabled to the handling function by the sigaction
function.
*/
