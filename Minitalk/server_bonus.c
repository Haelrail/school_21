
#include "minitalk_bonus.h"

static void	make_parameters_null_again(int *bit_number,
		char *c, int *null_counter)
{
	*bit_number = 0;
	*c = 0;
	*null_counter = 0;
}

static void	put_found_char(int *bit_number, char *c, int *null_counter)
{
	write(1, c, 1);
	make_parameters_null_again(bit_number, c, null_counter);
}

void	bit_to_char(int sig, siginfo_t *info, void *cont)
{
	static int	bit_number;
	static char	c;
	static int	pid;
	static int	null_counter;

	(void)cont;
	if ((!pid) || (pid != info->si_pid))
	{
		bit_number = 0;
		pid = info->si_pid;
	}
	c = c | (sig == SIGUSR1);
	null_counter += (sig == SIGUSR2);
	if (bit_number++ == 7)
	{
		if (null_counter == 8)
		{
			kill(info->si_pid, SIGUSR2);
			return ;
		}
		put_found_char(&bit_number, &c, &null_counter);
	}
	else
		c = c << 1;
}

int	main(int ac, char **av)
{
	struct sigaction	s_sig;

	(void)ac;
	(void)av;
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
