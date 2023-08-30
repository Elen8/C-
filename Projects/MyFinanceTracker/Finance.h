#ifndef FINANCE_H
#define FINANCE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlQuery>

class FinanceTracker: public QObject
{
    Q_OBJECT
public:
    explicit FinanceTracker(QObject* parent = nullptr);
    QSqlTableModel* getTableModel() const;
    int GetIndexOfCategoryInTable(const QString&);

public slots:
    bool addCategory(const QString&, const QString&);
    void addExpance(const QString&, const QString&);
    void deleteCategory(const QString&);
    void editMaxMount(const QString&, const QString&);
    
    //PREDICTIONS
    //Sortng By
    //Monthly Status
    //Notifications
    //

    //saveList - SQL


private:
    QSqlDatabase db;
    QSqlQuery *query;
    QSqlTableModel *model;
};

#endif // FINANCE_H
