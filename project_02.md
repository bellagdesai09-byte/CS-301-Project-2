# CS 302 – Project 2  
## Activity Log with Ordering Constraints (v5)

**Assigned:** Tuesday Feb 10  
**Due:** Fri Mar 13  

---

## Overview

In this project, you will design and implement an **Activity Log**: a system that records actions in the order they occur and provides controlled ways to access and process them.

The focus of this project is **abstraction, correctness, representation, and build discipline**. You will:

- Define a clear **Abstract Data Type (ADT)**
- Implement **two different internal representations** of that same ADT
- Enforce ordering constraints (FIFO or LIFO)
- Demonstrate correctness using a required checklist
- Build and compile your project using a **Makefile**

This project builds directly on **Project 1** and raises expectations in several important ways.

---

## How This Builds on Project 1

Project 1 emphasized foundational mechanics:

- Basic C++ structure and compilation
- Header and source file separation
- Pointer fundamentals
- Linear data reasoning
- Clean compilation with warnings enabled
- Following the provided project structure

Project 2 builds on those foundations and extends them:

### 1) Stronger Abstraction Discipline
In Project 1, you practiced working with linear data and pointer mechanics.  
In Project 2, you must design a formal **ADT contract** before implementing anything.

You are now responsible for:
- Separating logical behavior from physical representation
- Writing explicit behavioral guarantees
- Preventing misuse through interface design

### 2) Multiple Representations
In Project 1, you implemented a single structure.

In Project 2, you must implement:
- One **array-based representation**
- One **linked-based representation**

Both must satisfy the exact same ADT contract.

Core idea:
> An ADT defines behavior. Implementations define representation.

### 3) Representation Invariants
You are now responsible for maintaining:
- Accurate size tracking
- Correct ordering behavior
- Safe empty-case handling
- No memory leaks (linked version)

These expectations are stricter than Project 1.

### 4) Build Discipline
In Project 1, compilation was supported by the provided structure.  
In Project 2, you will take more ownership of your multi-file build using a Makefile.

---

## Conceptual Grounding

An **activity** is simply a record of something that happened.

Examples:
- A play in a sports game  
- A move in a game  
- A financial transaction  
- A task completion  
- A command issued in an application  

An **Activity Log** stores activities in a linear structure and allows controlled access according to defined ordering rules.

No prior industry knowledge is required.

---

## Student-Chosen Activity Theme

You may choose a theme that reflects your interests. Your theme determines what an “activity” represents, but it does **not** change the ADT requirements.

Examples:
- Sports event log  
- Game move history  
- Transaction history  
- Media playback log  
- Productivity action tracker  

### Important Constraints
- The ADT interface must be identical across implementations  
- Ordering rules must be enforced correctly  
- Themes do not change technical expectations  

---

## Required Written Documentation Format

All written components must be submitted as **Markdown (`.md`) files**.

Required files:
1. `ADT_Design.md`
2. `Design_Decisions.md`
3. `README.md`

No PDFs or Word documents will be accepted.

Markdown files must:
- Use clear headings (`#`, `##`, `###`)
- Use bullet points where appropriate
- Be readable as plain text (no screenshots of text)
- Be written in complete sentences
- Be technically precise

---

## Required Build System (Makefile)

Your project must build using a **Makefile**.

Your project should build successfully using `make` on a standard lab environment. Before submitting, please test your build process from a clean state (`make clean` followed by `make`).

### What you may choose
- You may name your `.cpp` and `.h` files as you choose.
- You may define your `Activity` record in a way that fits your theme.
- You may organize helper files as needed, as long as your project is easy to build and run.

### What must be true
- Running `make` builds your executable.
- Running `make clean` removes build artifacts.
- Your Makefile uses the required compiler flags (`-std=c++17 -Wall -Wextra -pedantic`).
- If you add new `.cpp` files, you must update your Makefile so they are compiled and linked.

---

## Part 1 – ADT Design (Write this first)

Create: `ADT_Design.md`

Your ADT design must include:

### 1) Purpose
What problem your Activity Log solves.

### 2) Logical Data Model
Describe the logical data stored. Do **not** mention arrays, nodes, pointers, or memory details.

### 3) Operations
Your ADT must include these operations (names may vary, behavior may not):

- `add(activity)`  
- `remove()`  
- `peek()`  
- `isEmpty()`  
- `size()`  

You must explicitly define whether your ordering policy is:
- **FIFO (queue behavior)**  
or  
- **LIFO (stack behavior)**  

### 4) Behavioral Guarantees
Clearly state:
- What `remove()` returns  
- What `peek()` returns  
- What happens if the log is empty  
- Why ordering cannot be violated by the user  

---

## Part 2 – Two Representations (Required)

You must implement the same ADT using:
- One **array-based implementation**
- One **linked-based implementation**

Both implementations must:
- Follow the same ADT interface
- Produce identical observable behavior
- Pass the same correctness checklist

Superficial differences do not count as separate implementations.

---

## Part 3 – Design Decisions

Create: `Design_Decisions.md`

Include:
1. Ordering policy rationale (why FIFO or LIFO makes sense for your theme)
2. Representation comparison (how the array-based and linked-based implementations differ)
3. Enforcement of invariants (ordering, size tracking, safe empty-case behavior)
4. Tradeoffs (clarity, structural complexity, memory implications)

---

## Part 4 – Correctness Checklist (Required)

Your driver or tests must demonstrate the following for **both implementations**:

- [ ] Add 5 activities, remove all, ordering is correct  
- [ ] Interleaved add/remove operations work correctly  
- [ ] `peek()` does not remove the element  
- [ ] `size()` updates correctly after every operation  
- [ ] Removing from empty is handled safely  
- [ ] Both implementations produce identical results for the same sequence of operations  

Clearly label output demonstrating each case.

---

## Implementation Expectations

Your code must:
- Separate interface from implementation
- Avoid exposing representation details
- Avoid memory leaks (linked version)
- Compile without warnings
- Build entirely through the Makefile

You are not graded on algorithmic optimization.

---

## Deliverables

Submit:
- Your ActivityLog ADT interface header (`.h`)
- Array-based implementation (`.cpp`)
- Linked-based implementation (`.cpp`)
- Driver or test file (`.cpp`)
- `Makefile`
- `ADT_Design.md`
- `Design_Decisions.md`
- `README.md`

---

## Summary

Project 2 emphasizes abstraction, representation, and correctness.

You are expected to:
- Design before coding
- Implement multiple representations
- Enforce invariants
- Demonstrate correctness
- Build cleanly using a Makefile
