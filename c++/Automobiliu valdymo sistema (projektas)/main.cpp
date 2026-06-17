// Bibliotekos, reikalingos programos veikimui
#include <iostream>     // Naudojama cin ir cout darbui su konsole
#include <fstream>      // Naudojama failų nuskaitymui ir įrašymui
#include <sstream>      // Naudojama teksto eilutės skaidymui pagal skyriklį
#include <string>       // Naudojama string tipo kintamiesiems
#include <algorithm>    // Naudojama sort funkcijai
#include <vector>       // Naudojama vector duomenų kolekcijai

using namespace std;


// Struktūra, aprašanti vieną automobilį
// Čia saugomi visi vieno automobilio duomenys
struct Automobilis {
    int id;
    string marke;
    string modelis;
    int metai;
    double kaina;
    string kuroTipas;
};


// Funkcija, kuri išveda pagrindinį programos meniu
// Ji tik parodo pasirinkimus, bet pati neatlieka veiksmų
void rodytiMeniu() {
    cout << endl;
    cout << "===== Automobiliu duomenu valdymo sistema =====" << endl;
    cout << "1. Rodyti visus automobilius" << endl;
    cout << "2. Prideti automobili" << endl;
    cout << "3. Redaguoti automobili" << endl;
    cout << "4. Istrinti automobili" << endl;
    cout << "5. Ieskoti automobilio pagal marke" << endl;
    cout << "6. Rikiuoti automobilius pagal kaina" << endl;
    cout << "7. Issaugoti ir iseiti" << endl;
    cout << "Pasirinkite veiksma: ";
}


// Funkcija, kuri parodo visus automobilius iš vector sąrašo
// const vector<Automobilis>& reiškia, kad sąrašas nebus kopijuojamas ir nebus keičiamas
void rodytiAutomobilius(const vector<Automobilis>& automobiliai) {
    // Tikriname, ar sąrašas nėra tuščias
    if (automobiliai.empty()) {
        cout << "Automobiliu sarasas tuscias." << endl;
        return;
    }

    cout << endl;
    cout << "===== Automobiliu sarasas =====" << endl;

    // Ciklas eina per visus automobilius sąraše
    for (int i = 0; i < automobiliai.size(); i++) {
        cout << "ID: " << automobiliai[i].id << endl;
        cout << "Marke: " << automobiliai[i].marke << endl;
        cout << "Modelis: " << automobiliai[i].modelis << endl;
        cout << "Metai: " << automobiliai[i].metai << endl;
        cout << "Kaina: " << automobiliai[i].kaina << " EUR" << endl;
        cout << "Kuro tipas: " << automobiliai[i].kuroTipas << endl;
        cout << "--------------------------" << endl;
    }
}


// Funkcija, kuri nuskaito automobilių duomenis iš tekstinio failo
// Duomenys faile turi būti formatu: id;marke;modelis;metai;kaina;kuroTipas
void nuskaitytiIsFailo(vector<Automobilis>& automobiliai, string failoPavadinimas) {
    // Atidarome failą skaitymui
    ifstream failas(failoPavadinimas);

    // Tikriname, ar failas sėkmingai atidarytas
    if (!failas) {
        cout << "Nepavyko atidaryti failo: " << failoPavadinimas << endl;
        return;
    }

    // Išvalome senus duomenis, kad nebūtų dublikatų
    automobiliai.clear();

    string eilute;

    // Skaitome failą po vieną eilutę
    while (getline(failas, eilute)) {
        stringstream ss(eilute);
        string dalis;
        Automobilis autoObj;

        // Nuskaitome ID
        getline(ss, dalis, ';');
        autoObj.id = stoi(dalis);

        // Nuskaitome markę
        getline(ss, autoObj.marke, ';');

        // Nuskaitome modelį
        getline(ss, autoObj.modelis, ';');

        // Nuskaitome metus
        getline(ss, dalis, ';');
        autoObj.metai = stoi(dalis);

        // Nuskaitome kainą
        getline(ss, dalis, ';');
        autoObj.kaina = stod(dalis);

        // Nuskaitome kuro tipą
        getline(ss, autoObj.kuroTipas, ';');

        // Pridedame nuskaitytą automobilį į vector sąrašą
        automobiliai.push_back(autoObj);
    }

    // Uždarome failą
    failas.close();

    cout << "Duomenys sekmingai nuskaityti is failo." << endl;
}


