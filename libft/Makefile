# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpetruno <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/25 18:27:37 by mpetruno          #+#    #+#              #
#    Updated: 2018/10/10 14:17:07 by mpetruno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Werror -Wextra

CC = gcc

FUNC_LIST = memset \
			bzero \
			memcpy \
			memccpy \
			memmove \
			memchr \
			memcmp \
			strlen \
			strdup \
			strcpy \
			strncpy \
			strcat \
			strncat \
			strlcat \
			strchr \
			strrchr \
			strstr \
			strnstr \
			strcmp \
			strncmp \
			atoi \
			isupper \
			islower \
			isalpha \
			isdigit \
			isalnum \
			isascii \
			isprint \
			toupper \
			tolower \
			memalloc \
			memdel \
			strnew \
			strdel \
			strclr \
			striter \
			striteri \
			strmap \
			strmapi \
			strequ \
			strnequ \
			strsub \
			strjoin \
			strtrim \
			strsplit \
			itoa \
			putchar \
			putstr \
			putendl \
			putnbr \
			putchar_fd \
			putstr_fd \
			putendl_fd \
			putnbr_fd \
			lstnew \
			lstdelone \
			lstdel \
			lstadd \
			lstiter \
			lstmap \
			lltoa_base \
			ulltoa_base \
			dtoa

SRC_LIST = $(addsuffix .c, $(addprefix ft_, $(FUNC_LIST)))

OBJ_LIST = $(addsuffix .o, $(addprefix ft_, $(FUNC_LIST)))

all: $(NAME)

$(NAME): $(OBJ_LIST)
	@echo "Compiling libft..."
	@ar -r $(NAME) $(OBJ_LIST)
	@ranlib $(NAME)

%.o: %.c
	@$(CC) -c $^ $(FLAGS)

clean:
	rm -f $(OBJ_LIST)

fclean: clean
	rm -f $(NAME)

re: fclean all

