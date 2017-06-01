/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voliynik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:27:08 by voliynik          #+#    #+#             */
/*   Updated: 2017/05/20 20:51:52 by voliynik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wdlen(const char *s, char c)
{
	size_t size;

	size = 0;
	while (s[size] != '\0' && s[size] != c)
		size++;
	return (size);
}

static	size_t	ft_countwd(const char *s, char c)
{
	size_t i;
	size_t wd_count;

	i = 0;
	wd_count = 0;
	while (s[i] != '\0')
	{
		while ((s[i] == c) && s[i] != '\0')
			i++;
		if (s[i])
			wd_count++;
		while (!(s[i] == c) && s[i] != '\0')
			i++;
	}
	return (wd_count);
}

static char		*ft_passwd(const char *s, size_t wd_length)
{
	char	*word;
	size_t	i;

	i = 0;
	if ((word = (char *)malloc(sizeof(char *) * (wd_length + 1))) == NULL)
		return (NULL);
	while (i < wd_length)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		i;
	size_t	j;
	int		arr_size;

	j = 0;
	if (s == NULL)
		return (NULL);
	arr_size = ft_countwd(s, c);
	if (!(arr = (char **)malloc(sizeof(char *) * (arr_size + 1))))
		return (NULL);
	i = -1;
	while (++i < arr_size)
	{
		while ((s[j] == c))
			j++;
		if ((arr[i] = ft_passwd(s + j, ft_wdlen(s + j, c))) == NULL)
			return (NULL);
		while (s[j] != c && s[j])
			j++;
	}
	arr[i] = 0;
	return (arr);
}
