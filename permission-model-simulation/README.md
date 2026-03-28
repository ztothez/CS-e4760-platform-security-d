# Permission Model Simulation
Implements a simplified UNIX permission model to demonstrate how access control is resolved at the system level.

## Overview
This program evaluates whether a user can perform specific operations on a file based on standard UNIX permission rules.

It processes:
- Octal permission values (e.g. `755`)
- File ownership (owner and group)
- Requested operations (`rwx`)
- User identity and group memberships

## Exit Codes
- `0` → access granted  
- `1` → access denied  
- `2` → invalid input  

## Key Concepts Demonstrated
- Parsing and validation of octal permission values  
- Bitmask-based permission evaluation  
- Owner / group / other resolution logic  
- Input validation under constrained rules  

## Implementation Notes
The logic explicitly replicates how UNIX resolves permissions without relying on system calls, providing a clear view into the underlying decision process.

## Usage
```bash
./permissions <perm> <owner> <group> <ops> <user> [groups...]
````

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

## Purpose
Part of a broader exploration of platform security and system-level behavior using C.