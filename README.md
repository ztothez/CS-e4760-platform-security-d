# CS-E4760 – Platform Security

Coursework for CS-E4760 (Platform Security), focused on low-level system behavior and secure programming in C.

The exercises explore how vulnerabilities arise from incorrect assumptions in areas such as input handling, memory usage, and permission checks.

All programs are written in C and tested on Linux using `gcc`.

---

## Structure

- `exercise01/` – Argument handling and controlled file output
- `exercise02/` – Simulated UNIX-style permission checks
- `exercise03/` – Undefined behavior (stack overflow, type confusion)

Each exercise is self-contained and targets a specific class of issues.

---

## Compilation

```bash
gcc -Wall -Wextra -O2 file.c -o program

Notes

Some programs intentionally include unsafe patterns to demonstrate specific classes of vulnerabilities.

These examples are included for learning purposes and are not production-safe.