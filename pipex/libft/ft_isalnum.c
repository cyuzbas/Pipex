/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalnum.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cyuzbas <cyuzbas@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/04 13:38:05 by cyuzbas       #+#    #+#                 */
/*   Updated: 2021/10/26 10:55:26 by cyuzbas       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	int	x;

	x = 0;
	if (ft_isdigit(c) || ft_isalpha(c))
		x = 1;
	return (x);
}
