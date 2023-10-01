#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>


using namespace std;

int sqrt(int n) {
    int start = 0;
    int end = n - 1;
    int ans;
    long long mid;

    while(start <= end) {
        mid = start + (end - start)/2;
        if(mid * mid > n) {
            end = mid - 1;
        }
        else {
            ans = mid;
            start = mid + 1;
        }
    }
    return ans;
}

vector<vector<int>> storeInSquare(const vector<int>& bin) {

    int size = sqrt(bin.size()) + 1;

    vector<vector<int>> vect(size, vector<int>(size,0));

    int index = 0;
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if(index < bin.size()) {
                vect[i][j] = bin[index];
            index++;
            } else {
                vect[i][j] = 0;
            }
        }
    }

    return vect;
}

vector<int> encryptBinaryString(const vector<vector<int>>& matrix) {

    vector <int> str;
    int size = matrix.size();

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            str.push_back(matrix[i][j]);
        }
    }

    return str;
}

vector<vector<int>> encryptBySquare(const vector<vector<int>>& square) {
    int size = square.size();

    // transpose of matrix
    vector<vector<int>> transposedMatrix = square;

    for(int i = 0; i < size - 1; i++) {
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

vector<vector<int>> decryptBySquare(const vector<vector<int>>& square) {
    int size = square.size();

    vector<vector<int>> reversedMatrix = square;
    for(int i = 0; i < size; i++) {
        reverse(reversedMatrix[i].begin(), reversedMatrix[i].end());
    }

    vector<vector<int>> originalMatrix = reversedMatrix;

    for(int i = 0; i < size; i++) {
        for(int j = i+1; j < size; j++) {
            swap(originalMatrix[i][j], originalMatrix[j][i]);
        }
    }

    return originalMatrix;
}
