NAME = client
NAMESV = server

CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBFT = ./libft.a

SRCCL = client.c
SRCSV = server.c

OBJCL = $(SRCCL.c=.o)
OBJSV = $(SRCSV.c=.o)

all : $(NAME) $(NAMESV)

$(NAME) : $(OBJCL)
    $(CC) $(CFLAGS) $(OBJCL) $(LIBFT) -o $(NAME)

$(NAMESV) : $(OBJSV)
    $(CC) $(CFLAGS) $(OBJSV) $(LIBFT) -o $(NAME)

clean :
    rm -f $(OBJCL) $(OBJSV)

fclean : clean
    rm -f $(NAME) $(NAMESV)

re : fclean all

.PHONY : all clean fclean re