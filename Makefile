.DEFAULT_GOAL := all
SHELL         := bash

ASTYLE        := astyle
CHECKTESTDATA := checktestdata
CPPCHECK      := cppcheck
DOXYGEN       := doxygen
SHELL 		  := /bin/bash # added due to instructions from Project #1

ifeq ($(shell uname -s), Darwin)
    BOOST    := /usr/local/include/boost
    CXX      := clang++
    CXXFLAGS := --coverage -g -std=c++17 -Wall -Wextra -Wpedantic
    GCOV     := llvm-cov gcov
    GTEST    := /usr/local/src/googletest-master
    LDFLAGS  := -lgtest -lgtest_main
    LIB      := /usr/local/lib
    VALGRIND :=
else ifeq ($(shell uname -p), unknown)
    BOOST    := /usr/include/boost
    CXX      := g++
    CXXFLAGS := --coverage -g -std=c++17 -Wall -Wextra -Wpedantic
    GCOV     := gcov
    GTEST    := /usr/src/gtest
    LDFLAGS  := -lgtest -lgtest_main -pthread
    LIB      := /usr/lib
    VALGRIND :=
else
    BOOST    := /usr/local/opt/boost-1.67/include/boost
    CXX      := g++-11
    CXXFLAGS := --coverage -g -std=c++17 -Wall -Wextra -Wpedantic
    GCOV     := gcov-11
    GTEST    := /usr/local/include/gtest
    LDFLAGS  := -L/usr/local/opt/boost-1.77/lib/ -lgtest -lgtest_main -pthread
    LIB      := /usr/local/lib
    VALGRIND := valgrind-3.17
endif

# run docker
docker:
	docker run --rm -i -t -v $(PWD):/usr/gcc -w /usr/gcc gpdowning/gcc

# get git config
config:
	git config -l

# get git log
Life.log.txt:
	git log > Life.log.txt

# get git status
status:
	make clean
	@echo
	git branch
	git remote -v
	git status

# download files from the Life code repo
pull:
	make clean
	@echo
	git pull
	git status

# upload files to the Life code repo
push:
	make clean
	@echo
	git add .gitignore
	git add .gitlab-ci.yml
	git add Life.hpp
	-git add Life.log.txt
	-git add html
	git add Makefile
	git add README.md
	git add RunLife.cpp
	git add RunLife.ctd.txt
	git add TestLife.cpp
	git commit -m "another commit"
	git push
	git status

# compile run harness
RunLifeConway: RunLifeConway.cpp
	-$(CPPCHECK) RunLifeConway.cpp
	$(CXX) $(CXXFLAGS) RunLifeConway.cpp -o RunLifeConway

RunLifeFredkin: RunLifeFredkin.cpp
	-$(CPPCHECK) RunLifeFredkin.cpp
	$(CXX) $(CXXFLAGS) RunLifeFredkin.cpp -o RunLifeFredkin

RunLifeCell: RunLifeCell.cpp
	-$(CPPCHECK) RunLifeCell.cpp
	$(CXX) $(CXXFLAGS) RunLifeCell.cpp -o RunLifeCell

# compile test harness
TestLife: Life.hpp TestLife.cpp
	-$(CPPCHECK) TestLife.cpp
	$(CXX) $(CXXFLAGS) TestLife.cpp -o TestLife $(LDFLAGS)

# run/test files, compile with make all
FILES :=          \
    RunLifeConway \
	RunLifeFredkin\
	RunLifeCell   \
    TestLife

# compile all
all: $(FILES)

# execute test harness
test: TestLife
	$(VALGRIND) ./TestLife
ifeq ($(shell uname -s), Darwin)
	$(GCOV) TestLife.cpp | grep -B 2 "hpp.gcov"
else ifeq ($(shell uname -p), unknown)
	$(GCOV) TestLife.cpp | grep -B 2 "hpp.gcov"
else
	$(GCOV) TestLife-TestLife.cpp | grep -B 2 "hpp.gcov"
endif

# clone the Life test repo
../cs371p-Life-tests:
	git clone https://gitlab.com/gpdowning/cs371p-Life-tests.git ../cs371p-Life-tests

# test files in the Life test repo
T_FILES := `ls ../cs371p-Life-tests/*Conway.in.txt`

# check the integrity of all the test files in the Collatz test repo
ctd-check: ../cs371p-Life-tests
	-for v in $(T_FILES); do echo $(CHECKTESTDATA) RunLife.ctd.txt $$v; $(CHECKTESTDATA) RunLife.ctd.txt $$v; done

# generate a random input file
ctd-generate:
	for v in {1}; do $(CHECKTESTDATA) -g RunLife.ctd.txt >> RunLife.gen.txt; done

