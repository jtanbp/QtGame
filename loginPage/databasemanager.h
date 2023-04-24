#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QString>
#include <QSqlDatabase>

class DatabaseManager
{
public:
    DatabaseManager(const QString &path);
    bool addUser(const QString &username, const QString &password, const QString &firstName,
                 const QString &lastName, const QString &dateOfBirth, const QString &gender);
private:
    QSqlDatabase m_db;
};

#endif // DATABASEMANAGER_H
