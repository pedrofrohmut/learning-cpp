# Compiler flags
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -O2 -std=c++17
# -I./raylib-5.5_linux_amd64/include/
LDFLAGS = -L./raylib-5.5_linux_amd64/lib/ -lm -lraylib
# -ldl -lglfw -lpthread

SOURCE = src/main.cpp

OUTPUT = out/tetris.out

all: main

compile-run: main run

debug: $(SOURCE)
	$(CXX) -Wall -Wextra -Werror -std=c++17 -g -Og -o $(OUTPUT) $(SOURCE) $(LDFLAGS)

main: $(SOURCE)
	$(CXX) $(CXXFLAGS) -o $(OUTPUT) $(SOURCE) $(LDFLAGS)

run: $(OUTPUT)
	LD_LIBRARY_PATH=./raylib-5.5_linux_amd64/lib/ ./$(OUTPUT)

clean:
	rm -f $(OUTPUT)
