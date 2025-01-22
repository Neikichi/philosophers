NAME = libft.a

INC_DIR = include
LIBFT_DIR = libft
SRC_DIR = src
STRING_DIR = $(SRC_DIR)/string
CHAR_DIR = $(SRC_DIR)/char
MEMORY_DIR = $(SRC_DIR)/memory
LIST_DIR = $(SRC_DIR)/list
NUMBER_DIR = $(SRC_DIR)/number
PRINTF_DIR = $(SRC_DIR)/printf
IO_DIR = $(SRC_DIR)/io
MATH_DIR = $(SRC_DIR)/math
UTILS_DIR = $(SRC_DIR)/utils

# SRC = $(wildcard $(CHAR_DIR)/*.c) \
#       $(wildcard $(STRING_DIR)/*.c) \
#       $(wildcard $(MEMORY_DIR)/*.c) \
#       $(wildcard $(LIST_DIR)/*.c) \
#       $(wildcard $(NUMBER_DIR)/*.c) \
#       $(wildcard $(PRINTF_DIR)/*.c) \
#       $(wildcard $(IO_DIR)/*.c)
#
SRC = \
	$(CHAR_DIR)/ft_isalnum.c \
	$(CHAR_DIR)/ft_isalpha.c \
	$(CHAR_DIR)/ft_isascii.c \
	$(CHAR_DIR)/ft_isdigit.c \
	$(CHAR_DIR)/ft_islower.c \
	$(CHAR_DIR)/ft_isprint.c \
	$(CHAR_DIR)/ft_isspace.c \
	$(CHAR_DIR)/ft_isupper.c \
	$(CHAR_DIR)/ft_tolower.c \
	$(CHAR_DIR)/ft_toupper.c \
	$(CHAR_DIR)/ft_issign.c \
	$(IO_DIR)/ft_putchar_fd.c \
	$(IO_DIR)/ft_putendl_fd.c \
	$(IO_DIR)/ft_putnbr_fd.c \
	$(IO_DIR)/ft_putnchar_fd.c \
	$(IO_DIR)/ft_putnstr_fd.c \
	$(IO_DIR)/ft_putstr_fd.c \
	$(IO_DIR)/get_next_line.c \
	$(LIST_DIR)/ft_lstadd_back.c \
	$(LIST_DIR)/ft_lstadd_front.c \
	$(LIST_DIR)/ft_lstclear.c \
	$(LIST_DIR)/ft_lstdelone.c \
	$(LIST_DIR)/ft_lstiter.c \
	$(LIST_DIR)/ft_lstlast.c \
	$(LIST_DIR)/ft_lstmap.c \
	$(LIST_DIR)/ft_lstnew.c \
	$(LIST_DIR)/ft_lstsize.c \
	$(LIST_DIR)/ft_lstpop_front.c \
	$(LIST_DIR)/ft_lstpop_back.c \
	$(LIST_DIR)/ft_lstrange.c \
	$(LIST_DIR)/ft_lstrrange.c \
	$(MEMORY_DIR)/ft_bzero.c \
	$(MEMORY_DIR)/ft_calloc.c \
	$(MEMORY_DIR)/ft_memchr.c \
	$(MEMORY_DIR)/ft_memcmp.c \
	$(MEMORY_DIR)/ft_memcpy.c \
	$(MEMORY_DIR)/ft_memmove.c \
	$(MEMORY_DIR)/ft_memset.c \
	$(NUMBER_DIR)/ft_atoi.c \
	$(NUMBER_DIR)/ft_atoi_base.c \
	$(NUMBER_DIR)/ft_countdigits.c \
	$(NUMBER_DIR)/ft_countdigits_hex.c \
	$(NUMBER_DIR)/ft_countdigits_u.c \
	$(NUMBER_DIR)/ft_itoa.c \
	$(NUMBER_DIR)/ft_itoa_hex.c \
	$(NUMBER_DIR)/ft_itoa_u.c \
	$(PRINTF_DIR)/ft_bs_esc.c \
	$(PRINTF_DIR)/ft_flags.c \
	$(PRINTF_DIR)/ft_flags_cs.c \
	$(PRINTF_DIR)/ft_flags_di.c \
	$(PRINTF_DIR)/ft_flags_p.c \
	$(PRINTF_DIR)/ft_flags_u.c \
	$(PRINTF_DIR)/ft_flags_x.c \
	$(PRINTF_DIR)/ft_printf.c \
	$(STRING_DIR)/ft_split.c \
	$(STRING_DIR)/ft_strchr.c \
	$(STRING_DIR)/ft_strdup.c \
	$(STRING_DIR)/ft_striteri.c \
	$(STRING_DIR)/ft_strjoin.c \
	$(STRING_DIR)/ft_strlcat.c \
	$(STRING_DIR)/ft_strlcpy.c \
	$(STRING_DIR)/ft_strlen.c \
	$(STRING_DIR)/ft_strlowercase.c \
	$(STRING_DIR)/ft_strmapi.c \
	$(STRING_DIR)/ft_strncmp.c \
	$(STRING_DIR)/ft_strnstr.c \
	$(STRING_DIR)/ft_strrchr.c \
	$(STRING_DIR)/ft_strtrim.c \
	$(STRING_DIR)/ft_struppercase.c \
	$(STRING_DIR)/ft_substr.c \
	$(STRING_DIR)/ft_word_count.c \
	$(MATH_DIR)/ft_abs.c \
	$(MATH_DIR)/ft_fabs.c \
	$(MATH_DIR)/ft_dabs.c \
	$(MATH_DIR)/ft_min.c \
	$(MATH_DIR)/ft_max.c \
	$(MATH_DIR)/ft_fmin.c \
	$(MATH_DIR)/ft_fmax.c \
	$(MATH_DIR)/ft_dmin.c \
	$(MATH_DIR)/ft_dmax.c \
	$(UTILS_DIR)/ft_splits_utils.c

OBJ = $(SRC:%.c=%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
IFLAGS = -I$(INC_DIR)
AR = ar
ARFLAGS = rcs

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Creating library..."
	@$(AR) $(ARFLAGS) $@ $(OBJ)
	@echo "Created $(NAME)"

bonus: all

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

# debug: CFLAGS += -g -fpic
# debug: fclean all
# 	@echo "Enable debug mode"

.PHONY: all clean fclean re bonus #debug
