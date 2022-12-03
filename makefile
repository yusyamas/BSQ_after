NAME := bsq
SRCDIR := ./srcs
OBJDIR := ./srcs
INCDIR := -I ./includes
SRCS := $(wildcard $(SRCDIR)/*.c)
OBJS := $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.o)))
SRC := gen.cpp
SRC2 := gen_error.cpp
SRC3 := check.cpp
CC := gcc
CPP := g++
CFLAG := -Wall -Wextra -Werror
SAFECASE := $(wildcard ./map/map*.txt)
ERRORCASE := $(wildcard ./maperror/map*.txt)
.PHONY: all clean fclean re delete errortest maptest mapgen test

all: bsq test

bsq : $(OBJS)
	$(CC) $(CFLAG) $(INCDIR) -o $@ $^

$(OBJDIR)/%.o : $(SRCDIR)/%.c
	$(CC) $(CFLAG) $(INCDIR) -c $< -o $@

test : gen error check

gen : $(SRC)
	$(CPP) -o $@ $^

error : $(SRC2)
	$(CPP) -o $@ $^

check : $(SRC3)
	$(CPP) -o $@ $^

errortest : $(ERRORCASE)
	./bsq $^ > test.txt

mapgen:
	./test_gen.sh

maptest: mapgen $(SAFECASE)
	./bsq $(SAFECASE) > test.txt

delete:
	$(RM) $(NAME)
	$(RM) gen
	$(RM) error
	$(RM) check

clean:
	$(RM) $(OBJS)

fclean:	clean delete

re:	fclean all
