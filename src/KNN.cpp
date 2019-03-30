//
// Created by Gabriel on 29.03.2019.
//

#include "../include/KNN.h"
#include <cmath>
#include <iostream>
using namespace std;
KNN::KNN(shared_ptr<IrisCollection> trainData,shared_ptr<IrisCollection> testData):trainData(trainData),testData(testData)
{
}

KNN::~KNN() {

}

void KNN::calculateDistances(Iris iris,int size,bool sl,bool sw, bool pl,bool pw) {
    distance.clear();
    for(int i=0;i<70;i++)
    {
        double sum = 0;
       if(sl)
        {
            sum += pow(iris.getSl()-trainData->getIris(i)->getSl(),2.0);
        }
//        if(sw)
//        {
//            sum += pow(iris.getSw()-trainData.getIris(i).getSw(),2.0);
//
//        }
//        if(pl)
//        {
//            sum += pow(iris.getPl()-trainData.getIris(i).getPl(),2.0);
//
//        }
//        if(pw)
//        {
//            sum += pow(iris.getPw()-trainData.getIris(i).getPw(),2.0);
//        }
        trainData->getIris(i)->setDistance(sum);
    }
}

double KNN::getDistances(int i)
{
    return trainData->getIris(i)->getDistance();
}