// Funkcija, kuri išsaugo visus automobilius į tekstinį failą
// Ji perrašo failą naujais duomenimis
void issaugotiIFaila(const vector<Automobilis>& automobiliai, string failoPavadinimas) {
    // Atidarome failą rašymui
    ofstream failas(failoPavadinimas);

    // Tikriname, ar failas sėkmingai atidarytas
    if (!failas) {
        cout << "Nepavyko atidaryti failo irasymui: " << failoPavadinimas << endl;
        return;
    }

    // Įrašome kiekvieną automobilį į failą
    for (int i = 0; i < automobiliai.size(); i++) {
        failas << automobiliai[i].id << ";"
               << automobiliai[i].marke << ";"
               << automobiliai[i].modelis << ";"
               << automobiliai[i].metai << ";"
               << automobiliai[i].kaina << ";"
               << automobiliai[i].kuroTipas << endl;
    }

    // Uždarome failą
    failas.close();

    cout << "Duomenys sekmingai issaugoti i faila." << endl;
}


// Funkcija, kuri randa kitą laisvą ID numerį
// Ji suranda didžiausią esamą ID ir grąžina vienetu didesnį
int gautiKitaId(const vector<Automobilis>& automobiliai) {
    int didziausiasId = 0;

    // Ieškome didžiausio ID sąraše
    for (int i = 0; i < automobiliai.size(); i++) {
        if (automobiliai[i].id > didziausiasId) {
            didziausiasId = automobiliai[i].id;
        }
    }

    return didziausiasId + 1;
}


// Funkcija, kuri prideda naują automobilį į sąrašą
// Tai yra CRUD operacija Create
void pridetiAutomobili(vector<Automobilis>& automobiliai) {
    Automobilis naujas;

    // Naujam automobiliui automatiškai priskiriamas ID
    naujas.id = gautiKitaId(automobiliai);
    cout << "Automobiliui priskirtas ID: " << naujas.id << endl;

    // Vartotojas įveda automobilio duomenis
    cout << "Iveskite marke: ";
    cin >> naujas.marke;

    cout << "Iveskite modeli: ";
    cin >> naujas.modelis;

    cout << "Iveskite metus: ";
    cin >> naujas.metai;

    cout << "Iveskite kaina: ";
    cin >> naujas.kaina;

    cout << "Iveskite kuro tipa: ";
    cin >> naujas.kuroTipas;

    // Naujas automobilis įdedamas į vector sąrašą
    automobiliai.push_back(naujas);

    cout << "Automobilis sekmingai pridetas." << endl;
}


// Funkcija, kuri redaguoja esamą automobilį pagal ID
// Tai yra CRUD operacija Update
void redaguotiAutomobili(vector<Automobilis>& automobiliai) {
    int id;
    bool rastas = false;

    cout << "Iveskite automobilio ID, kuri norite redaguoti: ";
    cin >> id;

    // Einame per visą sąrašą ir ieškome automobilio pagal ID
    for (int i = 0; i < automobiliai.size(); i++) {
        if (automobiliai[i].id == id) {
            cout << "Automobilis rastas." << endl;

            // Rodome seną reikšmę ir prašome įvesti naują
            cout << "Dabartine marke: " << automobiliai[i].marke << endl;
            cout << "Iveskite nauja marke: ";
            cin >> automobiliai[i].marke;

            cout << "Dabartinis modelis: " << automobiliai[i].modelis << endl;
            cout << "Iveskite nauja modeli: ";
            cin >> automobiliai[i].modelis;

            cout << "Dabartiniai metai: " << automobiliai[i].metai << endl;
            cout << "Iveskite naujus metus: ";
            cin >> automobiliai[i].metai;

            cout << "Dabartine kaina: " << automobiliai[i].kaina << endl;
            cout << "Iveskite nauja kaina: ";
            cin >> automobiliai[i].kaina;

            cout << "Dabartinis kuro tipas: " << automobiliai[i].kuroTipas << endl;
            cout << "Iveskite nauja kuro tipa: ";
            cin >> automobiliai[i].kuroTipas;

            cout << "Automobilio duomenys sekmingai atnaujinti." << endl;

            rastas = true;
            break;
        }
    }

    // Jei automobilis nerastas, išvedamas pranešimas
    if (!rastas) {
        cout << "Automobilis su tokiu ID nerastas." << endl;
    }
}


