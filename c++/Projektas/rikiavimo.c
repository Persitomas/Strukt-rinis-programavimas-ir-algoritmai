#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

using namespace std;

// Funkcija sujungia dvi surikiuotas masyvo dalis
void merge(vector<int>& arr, int left, int mid, int right,
long long& comparisons, long long& moves) {
vector<int> temp;

int i = left; // Kairės dalies pradžia
int j = mid + 1; // Dešinės dalies pradžia

// Lyginame abiejų dalių elementus ir dedame mažesnį į laikiną masyvą
while (i <= mid && j <= right) {
comparisons++;

if (arr[i] <= arr[j]) {
temp.push_back(arr[i]);
i++;
} else {
temp.push_back(arr[j]);
j++;
}

moves++;
}

// Jeigu kairėje dalyje dar liko elementų, juos perkeliame
while (i <= mid) {
temp.push_back(arr[i]);
i++;
moves++;
}

// Jeigu dešinėje dalyje dar liko elementų, juos perkeliame
while (j <= right) {
temp.push_back(arr[j]);
j++;
moves++;
}

// Laikino masyvo reikšmes perkeliame atgal į pagrindinį masyvą
for (int k = 0; k < temp.size(); k++) {
arr[left + k] = temp[k];
}
}

// Rekursinė suliejimo rikiavimo funkcija
void mergeSort(vector<int>& arr, int left, int right,
long long& comparisons, long long& moves) {
if (left < right) {
int mid = (left + right) / 2;

mergeSort(arr, left, mid, comparisons, moves);
mergeSort(arr, mid + 1, right, comparisons, moves);

merge(arr, left, mid, right, comparisons, moves);
}
}

int main() {
vector<int> data;
int number;

// Atidaromas duomenų failas
ifstream inputFile("nesurikiuoti_5000.txt");

if (!inputFile) {
cout << "Nepavyko atidaryti failo nesurikiuoti_5000.txt" << endl;
return 1;
}

// Skaičiai nuskaitomi iš failo į vektorių
while (inputFile >> number) {
data.push_back(number);
}

inputFile.close();

long long comparisons = 0;
long long moves = 0;

// Laikas pradedamas matuoti tik prieš rikiavimą
auto start = chrono::high_resolution_clock::now();

mergeSort(data, 0, data.size() - 1, comparisons, moves);

// Laikas sustabdomas iškart po rikiavimo
auto end = chrono::high_resolution_clock::now();

auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

// Surikiuoti duomenys išsaugomi į rezultatų failą
ofstream outputFile("suliejimo_rezultatas.txt");

for (int value : data) {
outputFile << value << endl;
}

outputFile.close();

cout << "Failas surikiuotas suliejimo rikiavimu." << endl;
cout << "Rikiavimo laikas: " << duration.count() << " mikrosekundes" << endl;
cout << "Palyginimu skaicius: " << comparisons << endl;
cout << "Perkelimu skaicius: " << moves << endl;

return 0;
}