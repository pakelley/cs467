CPP=g++
DEBUG=-g
FLAGS=-Wall -std=c++11 $(DEBUG)

UTILS_SPEC=../src/utils.hpp
FFT_SPEC=../src/fft.hpp
TEST_FUNC_SPEC=../src/test_funcs.hpp

FFT_SRC=../src/fft.cpp
TEST_FUNC_SRC=../src/test_funcs.cpp
ANALYSIS_SRC=../src/analysis.cpp

FFT_INCL=$(FFT_OBJ) $(FFT_SPEC)
TEST_FUNC_INCL=$(TEST_FUNC_OBJ) $(TEST_FUNC_SPEC)

FFT_OBJ=fft.o
ANALYSIS_BIN=../bin/analysis


all: $(ANALYSIS_BIN)

$(ANALYSIS_BIN): $(ANALYSIS_SRC) $(FFT_INCL) $(TEST_FUNC_INCL) $(UTILS_SPEC)
	$(CPP) $(FLAGS) -o $(ANALYSIS_BIN) $(ANALYSIS_SRC) $(FFT_OBJ) $(TEST_FUNC_OBJ)

$(FFT_OBJ): $(FFT_SPEC) $(FFT_SRC) $(UTILS_SPEC)
	$(CPP) $(FLAGS) -o $(FFT_OBJ) -c $(FFT_SRC)

$(TEST_FUNC_OBJ): $(TEST_FUNC_SPEC) $(TEST_FUNC_SRC) $(UTILS_SPEC)
	$(CPP) $(FLAGS) -o $(TEST_FUNC_OBJ) -c $(TEST_FUNC_SRC)
