# Platform Security Labs
Hands-on C-based implementations exploring platform-level security mechanisms, low-level system behavior, and secure programming practices on Linux.

## Overview
This project examines how modern platforms enforce security at the system level, including file permissions, process behavior, and unsafe assumptions in software.

The modules demonstrate how vulnerabilities arise from incorrect assumptions and how platform features mitigate them.

## What this demonstrates
- Understanding of low-level system behavior and security mechanisms  
- Experience with C programming in a Linux environment  
- Analysis of unsafe input handling and undefined behavior  
- Practical exploration of how platforms enforce security constraints  

## Project Structure
- `secure-file-output/` — Safe argument handling and controlled file output  
- `permission-model-simulation/` — UNIX permission resolution logic  
- `undefined-behavior-demo/` — Demonstrations of unsafe memory and type behavior 

## Usage
Each module is self-contained and can be compiled and executed independently.

### Compile
```bash
gcc -o program program.c
````

### Run
```bash
./program
```

Refer to each module’s README for detailed usage instructions and examples.

## Implementation Notes
These implementations focus on illustrating core security concepts at the system level rather than providing production-ready solutions.

## Background
Originally developed as part of a university course on platform security, focusing on how modern systems enforce security at the software and hardware level.