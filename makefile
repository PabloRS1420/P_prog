OBJS      = $(patsubst src/%.c, obj/%.o,$(wildcard src/*.c))
TESTS			= $(patsubst src/%_test.c, %_test, $(wildcard src/*.c))
CFLAGS = -Wall -ansi -pedantic -g
SRCS =  $(include/%.h)

##########################################################################
OBJS_without_mains = $(filter-out obj/%_test.o obj/execute_tests.o obj/game_loop.o, $(OBJS))
OBJS_goose = $(OBJS_without_mains) obj/game_loop.o
OBJS_tests = $(OBJS_without_mains) obj/execute_tests.o

########################################################
obj/%.o: src/%.c include/%.h
	@echo ">>>>>> Creating $@";
	gcc $(CFLAGS) -c -o $@ $<;
obj/%.o: src/%.c
	@echo "=>>>>> Creating $@";
	gcc $(CFLAGS) -c -o $@ $<;
################################################################
all: cleantemp clean $(OBJS) goose $(TESTS) execute_tests doxy dist
goose: $(OBJS_goose)
		gcc -o goose $(OBJS_goose)
execute_tests: $(OBJS_tests)
		gcc -o execute_tests $(OBJS_tests)
%_test: $(OBJS_without_mains) obj/%_test.o
		gcc -o $@ obj/$@.o $(OBJS_without_mains)

doxy: Doxyfile $(SRCS)
	doxygen Doxyfile

cleantemp:
		rm -f obj/*.o

dist:
		tar cvzf goose.tgz src/*.c include/*.h obj doc/* *.dat makefile Doxyfile Doxygen_Documentation.html Project_Management/*

clean:
		rm -f goose execute_tests *_test

run:
		@echo ">>>>>> Starting the game of the goose"; sleep 2; ./goose data.dat

runvalg:
		@echo ">>>>>> Starting with control of memory leaks"; sleep 2; valgrind --leak-check=full ./goose data.dat

runlog:
		@echo ">>>>>> Starting the game of the goose, logfile created in same folder: logfile.txt"; sleep 3; ./goose data.dat -l logfile.txt
