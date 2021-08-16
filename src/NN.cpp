//
// Created by 0 on 2021/8/13.
//
#include <NN.h>
#include <cmath>
#include <random>
#include <chrono>
#include <iostream>

using namespace std;

void NN::init(int hiddenLayerNum, float lr) {
    learningRate = lr;

    default_random_engine e;
    e.seed(chrono::system_clock::now().time_since_epoch().count());
    uniform_real_distribution<double> u(-1.0, 1.0);
    vector<double> temp;

    for(int i = 0; i < dataLoader.featureNum; i++){
        temp = {};
        for(int j = 0; j < dataLoader.featureNum; j++){
            temp.push_back(u(e));
        }
        inputLayer.emplace_back(temp);
    }

    int hiddenNueronNum = (int)round((2.0/3.0)*dataLoader.featureNum + (2.0/3.0)*dataLoader.classNum);

}


void NN::train() {

}

void NN::eval() {

}

void NN::pred() {

}

double NN::loss(const vector<double>& output, int expected) {
    return -log(output[expected]);
}

double NN::ReLu(double z) {
    return z > 0 ? z : 0;
}

vector<double> NN::softMax(const vector<double>& z) {
    vector<double> res = vector<double>(z.size());
    double temp = 0;
    for(double i : z){
        temp += exp(i);
    }
    for(int i = 0; i < z.size(); i++){
        res[i] = z[i]/temp;
    }
    return res;
}

void NN::load(string file) {
    dataLoader.load(file);
}
