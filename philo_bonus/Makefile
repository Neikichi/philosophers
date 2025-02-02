NAME = philo_bonus

SRC_DIR = src
INC_DIR = include

SRC = $(wildcard $(SRC_DIR)/*.c)

OBJ = $(SRC:$(SRC_DIR)/%.c=$(SRC_DIR)/%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread
IFLAGS = -I$(INC_DIR)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Creating $(NAME)..."
	@$(CC) $(CFLAGS) $(IFLAGS) $(LFLAGS) $(OBJ) -o $(NAME) 
	@echo "Created $(NAME)"

%.o: %.c
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	@echo "Removing objects files..."
	@rm -f $(OBJ)
	@echo "Objects files removed."

fclean: clean
	@echo "Removing $(NAME)..."
	@rm -f $(NAME)
	@echo "$(NAME) removed."

re: fclean all

debug: CFLAGS += -g -fpic
debug: clean all
	@echo "Enable debug mode"

.PHONY: all clean fclean re #bonus #debug #valgrind #fsanitize fsan
