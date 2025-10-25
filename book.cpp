#include <sstream>
#include <algorithm>
#include "book.h"

using namespace std;

// Constructeur par défaut
Book::Book() : title(""), author(""), isbn(""), isAvailable(true), borrowerName("") {}

// Constructeur avec paramètres
Book::Book(const string &title, const string &author, const string &isbn)
    : title(title), author(author), isbn(isbn), isAvailable(true), borrowerName("") {}

// Getters
string Book::getTitle() const { return title; }
string Book::getAuthor() const { return author; }
string Book::getISBN() const { return isbn; }
bool Book::getAvailability() const { return isAvailable; }
string Book::getBorrowerName() const { return borrowerName; }

// Setters
void Book::setTitle(const string &title) { this->title = title; }
void Book::setAuthor(const string &author) { this->author = author; }
void Book::setISBN(const string &isbn) { this->isbn = isbn; }
void Book::setAvailability(bool available) { this->isAvailable = available; }
void Book::setBorrowerName(const string &name) { this->borrowerName = name; }

// Emprunter
void Book::checkOut(const string &borrower)
{
    if (isAvailable)
    {
        isAvailable = false;
        borrowerName = borrower;
    }
}

// Retourner
void Book::returnBook()
{
    isAvailable = true;
    borrowerName.clear();
}

// Affichage simple
string Book::toString() const
{
    string result = "Titre: " + title + "\nAuteur: " + author + "\nISBN: " + isbn;
    result += "\nDisponibilite: " + string(isAvailable ? "Disponible" : "Emprunte");
    if (!isAvailable && !borrowerName.empty())
    {
        result += "\nEmprunte par: " + borrowerName;
    }
    return result;
}

// Format fichier: title|author|isbn|isAvailable(1/0)|borrowerName
string Book::toFileFormat() const
{
    string result = title + "|" + author + "|" + isbn + "|";
    result += (isAvailable ? "1" : "0");
    result += "|";
    result += borrowerName; // vide si dispo
    return result;
}

// Parse depuis une ligne du fichier (même format que toFileFormat)
void Book::fromFileFormat(const string &line)
{
    stringstream ss(line);
    string token;

    getline(ss, title, '|');
    getline(ss, author, '|');
    getline(ss, isbn, '|');

    string availStr;
    getline(ss, availStr, '|');
    // Par défaut, si le champ manque, on considère dispo
    if (availStr == "0" || availStr == "false" || availStr == "False")
    {
        isAvailable = false;
    }
    else
    {
        isAvailable = true;
    }

    // borrowerName peut être vide
    getline(ss, borrowerName, '|');
    if (isAvailable)
    {
        borrowerName.clear();
    }
}
