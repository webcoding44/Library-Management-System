#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include <vector>
#include <map>
#include <string>

class Library {
private:
    std::vector<Book> books;
    std::map<std::string, int> idIndex;
    std::string filename;

    void updateIndex();

public:
    Library(std::string filename = "library_data.txt");

    // Book management
    void addBook(std::string id, std::string title, std::string author, int year);
    void deleteBook(std::string id);
    void editBook(std::string id, std::string newTitle, std::string newAuthor, int newYear);

    // Search
    std::vector<Book> searchByTitle(std::string title) const;
    std::vector<Book> searchByAuthor(std::string author) const;

    // Borrow operations
    void borrowBook(std::string id, std::string borrowerName);
    void returnBook(std::string id);

    // Display
    void displayAllBooks() const;
    void displayAvailableBooks() const;
    void displayBorrowedBooks() const;

    // Sort
    void sortByTitle();
    void sortByAuthor();
    void sortByYear();

    // File operations
    void saveToFile() const;
    void loadFromFile();

    // Statistics
    void displayStats() const;
};

#endif // LIBRARY_H