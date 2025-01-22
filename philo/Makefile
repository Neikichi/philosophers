NAME = philo

SRC_DIR = src
INC_DIR = include
LIBFT_DIR = libft

SRC = $(wildcard $(SRC_DIR)/*.c)

OBJ = $(SRC:$(SRC_DIR)/%.c=$(SRC_DIR)/%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread
IFLAGS = -I$(INC_DIR) -I$(LIBFT_DIR)/$(INC_DIR)
# LFLAGS = 
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@echo "Creating $(NAME)..."
	@$(CC) $(CFLAGS) $(IFLAGS) $(OBJ) $(LIBFT) -o $(NAME) 
	@echo "Created $(NAME)"

$(LIBFT):
	@make -C $(LIBFT_DIR) all

%.o: %.c
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	@echo "Removing objects files..."
	@make -C $(LIBFT_DIR) clean
	@rm -f $(OBJ)
	@echo "Objects files removed."

fclean: clean
	@echo "Removing $(NAME) and $(BNAME)..."
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)
	@echo "$(NAME) and $(BNAME) removed."

re: fclean all

# debug: CFLAGS += -g -fpic
# debug: clean all
# 	@echo "Enable debug mode"

# valgrind:
# 	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./pipex "" "" ls "/dev/stdout"

# fsanitize: CFLAGS += -fsanitize=address,leak -g3 -O1
# fsanitize: clean all
# 	@echo "AddressSanitizer enabled for $(NAME)"
#
# fsan: fsanitize
# 	./$(NAME) test_maps/pyramide.fdf

.PHONY: all clean fclean re bonus #debug #valgrind #fsanitize fsan

