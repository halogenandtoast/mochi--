OBJS = src/mochi.tab.o \
			 src/lex.o \
			 src/interpreter.o \
			 src/main.o

all: mochi

src/mochi.tab.hpp: src/mochi.tab.cpp

src/mochi.tab.cpp: src/mochi.y
	bison -d -o $@ $^

src/lex.cpp: src/lex.l src/mochi.tab.hpp
	flex -o $@ $^

%.o: %.cpp
	g++ -o $@ -c $<

mochi: $(OBJS)
	g++ -o $@ $(OBJS)

clean:
	@rm -f ${OBJS} mochi lex src/lex.cpp src/mochi.tab.cpp src/mochi.tab.hpp src/location.hh src/position.hh src/stack.hh
