# CS-E4760 – Platform Security

This repository contains my coursework for CS-E4760 (Platform Security).

The exercises focus on low-level system behavior and security concepts implemented in C.  
Topics include permission models, argument validation, undefined behavior, and memory safety issues.

Each exercise is organized into its own folder and is self-contained.

All programs were compiled and tested on a Linux environment using `gcc`.

---

## Structure

- `exercise01/` – Basic program structure, argument handling, and file output.
- `exercise02/` – Simulating UNIX-style permission checks.
- `exercise03/` – Demonstrations of undefined behavior (stack overflow and type confusion).

---

## Compilation

Example:

```bash
gcc -Wall -Wextra -O2 file.c -o program
