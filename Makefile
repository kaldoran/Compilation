# Release/Debug

DEBUG=yes

# Directories

SRC_DIR = SRC
INC_DIR = INC
OBJ_DIR = OBJ
BIN_DIR = BIN

# Yacc & lex
YACC = yacc
LEX = lex
OUT_YACC_LEX = $(SRC_DIR)/$(YACC).c $(SRC_DIR)/$(LEX).c

# Compilation flags

CXX = gcc
CXXFLAGS = -Wextra -Wall -pedantic -ansi
LDFLAGS = -ly -lfl

ifeq ($(DEBUG), yes)
	CXXFLAGS += -g
else
	CXXFLAGS += -O2 -s
endif

# Sources & Headers & Bin

SRC = $(foreach dir, $(SRC_DIR), $(wildcard $(dir)/*.c)) 
OBJ = $(addsuffix .o, $(basename $(subst ${SRC_DIR}, ${OBJ_DIR}, ${SRC})))
BIN = prog

# Make

.PHONY: clean mrproper
.SUFFIXES:

all: $(BIN)

$(BIN): $(OBJ) #parse
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -o ${BIN_DIR}/${BIN} $(OBJ) $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@

parse:
	yacc -d $(SRC_DIR)/$(YACC).y -o $(SRC_DIR)/$(YACC).c
	lex -t $(SRC_DIR)/$(LEX).l > $(SRC_DIR)/$(LEX).c

clean:
	@rm -f $(OBJ)
	@rm -f $(SRC_DIR)/$(YACC).c $(SRC_DIR)/$(LEX).c
	@rm -f $(OBJ_DIR)/$(YACC).o $(OBJ_DIR)/$(LEX).o
	@rm -rf $(SRC_DIR)/*~ $(SRC_DIR)/*# $(INC_DIR)/*~ $(INC_DIR)/*# *~ *#

mrproper: clean
	@rm -rf $(BIN_DIR)/$(BIN)

rebuild: mrproper all
