#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include "ft_printf/ft_printf.h"

unsigned int nb = 0;

int ft_pow(int n)
{
	int n2;

	if (n == 0)
		return (1);
	if (n == 1)
		return (2);
	n2 = 2;
	while (n > 1)
	{
		n2 *= 2;
		n--;
	}
	return (n2);
}

void segs_sender(unsigned int n2, pid_t pid)
{
	int j;

	j = 0;
	while (n2 > 0)
	{
		if (n2 % 2 == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(840);
		j++;
	}
}

char reverse_bits(char c) {
	char result = 0;
	int i;
	for (i = 0; i < 8; i++) {
		result <<= 1;
		if (c & (1 << i)) {
			result |= 1;
		}
	}
	return result;
}

void conv_to_bits(unsigned char c, pid_t pid)
{
	int nb2;
	int i;

	nb2 = (int)c;
	i = 255;
	if (nb2 == 0)
	{
		printf("\n");
		return ;
	}
	// printf("here nb2 == %i\n", nb2);
	while (nb2 > 0)
	{
		// printf("--nb2 == %i\n", nb2);
		if (nb2 % 2 != 0)
		{
			printf("1--");
			kill(pid, SIGUSR2);§
		}
		else
		{
			printf("0--");
			kill(pid, SIGUSR1);
		}
		nb2 /= 2;
		usleep(840);
	}
		while (i / 2 > (int)c)
	{
		printf("0++");§§
		kill(pid, SIGUSR1);
		usleep(840);
		i /= 2;§
	}
}

int main(int argc, char **argv)
{
	char *text;
	int i;
	if (argc != 3)
	{

		write(1, "\U0001F600\n", 6);
		ft_printf("n of args args == %i\n", argc);
		return 0;
	}

	pid_t pid = atoi(argv[1]);
	text = argv[2];
	i = 0;
	while (text[i])
	{
		conv_to_bits((unsigned char)text[i], pid);
		i++;
	}
	conv_to_bits(0, pid);
	return 0;
}
