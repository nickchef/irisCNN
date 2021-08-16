//
// Created by 0 on 2021/8/13.
//
#include "DataLoader.h"
#include <string>
#include <fstream>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

bool isNumber(const string& str){
    return all_of(str.begin(), str.end(), [](char c){return isdigit(c)!= 0 || c == '.';});
}

void DataLoader::load(const string& file) {
    ifstream data;
    cout << "opening " << file << endl;
    data.open(file);

    if(!data.is_open()){
        cout << "FF" << endl;
        return;
    }

    char buf[1024] = {0};

    int locator, counter = 1, feature_num = 0;
    string temp;
    vector<float> temp_sample;
    data >> buf;

    temp = strtok(buf, ",");
    for(;;){
        if(!isNumber(temp)){
            train_y.emplace_back(temp);
            classes.insert(pair<string, int>(temp, 0));
            classNum = 1;
            break;
        }
        temp_sample.push_back(stof(temp));
        feature_num++;
        temp = strtok(nullptr, ",");
    }
    train_x.push_back(temp_sample);

    while(data >> buf){
        temp_sample = vector<float>(feature_num);
        locator = 0;
        temp_sample[locator++] = stof(strtok(buf, ","));
        for (;;){
            temp = strtok(nullptr, ",");
            if(!isNumber(temp)){
                train_y.emplace_back(temp);
                if(classes.find(temp) == classes.end()){
                    classes.insert(pair<string, int>(temp, classNum));
                    classNum++;
                }
                break;
            }
            temp_sample[locator++] = stof(temp);
        }
        train_x.push_back(temp_sample);
        counter++;
    }

    counter = (int)round(counter * 0.3);
    auto x = train_x.end();
    auto y = train_y.end();
    for(int i = 0; i < counter; i++){
        test_x.push_back(*x);
        test_y.push_back(*y);
        train_x.pop_back();
        train_y.pop_back();
        advance(x, -1);
        advance(y, -1);
    }

    cout << "Load success:" << endl;
    cout << "trainX = " << train_x.size() << endl;
    cout << "trainY = " << train_y.size() << endl;
    cout << "testX = " << test_x.size() << endl;
    cout << "testY = " << test_y.size() << endl;
    cout << "feature = " << feature_num << endl;

    data.close();
    featureNum = feature_num;
}
