#include<iostream>
#include<string.h>

using namespace std;

string s;

bool isPallin(int l , int r) {
    if(l > r) return true;
    return (s[l] == s[r]) * isPallin(l + 1 , r - 1);
} 

int main() {
    cin >> s;
    if(isPallin(0 , (int) s.size() - 1)) cout << "Yes" << "\n";
    else cout << "No" << "\n";
}