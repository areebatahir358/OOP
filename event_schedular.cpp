#include <iostream>
#include <string>
#include <stdexcept>  
using namespace std;

class event
{
private:
    string name;

public:
    event()
    {
        name = " ";
    }
    event(string eventN)
    {
        name = eventN;
    }
    void seteventName(string eventN)
    {
        name = eventN;
    }
    string geteventName()
    {
        return name;
    }
};

class time
{
private:
    int hour;
    int minutes;

public:
    time()
    {
        hour = 0;
        minutes = 0;
    }
    void setTime(int h, int m)
    {
        if (h >= 0 && h < 24 && m >= 0 && m < 60)
        {
            hour = h;
            minutes = m;
        }
        else
            throw invalid_argument("Hour must be between 0 and 23, and minutes between 0 and 59.");
    }
    int getHour()
    {
        return hour;
    }
    int getMinutes()
    {
        return minutes;
    }
};

class EventDate
{
private:
    int Date;
    int month;
    int year;

    event nameobj;
    time detailsobj;

public:
    EventDate()
    {
        Date = 0;
        month = 0;
        year = 0;
    }
    EventDate(int d, int mth, int y, int h, int m, string eventN)
    {
        nameobj.seteventName(eventN);

        Date = d;
        month = mth;
        year = y;

        detailsobj.setTime(h, m);
    }

    bool isLeapYear(int y)
    {
        return (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));
    }

    bool isValidDate(int d, int mth, int y)
    {
        if (mth < 1 || mth > 12)
            return false;

        int daysInMonth[] = { 31, (isLeapYear(y) ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        return (d > 0 && d <= daysInMonth[mth - 1]);
    }

    void setdateMonthYear(int d, int mth, int y)
    {
        if (y <= 0 || y > 2024 || !isValidDate(d, mth, y))
        {
            throw invalid_argument("Invalid date, month, or year. Please enter valid values.");
        }
        Date = d;
        month = mth;
        year = y;
    }

    void setTimings(int h, int m)
    {
        detailsobj.setTime(h, m);
    }

    void settingeventname(string eventN)
    {
        nameobj.seteventName(eventN);
    }

    int getDate()
    {
        return Date;
    }
    int getMonth()
    {
        return month;
    }
    int getYear()
    {
        return year;
    }

    void displayEventDetails()
    {
        string eventN = nameobj.geteventName();
        int timehours = detailsobj.getHour();
        int timeminutes = detailsobj.getMinutes();
        cout << eventN << " will be at " << timehours << ":" << timeminutes << endl;
        cout << "See you there on " << Date << "/" << month << "/" << year << endl;
    }
};

int main()
{
    EventDate obj;
    string eventN;
    int h, m, d, mth, y;

    try
    {
        cout << "Enter event name: ";
        cin >> eventN;
        obj.settingeventname(eventN);

        cout << "Enter hours and minutes (0-23 for hours, 0-59 for minutes): ";
        cin >> h >> m;
        obj.setTimings(h, m);

        cout << "Enter date, month, and year (e.g., 12 05 2024): ";
        cin >> d >> mth >> y;
        obj.setdateMonthYear(d, mth, y);

        obj.displayEventDetails();
    }
    catch (const invalid_argument &e)
    {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
