#include <bits/stdc++.h>
#include <iostream>
#include "square.cpp"

using namespace std;


vector<int> stringToBinary(const string& str) {
    vector<int> bin;

    for(int i = 0; i < str.size(); i++) {
        int character = int(str[i]);

        for(int j = 7; j >= 0; j--) {
            int bit = (character >> j) & 1;
            bin.push_back(bit);
        }
    }
    return bin;
}




int main() {
    string str;
    str = "Hi This is Satvik Batra";

    vector<int> bin = stringToBinary(str);
    // for(int i : bin) {
    //     cout << i;
    // }
    // cout << endl;
    // cout << bin.size() << endl;

    vector<vector<int>> square = storeInSquare(bin);

    // int size = sqrt(bin.size()) + 1;
    // for(int i = 0; i < size; i++) {
    //     for(int j = 0; j < size; j++) {
    //         cout << square[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    int angle = 30;

    vector<vector<int>> encryptSquare = encryptBySquare(square, angle);
    cout << square.size() << endl;
}