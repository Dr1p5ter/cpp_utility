CC=g++
STD=c++17
DS_F="test_ds.cpp"
ALGO_F="test_algo.cpp"
EXEC="prog"
DESC=""

compile_ds_test:
	@echo "Compiling $(DS_F) from repo.."
	$(CC) $(DS_F) -Werror -Wall -std=$(STD) -o $(EXEC)
	make run

compile_algo_test:
	@echo "Compiling $(ALGO_F) from repo.."
	$(CC) $(ALGO_F) -Werror -Wall -std=$(STD) -o $(EXEC)
	make run

.SILENT:
run:
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

edit-help:
	@echo "Use ctr + v && ctr + i to get indents"

