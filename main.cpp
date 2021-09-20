#include <iostream>
#include "Method.h"

using namespace std;
int main() {
    Set S1;
    Set S2;
    S1 = S1 + 2 + 3 + 4 + 5 + 1;
    cout << S1;
    S1 = S1/2;
    cout << S1;
    S2 = S2 + 5 + 4;
    S2 = S1 / S2;
    cout << S2;

    Sieve(16);

    return 0;
}
