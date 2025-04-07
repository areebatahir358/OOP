#include <iostream>
#include <vector>
#include <string>
using namespace std;

string getInput(vector<string> &Svector)
{
    string S;
    cout << "Enter 3 strings:" << endl;
    for (int i = 0; i < 3; i++)
    {
        cin >> S;
        Svector.push_back(S);
    }
}

string display(vector<string> &Svector)
{
    cout << "Entered strings are:" << endl;
    for (auto str : Svector)
    {
        cout << str << " ";
    }
    cout << endl;
}

// Function to capitalize the first letter of each string
vector<string> changeCaps(vector<string> &Svector)
{
    vector<string> capitalizeString;
    for (string &str : Svector)
    {
        if (!str.empty())
        {
            string capitalizeStr = str;
            if (capitalizeStr[0] >= 'a' && capitalizeStr[0] <= 'z')
            {
                capitalizeStr[0] -= ('a' - 'A');
            }
            capitalizeString.push_back(capitalizeStr);
        }
    }

    return capitalizeString;
}

// Function to filter strings that contain numbers
vector<string> isNumberString(vector<string> Nstring)
{
    vector<string> filteredStringNum;
    for (string &str : Nstring)
    {
        bool hasDigit = false;
        for (char ch : str)
        {
            if (isdigit(ch))
            {
                hasDigit = true;
                break;
            }
        }
        if (hasDigit)
        {
            filteredStringNum.push_back(str);
        }
    }
    return filteredStringNum;
}

int main()
{
    vector<string> Svector;
    vector<string> Nstring;
    int choice;
    string Snum;

    do
    {
        cout << "\nString Processor Menu:" << endl;
        cout << "1. Enter Strings" << endl;
        cout << "2. Display Strings" << endl;
        cout << "3. Capitalize First Letter of Each String" << endl;
        cout << "4. Filter Strings with Numbers" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            getInput(Svector);
            break;

        case 2:
            display(Svector);
            break;

        case 3:
        {
            vector<string> Cstring = changeCaps(Svector);
            cout << "Strings with first letter capitalized:" << endl;
            for (string &str : Cstring)
            {
                cout << str << " ";
            }
            cout << endl;
            break;
        }

        case 4:
        {
            cout << "Enter 5 strings with or without numbers:" << endl;
            for (int i = 0; i < 5; i++)
            {
                cin >> Snum;
                Nstring.push_back(Snum);
            }

            vector<string> strResult = isNumberString(Nstring);
            cout << "Strings with numbers are:" << endl;
            for (string &str : strResult)
            {
                cout << str << " ";
            }
            cout << endl;
            break;
        }

        case 5:
            cout << "Exiting program." << endl;
            break;

        default:
            cout << "Invalid choice! Please try again." << endl;
        }

    } while (choice != 5);

    return 0;
}
