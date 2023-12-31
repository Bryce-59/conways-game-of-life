.DEFAULT_GOAL := test

ASTYLE        := astyle
CPPCHECK      := cppcheck
CXXFLAGS 	  := --coverage -g -std=c++17 -Wall -Wextra -Wpedantic
DOXYGEN       := doxygen
SHELL 		  := /bin/bash

ifeq ($(shell uname -s), Darwin)
    CXX      := clang++
    GCOV     := llvm-cov gcov
    LDFLAGS  := -lgtest -lgtest_main
    VALGRIND :=
else ifeq ($(shell uname -p), unknown)
    CXX      := g++
    GCOV     := gcov
    LDFLAGS  := -lgtest -lgtest_main -pthread
    VALGRIND :=
else
    CXX      := g++-11
    GCOV     := gcov-11
    LDFLAGS  := -L/usr/local/opt/boost-1.77/lib/ -lgtest -lgtest_main -pthread
    VALGRIND := valgrind
endif

# compile run harness
run: RunLifeConway.cpp
	-$(CPPCHECK) RunLifeConway.cpp
	$(CXX) $(CXXFLAGS) RunLifeConway.cpp -o RunLifeConway

# download files from GitHub
pull:
	make clean
	@echo
	git pull
	git status

# upload files to GitHub
push:
	make clean
	@echo
	git add *
	git commit -m "push commit"
	git push
	git status

# compile test harness
TestLife: Life.hpp TestLife.cpp
	-$(CPPCHECK) TestLife.cpp
	$(CXX) $(CXXFLAGS) TestLife.cpp -o TestLife $(LDFLAGS)

# execute test harness
test: TestLife
	$(VALGRIND) ./TestLife
# ifeq ($(shell uname -s), Darwin)
# 	$(GCOV) TestLife.cpp | grep -B 2 "hpp.gcov"
# else ifeq ($(shell uname -p), unknown)
# 	$(GCOV) TestLife.cpp | grep -B 2 "hpp.gcov"
# else
# 	$(GCOV) TestLife-TestLife.cpp | grep -B 2 "hpp.gcov"
# endif

# test files in the test repo
T_FILES_CONWAY := `ls ./tests/*ConwayCell.in.txt`

# execute the run harness against a test file and diff with the expected output
./tests/%ConwayCell: run
	./RunLifeConway < $@.in.txt > RunLifeConway.tmp.txt
	diff RunLifeConway.tmp.txt $@.out.txt

# execute the run harness against all of the test files in the test repo and diff with the expected output
run-tests: ./tests
	-for v in $(T_FILES_CONWAY); do make $${v/.in.txt/}; done

# auto format the code
format:
	$(ASTYLE) AbstractCell.hpp
	$(ASTYLE) ConwayCell.hpp
	$(ASTYLE) Life.hpp
	$(ASTYLE) RunLife.cpp
	$(ASTYLE) RunLifeConway.cpp
	$(ASTYLE) TestLife.cpp

# create Doxfile
Doxyfile:
	$(DOXYGEN) -g

# create html directory
html: Doxyfile
	$(DOXYGEN) Doxyfile

# remove executables and temporary files
clean:
	rm -f  *.gcda
	rm -f  *.gcno
	rm -f  *.gcov
	rm -f  *.gen.txt
	rm -f  *.tmp.txt
	rm -f  *.orig
	rm -f  RunLifeCell
	rm -f  TestLife
	rm -rf *.dSYM

# remove executables, temporary files, and generated files
scrub:
	make clean
	rm -f  Doxyfile
	rm -rf html
	rm -rf latex
