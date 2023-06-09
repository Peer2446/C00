/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wongamph <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:26:19 by wongamph          #+#    #+#             */
/*   Updated: 2023/06/13 12:30:45 by wongamph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcat(char *dest, char *src)
{
	int	begin;

	begin = 0;
	while (dest[begin] != '\0')
	{
		begin++;
	}
	while (*src != '\0')
	{
		dest[begin++] = *src++;
	}
	dest[begin] = '\0';
	return (dest);
}
