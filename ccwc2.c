#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100

// Function declarations
void print_usage(char *program_name);
long int count_bytes(FILE *file);
int count_lines(FILE *file);
int count_words(FILE *file);
long int count_characters(FILE *file);

int main(int argc, char *argv[])
{
        if (argc < 2 || argc > 3)
        {
                print_usage(argv[0]);
                return 1;
        }

        FILE *file;
        if (argc == 3)
        {
                file = fopen(argv[2], "r");
                if (file == NULL)
                {
                        printf("Cannot open file: %s\n", argv[2]);
                        return 1;
                }
        }
        else
        {
                file = stdin; // Open standard input
        }

        int count_bytes_flag = 0;
        int count_lines_flag = 0;
        int count_words_flag = 0;
        int count_characters_flag = 0;

        if (argc == 2 || strcmp(argv[1], "-c") == 0)
        {
                count_bytes_flag = 1;
        }
        if (argc == 2 || strcmp(argv[1], "-m") == 0)
        {
                count_characters_flag = 1;
        }

        if (argc == 2 || strcmp(argv[1], "-l") == 0)
                count_lines_flag = 1;

        if (argc == 2 || strcmp(argv[1], "-w") == 0)
                count_words_flag = 1;

        if (count_bytes_flag || count_lines_flag || count_words_flag || count_characters_flag)
        {
                long int count = 0;

                if (count_bytes_flag)
                {
                        count = count_bytes(file);
                        printf("%8ld ", count);
                }
                if (count_lines_flag)
                {
                        count = count_lines(file);
                        printf("%8ld ", count);
                }
                if (count_words_flag)
                {
                        count = count_words(file);
                        printf("%8ld ", count);
                }
                if (count_characters_flag)
                {
                        count = count_characters(file);
                        printf("%8ld ", count);
                }
                if (argc == 3)
                        printf("%s\n", argv[2]);
                else
                        printf("\n");
        }
        else
        {
                print_usage(argv[0]);
        }

        if (file != stdin)
        {
                fclose(file);
        }

        return 0;
}

void print_usage(char *program_name)
{
        printf("Usage: %s [OPTION] [FILE]\n", program_name);
        printf("Options:\n");
        printf("    -c    Count the number of bytes\n");
        printf("    -l    Count the number of lines\n");
        printf("    -w    Count the number of words\n");
        printf("    -m    Count the number of characters (including multibyte characters)\n");
        printf("Default: %s -c -l -w [FILE]\n", program_name);
}

long int count_bytes(FILE *file)
{
        long int count = 0;
        fseek(file, 0, SEEK_END);
        count = ftell(file);
        fseek(file, 0, SEEK_SET);
        return count;
}

int count_lines(FILE *file)
{
        int count = 0;
        int ch;
        while ((ch = fgetc(file)) != EOF)
        {
                if (ch == '\n')
                        count++;
        }
        return count;
}

int count_words(FILE *file)
{
        int count = 0;
        int ch;
        int in_word = 0;
        while ((ch = fgetc(file)) != EOF)
        {
                if (ch == ' ' || ch == '\n' || ch == '\t')
                        in_word = 0;
                else if (!in_word)
                {
                        in_word = 1;
                        count++;
                }
        }
        return count;
}

long int count_characters(FILE *file)
{
        long int count = 0;
        int ch;
        while ((ch = fgetc(file)) != EOF)
        {
                if (ch != '\n')
                        count++;
        }
        return count;
}
