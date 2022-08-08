CC=g++
STD=c++17
DS_F="test_ds.cpp"
ALGO_F="test_algo.cpp"
EXEC="prog"
DESC=""

.SILENT:
compile_ds_test:
	@echo "Compiling $(DS_F) from repo.."
	$(CC) $(DS_F) -Werror -Wall -std=$(STD) -o $(EXEC)
	@echo "\n\nOutput:\n"
	./$(EXEC)
	@echo "\n\n"
	rm ./$(EXEC) -v

.SILENT:
compile_algo_test:
	@echo "Compiling $(ALGO_F) from repo.."
	$(CC) $(ALGO_F) -Werror -Wall -std=$(STD) -o $(EXEC)
	@echo "\n\nOutput:\n"
	./$(EXEC)
	@echo "\n\n"
	rm ./$(EXEC) -v

.SILENT:
display:
	@echo "------ List of algo files: ------"
	ls ./algo_cpp -ghq && ls ./algo_h -ghq
	@echo "------  List of ds files:  ------"
	ls ./ds_cpp -ghq && ls ./ds_h -ghq

.SILENT:
refresh:
	git add .
	git status

help:
	@echo "List of commands:"
	@echo "  compile_ds_test - runs data structure test enviornment"
	@echo "  compile_algo_test - runs algorithm test enviornment"
	@echo "  display - shows all files located in package"
	@echo "  refresh - updates file changes to git"
	@echo "  help - shows list of commands available for this repository"

# ctr + v then ctr + i
