/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_redactor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltalitha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 13:27:15 by ltalitha          #+#    #+#             */
/*   Updated: 2019/12/26 15:08:30 by gdoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*str_redactor(char *arg, register t_flag flags)
{
	char	*str;
	int		len;

	len = ft_strlen(arg);
	if (flags.width != -1 && flags.width < len && flags.spcf != '%')
	{
		if (flags.width == 0 && len == 1)
			arg[flags.width + 1] = '\0';
		else
			arg[flags.width] = '\0';
		len = flags.width;
	}
	if (len < flags.length)
	{
		str = ft_strnew(flags.length - len);
		ft_memset(str, flags.filler, flags.length - len);
		arg = (flags.minus) ?\
		ft_strjoin_free(arg, str, 3) : ft_strjoin_free(str, arg, 3);
	}
	return (arg);
}

int		putstr_for_null_char(char *s)
{
	size_t i;

	i = 0;
	if (s != NULL)
		while (s[i] != '\0')
		{
			if (s[i] == '@')
			{
				s[i] = (0000);
			}
			ft_putchar(s[i]);
			i++;
		}
	return (i);
}
