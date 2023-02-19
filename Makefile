CLIENT			=	client
SERVER			=	server
PRINTF			=	ft_printf/libftprintf.a

C_SRCS			=	client.c
S_SRCS			=	server.c
PRINTF_SRCS		=	ft_printf/ft_printf.c \
					ft_printf/ft_put_unsigned.c \
					ft_printf/ft_put_ptr.c \
					ft_printf/ft_put_hex.c \
					ft_printf/ft_put_nbr.c


C_OBJS			=	$(C_SRCS:.c=.o)
S_OBJS			=	$(S_SRCS:.c=.o)


CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror


all:			both

both:			$(CLIENT) $(SERVER)


$(CLIENT):		$(C_OBJS) $(PRINTF_SRCS)
				$(MAKE) -C ft_printf
				CC $(C_OBJS) $(PRINTF) -o $(CLIENT)

$(SERVER):		$(S_OBJS) $(PRINTF_SRCS)
				$(CC) $(S_OBJS) $(PRINTF) -o $(SERVER)

clean:
				$(MAKE) clean -C ft_printf
				rm -f $(S_OBJS) $(C_OBJS)

fclean:			clean
				$(MAKE) fclean -C ft_printf
				rm -f $(CLIENT) $(SERVER)

re:				fclean all