# execute the run harness against your test files in the Life test repo and diff with the expected output
run-conway: RunLifeConway
	$(CHECKTESTDATA) RunLife.ctd.txt ../cs371p-Life-tests/brycedrichardson191-RunLifeConway.in.txt
	./RunLifeConway < ../cs371p-Life-tests/brycedrichardson191-RunLifeConway.in.txt > RunLifeConway.tmp.txt
	diff RunLifeConway.tmp.txt ../cs371p-Life-tests/brycedrichardson191-RunLifeConway.out.txt

run-fredkin: RunLifeFredkin
	$(CHECKTESTDATA) RunLife.ctd.txt ../cs371p-Life-tests/brycedrichardson191-RunLifeFredkin.in.txt
	./RunLifeFredkin < ../cs371p-Life-tests/brycedrichardson191-RunLifeFredkin.in.txt > RunLifeFredkin.tmp.txt
	diff RunLifeFredkin.tmp.txt ../cs371p-Life-tests/brycedrichardson191-RunLifeFredkin.out.txt

run-cell: RunLifeCell
	$(CHECKTESTDATA) RunLife.ctd.txt ../cs371p-Life-tests/brycedrichardson191-RunLifeCell.in.txt
	./RunLifeCell < ../cs371p-Life-tests/brycedrichardson191-RunLifeCell.in.txt > RunLifeCell.tmp.txt
	diff RunLifeCell.tmp.txt ../cs371p-Life-tests/brycedrichardson191-RunLifeCell.out.txt

# auto format the code
format:
	$(ASTYLE) Life.hpp
	$(ASTYLE) RunLife.cpp
	$(ASTYLE) TestLife.cpp

# you must edit Doxyfile and
# set EXTRACT_ALL     to YES
# set EXTRACT_PRIVATE to YES
# set EXTRACT_STATIC  to YES
# create Doxfile
Doxyfile:
	$(DOXYGEN) -g

# create html directory
html: Doxyfile
	$(DOXYGEN) Doxyfile

# check files, check their existence with make check
C_FILES :=            \
    .gitignore        \
    .gitlab-ci.yml    \
    Life.log.txt \
    html

# check the existence of check files
check: $(C_FILES)

# remove executables and temporary files
clean:
	rm -f  *.gcda
	rm -f  *.gcno
	rm -f  *.gcov
	rm -f  *.gen.txt
	rm -f  *.tmp.txt
	rm -f  RunLifeConway
	rm -f  RunLifeFredkin
	rm -f  RunLifeCell
	rm -f  TestLife
	rm -rf *.dSYM

# remove executables, temporary files, and generated files
scrub:
	make clean
	rm -f  Life.log.txt
	rm -f  Doxyfile
	rm -rf html
	rm -rf latex

# output versions of all tools
versions:
	@echo  'shell uname -p'
	@echo $(shell uname -p)

	@echo
	@echo  'shell uname -s'
	@echo $(shell uname -s)

	@echo
	@echo "% which $(ASTYLE)"
	@which $(ASTYLE)
	@echo
	@echo "% $(ASTYLE) --version"
	@$(ASTYLE) --version

	@echo
	@echo "% which $(CHECKTESTDATA)"
	@which $(CHECKTESTDATA)
	@echo
	@echo "% $(CHECKTESTDATA) --version"
	@$(CHECKTESTDATA) --version

	@echo
	@echo "% which cmake"
	@which cmake
	@echo
	@echo "% cmake --version"
	@cmake --version

	@echo
	@echo "% which $(CPPCHECK)"
	@which $(CPPCHECK)
	@echo
	@echo "% $(CPPCHECK) --version"
	@$(CPPCHECK) --version

	@echo
	@echo "% which $(DOXYGEN)"
	@which $(DOXYGEN)
	@echo
	@echo "% $(DOXYGEN) --version"
	@$(DOXYGEN) --version

	@echo
	@echo "% which $(CXX)"
	@which $(CXX)
	@echo
	@echo "% $(CXX) --version"
	@$(CXX) --version

	@echo "% which $(GCOV)"
	@which $(GCOV)
	@echo
	@echo "% $(GCOV) --version"
	@$(GCOV) --version

	@echo "% which git"
	@which git
	@echo
	@echo "% git --version"
	@git --version

	@echo
	@echo "% which make"
	@which make
	@echo
	@echo "% make --version"
	@make --version

ifneq ($(VALGRIND),)
	@echo
	@echo "% which $(VALGRIND)"
	@which $(VALGRIND)
	@echo
	@echo "% $(VALGRIND) --version"
	@$(VALGRIND) --version
endif

	@echo
	@echo "% which vim"
	@which vim
	@echo
	@echo "% vim --version"
	@vim --version

	@echo
	@echo "% grep \"#define BOOST_LIB_VERSION \" $(BOOST)/version.hpp"
	@grep "#define BOOST_LIB_VERSION " $(BOOST)/version.hpp

	@echo
	@echo "pkg-config --modversion gtest"
	@pkg-config --modversion gtest
	@echo
	@echo "% ls -al $(LIB)/libgtest*.a"
	@ls -al $(LIB)/libgtest*.a
