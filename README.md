# Cat Command - Linux Analog Implementation

A C implementation of the Unix/Linux `cat` command with support for standard options and functionality.

## Project Overview

This project aims to create a fully-featured analog of the `cat` command found in Linux/Unix systems. The `cat` command is used to display file contents, concatenate files, and work with standard input/output streams.

## Implementation Roadmap

### Phase 1: Core Functionality Fixes ⚠️ **HIGH PRIORITY**

1. **Fix Current Bugs**
   - [x] Fix buffer size issue in `fgets()` call
   - [x] Improve memory management and file handling
   - [ ] Add proper error messages with file names

2. **Basic Multiple File Support**
   - [x] Handle multiple file arguments: `cat file1.txt file2.txt file3.txt`
   - [x] Concatenate files in the order specified
   - [ ] Continue processing remaining files if one fails

3. **Standard Input Support**
   - [ ] Read from stdin when no arguments provided: `cat`
   - [ ] Support reading from stdin with `-` argument: `cat file1.txt - file2.txt`
   - [ ] Handle EOF properly from keyboard input (Ctrl+D on Unix, Ctrl+Z on Windows)

### Phase 2: Essential Command-Line Options

4. **Line Numbering Options**
   - [ ] `-n, --number`: Number all output lines starting from 1
   - [ ] `-b, --number-nonblank`: Number only non-empty lines

5. **Visual Options**
   - [ ] `-e, --show-ends`: Display `$` at the end of each line
   - [ ] `-t, --show-tabs`: Display TAB characters as `^I`
   - [ ] `-v, --show-nonprinting`: Display non-printing characters using `^` and `M-` notation

6. **Blank Line Handling**
   - [ ] `-s, --squeeze-blank`: Suppress repeated empty lines (show max one blank line)

### Phase 3: Advanced Options

7. **Combined Options**
   - [ ] `-A, --show-all`: Equivalent to `-vET` (show all non-printing chars, ends, tabs)
   - [ ] `-E, --show-ends`: Same as `-e` but as separate option
   - [ ] `-T, --show-tabs`: Same as `-t` but as separate option

8. **Help and Version**
   - [ ] `--help`: Display usage information and options
   - [ ] `--version`: Display version information

### Phase 4: Robustness and Optimization

9. **Error Handling Improvements**
   - [ ] Detailed error messages with errno descriptions
   - [ ] Handle different file types (directories, special files, etc.)
   - [ ] Proper handling of binary files
   - [ ] Handle files that don't exist vs. permission errors

10. **Performance Optimization**
    - [ ] Implement efficient buffered I/O
    - [ ] Handle large files without loading entire content into memory
    - [ ] Optimize for different file sizes

11. **Cross-Platform Support**
    - [ ] Windows line ending support (`\r\n`)
    - [ ] Unix line ending support (`\n`)
    - [ ] Handle different character encodings properly

### Phase 5: Testing and Documentation

12. **Testing Suite**
    - [ ] Unit tests for core functions
    - [ ] Integration tests with various file types
    - [ ] Edge case testing (empty files, very large files, binary files)
    - [ ] Cross-platform testing

13. **Documentation**
    - [ ] Man page creation
    - [ ] Usage examples
    - [ ] Performance benchmarks vs. system cat

## Technical Requirements

### Dependencies
- C11 standard library
- CMake 3.30+
- Standard POSIX functions (for Unix/Linux compatibility)

### Recommended File Structure
```
cat-command/
├── src/
│   ├── main.c           # Entry point and argument parsing
│   ├── cat_core.c       # Core cat functionality
│   ├── cat_core.h       # Core function declarations
│   ├── options.c        # Command-line option parsing
│   ├── options.h        # Option structure definitions
│   └── utils.c          # Utility functions
├── tests/               # Test files and test suite
├── docs/                # Documentation
├── CMakeLists.txt
├── README.md
└── LICENSE
```

### Key Functions to Implement

```c
// Core functionality
int cat_file(const char* filename, const struct cat_options* opts);
int cat_stdin(const struct cat_options* opts);
int process_files(char* files[], int file_count, const struct cat_options* opts);

// Option parsing
struct cat_options parse_arguments(int argc, char* argv[]);
void print_help(void);
void print_version(void);

// Utility functions
void print_line_with_options(const char* line, int line_number, const struct cat_options* opts);
char* format_nonprinting_chars(const char* input);
```

### Option Structure
```c
struct cat_options {
    bool number_lines;           // -n, --number
    bool number_nonblank;        // -b, --number-nonblank  
    bool show_ends;              // -e, --show-ends
    bool show_tabs;              // -t, --show-tabs
    bool show_nonprinting;       // -v, --show-nonprinting
    bool squeeze_blank;          // -s, --squeeze-blank
    bool show_all;               // -A, --show-all
};
```

## Building and Running

### Build Instructions
```bash
# Create build directory
mkdir build && cd build

# Configure with CMake
cmake ..

# Build
make

# Run
./cat_command [options] [files...]
```

### Usage Examples (Target Behavior)
```bash
# Display single file
./cat_command file.txt

# Display multiple files
./cat_command file1.txt file2.txt

# Read from stdin
./cat_command

# Number all lines
./cat_command -n file.txt

# Show line endings and tabs
./cat_command -et file.txt

# Squeeze blank lines and number non-empty lines
./cat_command -sb file.txt
```

## Testing Plan

1. **Functional Testing**: Compare output with system `cat` command
2. **Edge Cases**: Empty files, binary files, permission denied, non-existent files
3. **Performance**: Test with large files (>100MB)
4. **Memory**: Check for memory leaks using valgrind
5. **Cross-platform**: Test on Windows, Linux, and macOS

## References

- [GNU Coreutils Cat](https://www.gnu.org/software/coreutils/manual/html_node/cat-invocation.html)
- [POSIX Cat Specification](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/cat.html)
- [Linux Man Page for Cat](https://man7.org/linux/man-pages/man1/cat.1.html)

## License

MIT License - see [LICENSE](LICENSE) file for details.

## Contributing

1. Follow the implementation roadmap phases
2. Write tests for new functionality
3. Ensure cross-platform compatibility
4. Document any new options or behavior changes
5. Performance test with large files before submitting
