/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoze <gdoze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 14:32:56 by gdoze             #+#    #+#             */
/*   Updated: 2019/12/23 13:37:59 by gdoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		length(char const *s)
{
	char const *p;

	while ((*s == ' ' || *s == '\t' || *s == '\n') && *s)
		s++;
	p = s;
	while (*s != '\0')
		s++;
	if (p != s)
		s--;
	while (*s == ' ' || *s == '\t' || *s == '\n')
		s--;
	return ((s - p) + 1);
}

char			*ft_strtrim(char const *s)
{
	char	*str;

	if (s == NULL)
		return (NULL);
	while ((*s == ' ' || *s == '\t' || *s == '\n') && *s)
		s++;
	str = ft_strsub(s, 0, length(s));
	return (str);
}
