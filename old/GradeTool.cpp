#include <iostream>
#include <list>
using namespace std;

void GradeTool()
{
    int grades[20];
    int i = 0;
    int x;
    int a = 0, b = 0, c = 0, d = 0, f = 0;
    float sum = 0, avg;

    cout << "Enter your grades, followed by '-1' to end grading\n";

    while (i < 20)
    {
        cin >> x;
        if (x == -1)
            break;
        grades[i] = x;
        i++;
    }

    cout << "Grades: ";

    for (int ii = 0; ii < i; ii++)
    {
        int g = grades[ii];
        cout << g << " ";
        if (g >= 90)
            a++;
        else if (g >= 80)
            b++;
        else if (g >= 70)
            c++;
        else if (g >= 60)
            d++;
        else
            f++;
        sum += g;
    }
    cout << "\n";

    avg = sum / i;

    cout << "'A' Students: " << a << "\n";
    cout << "'B' Students: " << b << "\n";
    cout << "'C' Students: " << c << "\n";
    cout << "'D' Students: " << d << "\n";
    cout << "'F' Students: " << f << "\n";

    cout << "Class Average: " << avg << "\n";
}