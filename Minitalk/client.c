
#include "minitalk.h"

/*static void	ft_error(char *s)
{
	while (*s)
	{
		ft_putchar_fd(*s, 2);
		s++;
	}
	write(1, "\n", 1);
}*/

static int	send_signal(int pid, int i, char c)
{
	if ((c >> i) & 1)
	{
		if (kill(pid, SIGUSR1) < 0)
		{
			write(1, "Error PID\n", 10);
			return (1);
		}
	}
	else
	{
		if (kill(pid, SIGUSR2) < 0)
		{
			write(1, "Error PID\n", 10);
			return (1);
		}
	}
	return (0);
}

static void	send_str(int pid, char *str)
{
	int		i;

	while (*str)
	{
		i = 8;
		while (i--)
		{
			if (send_signal(pid, i, *str))
				return ;
			usleep(400);
		}
		str++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		send_str(pid, argv[2]);
	}
	else
		write(1, "Error input\n", 12);
	return (0);
}
