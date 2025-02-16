
NAME = fdf
SRCS_DIR = ./srcs
SRC = $(SRCS_DIR)/draw_map.c $(SRCS_DIR)/get_map.c $(SRCS_DIR)/set_offset.c\
	  $(SRCS_DIR)/get_next_line.c $(SRCS_DIR)/get_next_line_utils.c\
	  $(SRCS_DIR)/mlx_window.c $(SRCS_DIR)/set_scale.c $(SRCS_DIR)/main.c\
	  $(SRCS_DIR)/error.c $(SRCS_DIR)/check_file.c $(SRCS_DIR)/map_utils.c
OBJ_DIR = obj
OBJ = $(SRC:$(SRCS_DIR)/%.c=$(OBJ_DIR)/%.o)

CC = cc

LINKS = -lmlx -L./minilibx-linux -lft -L./libft -lXext -lX11 -lm -lz
# LINKS += -l./mlx_linux
CFLAGS = -I./minilibx-linux/ -I./libft
CFLAGS += -Wall -Wextra -Werror
# CFLAGS += -fsanitize=address -g
LIBFT_PATH = libft/
MLX_PATH = minilibx-linux/
RM = rm -rf

$(NAME) : $(OBJ)
	$(MAKE) -C $(LIBFT_PATH)
	$(MAKE) -C $(MLX_PATH)
	$(CC) $(OBJ) $(CFLAGS) $(LINKS) -o $(NAME)

$(OBJ_DIR)/%.o : $(SRCS_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

clean :
	$(RM) $(OBJ)
	$(RM) $(OBJ_DIR)
	@cd $(LIBFT_PATH) && $(MAKE) clean

fclean : clean
	$(RM) $(NAME)
	@cd $(MLX_PATH) && $(MAKE) clean
	@cd $(LIBFT_PATH) && $(MAKE) fclean


re : fclean all

.PHONY : all clean fclean re
