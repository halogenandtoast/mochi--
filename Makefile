SRC = src/main.cpp
OBJ = ${SRC:.cpp=.o}

CC = g++
LEX = flex
YACC = bison

all: mochi

.cpp.o:
	@${CC} -c -o $@ $<

mochi: ${OBJ}
	${CC} ${OBJ} -o mochi

clean:
	@rm -f ${OBJ} mochi
