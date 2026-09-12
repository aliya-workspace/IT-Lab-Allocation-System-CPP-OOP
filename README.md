# IT-Lab-Allocation-System-CPP-OOP
Console-based lab allocation system in C++ demonstrating OOP concepts — inheritance, polymorphism, static members, friend functions, file handling, and exception handling.

## Overview
This system allows an admin to allocate lab time slots to instructors while preventing double-booking of the same day/time slot. All allocations are saved to a file for record-keeping.

## Features
- Role-based classes for Admin, Instructor, and Lab Assistant
- Lab allocation with day, time, and instructor assignment
- Conflict detection to prevent double-booking of time slots
- Persistent storage of allocations using file handling
- Tracks total number of allocations made
- Exception handling for file operation errors

## OOP Concepts Used
- **Abstract Class & Pure Virtual Functions** — `User` base class with `showRole()`
- **Inheritance** — `Admin` and `Instructor` inherit from `User`
- **Polymorphism** — each class overrides `showRole()` differently
- **Static Members** — tracks total allocations across all objects
- **Friend Functions** — `showTotalAllocations()` accesses private data
- **File Handling** — allocations persisted to `allocations.txt`
- **Exception Handling** — `try-catch` for file operation errors

## Tech Stack
- Language: C++
- Concepts: OOP, File I/O, Exception Handling

## How to Run
1. Compile: `g++ lab_allocation.cpp -o lab_allocation`
2. Run: `./lab_allocation` (or `lab_allocation.exe` on Windows)
3. Follow the on-screen admin menu to allocate labs or view total allocations

## Author
Aliya Khanam — BSIT Student, University of Sargodha
