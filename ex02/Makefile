CC=clang++
C_FLAGS=-Wall -Wextra -Werror -std=c++98

BIN=ex02

INC=inc/

HFILE=Base.hpp\
	utils.hpp


HDR= $(addprefix $(INC)/, $(HFILE))

SDIR=src

SFILE=main.cpp\
	utils.cpp

SRC=$(addprefix $(SDIR)/, $(SFILE))

ODIR=obj
OFILE=$(patsubst %.cpp, %.o, $(SFILE))
OBJ=$(addprefix $(ODIR)/, $(OFILE))

.Phony: all clean fclean re run

all:$(BIN)

$(BIN): $(ODIR) $(OBJ) $(SRC) $(HDR)
	$(CC) $(C_FLAGS) $(OBJ) -I $(INC) -o $(BIN) 

$(ODIR):
	mkdir obj

$(ODIR)/%.o: $(SDIR)/%.cpp
	$(CC) $(C_FLAGS) $^ -c -o $@

clean:
	rm -fd $(OBJ) $(ODIR)

fclean:
	make clean
	rm -f $(BIN)

re:
	make fclean
	make $(BIN)

run:$(BIN)
	./$(BIN)
