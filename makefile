NAME = NTTT
all:
	@echo "Compiling..."
	g++ -o $(NAME) src/*.cpp
run: all
	@echo "Running..."
	./$(name)
clean:
	-rm *.o
