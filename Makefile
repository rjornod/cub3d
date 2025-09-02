
NAME      := cub3D
CC        := cc
CFLAGS    := -Wall -Wextra -Werror -Wunreachable-code -Ofast -g
# ARGS ?=
# valgrind: $(NAME)
# 	valgrind --leak-check=full --track-origins=yes ./$(NAME) $(ARGS)

SRC_DIR   := src
INC_DIR   := include
BUILD_DIR := build

SRC_ROOT = \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/utils.c \
	$(SRC_DIR)/utils2.c \

SRC_PARSING = \
	$(SRC_DIR)/parsing/parsing.c \
	$(SRC_DIR)/parsing/input_check.c \
	$(SRC_DIR)/parsing/text_color_check.c \
	$(SRC_DIR)/parsing/validate_text_col.c \
	$(SRC_DIR)/parsing/validate_color.c \
	$(SRC_DIR)/parsing/validate_outer_walls.c \
	$(SRC_DIR)/parsing/validate_map.c \
	$(SRC_DIR)/parsing/validate_map_inside.c \
	$(SRC_DIR)/parsing/parse_color.c \
	$(SRC_DIR)/parsing/parse_textures.c \


SRC_RENDERING = \
	$(SRC_DIR)/rendering/mlx_init.c \
	$(SRC_DIR)/rendering/map_init.c \
	$(SRC_DIR)/rendering/raycasting.c \
	$(SRC_DIR)/rendering/render_utils.c \

GNL_DIR  := libs/gnl
GNL_SRCS = $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c

SRCS = $(SRC_ROOT) $(SRC_PARSING) $(SRC_RENDERING) $(GNL_SRCS)


OBJS      := $(SRCS:%.c=$(BUILD_DIR)/%.o)
HEADERS   := -I $(INC_DIR) -I $(MLX42_DIR)/include

LIB_DIR    := libs
LIBFT_DIR  := $(LIB_DIR)/libft
LIBFT_A    := $(LIBFT_DIR)/libft.a

MLX42_DIR  := $(LIB_DIR)/MLX
MLX42_TAG  := v2.4.1
MLX_A      := $(MLX42_DIR)/build/libmlx42.a


UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
    # macOS: needs frameworks for GLFW
    LIBS_OS := -lglfw -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo
else
    # Linux
    LIBS_OS := -ldl -lglfw -pthread -lm
endif

LIBS := $(MLX_A) $(LIBFT_A) $(LIBS_OS)

all: $(NAME)

$(NAME): $(MLX_A) $(LIBFT_A) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(HEADERS) -o $@

# Object build
$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)/$(SRC_DIR)

# ---- libft (kept in repo; just build it) ----
$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR)

# ---- MLX42 (cloned + built on demand) ----
$(MLX42_DIR):
	@mkdir -p $(LIB_DIR)
	@git clone --depth 1 --branch $(MLX42_TAG) https://github.com/codam-coding-college/MLX42.git $(MLX42_DIR)

$(MLX_A): | $(MLX42_DIR)
	@cmake -S $(MLX42_DIR) -B $(MLX42_DIR)/build >/dev/null
	@cmake --build $(MLX42_DIR)/build -j >/dev/null

# ===== Housekeeping =====
clean:
	@rm -rf $(BUILD_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean || true
	@rm -rf $(MLX42_DIR)/build

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean || true

re: fclean all

# Force a fresh MLX build if needed
mlx_rebuild: $(MLX42_DIR)
	@rm -rf $(MLX42_DIR)/build
	@$(MAKE) $(MLX_A)

.PHONY: all clean fclean re mlx_rebuild
