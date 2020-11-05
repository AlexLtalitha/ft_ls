/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoze <gdoze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 15:27:16 by gdoze             #+#    #+#             */
/*   Updated: 2019/12/23 16:44:03 by ltalitha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*specifier(t_flag *flags, va_list *ap)
{
	char *s;

	s = NULL;
	if (flags->spcf == 's' || flags->spcf == 'c')
		s = hendler_s_c(flags, ap);
	else if (flags->spcf == 'd' || flags->spcf == 'i')
		s = flags_d_i(*flags, ap);
	else if (flags->spcf == 'X' || flags->spcf == 'x')
		s = hendler_big_x_x(*flags, ap);
	else if (flags->spcf == 'b')
		s = redactor(ft_itoa_base(va_arg(*ap, int), 2), *flags, 'o');
	else if (flags->spcf == 'o' || flags->spcf == 'f')
		s = hendler_o_f(*flags, ap);
	else if (flags->spcf == 'u' || flags->spcf == 'U')
		s = hendler_big_u_u(*flags, ap);
	else if (flags->spcf == 'p')
		s = redactor(ft_itoa_base_unsigned(va_arg(*ap, size_t), 16),\
		*flags, 'p');
	else if (flags->spcf == '%')
		s = str_redactor(ft_strdup("%"), *flags);
	else if (flags->spcf == '\0')
		return (NULL);
	else
		s = str_redactor(ft_strdup(""), *flags);
	return (s);
}
