#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "ft_printf/ft_printf.h"

static int client_pid = 0;

int ft_pow(int n)
{
	int nb;

	if (n == 0)
		return (1);
	if (n == 1)
		return (2);
	nb = 2;
	while (n > 1)
	{
		nb *= 2;
		n--;
	}
	return (nb);
}

char conv_to_char(char *bits)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (bits[i])
	{
		if (bits[i] == '1')
			nb += ft_pow(8 - i);
		i++;
	}
	return (nb);
}

void handle_signal(int signal, siginfo_t *info, void* context)
{
	static int nb;
	static int global;

	context = 0;
	if (client_pid != info->si_pid)
	{
		client_pid = info->si_pid;
		global = 0;
		nb = 0;
	}
	if (signal == SIGUSR1)
		global++;
	else if (signal == SIGUSR2)
	{
		nb += ft_pow(7 - global);
		global++;
	}
	if (global == 8)
	{
		if (nb == 0)
			ft_printf("\n");
		else
			ft_printf("%c", (char)(nb));
		global = 0;
		nb = 0;
	}
}

int main()
{
	ft_printf("pid == %i\n", getpid());
	struct sigaction act;
	act.sa_sigaction = handle_signal;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
	{
	}

	return 0;
}
