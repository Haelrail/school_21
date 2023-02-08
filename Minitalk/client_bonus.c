
#include "minitalk_bonus.h"

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

static void	char_to_bit(int pid, char *str)
{
	int		i;

	i = 8;
	while (i--)
	{
		if (send_signal(pid, i, *str))
			exit (0);
		usleep(400);
	}
}

static void	send_str(int pid, char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		char_to_bit(pid, &str[i]);
		i++;
	}
	char_to_bit(pid, &str[i]);
}

static void	send_report(int sig, siginfo_t *info, void *cont)
{
	(void)info;
	(void)cont;
	if (sig == SIGUSR2)
	{
		write (1, "Success\n", 8);
		exit (0);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	s_sig;
	int					pid;

	s_sig.sa_sigaction = send_report;
	s_sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sig, NULL);
	sigaction(SIGUSR2, &s_sig, NULL);
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		send_str(pid, argv[2]);
	}
	else
	{
		write(1, "Error input\n", 12);
		exit (0);
	}
	while (1)
		pause();
	return (0);
}
