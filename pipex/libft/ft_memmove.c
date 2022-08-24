/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cyuzbas <cyuzbas@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/05 11:13:35 by cyuzbas       #+#    #+#                 */
/*   Updated: 2021/10/26 10:57:31 by cyuzbas       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*d;
	char	*s;
	size_t	i;

	d = (char *)dest;
	s = (char *)src;
	i = 0;
	if (!d && !s)
		return (NULL);
	while (i < len)
	{
		if (d < s)
			d[i] = s[i];
		else
			d[len - i - 1] = s[len - i - 1];
		i++;
	}
	return (dest);
}
