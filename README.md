# `wc` unix tool

`wc` is a command-line utility that provides various statistics about a given file. It counts the number of bytes, lines, words, and characters (including multibyte characters) in the specified file.

## Overview
In this project, I will create a custom File Statistics tool like `wc` called `ccwc`

## Usage

Usage: `ccwc [OPTION] [FILE]`

Options:

- `c`	Count the number of bytes
- `l` Count the number of lines
- `w` Count the number of words
- `m` Count the number of characters (including multibyte characters
 
Default: `file_stats -c -l -w [FILE]`

## Features

- **Byte Count**: Use the `-c` option to count the number of bytes in a file.
- **Line Count**: Use the `-l` option to count the number of lines in a file.
- **Word Count**: Use the `-w` option to count the number of words in a file.
- **Character Count**: Use the `-m` option to count the number of characters (including multibyte characters) in a file.

## Getting Started

To get started with the File Statistics Counter utility, follow these steps:

1. Clone the repository or download the source code files.
```
$ git clone https://github.com/Markkimotho/ccwc.git
$ cd ccwc/
```

2. Compile the source code using a C compiler.
```
$ gcc ccwc.c -o ccwc
```

or 

```
$ make
```

3. Run the executable file with the desired command-line options and the path to the file you want to analyze.

Example usages:

- To count the number of bytes, lines, and words in a file:


```
$ ./ccwc -c -l -w myfile.txt
```

- To count the number of characters in a file:
```
$ ./ccwc -m myfile.txt
```

## Dependencies
`ccwc` has no external dependencies. It is implemented in plain C and uses standard C libraries.

## Contributing
Contributions are welcome! If you find any issues or have suggestions for improvements, please feel free to open an issue or submit a pull request.

## Acknowledgments
The `ccwc` utility is based off the [Coding Challenges](https://codingchallenges.fyi/challenges/intro) by [John Cricket](https://uk.linkedin.com/in/johncrickett).

The `test.txt` file was obtained from [Project Gutenberg](https://www.gutenberg.org/cache/epub/132/pg132.txt)

## Contact
For any inquiries or questions, you can reach out to [me](kimothomark93@gmail.com).
