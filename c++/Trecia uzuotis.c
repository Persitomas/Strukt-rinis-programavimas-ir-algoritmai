#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;

const int MAX_ITEMS = 20;
const double PVM = 0.21;

struct menuItemType {
    string menuItem;
    double menuPrice;
};

void getData(menuItemType menuList[], int &menuSize);
void showMenu(menuItemType menuList[], int menuSize);
void printCheck(menuItemType menuList[], int orderQty[], int menuSize);

int main() {
    menuItemType menuList[MAX_ITEMS];
    int orderQty[MAX_ITEMS];
    int menuSize = 0;

    for (int i = 0; i < MAX_ITEMS; i++) {
        orderQty[i] = 0;
    }

    getData(menuList, menuSize);

    if (menuSize == 0) {
        cout << "Meniu failas nerastas arba tuscias." << endl;
        return 0;
    }

    showMenu(menuList, menuSize);

    int pasirinkimas;
    int kiekis;

    cout << endl;
    cout << "Iveskite patiekalo numeri. Jei norite baigti, iveskite 0." << endl;

    do {
        cout << "Patiekalo numeris: ";
        cin >> pasirinkimas;

        if (pasirinkimas > 0 && pasirinkimas <= menuSize) {
            cout << "Kiek porciju norite? ";
            cin >> kiekis;

            if (kiekis > 0) {
                orderQty[pasirinkimas - 1] = orderQty[pasirinkimas - 1] + kiekis;
            } else {
                cout << "Kiekis turi buti didesnis uz 0." << endl;
            }
        } else if (pasirinkimas != 0) {
            cout << "Tokio patiekalo numerio nera." << endl;
        }

    } while (pasirinkimas != 0);

    printCheck(menuList, orderQty, menuSize);

    return 0;
}

void getData(menuItemType menuList[], int &menuSize) {
    ifstream fin("menu.txt");

    if (!fin) {
        cout << "Nepavyko atidaryti menu.txt failo." << endl;
        return;
    }

    string line;

    while (getline(fin, line) && menuSize < MAX_ITEMS) {
        int tabPos = line.find_last_of('\t');

        if (tabPos != -1) {
            menuList[menuSize].menuItem = line.substr(0, tabPos);

            string priceText = line.substr(tabPos + 1);
            menuList[menuSize].menuPrice = atof(priceText.c_str());

            menuSize++;
        }
    }

    fin.close();
}

void showMenu(menuItemType menuList[], int menuSize) {
    cout << fixed << setprecision(2);

    cout << "Sveiki atvyke i restorana \"Pavadinimas\"" << endl;
    cout << endl;
    cout << "Pusryciu meniu:" << endl;
    cout << endl;

    for (int i = 0; i < menuSize; i++) {
        cout << setw(2) << i + 1 << ". ";
        cout << left << setw(45) << menuList[i].menuItem;
        cout << right << setw(6) << menuList[i].menuPrice << " EUR" << endl;
    }

    cout << endl;
    cout << "Pasirinkite patiekalo numeri ir nurodykite porciju kieki." << endl;
    cout << "Galite pasirinkti kelis skirtingus patiekalus." << endl;
    cout << "Ta pati patiekala galima pasirinkti kelis kartus." << endl;
}

void printCheck(menuItemType menuList[], int orderQty[], int menuSize) {
    ofstream fout("receipt.txt");

    double sumaBePVM = 0;
    double mokesciai;
    double galutineSuma;

    for (int i = 0; i < menuSize; i++) {
        sumaBePVM = sumaBePVM + orderQty[i] * menuList[i].menuPrice;
    }

    mokesciai = sumaBePVM * PVM;
    galutineSuma = sumaBePVM + mokesciai;

    cout << endl;
    cout << fixed << setprecision(2);

    cout << "Sveiki atvyke i restorana \"Pavadinimas\"" << endl;
    cout << endl;

    fout << fixed << setprecision(2);
    fout << "Sveiki atvyke i restorana \"Pavadinimas\"" << endl;
    fout << endl;

    for (int i = 0; i < menuSize; i++) {
        if (orderQty[i] > 0) {
            double eilutesSuma = orderQty[i] * menuList[i].menuPrice;

            cout << left << setw(3) << orderQty[i];
            cout << left << setw(45) << menuList[i].menuItem;
            cout << right << setw(7) << eilutesSuma << " EUR" << endl;

            fout << left << setw(3) << orderQty[i];
            fout << left << setw(45) << menuList[i].menuItem;
            fout << right << setw(7) << eilutesSuma << " EUR" << endl;
        }
    }

    cout << endl;
    cout << left << setw(48) << "Mokesciai (21%)";
    cout << right << setw(7) << mokesciai << " EUR" << endl;

    cout << left << setw(48) << "Galutine suma";
    cout << right << setw(7) << galutineSuma << " EUR" << endl;

    fout << endl;
    fout << left << setw(48) << "Mokesciai (21%)";
    fout << right << setw(7) << mokesciai << " EUR" << endl;

    fout << left << setw(48) << "Galutine suma";
    fout << right << setw(7) << galutineSuma << " EUR" << endl;

    fout.close();

    cout << endl;
    cout << "Saskaita issaugota faile receipt.txt" << endl;
}