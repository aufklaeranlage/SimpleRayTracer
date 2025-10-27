# directories
SRC_DIR		:= src
INC_DIR		:= inc
OBJ_DIR		:= obj
LIB_DIR		:= lib

# files
NAME		:= miniRT

## sources
SRC	:=

## objects
OBJ		:= $(SRC:.c=.o)
OBJ		:= $(addprefix $(OBJ_DIR)/, $(OBJ))

## dependencies
DEPS	:= $(OBJ:%.o=%.d)

## libraries
FPN		:= libfpn.a
FPN_DIR	:= $(LIB_DIR)/fpn

## commands
CC			:= cc
LD			:= cc
RM			:= rm -rf
AR			:= ar
RANLIB		:= ranlib
DIR_DUP		= mkdir -p $(@D)	# $(@D) = target directory

## cflags
CFLAGS		:=
CFLAGS		+= -Wall
CFLAGS		+= -Wextra
CFLAGS		+= -Werror
CFLAGS		+= -O3

## cppflags
CPPFLAGS	:=
CPPFLAGS	+= -MMD
CPPFLAGS	+= -MP
CPPFLAGS	+= $(addprefix -I, $(INC_DIR))
CPPFLAGS	+= $(addprefix -I, $(FPN_DIR)/$(INC_DIR))

## ldflags
LDFLAGS		:=
# fpn
LDFLAGS		+= $(addprefix -L, $(FPN_DIR))
LDFLAGS		+= $(addprefix -l, fpn)

## conditional flags
ifeq ($(DEBUG), 1)
	CFLAGS += -O0
	CFLAGS += -g3
	CFLAGS += -D LAZY_NORMALIZED
	CPPFLAGS += -g3
	CPPFLAGS += -D LAZY_NORMALIZED
endif

ifeq ($(UB), 1)
	CFLAGS += -O0
	CFLAGS += -g3
	CFLAGS += -fsanitize=undefined
	CPPFLAGS += -g3
	LDFLAGS += -fsanitize=undefined
endif

ifeq ($(ASAN), 1)
	CFLAGS += -O0
	CFLAGS += -g3
	CFLAGS += -fsanitize=address
	CPPFLAGS += -g3
	LDFLAGS += -fsanitize=address
endif

ifeq ($(LSAN), 1)
	CFLAGS += -O0
	CFLAGS += -g3
	CFLAGS += -fsanitize=leak
	CPPFLAGS += -g3
	LDFLAGS += -fsanitize=leak
endif

# rules

all: $(NAME)

$(NAME): $(OBJ) $(FPN)
	$(LD) $(OBJ) -o $@ $(LDFLAGS)

$(FPN):
	$(MAKE) -C $(FPN_DIR) FPN_BITS=32 FPN_WBITS=24

$(OBJ_DIR)/%.o: %.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

-include $(DEPS)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME) $(DEPS)

re: fclean all

run: re
	./$(NAME)

.PHONY: clean fclean re run
