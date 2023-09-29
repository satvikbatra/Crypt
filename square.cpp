#include <iostream>
#include <vector>
using namespace std;

int sqrt(int n) {
    int start = 0;
    int end = n - 1;
    int ans;
    long long mid = start + (end - start)/2;

    while(start <= end) {
        if(mid*mid > n) {
            end = mid - 1;
        }
        else {
            ans = mid;
            start = mid + 1;
        }
        mid = start + (end - start)/2;
    }
    return ans;
}

vector<vector<int>> storeInSquare(const vector<int>& bin) {
    int size = sqrt(bin.size()) + 1;
    vector<vector<int>> vect(size, vector<int>(size,0));

    int index = 0;
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            vect[i][j] = bin[index];
            index++;
        }
    }
    return vect;
}


vector<vector<int>> encryptBySquare(const vector<vector<int>>& square, int angle) {
    
}