char	*ft_strchr(const char *s, int c)
{
	char	*res;

	res = (char *)s;
	while (*res)
	{
		if ((char)c == *res)
			return (res);
		res++;
	}
	if (c == '\0')
		return (res);
	return (0);
}
