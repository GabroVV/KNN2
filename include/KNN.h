//
// Created by Gabriel on 29.03.2019.
//

#ifndef UNTITLED4IAD_ZAD1_KNN_H
#define UNTITLED4IAD_ZAD1_KNN_H

#define SpeciesAmount 3
#include "IrisCollection.h"
#include "Iris.h"
#include <memory>
class KNN{
private:
    IrisCollection* trainData;
    IrisCollection* testData;
    std::vector<int> result;
    double confusionMatrix[SpeciesAmount][SpeciesAmount];
public:
    KNN(IrisCollection* trainData,IrisCollection* testData);
    virtual ~KNN();
    void calculateDistances(std::shared_ptr<Iris> iris,int size,bool sl,bool sw, bool pl,bool pw);
    IrisCollection* getTrainData();
    IrisCollection* getTestData();
    int classify(int k,int testIrisPosition);
    double getAccuracy();
    void clearResult();
    void fillConfusionMatrix();
    void displayConfusionMatrix();
    int getResult(int position);
    void executeAlgorithm(bool sl,bool sw, bool pl,bool pw);

};
#endif //UNTITLED4IAD_ZAD1_KNN_H
