#include <iostream>
#include <string>

using namespace std;

int main() {
    const int MAX_MOKINIAI = 100; //Negali b˚ti daugiau nei 100 mokiniu
    const int MAX_PAZYMIAI = 10; // Negali b˚ti daugiau nei 10 pazymiu mokiniui

    string vardai[MAX_MOKINIAI];
    int pazymiai[MAX_MOKINIAI][MAX_PAZYMIAI];
    int kiekiai[MAX_MOKINIAI]; // Kiek kiekvienas mokinys turi ·vest¯ pa˛ymi¯
    int mokiniuSkaicius = 0;

    int pasirinkimas;

    do {
        cout << "\n====== MOKINIU PAZYMIU SISTEMA ======\n"; //meniu
        cout << "1. Ivesti nauja mokini\n";
        cout << "2. Perziureti visus duomenis\n";
        cout << "3. Atnaujinti pazymi\n";
        cout << "4. Pasalinti mokini\n";
        cout << "0. Iseiti\n";
        cout << "Pasirinkimas: ";
        cin >> pasirinkimas;

        if (pasirinkimas == 1) {
            if (mokiniuSkaicius < MAX_MOKINIAI) {
                cout << "Iveskite varda: ";
                cin >> vardai[mokiniuSkaicius];
                cout << "Kiek pazymiu ivesite (iki 10)? ";
                cin >> kiekiai[mokiniuSkaicius];

                for (int i = 0; i < kiekiai[mokiniuSkaicius]; i++) {
                    cout << "Iveskite " << i + 1 << "-a pazymi: ";
                    cin >> pazymiai[mokiniuSkaicius][i];
                }
                mokiniuSkaicius++;
            } else {
                cout << "Sarasas pilnas!\n";
            }
        } 
        else if (pasirinkimas == 2) {
            for (int i = 0; i < mokiniuSkaicius; i++) {
                cout << i + 1 << ". " << vardai[i] << ": ";
                for (int j = 0; j < kiekiai[i]; j++) {
                    cout << pazymiai[i][j] << " ";
                }
                cout << endl;
            }
        } 
        else if (pasirinkimas == 3) {
            int mokinioIndeksas, pazymioIndeksas;
            cout << "Kurio mokinio pazymi keisite (eiles nr.)? ";
            cin >> mokinioIndeksas;
            mokinioIndeksas--; // Paverciame i masyvo indeksa

            if (mokinioIndeksas >= 0 && mokinioIndeksas < mokiniuSkaicius) {
                cout << "Kuri pazymi keisite (1-" << kiekiai[mokinioIndeksas] << ")? ";
                cin >> pazymioIndeksas;
                pazymioIndeksas--;
                
                if (pazymioIndeksas >= 0 && pazymioIndeksas < kiekiai[mokinioIndeksas]) {
                    cout << "Iveskite nauja pazymi: ";
                    cin >> pazymiai[mokinioIndeksas][pazymioIndeksas];
                }
            }
        } 
        else if (pasirinkimas == 4) {
            int mokinioIndeksas;
            cout << "Kuri mokin· pasalinti (eiles nr.)? ";
            cin >> mokinioIndeksas;
            mokinioIndeksas--;

            if (mokinioIndeksas >= 0 && mokinioIndeksas < mokiniuSkaicius) {
                // Pastumiame visus elementus per vien‡ viet‡ atgal
                for (int i = mokinioIndeksas; i < mokiniuSkaicius - 1; i++) {
                    vardai[i] = vardai[i + 1];
                    kiekiai[i] = kiekiai[i + 1];
                    for (int j = 0; j < MAX_PAZYMIAI; j++) {
                        pazymiai[i][j] = pazymiai[i + 1][j];
                    }
                }
                mokiniuSkaicius--;
                cout << "Mokinys pasalintas.\n";
            }
        }
    } while (pasirinkimas != 0); //iseiti

    return 0;
}