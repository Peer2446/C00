/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wongamph <wongamph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:10:27 by wongamph          #+#    #+#             */
/*   Updated: 2023/06/19 13:02:01 by wongamph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	checkerror(char *base)
{
	int	i;
	int	j;
	int	lenbase;

	lenbase = ft_strlen(base);
	i = 0;
	if (lenbase < 2)
		return (1);
	while (i < lenbase)
	{
		j = i +1;
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| (base[i] >= 9 && base[i] <= 13))
			return (1);
		while (j < lenbase)
		{
			if (base[i] == base[j])
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	lenbase;

	lenbase = ft_strlen(base);
	if (checkerror(base) == 0)
	{
		if (nbr < 0)
		{
			write(1, "-", 1);
			if (nbr <= -1 * lenbase)
				ft_putnbr_base(-1 * (nbr / lenbase), base);
			ft_putnbr_base((nbr % lenbase) * -1, base);
		}
		else if (nbr < lenbase)
		{
			write(1, &base[nbr], 1);
		}
		else
		{
			ft_putnbr_base(nbr / lenbase, base);
			ft_putnbr_base(nbr % lenbase, base);
		}
	}
}
/*int main()
{
	ft_putnbr_base(-2, "01 ");
}*/
