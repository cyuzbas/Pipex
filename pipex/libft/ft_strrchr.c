/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cyuzbas <cyuzbas@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/13 13:15:17 by cyuzbas       #+#    #+#                 */
/*   Updated: 2021/10/13 13:55:48 by cyuzbas       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int c)
{
	int		s_len;
	char	*s;

	s = (char *) string;
	s_len = ft_strlen(s);
	while (s_len > 0 && s[s_len] != (char)c)
		s_len--;
	if (s[s_len] == (char)c)
		return (&s[s_len]);
	return (0);
}
