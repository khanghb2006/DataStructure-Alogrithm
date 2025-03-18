#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

void Input_Array(int * &arr , int n) {
    cout << "Enter the array" << " ";
    for (int i = 0 ; i < n; i++)
        cin >> *(arr + i);
    return;
}

void Print_Array(int *arr , int n) {
    cout << "Print the array" << " ";
    for (int i = 0; i < n; i++)
        cout << *(arr + i) << " ";
    cout << '\n';
    return;
}

int findMax(int *arr , int n) {
    int max_value = -1e9;
    for (int i = 0; i < n; i++)
        max_value = max(max_value , *(arr + i));
    return max_value;
}

int sumArray(int *arr , int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += *(arr + i);
    return sum;
}


void concatArrays(int *a , int na , int *b , int nb , int * &res , int &nres) {
    nres = na + nb;
    int j = 0;
    for (int i = 0; i < na; i++)
        res[j++] = a[i];
    for (int i = 0; i < nb; i++)
        res[j++] = b[i];
    return;
}

void findLongestAscendingSubarray(int *arr , int n , int * &res , int &nres) {
    int i = 0 , j = 0;
    nres = 0;
    while(i < n) {
        while ((j == 0 || arr[j - 1] < arr[j]) && j < n){
            if(nres < (j - i + 1)) {
                nres = j - i + 1;
                res = (arr + i);
            }
            j++;
        }
        i = j;
    }
}

int main() {
    int na , nb , nc , nres;
    cout << "Enter the number of elements in array a ";
    cin >> na;
    int *a = new int [na];
    Input_Array(a , na);
    cout << "Enter the number of elements in array b ";
    cin >> nb;
    int *b = new int[nb];
    Input_Array(b , nb);
    int *c = new int[na + nb];
    concatArrays(a , na , b , nb , c , nc);
    Print_Array(c , nc);
    cout << "Maximum value in the array c is " << findMax(c , nc) << "\n";
    cout << "The sum of elements in array c is " << sumArray(c , nc) << "\n";
    int *res = nullptr;
    findLongestAscendingSubarray(c , nc , res , nres);
    cout << "The longest ascending subarray in the array c is ";
    for (int i = 0; i < nres ; i++) cout << *(res + i) << " ";
    return 0;
}
