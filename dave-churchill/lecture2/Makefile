CXX = g++

FLAGS = -Wall -Wextra -std=c++17

all: hello student

memory: memory.cpp
	$(CXX) $(FLAGS) -o memory.out memory.cpp
	./memory.out

hello: hello.cpp
	$(CXX) $(FLAGS) -o hello.out hello.cpp
	./hello.out

student: student.cpp
	$(CXX) $(FLAGS) -o student.out student.cpp
	./student.out

clean:
	rm -f hello.out student.out
