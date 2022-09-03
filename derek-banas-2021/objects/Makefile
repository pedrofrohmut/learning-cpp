COMPILER=g++

shape:
	@$(COMPILER) -c src/Shape.cpp -I include/ -o bin/Shape.o
	@echo "Built Shape.o"

circle:
	@$(COMPILER) -c src/Circle.cpp -I include/ -o bin/Circle.o
	@echo "Built Circle.o"

project:
	$(COMPILER) -c src/main.cpp -I include/ -o bin/main.o
	@$(COMPILER) bin/Shape.o bin/Circle.o bin/main.o -o main.out
	@echo "Finished building main"

main:
	@mkdir ./bin
	@$(COMPILER) -c src/Shape.cpp -I include/ -o bin/Shape.o
	@$(COMPILER) -c src/Circle.cpp -I include/ -o bin/Circle.o
	$(COMPILER) -c src/main.cpp -I include/ -o bin/main.o
	@$(COMPILER) bin/Shape.o bin/Circle.o bin/main.o -o main.out
	@echo "Finished building main"

