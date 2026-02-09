#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int rev = 0;

    while (n > 0)
    {
        int rem = n % 10;      // last digit
        rev = rev * 10 + rem; // build reverse
        n /= 10;              // remove last digit
    }

    cout << rev;

    return 0;
}
