#include "../include/Book.h"
#include <stdexcept>

Book::Book() : year(0), isBorrowed(false) {}

Book::Book(std::string id, std::string title, std::string author, int year)
    : id(id), title(title), author(author), year(year), isBorrowed(false) {}

std::string Book::getId() const { return id; }
std::string Book::getTitle() const { return title; }
std::string Book::getAuthor() const { return author; }
int Book::getYear() const { return year; }
bool Book::getIsBorrowed() const { return isBorrowed; }
std::string Book::getBorrower() const { return borrower; }

void Book::setTitle(std::string title) { this->title = title; }
void Book::setAuthor(std::string author) { this->author = author; }
void Book::setYear(int year) { this->year = year; }

void Book::borrow(std::string borrowerName) {
    if (isBorrowed) {
        throw std::runtime_error("این کتاب قبلاً امانت داده شده است!");
    }
    isBorrowed = true;
    borrower = borrowerName;
}

void Book::returnBook() {
    if (!isBorrowed) {
        throw std::runtime_error("این کتاب امانت داده نشده است!");
    }
    isBorrowed = false;
    borrower = "";
}

void Book::display() const {
    std::cout << "شناسه: " << id << " | عنوان: " << title 
              << " | نویسنده: " << author << " | سال: " << year
              << " | وضعیت: " << (isBorrowed ? "امانت داده شده" : "موجود");
    if (isBorrowed) {
        std::cout << " (امانت گیرنده: " << borrower << ")";
    }
    std::cout << std::endl;
}

std::ofstream& operator<<(std::ofstream& out, const Book& book) {
    out << book.id << "|" << book.title << "|" << book.author 
        << "|" << book.year << "|" << book.isBorrowed 
        << "|" << book.borrower << "\n";
    return out;
}

std::ifstream& operator>>(std::ifstream& in, Book& book) {
    std::getline(in, book.id, '|');
    std::getline(in, book.title, '|');
    std::getline(in, book.author, '|');
    in >> book.year;
    in.ignore();
    in >> book.isBorrowed;
    in.ignore();
    std::getline(in, book.borrower);
    return in;
}