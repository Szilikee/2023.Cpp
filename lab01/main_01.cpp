#include <iostream>
#include <cmath>
#include <sstream>
#include <fstream>

using namespace std;

int countbits(int szam) {
    int count = 0;
    int i;
    cout << "8-bites szamjegyei a  " << szam << " szamnak: ";
    for (i = 1 << 7; i > 0; i = i / 2) {
        (szam & i) ? cout << "1" : cout << "0";
    }
    while (szam) {
        count++;
        szam >>= 1;
    }
    cout << count;
}


double mean(double array[], int numElements) {
    if (numElements == 0) {
        return NAN;
    }
    double count = 0;
    double atlag;
    for (int i = 0; i < numElements; ++i) {
        count += array[i];
        atlag = count / numElements;
    }
    return atlag;
}

bool setBit(int &number, int order) {
    if (order < 0 || order > 31) {
        return false;
    }
    int mask = 1 << order;
    number |= mask;

    return true;
}


double stddev(double array[], int numElements) {
    if (numElements == 0) {
        return NAN;
    }

    double atlag = mean(array, numElements);
    double negyzetekOsszege = 0;

    for (int i = 0; i < numElements; ++i) {
        double kulonbseg = array[i] - atlag;
        negyzetekOsszege += kulonbseg * kulonbseg;
    }

    double szoras = negyzetekOsszege / (numElements - 1);
    double szokozOsszeg = sqrt(szoras);

    return szokozOsszeg;
}

pair<double, double> max2(double array[], int numElements) {
    if (numElements < 2) {
        return std::make_pair(NAN, NAN);
    }

    double largest = array[0];
    double secondLargest = array[1];

    for (int i = 2; i < numElements; ++i) {
        if (array[i] > largest) {
            secondLargest = largest;
            largest = array[i];
        } else if (array[i] > secondLargest) {
            secondLargest = array[i];
        }
    }

    return std::make_pair(secondLargest, largest);
}

int countWords(string text) {
    istringstream szoveg(text);
    int szavak = 0;
    string word;
    while (szoveg >> word) {
        szavak++;
    }
    return szavak;
}

string code(std::string text) {
    for (char &c: text) {
        if (std::isalpha(c)) {
            if (c == 'z') {
                c = 'a';
            } else if (c == 'Z') {
                c = 'A';
            } else {
                c++;
            }
        }
    }
    return text;
}

string decode(std::string text) {
    for (char &c: text) {
        if (std::isalpha(c)) {
            if (c == 'a') {
                c = 'z';
            } else if (c == 'A') {
                c = 'Z';
            } else {
                c--;
            }
        }
    }
    return text;
}

string capitalizeWords(string text) {
    bool newWord = true;
    for (size_t i = 0; i < text.length(); ++i) {
        if (std::isalpha(text[i])) {
            if (newWord) {
                text[i] = std::toupper(text[i]);
                newWord = false;
            } else {
                text[i] = std::tolower(text[i]);
            }
        } else {
            newWord = true;
        }
    }
    return text;
}

int main() {
    //Elso feladat
    for (int i = 0; i < 128; ++i) {
        cout << "\n";
        countbits(i);
    }

    //Masodik feladat
    for (int i = 0; i < 35; ++i) {
        int n = 0;
        if (setBit(n, i)) {
            cout << i << " ---> " << n << endl;
        } else {
            cout << "Impossible operation!" << endl;
        }
    }


    //Harmadik feladat

    cout << "\n\n";
    double array[5] = {5, 2, 7, 3, 4};
    cout << "A tomb atlaga: " << mean(array, 5);

    //Negyedik feladat
    cout << "\n\n";
    cout << "A tomb szorasa: " << stddev(array, 5);

    //Otodik feladat
    std::pair<double, double> eredmeny = max2(array, 5);
    cout << "\nA tomb elso legnagyobb eleme: " << eredmeny.first;
    cout << "\nA tomb masodik legnagyobb eleme: " << eredmeny.second;

    //Hatodik feladat
    istringstream inputstream("1.5 6.8 2.9 7.3 korte 9.5 3.1 auto sport 8.2");
    string word;
    double osszeg = 0.0;
    while (inputstream >> word) {
        istringstream wordstream(word);
        double number;
        if (wordstream >> number) {
            osszeg += number;
        }
    }
    cout << "\nA paranccsor numerikus argumentumainak osszege: " << osszeg;

    //Hetedik feladat
    string filename = "input.txt";
    ifstream input(filename);
    if (!input) {
        cout << "\n\nHiba tortent a fajl megnyitasaval kapcsolatban!(" << filename << ")";
        return 1;
    }
    string text;
    string line;
    while (getline(input, line)) {
        text += line + " ";
    }
    int szavakszama = countWords(text);
    cout << "\nA beolvasott szavak szama: " << szavakszama;
    input.close();

    //Nyolcadik feladat
    string filename2 = "Code.txt";
    ifstream Code(filename2);
    if (!Code) {
        cout << "\n\nHiba tortent a fajl megnyitasaval kapcsolatban!(" << filename2 << ")";
        return 1;
    }
    string line2;
    string text2;
    while (getline(Code, line2)) {
        text2 += line2 + "\n";
    }

    string kodoltszoveg = code(text2);
    string dekodoltszoveg = decode(kodoltszoveg);
    ofstream kodolt("kodoltszoveg.txt");
    kodolt << kodoltszoveg;
    ofstream dekodolt("dekodoltszoveg.txt");
    dekodolt << dekodoltszoveg;

    //Kilencedik feladat
    cout << "\n\nAlakitsuk at a szoveg szavait ugy, hogy minden szo nagybetuvel kezdodjon es kisbetuvel folytatodjon.";
    cout << "\nIrd be a feladathoz hasznalt szoveget:";
    string text3;
    getline(cin, text3);
    string nagybetusitve = capitalizeWords(text3);
    cout << nagybetusitve;


    return 0;
}
