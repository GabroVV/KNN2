//
// Created by Gabriel on 27.03.2019.
//

#ifndef UNTITLED4IAD_ZAD1_IRISCOLLECTION_H
#define UNTITLED4IAD_ZAD1_IRISCOLLECTION_H

#include "Iris.h"
#include "vector"
#include <memory>
class IrisCollection
{
private:
    std::vector<std::shared_ptr<Iris>> collection;
public:
    IrisCollection();
    ~IrisCollection();
    unsigned long long int getSize();
    std::shared_ptr<Iris> getIris(int position);
    void addIris(std::shared_ptr<Iris> iris);
    void swapIris(std::shared_ptr<Iris> iris,int position);
    void loadCSV(std::string filename);
    void sortTrainData();
    std::vector<std::shared_ptr<Iris>> getKFirst(int k);

};

static bool sortByDistance(const std::shared_ptr<Iris>& i1,const std::shared_ptr<Iris>& i2)
{
    return i1->getDistance() < i2->getDistance();
}
#endif //UNTITLED4IAD_ZAD1_IRISCOLLECTION_H
