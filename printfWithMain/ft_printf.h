/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokhacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 16:30:01 by sokhacha          #+#    #+#             */
/*   Updated: 2022/04/30 16:44:08 by sokhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>


int ft_putchar(int c);
int	ft_putstr(char	*str);
int	ft_putnbr(int nb);
int ft_putnbr_u(unsigned int nb);
int	ft_putnbr_base(unsigned long long nbr, char *base);
int	ft_putnbr_hex(unsigned int nbr, char *base);
int ft_printf(const char *str, ...);


#endif
