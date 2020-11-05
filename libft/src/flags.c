/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltalitha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 16:59:08 by ltalitha          #+#    #+#             */
/*   Updated: 2019/12/23 16:59:15 by ltalitha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*hendler_s_c(t_flag *flags, va_list *ap)
{
	char *s;
	char ch;

	s = NULL;
	if (flags->spcf == 's')
	{
		s = va_arg(*ap, char *);
		s = (s) ? str_redactor(ft_strdup(s), *flags) : \
			str_redactor(ft_strdup("(null)"), *flags);
	}
	else if (flags->spcf == 'c')
	{
		ch = (char)va_arg(*ap, int);
		if (ch)
			s = str_redactor(ft_stradd(NULL, ch), *flags);
		else
		{
			s = str_redactor(ft_strdup("@"), *flags);
			flags->spcf = 'N';
		}
	}
	return (s);
}

char	*flags_d_i(register t_flag flags, va_list *ap)
{
	char *s;

	s = NULL;
	if (flags.spcf == 'd' || flags.spcf == 'i')
	{
		if (flags.h_flag == 1)
			s = ft_itoa((short)va_arg(*ap, int));
		else if (flags.h_flag == 2)
			s = ft_itoa((signed char)va_arg(*ap, int));
		else if (flags.l_flag || flags.j_flag || flags.z_flag)
			s = ft_itoa_long(va_arg(*ap, long));
		else
			s = ft_itoa(va_arg(*ap, int));
		s = redactor(s, flags, 'd');
	}
	return (s);
}

char	*hendler_o_f(register t_flag flags, va_list *ap)
{
	char *s;

	s = NULL;
	if (flags.spcf == 'o' && flags.h_flag == 1)
		s = redactor(ft_itoa_base((unsigned short)va_arg(*ap, int), 8),\
				flags, 'o');
	else if (flags.spcf == 'o' && flags.h_flag == 2)
		s = redactor(ft_itoa_base((unsigned char)va_arg(*ap, int),\
					8), flags, 'o');
	else if (flags.spcf == 'o' && (flags.l_flag == 1 || flags.l_flag == 2))
		s = redactor(ft_itoa_base_unsigned(va_arg(*ap, int), 8), flags, 'o');
	else
		s = redactor(ft_itoa_base(va_arg(*ap, int), 8), flags, 'o');
	if (flags.spcf == 'f')
	{
		flags.width = (flags.width == -1) ? 6 : flags.width;
		if (flags.ld_flag)
			s = redactor(ft_ftoa_long(va_arg(*ap, long double),\
						flags.width), flags, 'f');
		else
			s = redactor(ft_ftoa(va_arg(*ap, double),\
						flags.width), flags, 'f');
	}
	return (s);
}

char	*hendler_big_u_u(register t_flag flags, va_list *ap)
{
	char *s;

	s = NULL;
	if (flags.spcf == 'u' || flags.spcf == 'U')
	{
		if (flags.spcf == 'U' || flags.l_flag || flags.j_flag || flags.z_flag)
			s = ft_itoa_unsigned(va_arg(*ap, unsigned long));
		else if (flags.h_flag == 1)
			s = ft_itoa_unsigned((unsigned short)va_arg(*ap, unsigned int));
		else if (flags.h_flag == 2)
			s = ft_itoa_unsigned((unsigned char)va_arg(*ap, unsigned int));
		else
			s = ft_itoa_unsigned(va_arg(*ap, unsigned int));
		s = redactor(s, flags, 'u');
	}
	return (s);
}

char	*hendler_big_x_x(t_flag flags, va_list *ap)
{
	char *s;

	s = NULL;
	if (flags.spcf == 'X' || flags.spcf == 'x')
	{
		if (flags.j_flag || flags.l_flag)
			s = redactor(ft_itoa_base_unsigned(va_arg(*ap, size_t),\
			16), flags, 'x');
		else if (flags.h_flag == 1)
			s = redactor(ft_itoa_base((unsigned short)va_arg(*ap,\
			unsigned int), 16), flags, 'x');
		else if (flags.h_flag == 2)
			s = redactor(ft_itoa_base((unsigned char)va_arg(*ap,\
			unsigned int), 16), flags, 'x');
		else
			s = redactor(ft_itoa_base(va_arg(*ap, int), 16), flags, 'x');
		if (flags.spcf == 'X')
			ft_strupper(s);
	}
	return (s);
}
