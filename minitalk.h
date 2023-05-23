#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include "ft_printf/ft_printf.h"

void	ft_shiftoperation(int pid, char c);
void	signal_handler(int signal);
int		ft_atoi(const char *str);

#endif
