//
// Created by Szilikee on 2023. 12. 18..
//

#ifndef SZOVEG_GENERALAS_2023_12_18_CPP_TEXTGENERATOR_H
#define SZOVEG_GENERALAS_2023_12_18_CPP_TEXTGENERATOR_H

#include <string>
#include <iostream>

using namespace std;


class TextGenerator {
public:
    virtual void trainFromText(string trainingText) = 0;
    virtual void trainFromFile(string filename) = 0;
    virtual string generate(string startWords, int numWords=10) = 0;
    virtual ~TextGenerator() = default;
};



#endif //SZOVEG_GENERALAS_2023_12_18_CPP_TEXTGENERATOR_H
