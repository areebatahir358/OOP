#include <iostream>
#include <queue>

using namespace std;

int main()
{
    queue<int> numbers;
    int integers;
    queue<int> temp;
    queue<int> oddNumbers;

    cout << "Enter integers: (press 0 to stop)" << endl;
    while (true)
    {
        cin >> integers;
        while (integers < 0)
        {
            cout << "Invalid integer" << endl
                 << "Enter integer again:" << endl;
            cin >> integers;
        }
        if (integers == 0)
        {
            break;
        }
        numbers.push(integers);
    }

    cout << "Numbers in the queue are:" << endl;
    while (!numbers.empty())
    {
        cout << numbers.front() << " ";
        temp.push(numbers.front());
        numbers.pop();
    }
    cout << endl;

    cout << "Queue with odd numbers:" << endl;

    while (!temp.empty())
    {
        if (temp.front() % 2 != 0)
        {
            oddNumbers.push(temp.front());
        }
        temp.pop();
    }

    while (!oddNumbers.empty())
    {
        cout << oddNumbers.front() << " ";
        oddNumbers.pop();
    }

    cout << endl;

    return 0;
}
