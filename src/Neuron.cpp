//
// Created by 0 on 2021/8/13.
//

#include "Neuron.h"

using namespace std;

Neuron::Neuron(vector<double> w): weight(move(w)){
}

double Neuron::next(const vector<double>& x) {
    double output = 0.0;
    for(int i = 0; i < x.size(); i++){
        output += x[i] * weight[i];
    }
    return output + bias;
}

void Neuron::back(float) {

}

