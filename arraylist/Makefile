CC = gcc
CXX = g++
AR = ar
STRIP = strip
LCOV = lcov
GENHTML = genhtml

CFLAGS += -O2 -Wall -Wextra
CXXFLAGS += -O2 -Wall -Wextra
LDFLAGS += -lboost_unit_test_framework

CXXFLAGS += -I.

obj/%.o: %.cpp
	$(CXX) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

all: release

compile: bin/arraylist

test: bin/arraylist-test
	./bin/arraylist-test --show_progress

release: compile test
	${STRIP} bin/arraylist
	${STRIP} bin/arraylist-test

coverage: CXXFLAGS += --coverage
coverage: LDFLAGS += --coverage
coverage: test generate.coverage.report

generate.coverage.report:
	${LCOV} --capture --directory bin --output-file coverage.info
	${LCOV} --extract coverage.info "arraylist.cpp" -o coverage.filtered.info
	${GENHTML} coverage.filtered.info --output-directory coverage

clean:
	rm -rf obj/*.o bin/arraylist* *.info *.gcda *.gcno coverage*

bin/arraylist: obj/arraylist.o obj/main.o
	${CXX} -o bin/arraylist obj/arraylist.o obj/main.o ${LDFLAGS}

bin/arraylist-test: obj/arraylist.o obj/arraylist-test.o obj/main.o
	${CXX} -o bin/arraylist-test obj/arraylist.o obj/arraylist-test.o ${LDFLAGS}

obj/arraylist.o: arraylist.cpp arraylist.h
obj/arraylist-test.o: arraylist-test.cpp arraylist.h
obj/main.o: main.cpp arraylist.h

.PHONY: clean generate.coverage.report
