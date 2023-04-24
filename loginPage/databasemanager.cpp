#include "DatabaseManager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

DatabaseManager::DatabaseManager(const QString &path)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);

    if (!m_db.open())
    {
        qDebug() << "Error: Unable to open database";
        return;
    }

    QSqlQuery query(m_db);

    query.exec("CREATE TABLE IF NOT EXISTS users ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT, "
               "username TEXT UNIQUE NOT NULL, "
               "password TEXT NOT NULL, "
               "firstName TEXT NOT NULL, "
               "lastName TEXT NOT NULL, "
               "dateOfBirth TEXT NOT NULL, "
               "gender TEXT);");
}

bool DatabaseManager::addUser(const QString &username, const QString &password, const QString &firstName,
                              const QString &lastName, const QString &dateOfBirth, const QString &gender)
{
    QSqlQuery query(m_db);
    query.prepare("INSERT INTO users (username, password, firstName, lastName, dateOfBirth, gender) "
                  "VALUES (:username, :password, :firstName, :lastName, :dateOfBirth, :gender);");
    query.bindValue(":username", username);
    query.bindValue(":password", password);
    query.bindValue(":firstName", firstName);
    query.bindValue(":lastName", lastName);
    query.bindValue(":dateOfBirth", dateOfBirth);
    query.bindValue(":gender", gender);

    if (!query.exec())
    {
        qDebug() << "Error: Unable to add user" << query.lastError();
        return false;
    }

    return true;
}
