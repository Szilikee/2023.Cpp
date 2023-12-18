//
// Created by Szilikee on 2023. 12. 18..
//

#ifndef SZOVEG_GENERALAS_2023_12_18_CPP_SIMPLETEXTGENERATOR_H
#define SZOVEG_GENERALAS_2023_12_18_CPP_SIMPLETEXTGENERATOR_H

#include <string>
#include <vector>
#include <map>
#include "TextGenerator.h"

using namespace std;


class SimpleTextGenerator: public TextGenerator {
    map<string, vector<string>> data;
public:
    virtual void trainFromText(string trainingText) override;
    virtual void trainFromFile(string filename) override;
    virtual string generate(string startWords, int numWords=6) override;
    void printData() const; // a map kiíratása
};


#endif //SZOVEG_GENERALAS_2023_12_18_CPP_SIMPLETEXTGENERATOR_H
