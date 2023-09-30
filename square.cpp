#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>


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

vector<int> encryptBinaryString(const vector<vector<int>>& matrix) {
    vector <int> str;
    int size = matrix.size();
    // int index = 0;
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            str.push_back(matrix[i][j]);
            // index++;
        }
    }
    return str;
}

vector<vector<int>> encryptBySquare(const vector<vector<int>>& square) {
    int size = square.size();

    // transpose of matrix
    vector<vector<int>> transposedMatrix = square;

    for(int i = 0; i < size-1; i++) {
        for(int j = i+1; j < size; j++) {
            swap(transposedMatrix[i][j], transposedMatrix[j][i]);
        }
    }
    
    // reversed matrix
    vector<vector<int>> reversedMatrix = transposedMatrix;

    for(int i = 0; i < size; i++) {
        reverse(reversedMatrix[i].begin(), reversedMatrix[i].end());
    }

    return reversedMatrix;
}