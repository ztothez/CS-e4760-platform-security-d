# Exercise 02 – Permission Model Simulation
This program simulates a simplified UNIX permission check.

It takes a 3-digit octal permission (e.g. `755`), file owner, file group, requested operations (`rwx`), and a user with optional group memberships.

Exit codes:
- `0` → access granted  
- `1` → access denied  
- `2` → invalid input  

## What this exercise demonstrates
- Parsing and validating octal permission values
- Bitmask-based permission checks
- Owner / group / other resolution logic
- Input validation under constrained rules

The goal is to replicate how UNIX resolves permissions using explicit logic rather than system calls.

## Usage
```bash
./permissions <perm> <owner> <group> <ops> <user> [groups...]
````

---
## Example
```bash
./permissions 755 alice staff rx bob staff
```

* Permission: `755`
* Owner: `alice`
* Group: `staff`
* User: `bob` (member of `staff`)
* Requested operations: `rx`

The program determines whether access should be granted based on standard UNIX permission resolution.