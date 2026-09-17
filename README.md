# 🧵 Collaborative Account Transfer

This repository contains an academic activity developed during the **Operating Systems** course in my Computer Science degree.

The activity implements a **collaborative transfer between two accounts using multiple threads**, exploring the effects of concurrent access and the use of synchronization mechanisms.

📅 **Academic Semester:** 2026/02

---

## 🚀 Technologies & Tools

* **Programming Language:** C
* **Thread Library:** POSIX Threads (`pthread`)
* **Operating System:** Linux
* **Compiler:** GCC

---

## 📋 Activity Instructions

### Objective

Implement a program that uses **multiple threads** to transfer the entire balance from **Account A** to **Account B**.

### Initial State

* **Account A = 100,000,000**
* **Account B = 0**
* **Audit = 0** (global variable used to verify whether all values were actually transferred)

### Thread Behavior

1. Each thread maintains a **local variable** (`local_sum`), initialized to 0.
2. While there is still a balance in Account A:

   * If **A < 100**, transfer the entire remaining amount (`v = A`) to Account B.
   * Otherwise, randomly generate an integer `v` between **1 and 100**.
   * Transfer `v` from Account A to Account B.
   * Add `v` to the thread's **`local_sum`**.
3. When finished, the thread adds its `local_sum` to the global **Audit** variable.
4. The thread terminates when **Account A** is less than or equal to 0.

### General Rules

* Use **shared variables** to represent Account A, Account B, and Audit.
* The amount transferred in each step **cannot exceed 100**.
* Create **N threads** (4 or 8 threads are suggested).
* After all threads have finished, display the final account balances.

Example:

```text
Account A=0 Account B=1000000 Audit=1000000
```

---

## 📂 Implementations

### Q1 - Without Synchronization

The first implementation does not use **any synchronization primitive**, such as mutexes or semaphores.

The goal is to observe the effects of concurrent access to shared variables and the possibility of **race conditions**.

**Compile:**

```bash
gcc -pthread -o q1 q1.c
```

**Run:**

```bash
./q1
```

### Q3 - With Mutex

The second implementation performs the same task using `pthread_mutex_*` to control concurrent access to the shared variables.

The mutex ensures that the transfers remain consistent and prevents race conditions from causing incorrect results.

**Compile:**

```bash
gcc -pthread -o q3 q3.c
```

**Run:**

```bash
./q3
```

---

## 👩‍💻 Author

Developed with 💙 by **Júlia Roos Costa**
