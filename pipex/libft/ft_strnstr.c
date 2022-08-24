/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cyuzbas <cyuzbas@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/11 15:26:27 by cyuzbas       #+#    #+#                 */
/*   Updated: 2021/10/26 11:06:29 by cyuzbas       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		index;
	size_t		flag;

	if (*needle == 0 || ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (0 < len && *haystack != 0)
	{
		if (*haystack == *needle)
		{
			index = 0;
			flag = 0;
			while (index < len && haystack[index] != '\0' \
					&& needle[index] != '\0')
			{
				if (haystack[index] == needle[index])
					flag++;
				index++;
			}
			if (flag == ft_strlen(needle))
				return ((char *)haystack);
		}
		len--;
		haystack++;
	}
	return (0);
}
