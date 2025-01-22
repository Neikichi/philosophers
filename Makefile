NAME = philo_m
BNAME = philo_bonus

SRC_DIR = src
INC_DIR = include
LIBFT_DIR = libft
M_DIR = philo
B_DIR = philo_bonus

SRC = $(wildcard $(SRC_DIR)/*.c)
M_SRC = $(wildcard $(M_DIR)/$(SRC_DIR)/*.c)
B_SRC = $(wildcard $(B_DIR)/$(SRC_DIR)/*.c)

OBJ = $(SRC:$(SRC_DIR)/%.c=$(SRC_DIR)/%.o)
M_OBJ = $(M_SRC:.c=.o)
B_OBJ = $(B_SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread
IFLAGS = -I$(INC_DIR)
LFLAGS = -I$(LIBFT_DIR)/$(INC_DIR)
LIBFT = $(LIBFT_DIR)/libft.a
M_IFLAGS = -I$(M_DIR)/$(INC_DIR)
B_IFLAGS = -I$(B_DIR)/$(INC_DIR)

all: $(NAME)

$(NAME): $(M_OBJ) $(LIBFT)
	@echo "Creating $(NAME)..."
	@$(CC) $(CFLAGS) $(M_IFLAGS) $(LFLAGS) $(M_OBJ) $(LIBFT) -o $(NAME) 
	@echo "Created $(NAME)"

$(LIBFT):
	@make -C $(LIBFT_DIR) all

bonus: $(BNAME)

$(BNAME): $(B_OBJ) $(LIBFT)
	@echo "Creating $(BNAME)..."
	@$(CC) $(CFLAGS) $(B_IFLAGS) $(LFLAGS) $(M_OBJ) $(LIBFT) -o $(BNAME) 
	@echo "Created $(BNAME)"

%.o: %.c
	@$(CC) $(CFLAGS) $(M_FLAGS) -c $< -o $@

clean:
	@echo "Removing objects files..."
	@make -C $(LIBFT_DIR) clean
	@rm -f $(M_OBJ) $(B_OBJ)
	@echo "Objects files removed."

fclean: clean
	@echo "Removing $(NAME) and $(BNAME)..."
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME) $(BNAME)
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
