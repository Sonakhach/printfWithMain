/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokhacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:44:02 by sokhacha          #+#    #+#             */
/*   Updated: 2022/05/01 16:36:24 by sokhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
int chek(va_list al, char format)
{
	int n;

	n = 0;
	if (format == 'c')			
		n += ft_putchar(va_arg(al, int));
	else if (format == 's')
		n += ft_putstr(va_arg(al, char *));
	else if (format== 'i' || format == 'd')
		n += ft_putnbr(va_arg(al, int));
	else if (format == 'x')
		n += ft_putnbr_hex(va_arg(al, unsigned int), "0123456789abcdef");
	else if (format == 'X')
		n += ft_putnbr_hex(va_arg(al, unsigned int), "0123456789ABCDEF");
	else if (format == 'p')
		{
			write(1, "0x", 2);
			n += ft_putnbr_base(va_arg(al, unsigned long long), "0123456789abcdef");
			n += 2; 
		}
	else if (format == '%')
	    n += ft_putchar('%');
	else if (format == 'u')
       	n += ft_putnbr_u(va_arg(al, unsigned int));
	return (n);
}

int ft_printf(const char *str, ...)
{
	int i;
	va_list	al;
	int n;

	i = 0;
	n = 0;
	va_start(al, str);
	if (!str || !*str)
		return (0);
	while (str[i])
	{
		if (str[i] == '%')
		{
			n += chek(al, str[i + 1]);
			i += 2;
			// if (str[i + 1] == 'c')			
			// {
			// 	n += ft_putchar(va_arg(al, int));
			// 	i += 2;
			// }
			// else if (str[i + 1] == 's')
			// {
			// 	n += ft_putstr(va_arg(al, char *));
			// 	i += 2;
			// }
			// else if (str[i + 1] == 'i' || str[i + 1] == 'd')
			// {
			// 	n += ft_putnbr(va_arg(al, int));
			// 	i += 2;
			// }
			// else if (str[i + 1] == 'x')
			// {
			// 	n += ft_putnbr_hex(va_arg(al, unsigned int), "0123456789abcdef");
			// 	i += 2;
			// }
			// else if (str[i + 1] == 'X')
			// {
			// 	n += ft_putnbr_hex(va_arg(al, unsigned int), "0123456789ABCDEF");
			// 	i += 2;
			// }
			// else if (str[i + 1] == 'p')
			// {
			// 	write(1, "0x", 2);
			// 	n += ft_putnbr_base(va_arg(al, unsigned long long), "0123456789abcdef");
			// 	n += 2; 
			// 	i += 2;
			// }
			// else if (str[i + 1] == '%')
			// {
			// 	n += ft_putchar('%');
			// 	i += 2;
			// }
			// else if (str[i + 1] == 'u')
            // {
            // 	n += ft_putnbr_u(va_arg(al, unsigned int));
            //     i += 2;
            // }
		}
		else
		{
	 		n += ft_putchar(str[i]);
			i++;
		}
	}
	va_end(al);
	return (n);
}

int main()
{	int d = 37;
	int size1;
	int size2;
//	char d = 'c';
//	char *d = "s";
//	int d = 106676767676767;
	
//	char d = '%';
//	unsigned int	d = 45;

//	size1 = 	ft_printf("Hello %c world\n", d);
//	size1 = ft_printf("Hello %s world\n", d);
 // size1 = ft_printf("Hello %i world\n", d);
   size1 = ft_printf("Hello %x world\n", d);
   //size1 = ft_printf("Hello %X world\n", d);
//   size1 = ft_printf("Hello %p world\n", d);
//	size1 = ft_printf("Hello %% world\n", d);
//size1 =	ft_printf("Hello %u world\n", d);
	size2 = printf("Hello %x world\n", d);
	printf("ft       = %d\n", size1);
	printf("original = %d\n", size2);
	return (0);
}
