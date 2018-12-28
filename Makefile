all:
	g++ -Wno-unused-result -g -O3 -std=c++11 -o solve solve.cc

test:
	python ../run_test.py

clean:
	rm -rf solve

.PHONY: all clean test $(TESTS)
