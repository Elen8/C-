#include "Finance.h"
#include <QDebug>
#include <QMessageBox>

FinanceTracker::FinanceTracker(QObject* parent): QObject(parent)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./financetracker.db");

    if (db.open())
        qDebug() << "Opened";
    else
        qDebug() << "Failed";

    query = new QSqlQuery(db);
    query->exec("CREATE TABLE Categories(Category TEXT, MaxMount INT, CurrentMount INT);");

    model = new QSqlTableModel(this, db);
    model->setTable("Categories");
    model->select();
}

QSqlTableModel* FinanceTracker::getTableModel() const
{
    return model;
}

bool isDigit(const QString& str)
{
    int i = 0;
    int res = 0;
    while (res != -1 && i < str.size())
    {
        res = str[i].digitValue();
        i++;
    }
    if (res == -1)
        return false;
    return true;
}

int FinanceTracker::GetIndexOfCategoryInTable(const QString& category)
{
    QModelIndexList matches = model->match(model->index(0,0), Qt::DisplayRole, category, 1, Qt::MatchExactly);

    if (!matches.isEmpty())
        return matches.first().row();
    return -1;
}

bool FinanceTracker::addCategory(const QString& category, const QString& max_mount)
{
    if (category == "")
        QMessageBox::information(nullptr, "Category is empty", "Please fill category name.");
    else if (max_mount == "")
        QMessageBox::information(nullptr, "Mount is empty", "Please fill maximum mount of money.");
    else if (!isDigit(max_mount))
        QMessageBox::information(nullptr, "Mount should be digit", "Please fill maximum mount by digits.");
    else
    {
        if (GetIndexOfCategoryInTable(category) == -1)
        {

            int MaxMount = max_mount.toInt();
            int CurrentMount = 0;

            int newRow = model->rowCount();
            model->insertRow(newRow);
            QModelIndex strindex = model->index(newRow, 0);
            model->setData(strindex, category);

            QModelIndex max = model->index(newRow, 1);
            model->setData(max, MaxMount);

            QModelIndex curr = model->index(newRow, 2);
            model->setData(curr, CurrentMount);

            if (model->submitAll())
                qDebug() << "Submitted";
            else
                qDebug() << "Failed to submit";
            return true;
        }
        else
        {
            QMessageBox::information(nullptr, "Category redefinition", "The category already exists.");
        }
    }
    return false;
}

void FinanceTracker::addExpance(const QString& category, const QString& expance)
{
    if (category == "")
    {
        QMessageBox::information(nullptr, "Category isn't selected", "Please select category.");
        return;
    }
    if (expance == "" || expance.toInt() < 0)
    {
        QMessageBox::information(nullptr, "Invalid value", "Please enter valid mount.");
        return;
    }

    qDebug() << category;
    int row = GetIndexOfCategoryInTable(category);
    QModelIndex idx = model->index(row, 2);
    QVariant currentValue = model->data(idx, Qt::EditRole);
    int currentIntVal = currentValue.toInt();
    int updateIntVal = currentIntVal + expance.toInt();
    model->setData(idx, updateIntVal, Qt::EditRole);

    model->submitAll();
    QModelIndex MaxIdx = model->index(row, 1);
    QVariant MaxValue = model->data(MaxIdx, Qt::EditRole);
    model->select();
    qDebug() << row << updateIntVal << MaxValue.toInt();
    if (updateIntVal < MaxValue.toInt())
    {
        QMessageBox::information(nullptr, "Information", "Successfully added.");
        return;
    }
    else
    {
        QMessageBox::information(nullptr, "Warning", "Currnet mount is more than max mount.");
        return;
    }
}

void FinanceTracker::deleteCategory(const QString& category)
{
    if (category == "")
    {
        QMessageBox::information(nullptr, "Category isn't selected", "Please select category.");
        return;
    }

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(nullptr, "Remove category", "Do you want to remove category?",
                                    QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        qDebug() << "Yes was clicked";
        int row = GetIndexOfCategoryInTable(category);
        model->removeRow(row);
        model->select();
    }
    else
    {
        qDebug() << "Yes was *not* clicked";
    }
}

void FinanceTracker::editMaxMount(const QString& category, const QString& expance)
{
    if (category == "")
    {
        QMessageBox::information(nullptr, "Category isn't selected", "Please select category.");
        return;
    }
    if (expance == "" || expance.toInt() < 0)
    {
        QMessageBox::information(nullptr, "Invalid value", "Please enter valid mount.");
        return;
    }
    int row = GetIndexOfCategoryInTable(category);
    QModelIndex idx = model->index(row, 1);
    int updateIntVal = expance.toInt();
    model->setData(idx, updateIntVal, Qt::EditRole);

    model->submitAll();
    model->select();
}

