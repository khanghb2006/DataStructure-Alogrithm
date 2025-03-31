#include<iostream>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<vector>

using namespace std;

int n;
int cnt;
int a[15];
bool bit[15];
vector<string>sub;

void subset(int id , string s) {
    if(id == n) {
        s += '}';
        sub.push_back(s);
        return;
    }
    subset(id + 1 , s);
    if((int) s.size() != 1) s += ',';
    s += (a[id] + '0');
    subset(id + 1 , s);
    return;
}

bool cmp(string x , string y) {
    if((int) x.size() != (int) y.size())
        return (int) x.size() < (int) y.size();
    for (int i = 0; i < (int) x.size(); i++)
        if(x[i] != y[i]) return x[i] < y[i];
    return true;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
//    for (int i = 0; i < n; i++)
//        for (int j = i + 1; j < n; j++)
//            if(a[i] > a[j]) swap(a[i] , a[j]);
    subset(0 , "{");
    for (int i = 0; i < (int) sub.size(); i++)
    for (int j = i + 1; j < (int) sub.size(); j++)
        if(cmp(sub[j] , sub[i])) swap(sub[i] , sub[j]);
    for (auto it : sub) cout << it << "\n";
    return 0;
}
