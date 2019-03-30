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
    std::shared_ptr<IrisCollection> trainData;
    std::shared_ptr<IrisCollection> testData;
    std::vector<int> result;
    std::vector<double> distance;
public:
    KNN(std::shared_ptr<IrisCollection> trainData,std::shared_ptr<IrisCollection> testData);
    virtual ~KNN();
    void calculateDistances(Iris iris,int size,bool sl,bool sw, bool pl,bool pw);
    double getDistances(int i);
    const IrisCollection &getTrainData() const;



};
#endif //UNTITLED4IAD_ZAD1_KNN_H
