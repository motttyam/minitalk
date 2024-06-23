NAME = client
NAMESV = server

CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBFT = lib/libft.a
PRINTF = lib/libftprintf.a

SRCCL = client.c
SRCSV = server.c

OBJCL = $(SRCCL:.c=.o)
OBJSV = $(SRCSV:.c=.o)

all : $(NAME) $(NAMESV)

$(NAME) : $(OBJCL)
	$(CC) $(CFLAGS) $(OBJCL) $(LIBFT) $(PRINTF) -o $(NAME)

$(NAMESV) : $(OBJSV)
	$(CC) $(CFLAGS) $(OBJSV) $(LIBFT) $(PRINTF) -o $(NAMESV)

clean :
	rm -f $(OBJCL) $(OBJSV)

fclean : clean
	rm -f $(NAME) $(NAMESV)

re : fclean all

.PHONY : all clean fclean re
