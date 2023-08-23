#ifndef _CCWC_
#define _CCWC_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

#define BUFFER_SIZE 100

void print_usage(char *program_name);
long int count_bytes(FILE *file);
int count_lines(FILE *file);
int count_words(FILE *file);
long int count_characters(FILE *file);

#endif
