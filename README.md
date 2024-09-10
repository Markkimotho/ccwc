# `ccwc` - Custom File Statistics Tool

`ccwc` is a command-line utility that provides various statistics about a given file, similar to the Unix `wc` tool. It counts the number of bytes, lines, words, and characters (including multibyte characters) in the specified file.

## Overview

This project implements a custom File Statistics tool called `ccwc`.

## Usage

```bash
ccwc [OPTION] [FILE]
```

**Options**:

- `c` Count the number of bytes
- `l` Count the number of lines
- `w` Count the number of words
- `m` Count the number of characters (including multibyte characters
 
### Default Usages: 
```
ccwc [FILE]
```

## Features

- **Byte Count**: Use the `-c` option to count the number of bytes in a file.
- **Line Count**: Use the `-l` option to count the number of lines in a file.
- **Word Count**: Use the `-w` option to count the number of words in a file.
- **Character Count**: Use the `-m` option to count the number of characters (including multibyte characters) in a file.

## Getting Started

To get started with the File Statistics Counter utility, follow these steps:

1. Clone the repository or download the source code files.
```bash
$ git clone https://github.com/Markkimotho/ccwc.git
$ cd ccwc/
```

2. Compile the source code using a C compiler.
```bash
$ gcc ccwc.c -o ccwc
```

or use make:

```bash
$ make
```

3. Run the executable file with the desired command-line options and the path to the file you want to analyze.

**Example usages**:

- To count the number of bytes in a file:
```bash
$ ./ccwc -c myfile.txt
```

- To count the number of lines in a file:
```bash
$ ./ccwc -l myfile.txt
```

- To count the number of words in a file:
```bash
$ ./ccwc -w myfile.txt
```

- To count the number of characters in a file:
```bash
$ ./ccwc -m myfile.txt
```

- To count the number of bytes, lines, words and characters in a file:
```bash
$ ./ccwc myfile.txt
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
