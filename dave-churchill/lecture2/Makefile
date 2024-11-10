CXX = g++

FLAGS = -Wall -std=c++17

all: hello student

hello: hello.cpp
	$(CXX) $(FLAGS) -o hello.out hello.cpp
	./hello.out

student: student.cpp
	$(CXX) $(FLAGS) -o student.out student.cpp
	./student.out

clean:
	rm -f hello.out student.out
