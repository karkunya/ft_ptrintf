char	*ft_strrchr(const char *s, int c)
{
	char	*res;

	res = 0;
	while (*s)
	{
		if (*s == (unsigned char)c)
			res = (char *)s;
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (res);
}
