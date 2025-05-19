CXX     := g++
STRIP   := strip
LCOV    := lcov
GENHTML := genhtml

CXXFLAGS += -std=c++11 -O2 -Wall -Wextra -I./headers -I./vendor
LDFLAGS  += -std=c++11

BIN_DIR := bin
OBJ_DIR := obj

ARRAYLIST_OBJS = \
	$(OBJ_DIR)/arraylist/arraylist.o \
	$(OBJ_DIR)/arraylist/main.o

LINKEDLIST_OBJS = \
	$(OBJ_DIR)/linkedlist/linkedlist.o \
	$(OBJ_DIR)/linkedlist/main.o

GEN_REPORT_OBJS = \
	$(OBJ_DIR)/generate-report/main.o

ARRAYLIST_TEST_OBJS = \
	$(OBJ_DIR)/arraylist/arraylist.o \
	$(OBJ_DIR)/arraylist/arraylist-test.o \
	$(OBJ_DIR)/tests/test-suite.o

LINKEDLIST_TEST_OBJS = \
	$(OBJ_DIR)/linkedlist/linkedlist.o \
	$(OBJ_DIR)/linkedlist/linkedlist-test.o \
	$(OBJ_DIR)/tests/test-suite.o

ARRAYLIST_BIN := $(BIN_DIR)/arraylist
LINKEDLIST_BIN := $(BIN_DIR)/linkedlist
GENERATE_REPORT_BIN := $(BIN_DIR)/generate-report
ARRAYLIST_TEST_BIN := $(BIN_DIR)/arraylist-test
LINKEDLIST_TEST_BIN := $(BIN_DIR)/linkedlist-test

.PHONY: all compile test release coverage generate clean

all: release

compile: $(ARRAYLIST_BIN) $(LINKEDLIST_BIN) $(GENERATE_REPORT_BIN)

test: $(ARRAYLIST_TEST_BIN) $(LINKEDLIST_TEST_BIN)
	./$(ARRAYLIST_TEST_BIN)
	./$(LINKEDLIST_TEST_BIN)

release: compile test
	$(STRIP) $(ARRAYLIST_BIN) $(ARRAYLIST_TEST_BIN) $(LINKEDLIST_BIN) $(LINKEDLIST_TEST_BIN)

COVERAGE_CXXFLAGS := $(filter-out -O2,$(CXXFLAGS)) -O0 -g --coverage
COVERAGE_LDFLAGS := $(LDFLAGS) --coverage

coverage: CXXFLAGS := $(COVERAGE_CXXFLAGS)
coverage: LDFLAGS := $(COVERAGE_LDFLAGS)
coverage: test
	$(LCOV) --capture --directory $(OBJ_DIR)/arraylist --directory $(OBJ_DIR)/linkedlist --base-directory $(PWD) --output-file coverage.info
	$(LCOV) --extract coverage.info "$(PWD)/pkg/arraylist/arraylist.cpp" "$(PWD)/pkg/linkedlist/linkedlist.cpp" -o coverage.filtered.info
	$(GENHTML) coverage.filtered.info --output-directory coverage

# Link rules
$(ARRAYLIST_BIN): $(ARRAYLIST_OBJS)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

$(LINKEDLIST_BIN): $(LINKEDLIST_OBJS)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

$(GENERATE_REPORT_BIN): $(GEN_REPORT_OBJS)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

$(ARRAYLIST_TEST_BIN): $(ARRAYLIST_TEST_OBJS)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

$(LINKEDLIST_TEST_BIN): $(LINKEDLIST_TEST_OBJS)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Explicit object rules
$(OBJ_DIR)/arraylist/arraylist.o: pkg/arraylist/arraylist.cpp headers/arraylist.h
	@mkdir -p $(dir $@)
	$(CXX) -c $(CXXFLAGS) $< -o $@

$(OBJ_DIR)/arraylist/main.o: pkg/arraylist/main.cpp headers/arraylist.h
	@mkdir -p $(dir $@)
	$(CXX) -c $(CXXFLAGS) $< -o $@

$(OBJ_DIR)/arraylist/arraylist-test.o: tests/arraylist/arraylist-test.cpp vendor/doctest.h headers/arraylist.h
	@mkdir -p $(dir $@)
	$(CXX) -c $(CXXFLAGS) $< -o $@

$(OBJ_DIR)/linkedlist/linkedlist.o: pkg/linkedlist/linkedlist.cpp headers/linkedlist.h
	@mkdir -p $(dir $@)
	$(CXX) -c $(CXXFLAGS) $< -o $@

$(OBJ_DIR)/linkedlist/main.o: pkg/linkedlist/main.cpp headers/linkedlist.h
	@mkdir -p $(dir $@)
	$(CXX) -c $(CXXFLAGS) $< -o $@

$(OBJ_DIR)/linkedlist/linkedlist-test.o: tests/linkedlist/linkedlist-test.cpp vendor/doctest.h headers/linkedlist.h
	@mkdir -p $(dir $@)
	$(CXX) -c $(CXXFLAGS) $< -o $@

$(OBJ_DIR)/generate-report/main.o: pkg/generate-report/main.cpp
	@mkdir -p $(dir $@)
	$(CXX) -c $(CXXFLAGS) $< -o $@

$(OBJ_DIR)/tests/test-suite.o: tests/test-suite.cpp vendor/doctest.h
	@mkdir -p $(dir $@)
	$(CXX) -c $(CXXFLAGS) $< -o $@

clean:
	rm -rf obj/ bin/ *.info *.gcda *.gcno coverage*

output:
	@mkdir -p output

output/arraylist.csv: $(ARRAYLIST_BIN) output
	$(ARRAYLIST_BIN) | tee $@

output/linkedlist.csv: $(LINKEDLIST_BIN) output
	$(LINKEDLIST_BIN) | tee $@

generate: $(GENERATE_REPORT_BIN) output/arraylist.csv output/linkedlist.csv
	$(GENERATE_REPORT_BIN)
