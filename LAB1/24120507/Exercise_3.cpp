#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<ctype.h>
#include<fstream>

using namespace std;

string s;

bool isword(char c) {
    return isalpha(c) | isdigit(c);
}

void normalize(string &s) {
    string t = s;
    s = "";
    bool start = false;
    int i = 0 , j = (int) t.size() - 1;
    for ( ; j >= 0; j--) 
        if(isword(t[j]) || ispunct(t[j])) break;
    for (; i <= j; i++) if(!isspace(t[i])) break;
    for (; i <= j; i++) {
        if(isword(t[i])) s += t[i];
        if(ispunct(t[i])) {
            if(isspace(t[i + 1])) s += t[i];
            else {
                s += t[i];
                if(i != j) s += ' ';
            }
        }
        if(isspace(t[i]) && !isspace(t[i + 1]) && !ispunct(t[i + 1])) s += t[i];
    }
}

int count_word(string s) {
    int cnt = 0;
    for (int i = 0; i < (int) s.size(); i++) {
        if(!i || (isword(s[i]) && isspace(s[i - 1])))
            cnt++;
    }
    return cnt;
}

string longest_word(string s) {
    string ans = "" , tmp = "";
    for (char x : s) {
        if(isword(x)) tmp += x;
        else {
            if((int) tmp.size() > (int) ans.size())
                ans = tmp;
            tmp = "";
        }
    }
    return ans;
}

int main() {
    cin >> s;
    normalize(s);
    cout << "Normalized paragraph:" << "\n";
    cout << s << "\n";
    cout << "Word count: " << count_word(s) << "\n";
    cout << "Longest word: " << longest_word << "\n";
}