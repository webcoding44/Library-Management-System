#include "../include/Library.h"
#include <algorithm>
#include <stdexcept>
#include <sstream>

Library::Library(std::string filename) : filename(filename) {
    loadFromFile();
}

void Library::updateIndex() {
    idIndex.clear();
    for (size_t i = 0; i < books.size(); i++) {
        idIndex[books[i].getId()] = i;
    }
}

void Library::addBook(std::string id, std::string title, std::string author, int year) {
    if (idIndex.find(id) != idIndex.end()) {
        throw std::runtime_error("کتاب با این شناسه قبلاً وجود دارد!");
    }
    books.push_back(Book(id, title, author, year));
    idIndex[id] = books.size() - 1;
    saveToFile();
}

void Library::deleteBook(std::string id) {
    auto it = idIndex.find(id);
    if (it == idIndex.end()) {
        throw std::runtime_error("کتاب با این شناسه یافت نشد!");
    }
    if (books[it->second].getIsBorrowed()) {
        throw std::runtime_error("نمی‌توان کتاب امانت داده شده را حذف کرد!");
    }
    books.erase(books.begin() + it->second);
    updateIndex();
    saveToFile();
}

void Library::editBook(std::string id, std::string newTitle, std::string newAuthor, int newYear) {
    auto it = idIndex.find(id);
    if (it == idIndex.end()) {
        throw std::runtime_error("کتاب با این شناسه یافت نشد!");
    }
    books[it->second].setTitle(newTitle);
    books[it->second].setAuthor(newAuthor);
    books[it->second].setYear(newYear);
    saveToFile();
}

std::vector<Book> Library::searchByTitle(std::string title) const {
    std::vector<Book> results;
    for (const auto& book : books) {
        if (book.getTitle().find(title) != std::string::npos) {
            results.push_back(book);
        }
    }
    return results;
}

std::vector<Book> Library::searchByAuthor(std::string author) const {
    std::vector<Book> results;
    for (const auto& book : books) {
        if (book.getAuthor().find(author) != std::string::npos) {
            results.push_back(book);
        }
    }
    return results;
}

void Library::borrowBook(std::string id, std::string borrowerName) {
    auto it = idIndex.find(id);
    if (it == idIndex.end()) {
        throw std::runtime_error("کتاب با این شناسه یافت نشد!");
    }
    books[it->second].borrow(borrowerName);
    saveToFile();
}

void Library::returnBook(std::string id) {
    auto it = idIndex.find(id);
    if (it == idIndex.end()) {
        throw std::runtime_error("کتاب با این شناسه یافت نشد!");
    }
    books[it->second].returnBook();
    saveToFile();
}

void Library::displayAllBooks() const {
    if (books.empty()) {
        std::cout << "هیچ کتابی در کتابخانه وجود ندارد." << std::endl;
        return;
    }
    std::cout << "\n=== لیست همه کتاب‌ها ===" << std::endl;
    for (const auto& book : books) {
        book.display();
    }
}

void Library::displayAvailableBooks() const {
    std::cout << "\n=== کتاب‌های موجود ===" << std::endl;
    bool found = false;
    for (const auto& book : books) {
        if (!book.getIsBorrowed()) {
            book.display();
            found = true;
        }
    }
    if (!found) {
        std::cout << "هیچ کتابی موجود نیست." << std::endl;
    }
}

void Library::displayBorrowedBooks() const {
    std::cout << "\n=== کتاب‌های امانت داده شده ===" << std::endl;
    bool found = false;
    for (const auto& book : books) {
        if (book.getIsBorrowed()) {
            book.display();
            found = true;
        }
    }
    if (!found) {
        std::cout << "هیچ کتابی امانت داده نشده است." << std::endl;
    }
}

void Library::sortByTitle() {
    std::sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
        return a.getTitle() < b.getTitle();
    });
    updateIndex();
    saveToFile();
}

void Library::sortByAuthor() {
    std::sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
        return a.getAuthor() < b.getAuthor();
    });
    updateIndex();
    saveToFile();
}

void Library::sortByYear() {
    std::sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
        return a.getYear() < b.getYear();
    });
    updateIndex();
    saveToFile();
}

void Library::saveToFile() const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("خطا در باز کردن فایل برای ذخیره‌سازی!");
    }
    for (const auto& book : books) {
        file << book;
    }
    file.close();
}

void Library::loadFromFile() {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return;
    }
    books.clear();
    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty()) {
            Book book;
            std::istringstream iss(line);
            std::string id, title, author, yearStr, isBorrowedStr, borrower;
            
            std::getline(iss, id, '|');
            std::getline(iss, title, '|');
            std::getline(iss, author, '|');
            std::getline(iss, yearStr, '|');
            std::getline(iss, isBorrowedStr, '|');
            std::getline(iss, borrower);
            
            int year = std::stoi(yearStr);
            bool isBorrowed = (isBorrowedStr == "1");
            
            Book newBook(id, title, author, year);
            if (isBorrowed) {
                newBook.borrow(borrower);
            }
            books.push_back(newBook);
        }
    }
    file.close();
    updateIndex();
}

void Library::displayStats() const {
    int total = books.size();
    int available = 0;
    int borrowed = 0;
    
    for (const auto& book : books) {
        if (book.getIsBorrowed()) {
            borrowed++;
        } else {
            available++;
        }
    }
    
    std::cout << "\n=== آمار کتابخانه ===" << std::endl;
    std::cout << "تعداد کل کتاب‌ها: " << total << std::endl;
    std::cout << "کتاب‌های موجود: " << available << std::endl;
    std::cout << "کتاب‌های امانت داده شده: " << borrowed << std::endl;
}