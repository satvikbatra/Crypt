#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// convert string or data to binary
string binary(string str) {
    string bin = "";
    for(int i = 0; i < str.size(); i++) {
        int val = int(str[i]);
        
        while(val > 0) {
            (val % 2)? bin.push_back('1') : bin.push_back('0');
            val /= 2;
        }
        reverse(bin.begin(), bin.end());
    }
    return bin;
}

int main() {
    string str;
    str = "HI THIS IS SATVIK BATRA";

    string bin = binary(str);
    char arr[bin.length()];
    for(int i = 0; i < bin.length(); i++) {
        arr[i] = bin[i];
    }

    cout << sizeof(arr)/sizeof(arr[0]) << endl;
    cout << bin << endl;
}