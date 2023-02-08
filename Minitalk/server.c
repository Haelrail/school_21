
#include "minitalk.h"

void	bit_to_char(int sig, siginfo_t *info, void *content)
{
	static int	bit_number;
	static char	c;
	//static int	pid = 0;

	(void)content;
	(void)info;
	/*if (!pid || pid != info->si_pid)
	{
		bit_number = 0;
		c = 0;
		pid = info->si_pid;
	}*/
	c = c | (sig == SIGUSR1);
	if (bit_number++ == 7)
	{
		bit_number = 0;
		write(1, &c, 1);
		c = 0;
	}
	else
		c = c << 1;
}

int	main(int argc, char **argv)
{
	struct sigaction	s_sig;

	(void)argc;
	(void)argv;
	write (1, "Server PID: ", 12);
	ft_putnbr_fd(getpid(), 0);
	write (1, "\n", 1);
	s_sig.sa_sigaction = bit_to_char;
	s_sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sig, NULL);
	sigaction(SIGUSR2, &s_sig, NULL);
	while (1)
		pause();
	return (0);
}
