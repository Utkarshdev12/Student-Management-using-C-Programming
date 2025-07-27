# 🎓 Student Management System (C Language)

This is a console-based **Student Management System** developed using **C programming language**. It allows users to perform essential operations such as adding, listing, modifying, deleting, and searching student records stored in a binary file.

---

## 🚀 Features

- ✅ Add new student records  
- 📄 Display all stored records  
- 🔍 Search for a student by name  
- ✏️ Modify existing student details  
- ❌ Delete a student record  
- 💾 Data persistence using binary file (`student.dat`)

---

## 🛠️ Technologies Used

- **Language:** C  
- **File Handling:** Binary file operations  
- **Compiler:** GCC  
- **Platform:** Windows / Linux (Console Based)

---

## 📦 Structure of Student Record

```c
typedef struct {
    char name[50];       // Student full name
    char guardian[50];   // Guardian full name
    char branch[20];     // Branch (e.g., CSE, ECE)
    char usn[15];        // University Serial Number
    char gender[10];     // Gender
    int  year;           // Year of joining
    char phone[15];      // Phone number
    char address[50];    // Address
    char dob[15];        // Date of Birth
} STUDENT;
```
---

### ⚙️ To Compile and Run

💻 On Linux/Mac (using GCC):
---
gcc -o student student.c 

./student

🪟 On Windows (using GCC with PowerShell or CMD):
---
gcc -o student.exe student.c 

.\student.exe
