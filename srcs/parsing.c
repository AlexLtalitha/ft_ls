#include "../includes/ft_ls.h"
#include <stdio.h>

/*
** функция для обнаружения флага
*/

int			parsing(int ac, char **av, int *flags)
{
	int	i;

	*flags = 0;
	i = 0;
	while (++i < ac && av[i][0] == '-' && av[i][1])
	{
		if (av[i][1] == '-' && av[i][2])
			return (i + 1);
		if (!parse_options(av[i], flags))
			return (-1);
	}
	return (i);
}

/*
** возвращает положение символа в строке
*/

static int	ft_strchr_index(char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		++i;
	}
	return (-1);
}

/*
** здесь мы зажигаем n-й бит в соответствии с разобранным флагом
** например, если у нас есть -Ra, у нас будут флаги, равные 0b101
** пользователь решает, какие параметры он хочет:
** 1) для скрытых файлов и папок
** 2) l для деталей
** 3) R для рекурсивного отображения содержимого подпапок
** 4) r задать по дате создания
** 5) t для заказа по метке времени
** 6) d для отображения только текущего каталога
** 7) -1 \ n для отображения только в 1 столбце, это опция по умолчанию
** 8) -G для цветов
** nb: * flags & = (* s == 'l')? ~ 128: ~ 2; должен быть установлен в 0 л, если 1 был найден
** и обратно.
** nb2: * flags | = LS_ONE; по умолчанию устанавливается с помощью ls | cat -e
*/

int			parse_options(char *s, int *flags)
{
	int		n;

	while (*(++s))
	{
		if ((n = ft_strchr_index("alRrtdG1Ss", *s)) == -1)
			ls_error(s, USAGE);
		*flags |= (1 << n);
		if ((*s == 'l') || (*s == '1'))
			*flags &= (*s == 'l') ? ~LS_ONE : ~LS_L;
	}
	return (1);
}

/*
** функция для обработки ошибок
** 0: отображать использование для недопустимого флага, -1: errno, -2: mall_err
*/

int			ls_error(char *s, int error)
{
	if (error == USAGE)
	{
		ft_putstr_fd("ft_ls: illegal option -- ", 2);
		ft_putchar_fd(*s, 2);
		ft_putchar_fd('\n', 2);
		ft_putendl_fd("usage: ft_ls [-alRrtdG1Ss] [file ...]", 2);
	}
	else if (error == ERRNO || error == MALL_ERR)
		ft_putstr_fd("ft_ls: ", 2);
	if (error == ERRNO)
	{
		ft_putstr_fd(s, 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(strerror(ERRNO), 2);
	}
	else if (error == ERRNO)
		ft_putendl_fd(strerror(ERRNO), 2);
	if (error == USAGE || error == MALL_ERR)
		exit(EXIT_FAILURE);
	return (0);
}