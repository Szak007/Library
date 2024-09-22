# Library Management System

## Overview

The **Library Management System** is a console application written in C++ that simulates a book rental management system. It allows adding, editing, sorting, and searching for books according to various criteria such as title, author, year of publication, or loan status. The program utilizes the **Standard Template Library (STL)** for efficient sorting and searching, and stores data in both text and binary files.

## Features

- Add new books to the system.
- Sort books by title, author, genre, year, and loan status.
- Search for books by ID, title, author, genre, year, and loan status.
- Save book data to text and binary files for persistence.
- Load book data from text and binary files.

## Technologies

- **Programming Language**: C++
- **Libraries**: Standard Template Library (STL - list, vector, algorithm)
- **File Operations**: Read and write to text and binary files

## Installation and Usage

1. Clone the repository:
   ```bash
   git clone https://github.com/Szak007/Library.git
   ```
2. Prepare the necessary input file with book data (e.g., `books.txt`) in the following format:
   ```text
   1;The Great Gatsby;F. Scott Fitzgerald;Fiction;1925;0
   2;1984;George Orwell;Dystopia;1949;1
   ```
3. Compile the project using your favorite C++ compiler:

   ```bash
   g++ -o library main.cpp Book.cpp Function.cpp
   ```

4. Run the program with the input and output file parameters:
   ```bash
   ./library -f books.txt -o output.txt
   ```

## Project Structure

- **main.cpp**: The main entry point of the application.
- **Book.cpp / Book.h**: Contains the `Book` class and its methods.
- **List_of_books.h**: Handles operations on the list of books, including sorting and searching.
- **Function.cpp / Function.h**: Includes helper functions for sorting and searching books.
- **books.txt**: Sample input file containing book data.

## Skills Demonstrated

- Implementation of CRUD operations for managing book data.
- Efficient sorting and searching using **STL**.
- Handling file I/O for both text and binary files.
