/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 02:51:56 by ssghioua          #+#    #+#             */
/*   Updated: 2024/01/29 02:51:59 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_uint_len(unsigned int nb)
{
	int	int_len;

	int_len = 0;
	while (nb > 9)
	{
		nb /= 10;
		int_len++;
	}
	if (nb > 0)
		int_len++;
	return (int_len);
}

char	*ft_fill_ui_str(unsigned int nb, int int_len)
{
	int		i;
	char	*res;

	i = 0;
	res = (char *)malloc ((int_len + 1) * sizeof(char));
	if (res == NULL)
		return (res);
	while (nb)
	{
		res[int_len - 1 - i] = (nb % 10) + '0';
		nb /= 10;
		i++;
	}
	res[int_len] = '\0';
	return (res);
}

char	*ft_uitoa(unsigned int n)
{
	int		int_len;

	if (n == 0)
		return (ft_strjoin("0", ""));
	int_len = ft_check_uint_len(n);
	return (ft_fill_ui_str(n, int_len));
}
