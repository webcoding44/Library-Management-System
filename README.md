# 📚 Library Management System

<div align="center">

![C++](https://img.shields.io/badge/C%2B%2B-11%2F14%2F17-blue?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Platform](https://img.shields.io/badge/platform-Linux%20%7C%20Windows%20%7C%20macOS-lightgrey?style=for-the-badge)
![Status](https://img.shields.io/badge/status-stable-success?style=for-the-badge)

**A complete console-based Library Management System built with C++**

[Features](#-features) • [Installation](#-installation) • [Usage](#-usage) • [Structure](#-project-structure) • [Contributing](#-contributing)

</div>

---

## 📖 Overview

The **Library Management System** is a comprehensive C++ application that allows users to manage a library's collection of books. It provides features for adding, editing, deleting, searching, and tracking borrowed books with persistent file storage.

> **Note:** This project is an educational exercise designed to help learners understand advanced C++ concepts. Its user interface (UI) is designed in Persian (Farsi).

---

## ✨ Features

### 📋 Book Management
- ➕ **Add** new books with unique ID, title, author, and publication year
- ✏️ **Edit** existing book information
- 🗑️ **Delete** books (with protection for borrowed items)
- 🔍 **Search** books by title or author (partial matching supported)

### 🔄 Borrowing System
- 📤 **Borrow** books with borrower name tracking
- 📥 **Return** borrowed books
- ⚠️ **Validation** to prevent double-borrowing or returning non-borrowed books

### 📊 Reporting & Sorting
- 📑 Display all books in the library
- ✅ Show only available books
- 📕 Show only borrowed books
- 🔤 Sort books by title, author, or year
- 📈 View library statistics

### 💾 Data Persistence
- 💿 Automatic saving to file after every operation
- 📂 Automatic loading on startup
- 🛡️ Robust file I/O with error handling

---

## 🛠️ Technologies & Concepts

This project demonstrates mastery of the following C++ concepts:

| Category | Concepts |
|----------|----------|
| **OOP** | Classes, Objects, Encapsulation, Constructors |
| **STL** | `std::vector`, `std::map`, `std::string`, `std::sort` |
| **File I/O** | `std::ifstream`, `std::ofstream`, operator overloading |
| **Error Handling** | `try-catch`, `std::runtime_error`, custom exceptions |
| **Algorithms** | Linear search, custom comparators for sorting |
| **Modern C++** | Range-based for loops, auto, lambdas, `nullptr` |

---