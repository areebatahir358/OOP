#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void inputNumbers(vector<int> &V)
{
    int n;
    cout << "How many elements you want to enter?";
    cin >> n;
    int num;
    cout << "Enter "<<n<<" Numbers:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        V.push_back(num);
    }
}

void display(vector<int> &V)
{
    cout << "Elements of vector are:" << endl;
    for (auto vec : V)
    {
        cout << vec << " ";
    }
    cout << endl;
}

int getMin(vector<int> &V)
{
    int min = V[0];
    cout << "Minimum element in vector is: ";
    for (int i = 1; i < V.size(); i++)
    {
        if (V[i] < min)
        {
            min = V[i];
        }
    }
    cout << min << endl;
    return min;
}

int getMax(vector<int> &V)
{
    int max = V[0];
    cout << "Maximum element in vector is: ";
    for (int i = 1; i < V.size(); i++)
    {
        if (V[i] > max)
        {
            max = V[i];
        }
    }
    cout << max << endl;
    return max;
}

int countElement(vector<int> &V)
{
    int count = 0;
    for (auto vec : V)
    {
        count++;
    }
    cout << "Number of elements in vector is: " << count << endl;
    return count;
}

void sortElement(vector<int> &V, int order)
{
    if (order == 1)
    {
        cout << "Vector sorted in ascending order: ";
        sort(V.begin(), V.end());
        for (int i : V)
        {
            cout << i << " ";
        }
    }
    else if (order == -1)
    {
        cout << "Vector sorted in descending order: ";
        sort(V.begin(), V.end(), greater<int>());
        for (int i : V)
        {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main()
{
    vector<int> V;
    int choice, order;

    inputNumbers(V);

    do
    {
        cout << "\nMenu: " << endl;
        cout << "1. Display Elements" << endl;
        cout << "2. Find Minimum" << endl;
        cout << "3. Find Maximum" << endl;
        cout << "4. Count Elements" << endl;
        cout << "5. Sort Elements" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            display(V);
            break;
        case 2:
            getMin(V);
            break;
        case 3:
            getMax(V);
            break;
        case 4:
            countElement(V);
            break;
        case 5:
            cout << "Enter 1 for Ascending or -1 for Descending order: ";
            cin >> order;
            sortElement(V, order);
            break;
        case 6:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }

    } while (choice != 6);

    return 0;
}
