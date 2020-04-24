OS := $(shell uname -s)

ifeq ($(OS), Darwin) 
  CUNIT_PATH_PREFIX = /usr/local/Cellar/cunit/2.1-3/
  CUNIT_DIRECTORY = cunit
endif
ifeq ($(OS), Linux) 
  CUNIT_PATH_PREFIX = /util/CUnit/
  CUNIT_DIRECTORY = CUnit/
endif

objects = blocksWorld.o runner.o

testObjects = blocksWorld.o

CC = gcc
FLAGS = -g -c -Wall -std=c11 -O0 -fprofile-arcs -ftest-coverage

runner : $(objects) runner.c
	$(CC) -Wall -lm -lgcov --coverage -o run $(objects) 

debug : $(objects) runner.c
	$(CC) -g -lm -Wall -lgcov --coverage -std=c11 -o run.debug $(objects)

tests : ${testObjects} tests.o
	$(CC) -g -Wall -O0 -fprofile-arcs -ftest-coverage -std=c11 -lm -L $(CUNIT_PATH_PREFIX)lib -I $(CUNIT_PATH_PREFIX)include/$(CUNIT_DIRECTORY) -o tests ${testObjects} tests.o -lcunit

pyramiddebug: pyramid.o runner.o runner.c
	$(CC) -g -lm -Wall -lgcov --coverage -std=c11 -o run.debug pyramid.o runner.o

tests.o : tests.c
	$(CC) $(FLAGS) -I $(CUNIT_PATH_PREFIX)include/$(CUNIT_DIRECTORY) tests.c

runner.o : runner.c
	$(CC) $(FLAGS) runner.c

blocksWorld.o : blocksWorld.c
	$(CC) $(FLAGS) blocksWorld.c

pyramid.o: pyramid.c
	$(CC) $(FLAGS) pyramid.c

.PHONY: andRunCallGrind
andRunCallGrind:
	make clean
	make runner
	@echo "******************************************************************************"
	@echo "** Running program on large file using callgrind. This may take a minute... **"
	@echo "******************************************************************************"
	valgrind --tool=callgrind ./run 1000 1000
	@echo "******************************************************************************"
	@echo "** Done! Use callgrind_annotate to interpret the data file                  **"
	@echo "******************************************************************************"


clean :
	rm -fv run $(objects) tests tests.o run.debug *~
