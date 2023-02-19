#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include "ft_printf/ft_printf.h"


void	segs_sender(char *bits, pid_t pid)
{
	int j;

	j = 0;
	while (bits[j])
	{
		if (bits[j] == '0')
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(870);
		j++;
	}
}

void	conv_to_bits(char c, pid_t pid)
{
	char str[9] = "00000000\0";
	int i;
	int nb;

	i = 0;
	nb = (int)c;
	while (i < 8)
	{
		if (nb % 2 != 0)
			str[7 - i] = '1';
		nb /= 2;
		i++;
	}
	segs_sender(str, pid);
}


int main(int argc, char **argv)
{
	char *text;
	int i;
	if (argc != 3)
	{
		ft_printf("n of args args == %i\n", argc);
		return 0;
	}

	pid_t pid = atoi(argv[1]);
	text = argv[2];
	i = 0;
	while (text[i])
	{
		conv_to_bits(text[i], pid);
		i++;
	}
	conv_to_bits(0, pid);
	return 0;
}