// Funkcija, kuri ištrina automobilį pagal ID
// Tai yra CRUD operacija Delete
void istrintiAutomobili(vector<Automobilis>& automobiliai) {
    int id;
    bool rastas = false;

    cout << "Iveskite automobilio ID, kuri norite istrinti: ";
    cin >> id;

    // Ieškome automobilio pagal ID
    for (int i = 0; i < automobiliai.size(); i++) {
        if (automobiliai[i].id == id) {
            // erase pašalina elementą iš vector pagal jo poziciją
            automobiliai.erase(automobiliai.begin() + i);

            cout << "Automobilis sekmingai istrintas." << endl;

            rastas = true;
            break;
        }
    }

    // Jei automobilis su įvestu ID nerastas
    if (!rastas) {
        cout << "Automobilis su tokiu ID nerastas." << endl;
    }
}


// Funkcija, kuri ieško automobilių pagal markę
// Tai yra papildoma funkcija Nr. 1
void ieskotiPagalMarke(const vector<Automobilis>& automobiliai) {
    string ieskomaMarke;
    bool rastas = false;

    cout << "Iveskite ieskoma marke: ";
    cin >> ieskomaMarke;

    cout << endl;
    cout << "===== Paieskos rezultatai =====" << endl;

    // Einame per visus automobilius ir tikriname markę
    for (int i = 0; i < automobiliai.size(); i++) {
        if (automobiliai[i].marke == ieskomaMarke) {
            cout << "ID: " << automobiliai[i].id << endl;
            cout << "Marke: " << automobiliai[i].marke << endl;
            cout << "Modelis: " << automobiliai[i].modelis << endl;
            cout << "Metai: " << automobiliai[i].metai << endl;
            cout << "Kaina: " << automobiliai[i].kaina << " EUR" << endl;
            cout << "Kuro tipas: " << automobiliai[i].kuroTipas << endl;
            cout << "--------------------------" << endl;

            rastas = true;
        }
    }

    // Jei nerastas nė vienas automobilis su tokia marke
    if (!rastas) {
        cout << "Automobiliu su tokia marke nerasta." << endl;
    }
}


// Pagalbinė funkcija rikiavimui pagal kainą
// Ji nurodo sort funkcijai, kuris automobilis turi eiti pirmiau
bool pagalKaina(Automobilis a, Automobilis b) {
    return a.kaina < b.kaina;
}


// Funkcija, kuri surikiuoja automobilius pagal kainą
// Tai yra papildoma funkcija Nr. 2
void rikiuotiPagalKaina(vector<Automobilis>& automobiliai) {
    sort(automobiliai.begin(), automobiliai.end(), pagalKaina);

    cout << "Automobiliai surikiuoti pagal kaina nuo maziausios iki didziausios." << endl;
}


// Pagrindinė programos funkcija
// Nuo čia prasideda programos vykdymas
int main() {
    vector<Automobilis> automobiliai;

    // Programos pradžioje nuskaitome duomenis iš failo
    nuskaitytiIsFailo(automobiliai, "automobiliai.txt");

    int pasirinkimas;

    // do-while ciklas kartoja meniu tol, kol vartotojas pasirenka 7
    do {
        rodytiMeniu();
        cin >> pasirinkimas;

        // switch tikrina, kokį meniu punktą pasirinko vartotojas
        switch (pasirinkimas) {
            case 1:
                // Rodyti visus automobilius
                rodytiAutomobilius(automobiliai);
                break;

            case 2:
                // Pridėti naują automobilį
                pridetiAutomobili(automobiliai);
                break;

            case 3:
                // Redaguoti esamą automobilį
                redaguotiAutomobili(automobiliai);
                break;

            case 4:
                // Ištrinti automobilį
                istrintiAutomobili(automobiliai);
                break;

            case 5:
                // Ieškoti automobilio pagal markę
                ieskotiPagalMarke(automobiliai);
                break;

            case 6:
                // Rikiuoti automobilius pagal kainą
                rikiuotiPagalKaina(automobiliai);
                break;

            case 7:
                // Prieš išeinant iš programos išsaugome duomenis į failą
                issaugotiIFaila(automobiliai, "automobiliai.txt");
                cout << "Programa baigia darba." << endl;
                break;

            default:
                // Jei vartotojas įveda netinkamą meniu punktą
                cout << "Neteisingas pasirinkimas. Bandykite dar karta." << endl;
        }

    } while (pasirinkimas != 7);

    return 0;
}
