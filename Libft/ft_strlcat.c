/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdemetra <gdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 19:45:34 by gdemetra          #+#    #+#             */
/*   Updated: 2025/06/13 21:32:20 by gdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	i;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	i = 0;
	if (size <= dst_len)
		return (size + src_len);
	i = dst_len;
	while (*src && i < size - 1)
		*(dst + i++) = *src++;
	*(dst + i) = '\0';
	return (src_len + dst_len);
}

// int	main(void)
// {
// 	char *dst;

// 	dst = (char *)malloc(sizeof(dst) * 15);
// 	memset(dst, 'r', 6);

// 	printf("Concatination intended len - %zu, Concatinated string - %s\n",
// 		ft_strlcat(dst, "", 10), dst);
// }