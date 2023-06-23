#ifndef FILMFUNCTIONS_H
#define FILMFUNCTIONS_H

#include <string>
#include <mysql++/mysql++.h>

class FilmFunctions
{
private:
    mysqlpp::Connection connection;

public:
    FilmFunctions(const char* dbname, const char* dbip, const char* dbuser, const char* dbpasswd);
    bool isConnected();
    void findNameByID(const std::string& id);
    void guessMaxLength();
    void runApplication();
};

#endif // FILMFUNCTIONS_H
