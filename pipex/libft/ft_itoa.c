/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cyuzbas <cyuzbas@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/18 10:34:54 by cyuzbas       #+#    #+#                 */
/*   Updated: 2021/10/27 11:27:35 by cyuzbas       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	absolute(int n)
{
	if (n > 0)
		return (n);
	else
		return (-n);
}

static int	find_size(int n)
{
	int	size;

	size = 0;
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*zero_or_min(int i)
{
	char	*digit;

	digit = 0;
	if (i == -2147483648)
		digit = ft_strdup("-2147483648");
	else if (i == 0)
		digit = ft_strdup("0");
	if (!digit)
		return (NULL);
	return (digit);
}

char	*ft_itoa(int n)
{
	int		size;
	char	*ascii;	

	if (n == -2147483648 || n == 0)
		return (zero_or_min(n));
	size = find_size(n);
	if (n < 0)
		size++;
	ascii = (char *)malloc(sizeof(char) * (size + 1));
	if (!ascii)
		return (NULL);
	ascii[size] = 0;
	if (n < 0)
		ascii[0] = '-';
	n = absolute(n);
	while (n > 0)
	{
		size--;
		ascii[size] = n % 10 + '0';
		n /= 10;
	}
	return (ascii);
}
