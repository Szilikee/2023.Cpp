#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <utility>
#include <random>
using namespace std;

int main() {
    //1. feladat
    cout << "1. feladat: " << endl;
    vector<string> fruits {
            "melon", "strawberry", "raspberry","apple", "banana", "walnut", "lemon"
    };
    auto it = find_if(fruits.begin(), fruits.end(), [](const string& fruit){
        return fruit.find("berry") != string::npos;
    });
    if(it != fruits.end()){
        cout << "Van olyan gyumolcs, amelyben szerepel a 'berry' szo." << endl;
    } else
        cout << "Nincs olyan gyumolcs, amelyben szerepel a 'berry' szo." << endl;

    //2. feladat
    cout << "2. feladat: " << endl;
    vector<int> arr(5);
    for (int i = 0; i < 5; i++) {
        arr[i] = i;
    }
    bool a = all_of(arr.begin(), arr.end(), [&arr](int i) {
        return arr[i] % 2 == 0;
    });
    if(a)
    {
        cout << "TRUE\n";
    }
    else
    {
        cout << "FALSE\n";
    }
    //3. feladat
    cout << "3. feladat: " << endl;
    for_each(arr.begin(), arr.end(), [&arr](int i){
        return arr[i]*=2;
    });
    for (int i = 0; i < 5; ++i) {
        cout << arr[i] << " ";
    }

    //4. feladat
    cout << "4. feladat: " << endl;
    vector<string> months {
            "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"
    };
    int count = 0;
    for_each(months.begin(), months.end(), [&months, &count](const string& month){
        if(month.length() == 5){
            count++;
        }
    });
    cout << count << "db 5 betubol allo honap van." << endl;
    //5. feladat
    cout << "5. feladat: " << endl;
    sort(arr.begin(), arr.end(), [](int a, int b){
        return a > b;
    });
    for (int i = 0; i < 5; ++i) {
        cout << arr[i] << " ";
    }
    //greater objektummal valo rendezes
    std::sort(arr.begin(), arr.end(), std::greater<>());
    for (int i = 0; i < 5; ++i) {
        cout << arr[i] << " ";
    }
    //6. feladat
    cout << "6. feladat: " << endl;
    vector<pair<string, int>> data {
            {"Januar", 9},
            {"Februar", 12},
            {"Marcius", 20},
            {"Aprilis", 24},
            {"Majus", 25},
            {"Junius", 29},
            {"Julius", 31},
            {"Augusztus", 30},
            {"Szeptember", 28},
            {"Oktober", 21},
            {"November", 13},
            {"December", 4}
    };
    sort(data.begin(), data.end(), [](const pair<string, int>& a, const pair<string, int>& b){
        return a.second > b.second;
    });
    for (const auto& [month, days] : data) {
        cout << month << ": " << days << endl;
    }
    //7. feladat
    cout << "7. feladat: " << endl;
    sort(arr.begin(), arr.end(), [](int a, int b){
        return abs(a) > abs(b);
    });
    for (int i = 0; i < 5; ++i) {
        cout << arr[i] << " ";
    }
    //8. feladat
    cout << "8. feladat: " << endl;
    for_each(months.begin(), months.end(), [](string& month){
        month[0] = tolower(month[0]);
    });
    for (int i = 0; i < 12; ++i) {
        cout << months[i] << " ";
    }
    //9. feladat
    cout << "\n9. feladat: " << endl;
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    shuffle(alphabet.begin(), alphabet.end(), default_random_engine{});
    cout << alphabet << endl;
    sort(months.begin(), months.end(), [&alphabet](const string& a, const string& b){
        return alphabet.find(a[0]) < alphabet.find(b[0]);
    });
    for_each(months.begin(), months.end(), [](const string& month){
        cout << month << " ";
    });
    return 0;
}
