# Exercise 02 – Permission Model Simulation
This program simulates a simplified UNIX permission check.

It takes a 3-digit octal permission (e.g. `755`), file owner, file group, requested operations (`rwx` style), and a user with optional group memberships.

The program exits with:
- `0` if access is granted  
- `1` if access is denied  
- `2` for invalid input  

## What this exercise demonstrates
- Parsing and validating octal permission strings
- Bitmask operations for permission checks
- Owner / group / other resolution logic
- Defensive input validation

The goal is to replicate how UNIX resolves permission classes using pure logic, without relying on system calls.

## Usage
```
./permissions <perm> <owner> <group> <ops> <user> [groups...]
```

## Example
```
./permissions 755 alice staff rx bob staff
```

In this example:
- Permission is `755`
- File owner is `alice`
- File group is `staff`
- User `bob` is a member of `staff`
- Requested operations are `rx`

The program determines whether `bob` has the requested access based on standard UNIX permission resolution rules.

