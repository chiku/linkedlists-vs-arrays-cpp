CC := gcc
CXX := g++
AR := ar
STRIP := strip
LCOV := lcov
GENHTML := genhtml

CFLAGS += -O2 -Wall -Wextra
CXXFLAGS += -O2 -Wall -Wextra
LDFLAGS += -lboost_unit_test_framework

CXXFLAGS += -I.

obj/%.o: %.cpp
	$(CXX) -c $(CFLAGS) $(CXXFLAGS) $< -o $@

all: release

compile: bin/linkedlist

test: bin/linkedlist-test
	./bin/linkedlist-test --show_progress

release: compile test
	${STRIP} bin/linkedlist
	${STRIP} bin/linkedlist-test

coverage: CXXFLAGS += --coverage
coverage: LDFLAGS += --coverage
coverage: test generate.coverage.report

generate.coverage.report:
	${LCOV} --capture --directory ${PWD}/obj --base-directory ${PWD} --output-file coverage.info
	${LCOV} --extract coverage.info "${PWD}/linkedlist.cpp" -o coverage.filtered.info
	${GENHTML} coverage.filtered.info --output-directory coverage

clean:
	rm -rf obj/*.o bin/linkedlist* */*.info */*.gcda */*.gcno coverage*

bin/linkedlist: obj/linkedlist.o obj/main.o
	${CXX} -o bin/linkedlist obj/linkedlist.o obj/main.o ${LDFLAGS}

bin/linkedlist-test: obj/linkedlist.o obj/linkedlist-test.o obj/main.o
	${CXX} -o bin/linkedlist-test obj/linkedlist.o obj/linkedlist-test.o ${LDFLAGS}

obj/linkedlist.o: linkedlist.cpp linkedlist.h
obj/linkedlist-test.o: linkedlist-test.cpp linkedlist.h
obj/main.o: main.cpp linkedlist.h

.PHONY: all compile test release coverage generate.coverage.report clean
