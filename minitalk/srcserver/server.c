#include "../minitalk.h"

t_data	g_data;

static void	my_handler(int signum)
{
	if (signum == SIGUSR1)
	{
		g_data.symb = g_data.symb << 1;
		g_data.symb += 1;
	}
	if (signum == SIGUSR2)
		g_data.symb = g_data.symb << 1;
	g_data.now++;
	if (g_data.now == 8)
	{
		g_data.now = 0;
		ft_putchar_fd((char)g_data.symb, 1);
		g_data.symb = 0;
	}
}

int	main(void)
{
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	g_data.symb = 0;
	g_data.now = 0;
	while (1)
	{
		signal(SIGUSR1, my_handler);
		signal(SIGUSR2, my_handler);
	}
	return (0);
}
