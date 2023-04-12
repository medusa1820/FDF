/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 13:54:58 by musenov           #+#    #+#             */
/*   Updated: 2023/03/25 18:18:50 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// size_t	ft_strlen(const char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	while (*(str + i) != '\0')
// 		i++;
// 	return (i);
// }

char	*ft_strnew(size_t size)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	while (size > 0)
		*(str + size--) = '\0';
	*(str + 0) = '\0';
	return (str);
}

// char	*ft_strchr(const char *s, int c)
// {
// 	int	i;

// 	i = 0;
// 	while (*(s + i) != '\0')
// 	{
// 		if (*(s + i) == (char)c)
// 			return ((char *)s + i);
// 		i++;
// 	}
// 	if (*(s + i) == (char)c)
// 		return (((char *)s + i));
// 	return (NULL);
// }

char	*ft_strdup_gnl(char *s1)
{
	size_t	s1_len;
	char	*ptr;
	size_t	i;

	if (!s1)
		return (NULL);
	s1_len = ft_strlen(s1);
	ptr = (char *)malloc(sizeof(char) * (s1_len + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		*(ptr + i) = *(s1 + i);
		i++;
	}
	*(ptr + i) = '\0';
	return (ptr);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char	*s3;
	size_t	i_s12;
	size_t	i_s3;

	if (!s1 || !s2)
		return (free ((char *)s1), NULL);
	s3 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
		return (free ((char *)s1), NULL);
	i_s3 = 0;
	i_s12 = 0;
	while (*(s1 + i_s12) != '\0')
		*(s3 + i_s3++) = *(s1 + i_s12++);
	i_s12 = 0;
	while (*(s2 + i_s12) != '\0')
		*(s3 + i_s3++) = *(s2 + i_s12++);
	*(s3 + i_s3) = '\0';
	free ((char *)s1);
	return (s3);
}
