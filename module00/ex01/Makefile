NAME    = phonebook.out

CC      = c++
FLAGS    = -Werror -Wextra -Wall -std=c++98

DIR_SOURCES  = ./sources/
DIR_INCLUDES = ./includes/

# ++++++++++ SOURCES DIRECTORIES ++++++++++
SRC_DIR_SOURCES_ = $(DIR_SOURCES) 

# =============== INCLUDES DIRECTORIES ===============
INC_DIR_INCLUDE_ = $(DIR_INCLUDES)



# =============== SOURCES FILES ===============
FILES_SRC_DIR_SOURCES_ = Main.cpp \
						 Contact.cpp \
						 PhoneBook.cpp \
						 ContactChecker.cpp

# =============== SOURCES FILES + ITS DIRECTORIES ===============
F_SRC_DIR_SOURCES_ = $(addprefix $(DIR_SOURCES), $(FILES_SRC_DIR_SOURCES_))

# =============== FINAL VARIABLES ===============
SOURCES = $(F_SRC_DIR_SOURCES_)
OBJECTS = $(SOURCES:.cpp=.o)
DEPENDS = $(SOURCES:.cpp=.d)

%.o : %.cpp
	$(CC) $(FLAGS) -I$(INC_DIR_INCLUDE_) -MMD -c $< -o $@

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
