#include <iostream>

using namespace std;

bool isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return true;
    else
        return false;
}

int days_InMonth(int month, int year) {
    if (month == 2) {
        return (isLeapYear(year)) ? 29 : 28;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else {
        return 31;
    }
}

void printCalendar(int year) {
    string months[] = {"January", "February", "March", "April", "May", "June", "July",
                       "August", "September", "October", "November", "December"};

    for (int month = 1; month <= 12; month++) {
        cout << "  " << months[month - 1] << " " << year << endl;
        cout << "---------------------------" << endl;
        cout << " Sun Mon Tue Wed Thu Fri Sat" << endl;

        int daysInMonth = days_InMonth(month, year);
        int startingDay = (year * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400) % 7;
        int currentDay = 1;

        for (int i = 0; i < startingDay; i++) {
            cout << "    ";
        }

        for (int i = 1; i <= daysInMonth; i++) {
            printf("%4d", i);
            if ((i + startingDay) % 7 == 0 || i == daysInMonth) {
                cout << endl;
            }
        }
        cout << endl;
    }
}

int main() {
    int year;

    cout << "Enter year: ";
    cin >> year;

    if (year <= 0) {
        cout << "Invalid year input!" << endl;
        return 1;
    }

    printCalendar(year);

    return 0;
}
