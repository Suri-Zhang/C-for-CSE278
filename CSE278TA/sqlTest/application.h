//
// Created by joush on 2023/6/22.
//

#ifndef C_FOR_CSE278_APPLICATION_H
#define C_FOR_CSE278_APPLICATION_H
#include "C:\Program Files\MySQL\Connector C++ 8.0\include\mysql\jdbc.h"
#include "C:\Program Files\MySQL\MySQL Server 8.0\include\mysql.h"
#include "iostream"
using namespace std;
using std::string;
int main() {
    MYSQL * con; //= mysql_init((MYSQL*) 0);
    MYSQL_RES *res;
    MYSQL_ROW row;
    char tmp[400];
    //database configuartion
    char dbuser[30] = "Surui";
    char dbpasswd[30] = "Surui123"; // it must be    changed
    char dbip[30] = "www.rexjoush.com";
    char dbname[50] = "mona";
    char *query = NULL;

    int x;
    int y;
    int rt;//return value
    unsigned int t;

    int count = 0;

    con = mysql_init((MYSQL*)0);

    if (con != NULL && mysql_real_connect(con, dbip, dbuser, dbpasswd, dbname, 3306, NULL, 0)) {
        if (!mysql_select_db(con, dbname)) {
            printf("Select successfully the database!\n");
            con->reconnect = 1;
            query = "set names \'UTF-8\'";
            rt = mysql_real_query(con, query, strlen(query));
            if (rt) {
                printf("Error making query: %s !!!\n", mysql_error(con));
            }
            else {
                printf("query %s succeed!\n", query);
            }
        }
    }
    else {
        MessageBoxA(NULL, "Unable to connect the database,check your configuration!", "", NULL);
    }
    string name = "";
    cin >> name;
    sprintf(tmp, "select * from actor where name = %s", name.c_str());
    rt = mysql_real_query(con, tmp, strlen(tmp));
    if (rt)
    {
        printf("Error making query: %s !!!\n", mysql_error(con));
    }
    else
    {
        printf("%s executed!!!\n", tmp);
    }
    res = mysql_store_result(con);//将结果保存在res结构体中

    while (row = mysql_fetch_row(res)) {
        for (t = 0; t<mysql_num_fields(res); t++) {
            printf("%s  ", row[t]);
        }
        printf(".............\n");
        count++;
    }

    printf("number of rows %d\n", count);
    printf("mysql_free_result...\n");
    mysql_free_result(res);
    mysql_close(con);
    system("pause");
    return 0;
}


#endif //C_FOR_CSE278_APPLICATION_H
