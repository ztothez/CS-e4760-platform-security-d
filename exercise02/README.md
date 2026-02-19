# Exercise 02 – Permission Model Simulation

This program simulates a simplified UNIX permission check.

It takes a 3-digit octal permission (e.g. `755`), file owner, file group, requested operations (`rwx` style), and a user with optional group memberships. The program exits with:

- `0` if access is granted  
- `1` if access is denied  
- `2` for invalid input  

## What this exercise demonstrates

- Parsing and validating octal permission strings
- Bitmask operations for permission checks
- Owner/group/other resolution logic
- Defensive input validation

The goal was to replicate how UNIX resolves permission classes without relying on system calls.

## Example

