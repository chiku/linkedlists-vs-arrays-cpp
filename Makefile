CXX := g++
STRIP := strip
LCOV := lcov
GENHTML := genhtml

CXXFLAGS += -O2 -Wall -Wextra -I./headers -I./vendor
LDFLAGS +=

ARRAYLIST_BIN := bin/arraylist
LINKEDLIST_BIN := bin/linkedlist
GENERATE_REPORT_BIN := bin/generate-report
ARRAYLIST_TEST_BIN := bin/arraylist-test
LINKEDLIST_TEST_BIN := bin/linkedlist-test

%.o:
	mkdir -p $(dir $@)
	$(CXX) -c $(CXXFLAGS) $< -o $@

all: release

compile: $(ARRAYLIST_BIN) $(LINKEDLIST_BIN) $(GENERATE_REPORT_BIN)

test: $(ARRAYLIST_TEST_BIN) $(LINKEDLIST_TEST_BIN)
	./$(ARRAYLIST_TEST_BIN)
	./$(LINKEDLIST_TEST_BIN)

release: compile test
	${STRIP} $(ARRAYLIST_BIN) $(ARRAYLIST_TEST_BIN)
	${STRIP} $(LINKEDLIST_BIN) $(LINKEDLIST_TEST_BIN)

coverage: CXXFLAGS += --coverage
coverage: LDFLAGS += --coverage
coverage: test
	${LCOV} --capture --directory ${PWD}/obj/arraylist --directory ${PWD}/obj/linkedlist --base-directory ${PWD} --output-file coverage.info
	${LCOV} --extract coverage.info "${PWD}/pkg/arraylist/arraylist.cpp" "${PWD}/pkg/linkedlist/linkedlist.cpp" -o coverage.filtered.info
	${GENHTML} coverage.filtered.info --output-directory coverage

clean:
	rm -rf obj/ bin/ */*.info */*.gcda */*.gcno coverage*

$(ARRAYLIST_BIN): obj/arraylist/arraylist.o obj/arraylist/main.o
	mkdir -p $(dir $@)
	${CXX} ${CXXFLAGS} -o $@ $? ${LDFLAGS}

$(ARRAYLIST_TEST_BIN): obj/arraylist/arraylist.o obj/arraylist/arraylist-test.o
	mkdir -p $(dir $@)
	${CXX} ${CXXFLAGS} -o $@ $? ${LDFLAGS}

$(GENERATE_REPORT_BIN): obj/generate-report/main.o
	mkdir -p $(dir $@)
	${CXX} ${CXXFLAGS} -o $@ $? ${LDFLAGS}

$(LINKEDLIST_BIN): obj/linkedlist/linkedlist.o obj/linkedlist/main.o
	mkdir -p $(dir $@)
	${CXX} ${CXXFLAGS} -o $@ $? ${LDFLAGS}

$(LINKEDLIST_TEST_BIN): obj/linkedlist/linkedlist.o obj/linkedlist/linkedlist-test.o
	mkdir -p $(dir $@)
	${CXX} ${CXXFLAGS} -o $@ $? ${LDFLAGS}

obj/arraylist/arraylist.o: pkg/arraylist/arraylist.cpp headers/arraylist.h
obj/arraylist/arraylist-test.o: tests/arraylist/arraylist-test.cpp vendor/catch.hpp headers/arraylist.h
obj/arraylist/main.o: pkg/arraylist/main.cpp headers/arraylist.h

obj/linkedlist/linkedlist.o: pkg/linkedlist/linkedlist.cpp headers/linkedlist.h
obj/linkedlist/linkedlist-test.o: tests/linkedlist/linkedlist-test.cpp vendor/catch.hpp headers/linkedlist.h
obj/linkedlist/main.o: pkg/linkedlist/main.cpp headers/linkedlist.h

obj/generate-report/main.o: pkg/generate-report/main.cpp

.PHONY: all compile test release coverage clean
