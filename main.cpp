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

string binaryToString(const vector<int>& vect) {
    string str = "";

    for (size_t i = 0; i < vect.size(); i += 8) {
        int asciiValue = 0;
        for (size_t j = 0; j < 8; j++) {
            asciiValue <<= 1;
            asciiValue |= (str[i + j] - '0');
        }
        str += static_cast<char>(asciiValue);
    }
 
    return str;
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
    // cout << "Original Matrix: " << endl;
    // for(int i = 0; i < size; i++) {
    //     for(int j = 0; j < size; j++) {
    //         cout << square[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    // int angle = 30;

    vector<vector<int>> encryptSquare = encryptBySquare(square);
    
    // cout << "Rotated Matrix: " << endl;
    // for(int i = 0; i < size; i++) {
    //     for(int j = 0; j < size; j++) {
    //         cout << encryptSquare[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    // cout << encryptSquare.size() << endl;
    vector<int> encryptStringBin = encryptBinaryString(encryptSquare);
    // for(int i : encryptStringBin) {
    //     cout << i;
    // }
    // cout << endl;

    string encryptString = binaryToString(encryptStringBin);
    cout << encryptString << endl;
    
}
