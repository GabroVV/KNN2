//
// Created by Gabriel on 29.03.2019.
//

#include "../include/KNN.h"
#include <cmath>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
KNN::KNN(IrisCollection* trainData,IrisCollection* testData):trainData(trainData),testData(testData)
{
}

KNN::~KNN() {

}

void KNN::calculateDistances(shared_ptr<Iris> iris,int size,bool sl,bool sw, bool pl,bool pw) {
    distance.clear();
    for(int i=0;i<70;i++)
    {
        double sum = 0;
       if(sl)
//       cout<<endl<<i<<" ";
        {
            sum += pow(iris->getSl()-trainData->getIris(i)->getSl(),2.0);
   //         cout<<sum<<" ";
        }
        if(sw)
        {
            sum += pow(iris->getSw()-trainData->getIris(i)->getSw(),2.0);
 //           cout<<sum<<" ";


        }
        if(pl)
        {
            sum += pow(iris->getPl()-trainData->getIris(i)->getPl(),2.0);
   //         cout<<sum<<" ";

        }
        if(pw)
        {
            sum += pow(iris->getPw()-trainData->getIris(i)->getPw(),2.0);
   //         cout<<sum<<" ";
        }
        trainData->getIris(i)->setDistance(sum);
 //       cout<<trainData->getIris(i)->getDistance();
    }
}

IrisCollection* KNN::getTrainData()
{
    return trainData;
}

