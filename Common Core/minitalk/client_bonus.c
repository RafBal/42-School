/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:14:36 by rbaldin           #+#    #+#             */
/*   Updated: 2025/02/16 13:49:19 by rbaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_bit_count = 0;

void	char_sending(int p, unsigned char c)
{
	size_t	i;

	i = 8;
	while (i--)
	{
		if ((c >> i) & 1)
			kill(p, SIGUSR1);
		else
			kill(p, SIGUSR2);
		usleep(2000);
	}
}

/*
Example: Binary representation of 2: 00000010

Loop iterations (i from 7 to 0):

For i = 7: (c >> 7) & 1 == 0 (_0_0000010) → get '0'
For i = 6: (c >> 6) & 1 == 0 (0_0_000010) → get '0'
For i = 5: (c >> 5) & 1 == 0 (00_0_00010) → get '0'
For i = 4: (c >> 4) & 1 == 0 (000_0_0010) → get '0'
For i = 3: (c >> 3) & 1 == 0 (0000_0_010) → get '0'
For i = 2: (c >> 2) & 1 == 0 (00000_0_10) → get '0'
For i = 1: (c >> 1) & 1 == 1 (000000_1_0) → get '1'
For i = 0: (c >> 0) & 1 == 0 (0000001_0_) → get '0'

Output: 00000010
*/

static	void	acknowledging(int s)
{
	(void)s;
	g_bit_count++;
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	i = 0;
	pid = ft_atoi(argv[1]);
	if (argc == 3)
	{
		if (pid > 0)
		{
			signal(SIGUSR2, acknowledging);
			while (argv[2][i])
			{
				char_sending(pid, (unsigned char)argv[2][i]);
				i++;
			}
			char_sending(pid, '\0');
			if (++i == (g_bit_count / 8))
				ft_printf("Message sent successfully.\n");
		}
	}
	return (0);
}
/*
 The signal function is directly related to the kill function from the 
 server. Whenever it receives the SIGUSRN signal, it triggers the 
 acknowledging function, which follows a predefined format prototype.
 The acknowledging function enhances synchronization between client and
 server. In this application, it is used to acknowledge the 
 transmission of each bit.

char_sending(pid, '\0'); avoids signal corruption, as the server might
continue to read anything that do not belong to the original message
without this termination.

Because the acknowledging function contains just one parameter and does
not return any value, a global variable was used and then compared 
to acknowledge the message.

1 byte = 8 bits = 1 character
 */
