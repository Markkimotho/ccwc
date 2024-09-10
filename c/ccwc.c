#include "ccwc.h"

/**
 * main - Reads a file, provides the byte, character, word, and line counts
 * @argc: Number of command line arguments
 * @argv: An array that stores the command line arguments
 *
 * Return: 0 Upon Success
 *         1 Upon Failure
 */
int main(int argc, char *argv[]) {
    FILE *file = NULL;

    // Print the number of arguments received
    printf("Number of arguments: %d\n", argc);

    // Check for correct number of arguments
    if (argc < 2 || argc > 3) {
        print_usage(argv[0]);
        return 1;
    }

    // Open file or read from stdin
    file = fopen(argv[argc - 1], "rb"); // Open in binary mode
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", strerror(errno)); // Improved error message
        return 1;
    }

    // Flags for counting
    int count_bytes_flag = 1; // Default to counting bytes
    int count_lines_flag = 1; // Default to counting lines
    int count_words_flag = 1; // Default to counting words
    int count_characters_flag = 1; // Default to counting characters

    // Check for flags
    if (argc == 3) {
        if (strcmp(argv[1], "-c") == 0) {
            count_lines_flag = 0;
            count_words_flag = 0;
            count_characters_flag = 0;
        } else if (strcmp(argv[1], "-l") == 0) {
            count_bytes_flag = 0;
            count_words_flag = 0;
            count_characters_flag = 0;
        } else if (strcmp(argv[1], "-w") == 0) {
            count_bytes_flag = 0;
            count_lines_flag = 0;
            count_characters_flag = 0;
        } else if (strcmp(argv[1], "-m") == 0) {
            count_bytes_flag = 0;
            count_lines_flag = 0;
            count_words_flag = 0;
        } else {
            print_usage(argv[0]);
            fclose(file);
            return 1; // Invalid flag
        }
    }

    // Counting logic
    long int byte_count = 0;
    long int character_count = 0;
    int line_count = 0, word_count = 0;

    // Count bytes
    if (count_bytes_flag) {
        byte_count = count_bytes(file);
        printf("%8ld bytes ", byte_count);
    }

    // Reset the file pointer for next counts
    rewind(file);

    // Count characters
    if (count_characters_flag) {
        character_count = count_characters(file);
        printf("%8ld characters ", character_count);
    }

    // Reset the file pointer again
    rewind(file);

    // Count lines
    if (count_lines_flag) {
        line_count = count_lines(file);
        printf("%8d lines ", line_count);
    }

    // Reset the file pointer again
    rewind(file);

    // Count words
    if (count_words_flag) {
        word_count = count_words(file);
        printf("%8d words ", word_count);
    }

    // Print filename or newline
    printf("%s\n", argv[argc - 1]);

    // Close file if it was opened
    fclose(file);

    return 0;
}

/**
 * print_usage - Prints usage information and available options to the console
 * @program_name: The command used to execute the program 
 *
 * Return: None
 */
void print_usage(char *program_name) {
    printf("Usage: %s [OPTION] [FILE]\n", program_name);
    printf("Options:\n");
    printf("        -c      Count the number of bytes\n");
    printf("        -l      Count the number of lines\n");
    printf("        -w      Count the number of words\n");
    printf("        -m      Count the number of characters (including multibyte characters)\n");
    printf("Default: %s [FILE]\n", program_name);
}

/**
 * count_bytes - Counts the number of bytes in a file
 * @file: Pointer to FILE
 *
 * Return: Number of bytes in a file
 */
long int count_bytes(FILE *file) {
    if (file == NULL) {
        fprintf(stderr, "File pointer is NULL.\n");
        return -1;
    }

    // Attempt to seek to the end of the file
    if (fseek(file, 0, SEEK_END) != 0) {
        fprintf(stderr, "Error seeking to end of file: %s\n", strerror(errno));
        return -1;
    }

    long int count = ftell(file); // Get the byte count

    if (count == -1) {
        perror("Error getting file size");
    }

    fseek(file, 0, SEEK_SET); // Reset pointer to start
    return count >= 0 ? count : -1; // Return count or -1 on error
}

/**
 * count_lines - Counts the number of lines in a file
 * @file: Pointer to FILE
 *
 * Return: Number of lines in a file
 */
int count_lines(FILE *file) {
    int count = 0;
    int ch;

    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            count++;
        }
    }

    // If the file does not end with a newline, count the last line
    if (count > 0 && ch != '\n') count++;

    return count;
}

/**
 * count_words - Counts the number of words in a file
 * @file: Pointer to FILE
 *
 * Return: Number of words in a file
 */
int count_words(FILE *file) {
    int count = 0;
    int ch;
    int in_word = 0;

    while ((ch = fgetc(file)) != EOF) {
        if (isspace(ch)) {
            in_word = 0; // End of a word
        } else if (!in_word) {
            in_word = 1; // Start of a new word
            count++;
        }
    }

    return count;
}

/**
 * count_characters - Counts the number of characters in a file
 * @file: Pointer to FILE
 *
 * Return: Number of characters in a file
 */
long int count_characters(FILE *file) {
    long int count = 0;
    int ch;

    while ((ch = fgetc(file)) != EOF) {
        count++; // Count each character
    }

    rewind(file); // Reset file pointer
    return count; // Return character count
}