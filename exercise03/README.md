# Exercise 03 – Undefined Behavior Demonstrations

This exercise contains two small programs that intentionally trigger undefined behavior.

These examples are meant for educational purposes only.

## 1. Stack Buffer Overrun

Demonstrates what happens when a program writes past the end of a stack buffer.

Depending on compiler settings and stack layout, this may:
- Corrupt nearby variables
- Crash
- Appear to “work” (while still being undefined behavior)

This illustrates why bounds checking and memory safety are critical in C.

## 2. Type Confusion with Function Pointers

Demonstrates type confusion by reinterpreting a struct as another struct with a different function pointer type.

This violates C’s effective type rules and may:
- Crash
- Produce unexpected behavior
- Appear to work (but still be undefined behavior)

This mirrors real-world vulnerability classes such as:
- Function pointer corruption
- Vtable manipulation
- Callback misuse

---

These programs are intentionally unsafe and are not examples of correct coding practices.  
They are used to illustrate how subtle memory violations can lead to serious security issues.
