#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QListWidget>
#include <QMessageBox>

class ExpenseTracker : public QWidget {
    Q_OBJECT

public:
    ExpenseTracker(QWidget *parent = nullptr) : QWidget(parent), totalSalary(0), totalExpenses(0) {
        auto *mainLayout = new QVBoxLayout(this);

        // Salary input
        auto *salaryLayout = new QHBoxLayout();
        salaryInput = new QLineEdit();
        salaryInput->setPlaceholderText("Enter your monthly salary");
        QPushButton *saveSalaryBtn = new QPushButton("Save Salary");
        salaryLayout->addWidget(salaryInput);
        salaryLayout->addWidget(saveSalaryBtn);
        mainLayout->addLayout(salaryLayout);

        // Expense input
        auto *expenseLayout = new QHBoxLayout();
        categoryInput = new QLineEdit();
        categoryInput->setPlaceholderText("Expense category (e.g., Food)");
        amountInput = new QLineEdit();
        amountInput->setPlaceholderText("Amount");
        QPushButton *addExpenseBtn = new QPushButton("Add Expense");
        expenseLayout->addWidget(categoryInput);
        expenseLayout->addWidget(amountInput);
        expenseLayout->addWidget(addExpenseBtn);
        mainLayout->addLayout(expenseLayout);

        // Remaining budget label
        remainingLabel = new QLabel("Remaining budget: $0.00");
        mainLayout->addWidget(remainingLabel);

        // Today's expenses list
        expenseList = new QListWidget();
        mainLayout->addWidget(new QLabel("Today's Expenses:"));
        mainLayout->addWidget(expenseList);

        // Connections
        connect(saveSalaryBtn, &QPushButton::clicked, this, &ExpenseTracker::saveSalary);
        connect(addExpenseBtn, &QPushButton::clicked, this, &ExpenseTracker::addExpense);
    }

private slots:
    void saveSalary() {
        bool ok;
        double salary = salaryInput->text().toDouble(&ok);
        if (!ok || salary < 0) {
            QMessageBox::warning(this, "Invalid input", "Please enter a valid positive salary amount.");
            return;
        }
        totalSalary = salary;
        updateRemaining();
        QMessageBox::information(this, "Salary saved", "Monthly salary saved successfully.");
    }

    void addExpense() {
        QString category = categoryInput->text().trimmed();
        bool ok;
        double amount = amountInput->text().toDouble(&ok);
        if (category.isEmpty() || !ok || amount <= 0) {
            QMessageBox::warning(this, "Invalid input", "Please enter a valid category and positive amount.");
            return;
        }

        totalExpenses += amount;
        expenseList->addItem(QString("%1: $%2").arg(category).arg(amount, 0, 'f', 2));

        categoryInput->clear();
        amountInput->clear();

        updateRemaining();
    }

private:
    void updateRemaining() {
        double remaining = totalSalary - totalExpenses;
        remainingLabel->setText(QString("Remaining budget: $%1").arg(remaining, 0, 'f', 2));
    }

    QLineEdit *salaryInput;
    QLineEdit *categoryInput;
    QLineEdit *amountInput;
    QLabel *remainingLabel;
    QListWidget *expenseList;

    double totalSalary;
    double totalExpenses;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    ExpenseTracker window;
    window.setWindowTitle("Simple Expense Tracker");
    window.resize(400, 300);
    window.show();
    return app.exec();
}

#include "main.moc"
