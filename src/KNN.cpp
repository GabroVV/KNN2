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

void KNN::calculateDistances(shared_ptr<Iris> iris,bool sl,bool sw, bool pl,bool pw) {
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

int KNN::classify(int k)
{
    int species[SpeciesAmount] = {};
    int pointer;
    bool notDecided = true;
    while(notDecided)
    {
        for(int i=0;i<k;i++)
        {
            pointer = trainData->getIris(i)->getSpecies();
            switch(pointer)
            {
                case setosa: {species[setosa]++;break;}
                case versicolor: {species[versicolor]++;break;}
                case virginica: {species[virginica]++;break;}
            }
        }

       if(((species[setosa] == species[versicolor]) && (species[setosa] >= species[virginica])) ||
          ((species[setosa] == species[virginica]) && (species[setosa] >= species[versicolor])) ||
          ((species[versicolor] == species[virginica])&&(species[versicolor] >= species[setosa])))
       {
            k = 1;
            for(int i=0;i<SpeciesAmount;i++)
            {
                species[i] = 0;
            }
       }
       else
       {
           notDecided = false;
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

void KNN::fillConfusionMatrix()
{
    for(int i=0;i<SpeciesAmount;i++)
    {
        for(int j=0;j<SpeciesAmount;j++)
        {
            confusionMatrix[i][j] = 0;
        }
    }
    for(int i=0;i<testData->getSize();i++)
    {
        int testSpecies = testData->getIris(i)->getSpecies();
        confusionMatrix[testSpecies][result[i]]++;

    }
}

void KNN::displayConfusionMatrix()
{
    cout<<endl<<setw(18)<<""<<"Setosa"<<setw(12)<<"Versicolor"<<setw(12)<<"Virginica"<<endl;
    for(int i=0;i<SpeciesAmount;i++)
    {
        if(i == setosa) cout<<setw(12)<<"Setosa";
        else if(i == versicolor)cout<<setw(12)<<"Versicolor";
        else cout<<setw(12)<<"Virginica";

        for(int j=0;j<SpeciesAmount;j++)
        {
            confusionMatrix[i][j] = confusionMatrix[i][j]*SpeciesAmount*100/(double)testData->getSize();
            cout<<setw(12);
            cout<<confusionMatrix[i][j];
        }
        cout<<endl<<endl;
    }
}

int KNN::getResult(int position)
{
    return result[position];
}

void KNN::executeAlgorithm(bool sl,bool sw, bool pl,bool pw) {

    cout<<"--------------Dla cech--------------"<<endl
    <<boolalpha<<"Dlugosc dzialki kielicha: "<<sl<<endl
    <<"Szerokosc dzialki kielicha: "<<sw<<endl
    <<"Dlugosc platka: "<<pl<<endl
    <<"Szerokosc platka: "<<pw<<endl
    <<"------------------------------------";
    for (int k = 1; k <= 11; k += 2) {
        cout << endl << "k =" << k << endl;
        for (int i = 0; i < testData->getSize(); i++) {
            calculateDistances(testData->getIris(i), sl, sw, pl, pw);
            getTrainData()->sortTrainData();
            classify(k);
        }
        fillConfusionMatrix();
        displayConfusionMatrix();
        cout << " Dokladnosc:" << getAccuracy() << endl;
        clearResult();
    }
}