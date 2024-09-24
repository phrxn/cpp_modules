NAME    = bureaucrat

CC      = c++
FLAGS    = -Werror -Wextra -Wall -std=c++98

DIR_SOURCES  = ./
DIR_INCLUDES = ./

DEBUG = "-DDEBUG"

# ++++++++++ SOURCES DIRECTORIES ++++++++++
SRC_DIR_SOURCES_ = $(DIR_SOURCES) 

# =============== INCLUDES DIRECTORIES ===============
INC_DIR_INCLUDE_ = $(DIR_INCLUDES)



# =============== SOURCES FILES ===============
FILES_SRC_DIR_SOURCES_ = \
						 main.cpp \
						 Bureaucrat.cpp \
						 Form.cpp

# =============== SOURCES FILES + ITS DIRECTORIES ===============
F_SRC_DIR_SOURCES_ = $(addprefix $(DIR_SOURCES), $(FILES_SRC_DIR_SOURCES_))

# =============== FINAL VARIABLES ===============
SOURCES = $(F_SRC_DIR_SOURCES_)
OBJECTS = $(SOURCES:.cpp=.o)
DEPENDS = $(SOURCES:.cpp=.d)

%.o : %.cpp
	$(CC) $(FLAGS) $(DEBUG) -I$(INC_DIR_INCLUDE_) -MMD -c $< -o $@
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

ndebug: set_debug all

set_debug:
	$(eval DEBUG := "")

.PHONY: all re clean fclean
