//
// Created by Szilikee on 2023. 12. 18..
//

#include "SimpleTextGenerator.h"
#include <iostream>
#include <algorithm>
#include <regex>

void SimpleTextGenerator::trainFromText(string trainingText) {
    transform(trainingText.begin(), trainingText.end(), trainingText.begin(), ::tolower);
    const regex letters("[^a-z]");
    auto removeNonAlphabet = [&letters](const string &original)  ->  string {
        stringstream  newString;
        regex_replace(ostreambuf_iterator<char>(newString),original.begin(), original.end(), letters, "");
        return newString.str();
    };
    stringstream stream(trainingText);
    string str,string1, string2, string3;
    stream >> string1;
    string1=removeNonAlphabet(string1);
    stream >> string2;
    string2=removeNonAlphabet(string2);
    while (stream >> string3 ) {
        string3=removeNonAlphabet(string3);
        str = string1.append(" ").append(string2);
        if(data.find(str) == data.end()){
            vector<string> v;
            v.push_back(string3);
            data.insert(make_pair(str, v));
        }
        else
        {
            data.at(str).push_back(string3);
        }
        string1=string2;
        string2=string3;
    }
    str=string1.append(" ").append(string2);
    if(data.find(str) == data.end()){
        vector<string> v;
        v.push_back("");
        data.insert(make_pair(str, v));
    }
    else
    {
        data.at(str).push_back("");
    }
}

void SimpleTextGenerator::printData() const {
    for(const auto &a: data){
        cout << a.first << " : ";
        for(const string &b: a.second){
            cout << b << " ";
        }
        cout << endl;
    }
}

void SimpleTextGenerator::trainFromFile(string filename) {

}

string SimpleTextGenerator::generate(string startWords, int numWords) {
    string output, k1,k2, rand;
    string key = startWords;
    output.append(key).append(" ");
    for(int i = 0; i < numWords; i++){
        if(data.at(key)[0] == ""){
            return output;
        }
        random_shuffle(data.at(key).begin(), data.at(key).end());
        rand = data.at(key)[0];
        output.append(rand).append(" ");
        stringstream str(key);
        str >> k1 >> k2;
        key = k2.append(" ").append(rand);
    }
    return output;
}