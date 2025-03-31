#include<iostream>
#include<math.h>

using namespace std;

int n;

int sum_digit(int n) {
    if(!n) return 0;
    return (n % 10) + sum_digit(n / 10);
}

int main() {
    cin >> n;
    cout << sum_digit(n) << "\n";
}