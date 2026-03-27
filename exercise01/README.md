# Exercise 01 – Argument Handling and File Output
This program generates the first 10 Fibonacci numbers and writes them either to stdout or to a user-specified file.

It focuses on argument parsing and restricting unsafe file access.

Exit codes:
- `0` → success  
- `1` → invalid arguments or file error  

## What this exercise demonstrates
- Argument parsing with constrained input
- Basic file handling in C
- Input validation for filesystem operations
- Avoiding unsafe defaults when dealing with user input

The goal is to ensure that user-provided filenames cannot escape the intended scope.

## Usage
```bash
./program [file]
./program -- <file>
./program -
````

* No argument → stdout
* `<file>` → writes to file
* `-- <file>` → explicit file mode
* `-` → forces stdout

Invalid combinations are rejected.

## Example
```bash
./program output.txt
```

Writes the Fibonacci sequence to `output.txt` if the filename passes validation.

## Notes
The program rejects:

* paths containing `..`
* directory separators (`/`, `\`)

Only simple filenames are accepted. This prevents path traversal and unintended file access.

Validation is intentionally minimal and does not aim to fully secure filesystem interactions.
