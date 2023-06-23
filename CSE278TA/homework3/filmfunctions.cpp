#include "filmfunctions.h"
#include <iostream>
#include <mysql++/mysql++.h>
#include <sstream>

using namespace std;
using namespace mysqlpp;

FilmFunctions::FilmFunctions(const char* dbname, const char* dbip, const char* dbuser, const char* dbpasswd)
{
    connection.connect(dbname, dbip, dbuser, dbpasswd);
}

bool FilmFunctions::isConnected()
{
    return connection.connected();
}

void FilmFunctions::findNameByID(const string& id)
{
    string query = "SELECT CONCAT(first_name, ' ', last_name) AS name FROM actor WHERE actor_id = " + id;
    Query q = connection.query(query);
    if (StoreQueryResult res = q.store()) {
        if (res.empty()) {
            cout << "\nInvalid ID. Please try again.\n";
        } else {
            cout << "\nName: " << res[0]["name"] << "\n";
        }
    } else {
        cerr << "\nQuery failed: " << q.error() << "\n";
    }
}

void FilmFunctions::guessMaxLength()
{
    int max_length;
    cout << "\nPlease enter the maximum length or '-1' to return to the main menu: ";
    cin >> max_length;
    if (max_length == -1) {
        return;
    }

    if (max_length < 1) {
        cout << "\nInvalid length. Please try again.\n";
        return;
    }

    stringstream ss;
    ss << max_length;
    string max_length_str = ss.str();
    string query = "SELECT title FROM film_text WHERE LENGTH(title) = " + max_length_str + " ORDER BY title DESC";
    Query q = connection.query(query);
    if (StoreQueryResult res = q.store()) {
        cout << "\nNumber of titles with a length of " << max_length << ": " << res.num_rows() << endl;
        cout << "Titles with maximum length " << max_length << ":";
        if (res.num_rows() == 0) {
            cout << " none" << endl;
        } else {
            cout << "\n";
            for (size_t i = 0; i < res.num_rows(); i++) {
                cout << res[i]["title"] << endl;
            }
        }
    } else {
        cerr << "\nQuery failed: " << q.error() << "\n";
    }
}

void FilmFunctions::runApplication()
{
    if (isConnected()) {
        while (true) {
            cout << "\n1. Find the name by entering the ID."
                 << "\n2. Guess the max length of title."
                 << "\nIf you want to exit, enter -1.\n\nEnter your choice (1 or 2): ";
            int choice;
            cin >> choice;
            if (choice == -1) {
                cout << "BYE" << endl;
                return;
            } else if (choice == 1) {
                cout << "\nEnter the ID: ";
                string id;
                cin >> id;

                findNameByID(id);
            } else if (choice == 2) {
                guessMaxLength();
            } else {
                cout << "\nInvalid choice. Please try again.\n";
            }
        }
    } else {
        cerr << "Connection failed: " << connection.error() << "\n";
    }
}
