#include "../minitalk.h"

static char	*c_to_bin(char c)
{
	char	*str;
	int		i;

	i = 7;
	str = ft_strdup("00000000");
	while (c > 0)
	{
		str[i] = (c % 2) + '0';
		c /= 2;
		i--;
	}
	return (str);
}

static void	send(char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '1')
			kill(pid, SIGUSR1);
		if (str[i] == '0')
			kill(pid, SIGUSR2);
		usleep(50);
		i++;
	}
}

static int	errend(int code)
{
	if (code == 1)
	{
		ft_putstr_fd("ERROR\nEXPECTED INPUT: ", 1);
		ft_putstr_fd("SERVER_PID STRING_TO_PASS\n", 1);
	}
	if (code == 2)
		ft_putstr_fd("ERROR\nINVALID PID\n", 1);
	return (0);
}

int	main(int ac, char **av)
{
	int		i;
	int		pid;
	char	*symb;
	char	*str;

	if (ac != 3)
		return (errend(1));
	pid = ft_atoi(av[1]);
	if (pid <= 0)
		return (errend(2));
	i = 0;
	str = ft_strdup(av[2]);
	while (str[i])
	{
		symb = c_to_bin(str[i]);
		send(symb, pid);
		free(symb);
		i++;
	}
	free(str);
	return (0);
}
