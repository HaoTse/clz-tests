CC = gcc
CFLAGS = -O0 -std=gnu99 -Wall
EXECUTABLE = \
	test_iterator test_bin_search test_byte_shift \
	test_recursive \
	benchmark

default: clzcompute.o
	$(CC) $(CFLAGS) clzcompute.o clz_test.c -DITERATOR -o test_iterator
	$(CC) $(CFLAGS) clzcompute.o clz_test.c -DBINSEARCH -o test_bin_search
	$(CC) $(CFLAGS) clzcompute.o clz_test.c -DBYTESHIFT -o test_byte_shift
	$(CC) $(CFLAGS) clzcompute.o clz_test.c -DRECURSIVE -o test_recursive
	$(CC) $(CFLAGS) clzcompute.o benchmark.c -o benchmark

.PHONY: clean default

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@ 

check: default
	time ./test_iterator
	time ./test_bin_search
	time ./test_byte_shift
	time ./test_recursive

plot: default
	- rm *.txt
	for i in `seq 10000000 50000 400000000`; do \
		./benchmark $$i; \
	done
	gnuplot scripts/runtime.gp

clean:
	rm -f $(EXECUTABLE) *.o *.txt runtime.png
