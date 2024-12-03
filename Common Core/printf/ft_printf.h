/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:54:34 by rbaldin           #+#    #+#             */
/*   Updated: 2024/12/02 15:37:55 by rbaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(const char *type, ...);
int	ft_printf_char(va_list args, int fd);
int	ft_printf_str(va_list args, int fd);
int	ft_printf_ptr(va_list args, int fd);
int	ft_putnbr_fd_count(va_list args, int fd);
int	ft_nbrn_count(int n, int fd);
int	ft_put_uns_nbr_count(va_list args, int fd);
int	ft_put_hex(va_list args, int fd, const char form);
// ... other declarations

#endif

/* Importance of the libraries added:
 * <stdarg.h> for variadic functions:
 * 	va_start: initializes the va_list to retrieve arguments.
 * 	va_arg: accesses the next argument in the list.
 * 	va_end: cleans up the va_list after use.
 * 	va_copy: duplicates a va_list if needed.
 * <unistd.h> for low-level POSIX system calls:
 * 	write: outputs data to a file descriptor.
 * 	read: reads data from a file descriptor.
 * 	close: closes file descriptors.
 * <stdlib.h> for memory management control:
 * 	malloc: allocates memory dynamically.
 * 	free: frees memory dynamically.
 * 	atoi: converts strings to integers.
 * 	itoa: converts integers to strings.
 * 	exit: terminates the program.*	
 * Source: 42 Peer: Code copilot - C/C++ Docker Makefile GPT
 */
