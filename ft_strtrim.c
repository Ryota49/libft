/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemonthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 20:15:23 by jemonthi          #+#    #+#             */
/*   Updated: 2025/10/24 09:04:31 by jemonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len_start(char *s1, char *set)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (set[j])
	{
		if (s1[i] == set[j] && s1[i])
		{
			i++;
			j = -1;
		}
		if (set[j + 1] == '\0')
			return (i);
		j++;
	}
	return (i);
}

static	size_t	ft_len_end(char *s1, char *set, size_t len_end)
{
	size_t	j;

	j = 0;
	while (set[j])
	{
		if (s1[len_end - 1] == set[j] && len_end > 0)
		{
			len_end--;
			j = -1;
		}
		if (set[j + 1] == '\0')
			return (len_end);
		j++;
	}
	return (len_end);
}

static char	*ft_setzero(char *snew, size_t len_s, char *s1)
{
	size_t	i;

	i = 0;
	snew = malloc(sizeof(char) * (len_s + 1));
	if (!snew)
		return (NULL);
	while (i < len_s && s1[i])
	{
		snew[i] = s1[i];
		i++;
	}
	snew[i] = '\0';
	return (snew);
}

static char	*ft_conc(char *snew, char *s1, size_t len_start, size_t len_end)
{
	size_t	i;

	i = 0;
	while (len_start < len_end)
	{
		snew[i] = s1[len_start];
		i++;
		len_start++;
	}
	snew[i] = '\0';
	return (snew);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*snew;
	size_t	len_start;
	size_t	len_end;

	snew = NULL;
	len_start = ft_len_start((char *)s1, (char *)set);
	if (s1[0] == 0 || (len_start == ft_strlen(s1) && set[0] == '\0'))
	{
		snew = ft_setzero(snew, ft_strlen(s1), (char *)s1);
		return (snew);
	}
	len_end = ft_len_end((char *)s1, (char *)set, ft_strlen(s1));
	if (len_end == 0)
	{
		snew = malloc(sizeof(char));
		if (!snew)
			return (NULL);
		snew[0] = '\0';
		return (snew);
	}
	snew = malloc(sizeof(char) * (len_end - len_start + 1));
	if (!snew)
		return (NULL);
	snew = ft_conc(snew, (char *)s1, len_start, len_end);
	return (snew);
}
