//
// Created by Mona on 6/23/23.
//

#ifndef CSE278_APPLICATION_H
#define CSE278_APPLICATION_H

// #include "/mysql++.h"
#include <mysql++/mysql++.h>
#include <iostream>

using namespace std;
using namespace mysqlpp;

int main()
{
    char dbuser[30] = "Surui";
    char dbpasswd[30] = "Surui123";
    char dbip[30] = "www.rexjoush.com";
    char dbname[50] = "mona";

    Connection con(false);
    con.connect(dbname, dbip, dbuser, dbpasswd);

    if (con.connected()) {
        while (true) {
            cout << "1.Find the name by entering the ID.\n2. Guess the max length of title."
                    "\nIf you want to exit Enter -1\nEnter your choice (1 or 2): ";
            int choice;
            cin >> choice;
            if (choice == -2) {
                cout << "BYE" << endl;
                return 1;
            } else if (choice == 1) {
                cout << "\nEnter the ID: ";
                string id;
                cin >> id;

                string query = "SELECT CONCAT(first_name, ' ', last_name) AS name FROM actor WHERE actor_id = " + id;
                Query q = con.query(query);
                if (StoreQueryResult res = q.store())
                {
                    if (res.empty())
                    {
                        cout << "\nInvalid ID. Please try again.\n";
                    }
                    else
                    {
                        cout << "\nName: " << res[0]["name"] << "\n";
                    }
                }
                else
                {
                    cerr << "\nQuery failed: " << q.error() << "\n";
                }
            }
            else if (choice == 2) {
                // Guess max length of title
                string query = "SELECT MAX(LENGTH(title)) AS max_length FROM actor";
                Query q = con.query(query);
                if (StoreQueryResult res = q.store()) {
                    cout << "\nMax length of title: " << res[0]["max_length"] << "\n";
                }
                else {
                    cerr << "\nQuery failed: " << q.error() << "\n";
                }
            } else {
                cout << "\nInvalid choice. Please try again.\n";
            }
        }
    }
    else
    {
        cerr << "Connection failed: " << con.error() << "\n";
    }

    return 0;
}
