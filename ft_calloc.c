/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemonthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 19:21:50 by jemonthi          #+#    #+#             */
/*   Updated: 2025/10/31 17:37:03 by jemonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	size_max;
	size_t	i;
	char	*ptr;

	if (size != 0 && nmemb > (size_t) - 1 / size)
		return (NULL);
	size_max = nmemb * size;
	ptr = malloc(size_max);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < size_max)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
