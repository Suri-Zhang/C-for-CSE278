#include <iostream>
#include <string>
#include "filmfunctions.h"

using namespace std;

int main()
{
    char dbuser[30] = "Surui";
    char dbpasswd[30] = "Surui123";
    char dbip[30] = "www.rexjoush.com";
    char dbname[50] = "mona";

    FilmFunctions filmFunctions(dbname, dbip, dbuser, dbpasswd);

    filmFunctions.runApplication();

    return 0;
}
