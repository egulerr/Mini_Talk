SRCS_CL = client.c
SRCS_SR = server.c
SRCS_BCL = client_bonus.c
SRCS_BSR = server_bonus.c
SRCS = src/ft_printf.c src/ft_atoi.c
INC = minitalk.h
OBJS_SRCS = $(SRCS:.c=.o)
OBJS_CL = $(SRCS_CL:.c=.o) $(OBJS_SRCS)
OBJS_SR = $(SRCS_SR:.c=.o) $(OBJS_SRCS)
OBJS_BCL = $(SRCS_BCL:.c=.o) $(OBJS_SRCS)
OBJS_BSR = $(SRCS_BSR:.c=.o) $(OBJS_SRCS)
NAME = minitalk
CFLAGS  = -Wall -Wextra -Werror

all: server client

$(NAME):

bonus: client_bonus server_bonus

server: $(OBJS_SR)
	@gcc $(CFLAGS) $(OBJS_SR) -o server

client: $(OBJS_CL)
	@gcc $(CFLAGS) $(OBJS_CL) -o client

server_bonus: $(OBJS_BSR)
	@gcc $(CFLAGS) $(OBJS_BSR) -o server_bonus

client_bonus: $(OBJS_BCL)
	@gcc $(CFLAGS) $(OBJS_BCL) -o client_bonus

%.o: %.c $(INC)
	@echo "compling $<"
	@gcc $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS_CL) $(OBJS_SR) $(OBJS_SRCS) $(OBJS_BCL) $(OBJS_BSR)

fclean: clean
	@rm -rf server client server_bonus client_bonus

re: fclean all

.PHONY: all clean fclean re
