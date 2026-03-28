# Undefined Behavior Demonstrations
Demonstrates how undefined behavior in C leads to unpredictable execution, memory corruption, and security vulnerabilities.

## Overview
This module explores how violations of memory safety and type assumptions affect program behavior at the system level. The examples highlight how incorrect assumptions in low-level code can result in crashes, silent corruption, or inconsistent execution.

## Implemented Cases
### Stack Buffer Overrun (`ub_stack_overrun.c`)
- Writes beyond allocated stack memory boundaries  
- May corrupt adjacent variables or cause crashes  
- Illustrates how memory violations can remain undetected during execution  

### Type Confusion (Function Pointers) (`ub_type_confusion.c`)
- Interprets incompatible struct layouts  
- Results in invalid function pointer execution  
- Mirrors real-world issues such as:
  - Function pointer corruption  
  - Vtable manipulation  
  - Callback misuse  

## Usage
Each program can be compiled and executed independently.

### Stack Buffer Overrun
```bash
gcc -o ub_stack_overrun ub_stack_overrun.c
./ub_stack_overrun
````

### Type Confusion
```bash
gcc -o ub_type_confusion ub_type_confusion.c
./ub_type_confusion
```

## Security Implications
* Undefined behavior can appear to work while remaining unsafe
* Memory and type safety violations are a major source of vulnerabilities
* Low-level bugs can lead to severe exploitation scenarios
* Platform-level protections (e.g. memory safety mechanisms) are critical

## Notes
These programs are intentionally unsafe and exist to illustrate how subtle memory errors can lead to serious vulnerabilities.

## Purpose
Part of a broader exploration of platform security and low-level system behavior using C.