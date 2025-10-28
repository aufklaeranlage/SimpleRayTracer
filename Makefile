# directories
SRC_DIR		:= src
INC_DIR		:= inc
OBJ_DIR		:= obj
LIB_DIR		:= lib

# files
NAME		:= miniRT

## sources
SRC	:=
vpath %.c $(SRC_DIR)/tuple
SRC += tuple_init.c
SRC += tuple_check.c
SRC += tuple_math.c

## objects
OBJ		:= $(SRC:.c=.o)
OBJ		:= $(addprefix $(OBJ_DIR)/, $(OBJ))

##clibraries etc
FPT_DIR	:= lib/fptc-ns-lib/src

## dependencies
DEPS	:= $(OBJ:%.o=%.d)

## commands
CC			:= cc
LD			:= cc
RM			:= rm -rf
AR			:= ar
RANLIB		:= ranlib
MAKE		:= make
CMAKE		:= cmake
DIR_DUP		= mkdir -p $(@D)	# $(@D) = target directory

## cflags
CFLAGS		:=
CFLAGS		+= -Wall
CFLAGS		+= -Wextra
CFLAGS		+= -Werror

## cppflags
CPPFLAGS	:=
CPPFLAGS	+= -MMD
CPPFLAGS	+= -MP
CPPFLAGS	+= $(addprefix -I, $(INC_DIR))
CPPFLAGS	+= $(addprefix -I, $(FPT_DIR))

### fpt
CPPFLAGS		+= -DFPT_BITS=32

## ldflags
LDFLAGS		:=

# testing
## directories
TEST_DIR		:= test
TEST_SRC_DIR	:= $(TEST_DIR)/src
TEST_OBJ_DIR	:= $(TEST_DIR)/obj
## Unity
UNI			:= libunity.a
UNI_DIR		:= test/Unity

## sources
TEST_SRC	:=
vpath %.c $(TEST_SRC_DIR)
TEST_SRC	+= tuple.c

## objects
TEST_OBJ	:= $(TEST_SRC:.c=.out)
TEST_OBJ	:= $(addprefix $(TEST_OBJ_DIR)/, $(TEST_OBJ))

## flags
TEST_CPPFLAGS	+= $(addprefix -I, $(UNI_DIR)/src)
TEST_LDFLAGS	+= $(addprefix -L, $(UNI_DIR))
TEST_LDFLAGS	+= $(addprefix -l, unity)

ifndef DEBUG
	CFLAGS += -O3
else
	CFLAGS += -O0
endif

## conditional flagsbe
ifeq ($(DEBUG), 1)
	CFLAGS += -g3
	CPPFLAGS += -g3
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

$(NAME): $(OBJ)
	$(LD) $(OBJ) -o $@ $(LDFLAGS)

test: $(UNI) $(OBJ) $(TEST_OBJ)
	$(RM) $(TEST_OBJ_DIR)
	$(MAKE) -C $(UNI_DIR) clean

$(UNI):
	$(CMAKE) $(UNI_DIR)
	$(MAKE) -C $(UNI_DIR)

$(TEST_OBJ_DIR)/%.out: $(TEST_SRC_DIR)/%.c
	@$(DIR_DUP)
	$(CC) $(OBJ) $(CFLAGS) $(TEST_CFLAGS) $(CPPFLAGS) $(TEST_CPPFLAGS) -o $@ $< $(LDFLAGS) $(TEST_LDFLAGS)
	./$@
	$(RM) $@

$(OBJ_DIR)/%.o: %.c
	@$(DIR_DUP)
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
