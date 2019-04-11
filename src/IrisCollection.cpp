//
// Created by Gabriel on 27.03.2019.
//
using namespace std;

#include <iostream>
#include "fstream"
#include "IrisCollection.h"
#include <algorithm>

IrisCollection::IrisCollection(){
}

IrisCollection::~IrisCollection() {

}

shared_ptr<Iris> IrisCollection::getIris(int position){
    return collection[position];
}

void IrisCollection::addIris(shared_ptr<Iris> iris) {
    collection.push_back(iris);
}


void IrisCollection::loadCSV(std::string filename) {
    ifstream file(filename);
    string pl,pw,sl,sw,species;

    while( getline(file,sl,',')){

        getline(file,sw,',');
        getline(file,pl,',');
        getline(file,pw,',');
        getline(file,species,'\n');
        shared_ptr<Iris> temp(new Iris(stod(sl),stod(sw),stod(pl),stod(pw),stoi(species)));
        addIris(temp);
    }
}

void IrisCollection::sortTrainData()
{
    sort(collection.begin(),collection.end(),sortByDistance);

};

unsigned long long int IrisCollection::getSize()
{
    return collection.size();
}


