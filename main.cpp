//
// Created by 0 on 2021/8/13.
//

#include <NN.h>
#include <iostream>
#include <DataLoader.h>
#include <iostream>

using namespace std;

int main(){
    NN nn = NN();
    nn.load("./data/iris.data");
    nn.init();
}