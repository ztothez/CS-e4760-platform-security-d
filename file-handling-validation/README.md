# Secure File Output and Argument Handling
Demonstrates safe argument parsing and controlled file output in C, with a focus on input validation and filesystem safety.

## Overview
This program generates the first 10 Fibonacci numbers and writes them either to standard output or to a user-specified file.

It implements strict validation rules to prevent unsafe file access and unintended filesystem interactions.

## Exit Codes
- `0` → success  
- `1` → invalid arguments or file error  

## Key Concepts Demonstrated
- Argument parsing with constrained input  
- Safe file handling in C  
- Input validation for filesystem operations  
- Avoiding unsafe defaults when handling user input  

## Implementation Notes
The program enforces restrictions on user-provided filenames to prevent path traversal and unintended file access. Validation is intentionally simple, focusing on illustrating core security concepts rather than providing a complete solution.

## Usage
```bash
./program [file]
./program -- <file>
./program -
````

* No argument → writes to stdout
* `<file>` → writes to file
* `-- <file>` → explicit file mode
* `-` → forces stdout

Invalid combinations are rejected.

## Example

```bash
./program output.txt
```

Writes the Fibonacci sequence to `output.txt` if the filename passes validation.

## Security Considerations
The program rejects:

* paths containing `..`
* directory separators (`/`, `\`)

Only simple filenames are accepted, reducing the risk of path traversal and unintended file access.

## Purpose
Part of a broader exploration of platform security and system-level behavior using C.