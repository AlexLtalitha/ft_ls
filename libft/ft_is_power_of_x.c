int		ft_is_power_of_x(unsigned n, unsigned x)
{
	if (n == 0)
		return (0);
	while (!(n % x))
		n /= x;
	return ((n == 1) ? 1 : 0);
}
