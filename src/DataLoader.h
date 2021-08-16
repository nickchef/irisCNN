//
// Created by 0 on 2021/8/13.
//

#ifndef IRISCNN_DATALOADER_H
#define IRISCNN_DATALOADER_H

#include <string>
#include <vector>
#include <tr1/unordered_map>

using namespace std;

class DataLoader {
public:
    void load(const string& file);
    vector<vector<float>> train_x;
    vector<string> train_y;
    vector<vector<float>> test_x;
    vector<string> test_y;
    int featureNum, classNum;
    tr1::unordered_map<string, int> classes;
};


#endif //IRISCNN_DATALOADER_H
