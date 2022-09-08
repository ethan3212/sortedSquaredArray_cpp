#include <iostream>
#include <vector>
using namespace std;

// O(nLog(n)) time | O(n) space
vector<int> sortedSquaredArraySort(vector<int> array) {
    vector<int> squaredNumbers(array.size());// O(n) space
    for(int i = 0; i < array.size(); i++) {// O(n) time
        squaredNumbers[i] = array[i] * array[i];
    }
    sort(squaredNumbers.begin(), squaredNumbers.end());// O(nLog(n)) time
    return squaredNumbers;
}

// O(n) time | O(n) space
vector<int> sortedSquaredArrayReverseFill(vector<int> array) {
    vector<int> squaredNumbers(array.size());// O(n) space
    int left = 0;
    int right = array.size() - 1;
    for(int i = array.size() - 1; i >= 0; i--) {// O(n) time
        if(abs(array[left]) > abs(array[right])) {
            squaredNumbers[i] = array[left] * array[left];
            left++;
        } else {
            squaredNumbers[i] = array[right] * array[right];
            right--;
        }
    }
    return squaredNumbers;
}

int main() {
    vector<int> input = {1, 2, 3, 5, 6, 8, 9};
    vector<int> sort = sortedSquaredArraySort(input);
    vector<int> reverse = sortedSquaredArrayReverseFill(input);
    for(int element : sort) {
        cout << element << " ";
    }
    cout << " " << endl;
    for(int element : reverse) {
        cout << element << " ";
    }
    return 0;
}