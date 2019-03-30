//
// Created by Gabriel on 29.03.2019.
//

#ifndef UNTITLED4IAD_ZAD1_KNN_H
#define UNTITLED4IAD_ZAD1_KNN_H

#include "IrisCollection.h"
#include "Iris.h"
#include <memory>
class KNN{
private:
    IrisCollection* trainData;
public:
    IrisCollection getTestData();

private:
    IrisCollection* testData;
    std::vector<int> result;
    std::vector<double> distance;
public:
    KNN(IrisCollection* trainData,IrisCollection* testData);
    virtual ~KNN();
    void calculateDistances(std::shared_ptr<Iris> iris,int size,bool sl,bool sw, bool pl,bool pw);
    static bool sortByDistance(const std::shared_ptr<Iris>& i1,const std::shared_ptr<Iris>& i2);
    void sortTrainData();
    double getDistances(int i);
    IrisCollection* getTrainData();



};
#endif //UNTITLED4IAD_ZAD1_KNN_H
