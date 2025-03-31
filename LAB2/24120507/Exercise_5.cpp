#include<iostream>
#include<string.h>

using namespace std;

string s;

string Reverse(int id) {
    if(id < 0) return "";
    return s[id] + Reverse(id - 1);
}

int main() {
    cin >> s;
    cout << Reverse((int) s.size() - 1) << "\n";
}