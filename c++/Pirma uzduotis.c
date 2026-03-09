#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    int pasirinkimas;
    int valiuta;
    int kryptis;
    double kiekis;
    double rezultatas;

    // Valiut¯ kursai
    double GBP_Bendras   = 0.8729;
    double GBP_Pirkti    = 0.8600;
    double GBP_Parduoti  = 0.9220;

    double USD_Bendras   = 1.1793;
    double USD_Pirkti    = 1.1460;
    double USD_Parduoti  = 1.2340;

    double INR_Bendras   = 104.6918;
    double INR_Pirkti    = 101.3862;
    double INR_Parduoti  = 107.8546;

    cout << "=== Valiutos keitykla ===" << endl;
    cout << "1 - Palyginti valiutos kursa" << endl;
    cout << "2 - Pirkti valiuta" << endl;
    cout << "3 - Parduoti valiuta" << endl;

    cout << "Pasirinkite veiksma: ";
    cin >> pasirinkimas;

    cout << "\nPasirinkite valiuta:" << endl;
    cout << "1 - GBP" << endl;
    cout << "2 - USD" << endl;
    cout << "3 - INR" << endl;

    cin >> valiuta;

    if (pasirinkimas == 1) {

        cout << "\nPasirinkite konvertavim‡:" << endl;
        cout << "1 - EUR -> Pasirinkta valiuta" << endl;
        cout << "2 - Pasirinkta valiuta -> EUR" << endl;

        cin >> kryptis;

        if (kryptis == 1) {

            if (valiuta == 1)
                cout << "1 EUR = " << GBP_Bendras << " GBP" << endl;
            else if (valiuta == 2)
                cout << "1 EUR = " << USD_Bendras << " USD" << endl;
            else if (valiuta == 3)
                cout << "1 EUR = " << INR_Bendras << " INR" << endl;

        }
        else if (kryptis == 2) {

            if (valiuta == 1)
                cout << "1 GBP = " << 1 / GBP_Bendras << " EUR" << endl;
            else if (valiuta == 2)
                cout << "1 USD = " << 1 / USD_Bendras << " EUR" << endl;
            else if (valiuta == 3)
                cout << "1 INR = " << 1 / INR_Bendras << " EUR" << endl;

        }

    }

    else if (pasirinkimas == 2) {

        cout << "Iveskite EUR kiek· u˛ kur· norite pirkti pasirinktos valiutos: ";
        cin >> kiekis;

        if (valiuta == 1)
            rezultatas = kiekis * GBP_Pirkti;
        else if (valiuta == 2)
            rezultatas = kiekis * USD_Pirkti;
        else if (valiuta == 3)
            rezultatas = kiekis * INR_Pirkti;

        cout << fixed << setprecision(2);
        cout << "Jus gausite: " << rezultatas << endl;

    }

    else if (pasirinkimas == 3) {

        cout << "Iveskite kiek pasirinktos valiutos norite parduoti: ";
        cin >> kiekis;

        if (valiuta == 1)
            rezultatas = kiekis / GBP_Parduoti;
        else if (valiuta == 2)
            rezultatas = kiekis / USD_Parduoti;
        else if (valiuta == 3)
            rezultatas = kiekis / INR_Parduoti;

        cout << fixed << setprecision(2);
        cout << "Jus gausite: " << rezultatas << " EUR" << endl;

    }

    else {
        cout << "Neteisingas pasirinkimas." << endl;
    }

    return 0;
}