# Exercise 03 – Undefined Behavior Demonstrations
This exercise contains two small programs that intentionally trigger undefined behavior.

These examples are for demonstration only and are not safe to use in real applications.

## 1. Stack Buffer Overrun
Demonstrates writing past the end of a stack buffer.

Possible outcomes include:
- Corruption of nearby variables
- Program crashes
- Seemingly correct execution despite being invalid

This highlights how memory violations can remain hidden while still being unsafe.

## 2. Type Confusion with Function Pointers
Demonstrates type confusion by interpreting a struct as another struct with an incompatible function pointer type.

This violates C’s type rules and may:
- Crash
- Produce incorrect behavior
- Appear to work depending on memory layout

This mirrors real-world issues such as:
- Function pointer corruption
- Vtable manipulation
- Callback misuse

## Notes
These programs are intentionally unsafe and exist to illustrate how subtle memory errors can lead to serious vulnerabilities.