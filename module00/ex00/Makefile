NAME    = megaphone

CC      = c++
FLAGS    = -Werror -Wextra -Wall -std=c++98

# ++++++++++ SOURCES DIRECTORIES ++++++++++

DIR_SOURCE            = ./

# =============== SOURCES FILES ===============
FILES_SOURCE = megaphone.cpp

# =============== SOURCES FILES + ITS DIRECTORIES ===============
F_SOURCE = $(addprefix $(DIR_SOURCE), $(FILES_SOURCE))

# =============== FINAL VARIABLES ===============
SOURCES = $(FILES_SOURCE)
OBJECTS = $(SOURCES:.cpp=.o)
DEPENDS = $(SOURCES:.cpp=.d)

%.o : %.cpp
	$(CC) $(FLAGS) -MMD -c $< -o $@

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

clean:
	rm -rf $(DEPENDS)
	rm -rf $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEPENDS)

.PHONY: all re clean fclean
