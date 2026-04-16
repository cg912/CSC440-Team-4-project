#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void process_data() {
    char *data_buffer = (char *)malloc(50 * sizeof(char));
    strcpy(data_buffer, "Initial secure data");

    /* VULNERABILITY 1: Freeing the memory too early */
    free(data_buffer);

    /* VULNERABILITY 2: Use-After-Free */
    printf("Processing: %s\n", data_buffer);

    /* VULNERABILITY 3: Memory Leak */
    char *forgotten_buffer = (char *)malloc(100 * sizeof(char));
    strcpy(forgotten_buffer, "This memory is never freed");
    
    // Function exits without calling free(forgotten_buffer)
}

int main() {
    process_data();
    return 0;
}

/*
CWE-416 (Use After Free): 
The data_buffer is freed before it is used in the printf statement,
which can lead to undefined behavior, including crashes or
potentially executing arbitrary code if an attacker can manipulate the
freed memory.

CWE-401 (Memory Leak):
The forgotten_buffer is allocated but never freed, leading to a memory leak.
*/