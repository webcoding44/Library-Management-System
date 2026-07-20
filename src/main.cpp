#include "../include/Library.h"
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

int main() {
    Library library("library_data.txt");
    int choice;

    do {
        cout << "\n╔══════════════════════════════════════╗" << endl;
        cout << "║   سیستم مدیریت کتابخانه              ║" << endl;
        cout << "╠══════════════════════════════════════╣" << endl;
        cout << "║ 1. افزودن کتاب                      ║" << endl;
        cout << "║ 2. حذف کتاب                        ║" << endl;
        cout << "║ 3. ویرایش اطلاعات کتاب             ║" << endl;
        cout << "║ 4. جستجو بر اساس عنوان             ║" << endl;
        cout << "║ 5. جستجو بر اساس نویسنده           ║" << endl;
        cout << "║ 6. امانت دادن کتاب                 ║" << endl;
        cout << "║ 7. بازگرداندن کتاب                 ║" << endl;
        cout << "║ 8. نمایش همه کتاب‌ها                ║" << endl;
        cout << "║ 9. نمایش کتاب‌های موجود             ║" << endl;
        cout << "║ 10. نمایش کتاب‌های امانت داده شده   ║" << endl;
        cout << "║ 11. مرتب‌سازی بر اساس عنوان        ║" << endl;
        cout << "║ 12. مرتب‌سازی بر اساس نویسنده      ║" << endl;
        cout << "║ 13. مرتب‌سازی بر اساس سال          ║" << endl;
        cout << "║ 14. آمار کتابخانه                  ║" << endl;
        cout << "║ 0. خروج                            ║" << endl;
        cout << "╚══════════════════════════════════════╝" << endl;
        cout << "انتخاب شما: ";
        cin >> choice;

        try {
            switch (choice) {
                case 1: {
                    string id, title, author;
                    int year;
                    cout << "شناسه کتاب: ";
                    cin >> id;
                    cin.ignore();
                    cout << "عنوان کتاب: ";
                    getline(cin, title);
                    cout << "نویسنده: ";
                    getline(cin, author);
                    cout << "سال انتشار: ";
                    cin >> year;
                    library.addBook(id, title, author, year);
                    cout << "کتاب با موفقیت اضافه شد!" << endl;
                    break;
                }
                case 2: {
                    string id;
                    cout << "شناسه کتاب برای حذف: ";
                    cin >> id;
                    library.deleteBook(id);
                    cout << "کتاب با موفقیت حذف شد!" << endl;
                    break;
                }
                case 3: {
                    string id, title, author;
                    int year;
                    cout << "شناسه کتاب: ";
                    cin >> id;
                    cin.ignore();
                    cout << "عنوان جدید: ";
                    getline(cin, title);
                    cout << "نویسنده جدید: ";
                    getline(cin, author);
                    cout << "سال انتشار جدید: ";
                    cin >> year;
                    library.editBook(id, title, author, year);
                    cout << "اطلاعات کتاب با موفقیت ویرایش شد!" << endl;
                    break;
                }
                case 4: {
                    string title;
                    cin.ignore();
                    cout << "عنوان برای جستجو: ";
                    getline(cin, title);
                    auto results = library.searchByTitle(title);
                    if (results.empty()) {
                        cout << "کتابی یافت نشد." << endl;
                    } else {
                        cout << "\nنتایج جستجو:" << endl;
                        for (const auto& book : results) {
                            book.display();
                        }
                    }
                    break;
                }
                case 5: {
                    string author;
                    cin.ignore();
                    cout << "نویسنده برای جستجو: ";
                    getline(cin, author);
                    auto results = library.searchByAuthor(author);
                    if (results.empty()) {
                        cout << "کتابی یافت نشد." << endl;
                    } else {
                        cout << "\nنتایج جستجو:" << endl;
                        for (const auto& book : results) {
                            book.display();
                        }
                    }
                    break;
                }
                case 6: {
                    string id, borrower;
                    cout << "شناسه کتاب: ";
                    cin >> id;
                    cin.ignore();
                    cout << "نام امانت گیرنده: ";
                    getline(cin, borrower);
                    library.borrowBook(id, borrower);
                    cout << "کتاب با موفقیت امانت داده شد!" << endl;
                    break;
                }
                case 7: {
                    string id;
                    cout << "شناسه کتاب: ";
                    cin >> id;
                    library.returnBook(id);
                    cout << "کتاب با موفقیت بازگردانده شد!" << endl;
                    break;
                }
                case 8:
                    library.displayAllBooks();
                    break;
                case 9:
                    library.displayAvailableBooks();
                    break;
                case 10:
                    library.displayBorrowedBooks();
                    break;
                case 11:
                    library.sortByTitle();
                    cout << "کتاب‌ها بر اساس عنوان مرتب شدند!" << endl;
                    break;
                case 12:
                    library.sortByAuthor();
                    cout << "کتاب‌ها بر اساس نویسنده مرتب شدند!" << endl;
                    break;
                case 13:
                    library.sortByYear();
                    cout << "کتاب‌ها بر اساس سال مرتب شدند!" << endl;
                    break;
                case 14:
                    library.displayStats();
                    break;
                case 0:
                    cout << "خروج از برنامه..." << endl;
                    break;
                default:
                    cout << "انتخاب نامعتبر!" << endl;
            }
        } catch (const exception& e) {
            cout << "خطا: " << e.what() << endl;
        }

    } while (choice != 0);

    return 0;
}