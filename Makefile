CC = gcc
CFLAGS = -O0 -std=gnu99 -Wall
EXECUTABLE = \
	test_iterator test_bin_search test_byte_shift \
	test_recursive

default: clzcompute.o
	$(CC) $(CFLAGS) clzcompute.o clz_test.c -DITERATOR -o test_iterator
	$(CC) $(CFLAGS) clzcompute.o clz_test.c -DBINSEARCH -o test_bin_search
	$(CC) $(CFLAGS) clzcompute.o clz_test.c -DBYTESHIFT -o test_byte_shift
	$(CC) $(CFLAGS) clzcompute.o clz_test.c -DRECURSIVE -o test_recursive

.PHONY: clean default

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@ 

check: default
	time ./test_iterator
	time ./test_bin_search
	time ./test_byte_shift
	time ./test_recursive

clean:
	rm -f $(EXECUTABLE) *.o 
