# include <stdlib.h>
/*
** function used to adjust length for padding due to the flag -
*/
#include "libft.h"
void	ft_putnchar(int len, char c)
{
    char	*s;

    if (!(s = (char *)malloc(sizeof(char) * len + 1)))
        return ;
    s[len] = '\0';
    while (len--)
        s[len] = c;
    ft_putstr_free(s);
}