FLAGS=-std=c++20 -Ofast

student:
	g++ -c ${FLAGS} src/Student.cpp -o bin/Student.o

main:
	g++ ${FLAGS} src/main.cpp bin/Student.o -o out/main.out

clean:
	rm -rf bin/*.o
	rm -rf out/*.out
