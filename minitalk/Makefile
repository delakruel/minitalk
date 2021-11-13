LIBFT		= ./libft/libft.a
NAME		= minitalk
CC 			= clang
CFLAGS		= -Wextra -Wall -Werror
SERVERSRCS	= ./srcserver/server.c
SERVEROBJS	= $(SERVERSRCS:.c=.o)
SERVERNAME	= server
CLIENTSRCS	= ./srcclient/client.c
CLIENTOBJS	= $(CLIENTSRCS:.c=.o)
CLIENTNAME	= client

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re

all:	$(NAME)

$(SERVERNAME):	$(SERVEROBJS)
				$(MAKE) -C ./libft
				$(CC) $(CFLAGS) -o $(SERVERNAME) $(SERVEROBJS) $(LIBFT) 

$(CLIENTNAME):	$(CLIENTOBJS)
				$(MAKE) -C ./libft
				$(CC) $(CFLAGS) -o $(CLIENTNAME) $(CLIENTOBJS) $(LIBFT)

$(NAME): $(SERVERNAME) $(CLIENTNAME)

clean:
	$(MAKE) clean -C ./libft
	rm -rf $(SERVEROBJS) $(CLIENTOBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -rf $(SERVERNAME) $(CLIENTNAME)

re: fclean all