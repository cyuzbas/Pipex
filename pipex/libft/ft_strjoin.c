/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cyuzbas <cyuzbas@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/18 10:27:09 by cyuzbas       #+#    #+#                 */
/*   Updated: 2021/10/26 11:09:29 by cyuzbas       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		total;
	int		i;
	char	*result;

	if (s1 == NULL || s2 == NULL)
		return (0);
	total = ft_strlen(s1) + ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (total + 1));
	if (!result)
		return (0);
	i = 0;
	while (*s1 != 0)
	{
		result[i] = *s1;
		s1++;
		i++;
	}
	while (*s2 != 0)
	{
		result[i] = *s2;
		s2++;
		i++;
	}
	result[i] = 0;
	return (result);
}
