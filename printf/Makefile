NAME = libftprintf.a
CC = cc
AR = ar rcs
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

SRCS += $(wildcard ft*.c)
SRCS += $(wildcard */ft*.c)

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(AR) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
