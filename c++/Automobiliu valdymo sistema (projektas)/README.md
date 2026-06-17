# Automobiliu duomenu valdymo sistema

## Projekto tikslas

Sio projekto tikslas yra sukurti C++  programa, kuri leidzia valdyti automobiliu duomenis. Programa sukurta taikant strukturinio programavimo principus: naudojamos funkcijos, salyginiai sakiniai, ciklai, struktura `struct`, duomenu kolekcija `vector`, duomenu nuskaitymas is tekstinio failo ir duomenu issaugojimas i tekstini faila.

## Projekto tema

Pasirinkta projekto tema - automobiliu duomenu valdymo sistema.

Programa leidzia saugoti ir tvarkyti automobiliu informacija:

- ID numeri;
- marke;
- modeli;
- pagaminimo metus;
- kaina;
- kuro tipa.

Duomenys saugomi tekstiniame faile `automobiliai.txt`, naudojant kabliataski `;` kaip duomenu skyrikli.

## Programos funkcionalumas

Programa veikia per konsolini meniu. Vartotojas gali pasirinkti norima veiksma ivesdamas atitinkama meniu punkto numeri.

Programoje igyvendintos visos CRUD operacijos:

### Create - naujo automobilio pridejimas

Vartotojas gali prideti nauja automobili. Programa automatiskai priskiria nauja ID numeri ir leidzia ivesti automobilio marke, modeli, metus, kaina ir kuro tipa.

### Read - automobiliu perziura

Vartotojas gali perziureti visus automobilius, esancius sarase. Programa isveda kiekvieno automobilio informacija i ekrana.

### Update - automobilio redagavimas

Vartotojas gali redaguoti esama automobili pagal jo ID numeri. Suradus automobili, galima pakeisti jo marke, modeli, metus, kaina ir kuro tipa.

### Delete - automobilio istrynimas

Vartotojas gali istrinti automobili pagal jo ID numeri. Jei automobilis su tokiu ID randamas, jis pasalinamas is saraso.

## Papildomos funkcijos

Programoje igyvendintos dvi papildomos duomenu apdorojimo funkcijos:

### Paieska pagal marke

Vartotojas gali ivesti automobilio marke, o programa parodo visus automobilius, kuriu marke sutampa su ivesta reiksme.

### Rikiavimas pagal kaina

Programa gali surikiuoti automobilius pagal kaina nuo maziausios iki didziausios.

## Naudojami failai

Projekte naudojami sie failai:

### `main.cpp`

Pagrindinis programos failas. Jame yra visa programos logika:

- automobilio struktura `Automobilis`;
- meniu funkcija;
- duomenu nuskaitymo is failo funkcija;
- duomenu issaugojimo i faila funkcija;
- automobiliu pridejimo funkcija;
- automobiliu perziuros funkcija;
- automobiliu redagavimo funkcija;
- automobiliu istrynimo funkcija;
- paieskos pagal marke funkcija;
- rikiavimo pagal kaina funkcija.

### `automobiliai.txt`

Tekstinis duomenu failas, kuriame saugomi automobiliu irasai.

Duomenu formatas:

```text
id;marke;modelis;metai;kaina;kuroTipas
```

Pavyzdys:

```text
1;Toyota;Corolla;2018;9500;Benzinas
2;BMW;320;2016;12500;Dyzelinas
3;Tesla;Model3;2021;28000;Elektra
```

Pradiniame duomenu faile turi buti ne maziau kaip 15 automobiliu irasu.

## Programos paleidimo instrukcija

1. Atsisiuskite arba nukopijuokite projekto failus.
2. Isitikinkite, kad tame paciame aplanke yra failai:
   - `main.cpp`;
   - `automobiliai.txt`;
   - `README.md`.
3. Sukompiliuokite programa naudodami C++ kompiliatoriu.

Pavyzdys naudojant `g++`:

```bash
g++ main.cpp -o automobiliai
```

4. Paleiskite programa.

Windows sistemoje:

```bash
automobiliai.exe
```

Linux arba macOS sistemoje:

```bash
./automobiliai
```

5. Programai pasileidus, pasirinkite norima veiksma is meniu.

## Meniu punktai

Programa pateikia toki meniu:

```text
1. Rodyti visus automobilius
2. Prideti automobili
3. Redaguoti automobili
4. Istrinti automobili
5. Ieskoti automobilio pagal marke
6. Rikiuoti automobilius pagal kaina
7. Issaugoti ir iseiti
```

Pasirinkus 7 punkta, programa issaugo pakeistus duomenis i faila `automobiliai.txt` ir baigia darba.

## Naudojamos programavimo konstrukcijos

Projekte naudojamos sios C++ programavimo konstrukcijos:

- kintamieji ir pagrindiniai duomenu tipai;
- `struct` duomenu struktura;
- `vector` duomenu kolekcija;
- salyginiai sakiniai `if`, `else`;
- pasirinkimo sakinys `switch`;
- ciklai `for` ir `do-while`;
- funkcijos;
- failu skaitymas naudojant `ifstream`;
- failu rasymas naudojant `ofstream`;
- duomenu skaidymas naudojant `stringstream`;
- rikiavimas naudojant `sort`.

## Projekto struktura

```text
AutomobiliuDuomenuValdymas/

 main.cpp
 automobiliai.txt
 README.md
```

## Testavimo pavyzdys

Norint patikrinti, ar programa veikia teisingai, galima atlikti siuos veiksmus:

1. Paleisti programa.
2. Pasirinkti `1`, kad butu parodyti visi automobiliai.
3. Pasirinkti `2` ir prideti nauja automobili.
4. Pasirinkti `1` ir patikrinti, ar naujas automobilis atsirado sarase.
5. Pasirinkti `3` ir paredaguoti automobili pagal ID.
6. Pasirinkti `4` ir istrinti automobili pagal ID.
7. Pasirinkti `5` ir atlikti paieska pagal marke.
8. Pasirinkti `6` ir surikiuoti automobilius pagal kaina.
9. Pasirinkti `7`, kad duomenys butu issaugoti i faila.

## Isvada

Sis projektas leidzia praktiskai pritaikyti strukturinio programavimo principus C++ kalboje. Programa suteikia galimybe valdyti automobiliu duomenis, atlikti CRUD operacijas, ieskoti automobiliu pagal marke, rikiuoti automobilius pagal kaina ir saugoti duomenis tekstiniame faile.
