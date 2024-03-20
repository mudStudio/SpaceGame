# GENERIC
NAME = SpaceGame
CC = gcc
CFLAGS = -Wall #-Wextra

# INCLUDES
#INC = 

# SOURCES
SRCDIR =	$(wildcard src/*.c)
#vpath=../src:../src/game
#SRC = main.c test.c

# OBJECTS
#OBJDIR = src/tmp/
#OBJ = $(addprefix $(OBJDIR), $(SRC:.c=.o))
OBJ = $(SRCDIR:.c=.o)


# OS DEPENDANT VARIABLES
#$(info Compiling for Windows.)
EXT = .exe
DEL = del /q
FixPath = $(subst /,\,$1)
SDLPATH = -Iinclude/SDL2
LIB = -Linclude/SDL2 -lmingw32 -lib/lSDL2main -lib/SlSDL2



# RULES

# window rules
all: $(NAME)

$(NAME): 
	@gcc $(SRCDIR) -o $(NAME).exe -I include/SDL2 -L lib -lmingw32 -lSDL2main -lSDL2.dll
	@$(NAME).exe

%.o: %.c
#	$(info Compiling $< into $@)
	@$(CC) $(CFLAGS) -c $(call FixPath, $<) -o $(call FixPath, $@) $(call FixPath, $(SDLPATH))

clean:
	@$(DEL) $(call FixPath, $(OBJ))

fclean: clean
	@$(DEL) $(call FixPath, $(NAME)$(EXT))

re: fclean all

# linux rules
linux:
	@$(CC) $(CFLAGS) src/*.c -lm -o $(NAME) `sdl2-config --cflags --libs` 
	@./$(NAME)

linuxClean:
	@rm -rf *.o

linuxFClean: linuxClean
	@rm -rf $(NAME)

linuxRe: linuxFClean linux

# MAC rules


.PHONY: err, all, clean, fclean, re
