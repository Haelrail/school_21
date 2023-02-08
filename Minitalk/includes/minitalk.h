
#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <string.h>

void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
int		ft_strlen(char *str);
int		ft_atoi(const char *s);

#endif
