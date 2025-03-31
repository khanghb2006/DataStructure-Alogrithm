#include<iostream>
#include<math.h>
#include<fstream>

using namespace std;

bool readFile (char * filename , int * &a , int &n) {
    ifstream file(filename);
    if(!file) {
        cerr << "Cannot open this file" << "\n";
        return false;
    }
    file >> n;
    a = new int [n + 1];
    for (int i = 0; i < n; i++) 
        file >> *(a + i);
    file.close();
    return true;
}

void writeFile (char *filename , int x) {
    ofstream file(filename);
    file << x << "\n";
    file.close();
}

int LinearSearch (int *a , int n , int target) {
    int ans = -1;
    for (int i = 0; i < n; i++)
        if(*(a + i) == target) {
            ans = i;
            break;
        } 
    return ans;
}

int SearchSentinel (int *a , int n , int target) {
    a[n] = target;
    int i = 0;
    while(*(a + i) != target) i++;
    return (i < n ? i : -1);
}

int BinarySearch (int *a , int n , int target) {
    pair<int , int> val[n];
    for (int i = 0; i < n; i++)
        val[i] = make_pair(*(a + i) , i);

    auto cmp = [&] (pair<int,int> x , pair<int , int> y) -> bool {
        if(x.first != y.first) return x.first < y.first;
        return x.second < y.second;
    };

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if(cmp(val[i] , val[j])) swap(val[i] , val[j]);

    int lo = 0 , hi = n - 1 , ans = -1;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;
        if(val[mid].first <= target) {
            if(val[mid].first == target) ans = val[mid].second;
            hi = mid - 1;
        }else lo = mid + 1;
    }
    return ans;
}

int InterpolationSearch (int *a , int n , int target) {
    pair<int , int> val[n];
    for (int i = 0; i < n; i++)
        val[i] = make_pair(*(a + i) , i);

    auto cmp = [&] (pair<int,int> x , pair<int , int> y) -> bool {
        if(x.first != y.first) return x.first < y.first;
        return x.second < y.second;
    };

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if(cmp(val[i] , val[j])) swap(val[i] , val[j]);

    int lo = 0 , hi = n - 1, ans = -1;
    while(lo <= hi) {
        int mid = (val[hi].first - val[lo].first) / (hi - lo + 1);
        if(val[mid].first <= target) {
            if(val[mid].first == target) ans = val[mid].second;
            lo = mid - 1;
        }else lo = mid + 1;
    }
    return ans;
}

int main(int argc , char ** argv) {
    int ans = 0;
    int *a , n;
    if(!readFile (argv[3] , a , n)) {
        return 0;
    }
    if(atoi(argv[1]) == 1) ans = LinearSearch (a , n , atoi(argv[2]));
    if(atoi(argv[1]) == 2) ans = SearchSentinel (a , n , atoi(argv[2]));
    if(atoi(argv[1]) == 3) ans = BinarySearch (a , n , atoi(argv[2]));
    if(atoi(argv[1]) == 4) ans = SearchSentinel (a , n , atoi(argv[2]));
    writeFile (argv[4] , ans);
    return 0;
}