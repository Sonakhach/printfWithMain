/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokhacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 16:45:28 by sokhacha          #+#    #+#             */
/*   Updated: 2022/05/01 16:16:12 by sokhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putchar(int c)
{
    write(1, &c, 1);
    return (1);
}

int ft_putnbr_u(unsigned int nb)
{
	unsigned int i;

	i = 0;
    if (nb < 0)
    {
       nb *= -1;
    }
    if (nb / 10 > 0)
    {
       i += ft_putnbr_u(nb / 10);
    }
    i += ft_putchar(nb % 10 + '0');
    return (i);
}

int	ft_putstr(char	*str)
{
	int	i;

	if (!str)
		str = "(null)";
	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}



int	ft_putnbr(int nb)
{
	int i;

	i = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		i = 11;
	}
	if (nb < 0 && nb != -2147483648)
	{
		i += ft_putchar('-');
		nb *= -1;
	}
	if (nb / 10 > 0)
	{
		i += ft_putnbr(nb / 10);

	}
	if (nb != -2147483648)
	{
		i += ft_putchar(nb % 10 + '0');
	
	}
	return (i);
}

int	ft_putnbr_base(unsigned long long nbr, char *base)
{
	unsigned long long	nbra;
	int			countbase;
	int			a[1000];
	int			i;
	unsigned long	long		j;

	countbase = 0;
	nbra = nbr;
	i = 0;
	j = 0;
	while (base[countbase] != '\0')
		countbase++;
	if (nbra == 0)
		j += write(1,"0", 1);
	while (nbra > 0)
	{
		a[i] = nbra % countbase;
		nbra = nbra / countbase;
		i++;
	}
	while (--i != -1)
		j += write(1, &base[a[i]], 1);
	return (j);
}

int	ft_putnbr_hex(unsigned int nbr, char *base)
{
	unsigned int	nbra;
	int			countbase;
	int			a[1000];
	int			i;
	unsigned int		j;

	countbase = 0;
	nbra = nbr;
	i = 0;
	j = 0;
	if (nbra == 0)
		j += write(1,"0", 1);
	while (base[countbase] != '\0')
		countbase++;	
	while (nbra > 0)
	{
		a[i] = nbra % countbase;
		nbra = nbra / countbase;
		i++;
	}
	while (--i != -1)
		j += write(1, &base[a[i]], 1);
	return (j);
}