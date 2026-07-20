#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>
#include <fstream>

class Book {
private:
    std::string id;
    std::string title;
    std::string author;
    int year;
    bool isBorrowed;
    std::string borrower;

public:
    // Constructors
    Book();
    Book(std::string id, std::string title, std::string author, int year);

    // Getters
    std::string getId() const;
    std::string getTitle() const;
    std::string getAuthor() const;
    int getYear() const;
    bool getIsBorrowed() const;
    std::string getBorrower() const;

    // Setters
    void setTitle(std::string title);
    void setAuthor(std::string author);
    void setYear(int year);

    // Methods
    void borrow(std::string borrowerName);
    void returnBook();
    void display() const;

    // Friend functions for file I/O
    friend std::ofstream& operator<<(std::ofstream& out, const Book& book);
    friend std::ifstream& operator>>(std::ifstream& in, Book& book);
};

#endif // BOOK_H