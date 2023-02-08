
#include "minitalk_bonus.h"

static int	ft_intrank(int n)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	while (n)
	{
		n = n / 10;
		i++;
	}
	while (i > 1)
	{
		j = j * 10;
		i--;
	}
	return (j);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	n1;
	int				j;
	char			c;

	if (n < 0)
	{
		write (fd, "-", 1);
		n1 = n * (-1);
	}
	else
		n1 = n;
	j = ft_intrank(n);
	while (j)
	{
		c = 48 + (n1 / j);
		write (fd, &c, 1);
		n1 = n % j;
		j = j / 10;
	}
}

static int	ft_nextcharcheck( const char *str, int i, int s, unsigned int n)
{
	while ((str[i] == 32) || ((str[i] >= 9) && (str[i] <= 13)))
	{
		if ((str[i] == 32)
			|| ((str[i] >= 9) && (str[i] <= 13)) || (str[i + 1] == 43)
			|| (str[i + 1] == 45) || ((str[i + 1] >= 48) && (str[i + 1] <= 57)))
			i++;
		else
			return (0);
	}
	if (str[i] == 45)
		n = -1;
	while ((str[i] == 43) || (str[i] == 45))
	{
		if ((str[i + 1] >= 48) && (str[i + 1] <= 57))
			i++;
		else
			return (0);
	}
	while ((str[i] >= 48) && (str[i] <= 57))
	{
		s = (s * 10) + str[i] - 48;
		i++;
	}
	return (s * n);
}

int	ft_atoi(const char *str)
{
	int					i;
	int					s;
	unsigned int		n;

	i = 0;
	n = 1;
	s = 0;
	return (ft_nextcharcheck(str, i, s, n));
}

int	ft_strlen(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		i++;
	}
	return (i);
}
