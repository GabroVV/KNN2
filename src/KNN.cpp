//
// Created by Gabriel on 29.03.2019.
//

#include "../include/KNN.h"
#include <cmath>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
KNN::KNN(IrisCollection* trainData,IrisCollection* testData):trainData(trainData),testData(testData)
{
}

KNN::~KNN() {

}

void KNN::calculateDistances(shared_ptr<Iris> iris,int size,bool sl,bool sw, bool pl,bool pw) {
    for(int i=0;i<trainData->getSize();i++)
    {
        double sum = 0;
       if(sl)
        {
            sum += pow(iris->getSl()-trainData->getIris(i)->getSl(),2.0);
        }
        if(sw)
        {
            sum += pow(iris->getSw()-trainData->getIris(i)->getSw(),2.0);
        }
        if(pl)
        {
            sum += pow(iris->getPl()-trainData->getIris(i)->getPl(),2.0);
        }
        if(pw)
        {
            sum += pow(iris->getPw()-trainData->getIris(i)->getPw(),2.0);
        }
        trainData->getIris(i)->setDistance(sum);
    }
}

IrisCollection* KNN::getTrainData()
{
    return trainData;
}

IrisCollection* KNN::getTestData()
{
    return testData;
}

int KNN::Classify(int k,int testIrisPosition)
{
    int species[SpeciesAmount] = {};
    int pointer;
    bool remis = true;
    while(remis)
    {
        for(int i=0;i<k;i++)
        {
            pointer = trainData->getIris(i)->getSpecies();
            switch(pointer)
            {
                case 0: {species[0]++;break;}
                case 1: {species[1]++;break;}
                case 2: {species[2]++;break;}
            }
        }
       if(((species[0] == species[1]) && (species[0] >= species[2])) ||
          ((species[0] == species[2]) && (species[0] >= species[1])) ||
          ((species[1] == species[2])&&(species[1] >= species[0])))
       {
            k = 1;
            for(int i=0;i<SpeciesAmount;i++)
            {
                species[i] = 0;

            }
       }
       else
       {
            remis = false;
       }
    }

    result.push_back(max_element(species,species+SpeciesAmount) - species);
    return max_element(species,species+SpeciesAmount) - species;
}

double KNN::getAccuracy()
{
    int right = 0;
    for(int i=0;i<testData->getSize();i++)
    {
        if(testData->getIris(i)->getSpecies() == result[i])
        {
            right++;
        }
    }
    return right*100/(double)testData->getSize();
}

void KNN::clearResult()
{
    result.clear();
}

void KNN::DisplayConfusionMatrix()
{
    double T[SpeciesAmount][SpeciesAmount] ={};
    for(int i=0;i<testData->getSize();i++)
    {
        int testSpecies = testData->getIris(i)->getSpecies();
        T[testSpecies][result[i]]++;

    }
    for(int i=0;i<SpeciesAmount;i++)
    {
        for(int j=0;j<SpeciesAmount;j++)
        {
            T[i][j] = T[i][j]*SpeciesAmount*100/(double)testData->getSize();
            cout<<setw(8);
            cout<<T[i][j];
        }
        cout<<endl<<endl;
    }
}
