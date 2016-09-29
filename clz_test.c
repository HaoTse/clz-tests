#include <stdio.h>
#include <string.h>
#include "clzcompute.h"

#define UINT_MAX 4294967295

#define LOG2(X) ((unsigned) \
   __builtin_clz((X)))

int main(int argc, char const *argv[])
{
	char str[20];
	int clz;
	for(uint32_t i = 0; i < UINT_MAX; i++) {

		int correct = (i == 0) ? 32 : LOG2(i);

#if defined(ITERATOR)
    	clz = iterator_clz(i);
    	strcpy(str, "iterator_clz");
#endif

#if defined(BINSEARCH)
        clz = bin_search_clz(i);
        strcpy(str, "bin_search_clz");
#endif

#if defined(BYTESHIFT)
        clz = byte_shift_clz(i);
        strcpy(str, "byte_shift_clz");
#endif

    	//error message
    	if(correct != clz) {
    		printf("%s(%d) is error\n", str, i);
    		printf("output clz = %d, correct clz =  %d\n", clz, correct);
    		return 0;
    	}

	} //end of for loop

    printf("Very Good\n");

    return 0;
}