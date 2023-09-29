#include <bits/stdc++.h>
#include <iostream>
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
    for(int i : bin) {
        cout << i;
    }
    cout << endl;
    
}