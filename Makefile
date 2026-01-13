MAKEFLAGS += --no-print-directory

CC = gcc
CFLAGS = -g -Wall -Werror -Wextra

BUILD_PATH = build


CFILES_PATH = src
CFILES =	$(CFILES_PATH)/untrue.c \
		$(CFILES_PATH)/parser/parser.c \
		$(CFILES_PATH)/utils/io_check.c \

OBJ = $(CFILES:$(CFILES_PATH)/%.c=$(BUILD_PATH)/%.o)

NAME = untrue

all:
	@echo "Building $(NAME)...\n"
	@$(MAKE) $(NAME)
	@echo "Done."


$(NAME): $(OBJ)
	@echo "Linking $(NAME)...\n"
	@$(CC) $(OBJ) -o $(NAME)

$(BUILD_PATH)/%.o: $(CFILES_PATH)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes --log-file="resources/leaks.log" ./untrue untrue.config

clean:
	@echo "Cleaning object files...\n"
	@rm -f $(BUILD_PATH)/*.o

fclean: clean
	@echo "Fully cleaning project...\n"
	@rm -f $(NAME)
	@rm -rf $(BUILD_PATH)

re: fclean all

.PHONY: all clean fclean re
