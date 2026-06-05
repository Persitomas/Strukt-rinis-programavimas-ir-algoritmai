#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

using namespace std;

void insertionSort(vector<int>& arr, long long& comparisons, long long& swaps) {
for (int i = 1; i < arr.size(); i++) {
int key = arr[i];
int j = i - 1;

while (j >= 0) {
comparisons++;

if (arr[j] > key) {
arr[j + 1] = arr[j];
swaps++;
j--;
} else {
break;
}
}

arr[j + 1] = key;
}
}

int main() {
vector<int> data;
int number;

ifstream inputFile("nesurikiuoti_5000.txt");

if (!inputFile) {
cout << "Nepavyko atidaryti failo nesurikiuoti_5000.txt" << endl;
return 1;
}

while (inputFile >> number) {
data.push_back(number);
}

inputFile.close();

long long comparisons = 0;
long long swaps = 0;

auto start = chrono::high_resolution_clock::now();

insertionSort(data, comparisons, swaps);

auto end = chrono::high_resolution_clock::now();

auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

ofstream outputFile("surikiuotas_rezultatas.txt");

for (int value : data) {
outputFile << value << endl;
}

outputFile.close();

cout << "Failas surikiuotas." << endl;
cout << "Rikiavimo laikas: " << duration.count() << " mikrosekundes" << endl;
cout << "Palyginimu skaicius: " << comparisons << endl;
cout << "Perkelimu skaicius: " << swaps << endl;

return 0;
}