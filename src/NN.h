//
// Created by 0 on 2021/8/13.
//

#ifndef IRISCNN_NN_H
#define IRISCNN_NN_H
#include <Neuron.h>
#include <DataLoader.h>
#include <vector>

using namespace std;

class NN {
public:
    void init(int=1, float = 0.01);
    void train();
    void eval();
    void pred();
    void load(string file);

private:
    vector<vector<Neuron>> hiddenLayers;
    vector<Neuron> inputLayer;
    vector<Neuron> ouputLayer;

    DataLoader dataLoader;

    float learningRate = 0.01;

    static double loss(const vector<double>&, int);
    static double ReLu(double);
    static vector<double> softMax(const vector<double>&);
};


#endif //IRISCNN_NN_H
