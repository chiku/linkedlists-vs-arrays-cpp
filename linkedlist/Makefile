CC = gcc
CXX = g++
AR = ar
STRIP = strip
LCOV = lcov
GENHTML = genhtml

CFLAGS += -O2
CXXFLAGS += -O2
LDFLAGS += -lboost_unit_test_framework

CXXFLAGS += -I.

obj/%.o: %.cpp
	$(CXX) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

all: release

compile: bin/linklist

test: bin/linklist-test
	./bin/linklist-test --show_progress

release: compile test
	${STRIP} bin/linklist
	${STRIP} bin/linklist-test

coverage: CXXFLAGS += --coverage
coverage: LDFLAGS += --coverage
coverage: test generate.coverage.report

generate.coverage.report:
	${LCOV} --capture --directory linklist --output-file coverage.info
	${LCOV} --extract coverage.info "${PWD}/linklist.cpp" -o coverage.filtered.info
	${GENHTML} coverage.filtered.info --output-directory coverage

clean:
	rm -rf *.o bin/linklist-test bin/linklist *.info *.gcda *.gcno coverage*

bin/linklist: obj/linklist.o obj/main.o
	${CXX} -o bin/linklist obj/linklist.o obj/main.o ${LDFLAGS}

bin/linklist-test: obj/linklist.o obj/linklist-test.o obj/main.o
	${CXX} -o bin/linklist-test obj/linklist.o obj/linklist-test.o ${LDFLAGS}

obj/linklist.o: linklist.cpp linklist.h
obj/linklist-test.o: linklist-test.cpp linklist.h
obj/main.o: main.cpp linklist.h

.PHONY: clean generate.coverage.report
