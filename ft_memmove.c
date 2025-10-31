/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemonthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 18:07:07 by jemonthi          #+#    #+#             */
/*   Updated: 2025/10/18 20:55:44 by jemonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*ptr1;
	unsigned char		*ptr2;

	i = 0;
	ptr1 = (const unsigned char *)src;
	ptr2 = (unsigned char *)dest;
	if (!dest && !src)
		return (NULL);
	if (ptr2 < ptr1)
	{
		while (i < n)
		{
			ptr2[i] = ptr1[i];
			i++;
		}
		return (dest);
	}
	i = n;
	while (i > 0)
	{
		i--;
		ptr2[i] = ptr1[i];
	}
	return (dest);
}
