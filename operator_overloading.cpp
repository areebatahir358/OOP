#include <iostream>
using namespace std;

class fraction
{
private:
    float numerator;
    float denominator;

public:
    // Default constructor
    fraction() : numerator(0.0), denominator(1.0) {}

    // Parameterized constructor
    fraction(float n, float d) : numerator(n), denominator(d) {}

    // Copy constructor
    fraction(const fraction &obj) : numerator(obj.numerator), denominator(obj.denominator) {}

    // Setters and Getters
    void set_datamembers(float n, float d)
    {
        numerator = n;
        denominator = d;
    }

    float get_numerator() const { return numerator; }
    float get_denominator() const { return denominator; }

    // Operator Overloads (+, -, *, /)
    fraction operator+(const fraction &obj2)
    {
        return fraction(numerator + obj2.numerator, denominator + obj2.denominator);
    }

    fraction operator-(const fraction &obj2)
    {
        return fraction(numerator - obj2.numerator, denominator - obj2.denominator);
    }

    fraction operator*(const fraction &obj2)
    {
        return fraction(numerator * obj2.numerator, denominator * obj2.denominator);
    }

    fraction operator/(const fraction &obj2)
    {
        if (obj2.numerator == 0 || obj2.denominator == 0)
        {
            throw invalid_argument("Cannot divide by zero.");
        }
        return fraction(numerator / obj2.numerator, denominator / obj2.denominator);
    }

    // Display Method
    void display() const
    {
        cout << numerator << "/" << denominator << endl;
    }

    // Overload << operator (output)
    friend ostream& operator<<(ostream &o, const fraction &obj)
    {
        o << obj.numerator << "/" << obj.denominator;
        return o;
    }

    // Overload >> operator (input)
    friend istream& operator>>(istream &i, fraction &obj)
    {
        cout << "Enter numerator: ";
        i >> obj.numerator;
        cout << "Enter denominator: ";
        i >> obj.denominator;
        return i;
    }
};

// Main Function with Menu
int main()
{
    fraction obj1, obj2, result;
    int choice;
    do
    {
        cout << "\nMenu:\n";
        cout << "1. Input fractions\n";
        cout << "2. Add fractions\n";
        cout << "3. Subtract fractions\n";
        cout << "4. Multiply fractions\n";
        cout << "5. Divide fractions\n";
        cout << "6. Display fractions\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cin >> obj1;
            cin >> obj2;
            break;
        case 2:
            result = obj1 + obj2;
            cout << "Sum: " << result << endl;
            break;
        case 3:
            result = obj1 - obj2;
            cout << "Difference: " << result << endl;
            break;
        case 4:
            result = obj1 * obj2;
            cout << "Product: " << result << endl;
            break;
        case 5:
            try
            {
                result = obj1 / obj2;
                cout << "Division: " << result << endl;
            }
            catch (const invalid_argument &e)
            {
                cout << e.what() << endl;
            }
            break;
        case 6:
            cout << "First Fraction: ";
            obj1.display();
            cout << "Second Fraction: ";
            obj2.display();
            break;
        case 7:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 7);

    return 0;
}
