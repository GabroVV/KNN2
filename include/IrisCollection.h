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
    std::vector<std::shared_ptr<Iris>>collection;
public:
    IrisCollection();
    ~IrisCollection();
    std::shared_ptr<Iris> getIris(int position);
    void addIris(std::shared_ptr<Iris> iris);
    void loadCSV(std::string filename);
    std::vector<Iris> getCollection();
};
#endif //UNTITLED4IAD_ZAD1_IRISCOLLECTION_H
