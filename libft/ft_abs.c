int		ft_abs(int n)
{
	int mask;

	mask = (n >> 31);
	return ((n ^ mask) - mask);
}
