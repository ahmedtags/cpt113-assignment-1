# CPT113 - Data Structures (Assignment 1)

This repository contains the C++ implementations for **CPT113: Data Structures - Assignment 1** (Academic Session 2024/2025) at Universiti Sains Malaysia (USM).

## Course Details
- **Course Code:** CPT113
- **Course Name:** Data Structures
- **Semester:** Year 1, Semester 2 (2024/2025)
- **Project Title:** Stack and Queue Operations

---

## Assignment Overview

The assignment focuses on understanding and implementing foundational abstract data types (ADTs) in C++:
1. **Stack ADT:** LIFO (Last-In, First-Out) operations using arrays or linked lists.
2. **Queue ADT:** FIFO (First-In, First-Out) operations.
3. **Application & Testing:** Writing a CLI program in C++ to accept parameters, perform push/pop/enqueue/dequeue operations, and print internal states of the data structure.

---

## What I Did
- Developed the data structures and driver program in C++: [`Asgn1_22304588_AHMED_H_M_TAHA_CPT113.cpp`](Asgn1_22304588_AHMED_H_M_TAHA_CPT113.cpp).
- Provided incremental drafts: [`Asgn1_22304588_AHMED_H_M_TAHA_CPT113_11.cpp`](Asgn1_22304588_AHMED_H_M_TAHA_CPT113_11.cpp) and [`Asgn1_22304588_AHMED_H_M_TAHA.cpp`](Asgn1_22304588_AHMED_H_M_TAHA.cpp).
- Consolidated the original assignment guideline: [`Assignment 1_(2024)_1.3.pdf`](Assignment%201_%282024%29_1.3.pdf).

---

## Tools & Tech Stack
- **Language:** C++ (standard input/output, structures, pointers)
- **IDE/Compiler:** GCC / MinGW

---

## How to Run

1. Compile the main C++ program:
   ```bash
   g++ Asgn1_22304588_AHMED_H_M_TAHA_CPT113.cpp -o stack_queue_app
   ```
2. Run the executable:
   ```bash
   ./stack_queue_app
   ```
3. Use the menu options inside the command line console to add elements, pop/dequeue elements, and check sizes.

---

## 📸 Sample Output

```
===== Pension Eligibility and Calculation App (PECA) =====
1. Input Personal Information
2. Input Service and Wages Information
3. Display Service and Wages Information
4. Set Pension Date and Calculate Pension Estimation
5. Exit
Select an option: 1

Enter Employee ID: EMP002
Enter Employee Name: Sara Ahmed
Your Date of Birth Information:
Day: 10   Month: 5   Year: 1975

Select an option: 2
Service Information:
Set Appointment Date:
Day: 1   Month: 1   Year: 2000
Enter Last Salary: RM6000
Enter Total Allowance: RM1200

Select an option: 4
Set Pension Date:
Day: 1   Month: 1   Year: 2026

===== Employee Details =====

Service Information:
Name: Sara Ahmed
ID: EMP002
Date of Birth: 10/5/1975
Date of Appointment: 1/1/2000
Last Salary: RM6000
Total Allowance: RM1200

Pension Eligibility Calculation:
Pension Eligibility Confirmed!
Service Duration: 26 years and 0 months (312 months total).
Estimated Monthly Pension: RM3126.24
Gratuity: RM140400

Select an option: 5
Exiting the application. Goodbye!
```

