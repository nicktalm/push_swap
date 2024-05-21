/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:40:03 by ntalmon           #+#    #+#             */
/*   Updated: 2023/10/27 16:34:25 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *print, ...);
int		ft_putstr(char *s, int *counter);
int		ft_putchar(char c);
int		what_to_print1(va_list	ptr, int *counter, char print);
int		what_to_print2(va_list	ptr, int *counter, char print);
int		what_to_print3(va_list	ptr, int *counter, char print);
int		ft_putnbr(int nb, int *counter);
int		ft_smallx_putnbr(unsigned int ch, int *counter);
int		ft_bigx_putnbr(unsigned int ch, int *counter);
int		ft_u_putnbr(unsigned int n, int *counter);
int		ft_p_putnbr(unsigned long int ch, int *counter);
int		ft_putchar_nbr(char c, int *counter);
int		ft_putnbr_base(unsigned int ch, int *counter, char *base);
int		flag_check(va_list ptr, int *c, char print);

#endif