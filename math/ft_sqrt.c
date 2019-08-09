/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 18:41:31 by chermist          #+#    #+#             */
/*   Updated: 2019/08/09 17:32:11 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<libft.h>

int	ft_sqrt(int x)
{
	int		start;
	int		end;
	int		ans;
	int		mid;

	start = 1;
	end	= x;
	if (x == 0 || x == 1)
		return (x);
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (mid*mid == x)
			return (mid);
		if (mid * mid < x)
		{
			start = mid + 1;
			ans = mid;
		}
		else
			end = mid - 1;
	}
	return ans;
}
