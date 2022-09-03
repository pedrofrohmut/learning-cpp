COMPILER=g++

shape:
	@$(COMPILER) -c src/Shape.cpp -Iinclude/ -o bin/Shape.o
	@echo "Built Shape.o"

circle:
	@$(COMPILER) -c src/Circle.cpp -Iinclude/ -o bin/Circle.o
	@echo "Built Circle.o"

project:
	$(COMPILER) -c src/main.cpp -Iinclude/ -o bin/main.o
	@$(COMPILER) bin/Shape.o bin/Circle.o bin/main.o -o main
	@echo "Finished building main"
