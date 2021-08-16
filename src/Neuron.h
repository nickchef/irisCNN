//
// Created by 0 on 2021/8/13.
//

#ifndef IRISCNN_NEURON_H
#define IRISCNN_NEURON_H
#include <vector>

using namespace std;

class Neuron {
public:
    explicit Neuron(vector<double>);
    double next(const vector<double>&);
    void back(float);
private:
    vector<double> weight;
    double bias = 1.0;
    double differential = 0;
    double prev_output = 0;
};


#endif //IRISCNN_NEURON_H
