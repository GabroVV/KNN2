#include <iostream>
#include "../include/IrisCollection.h"
#include "../include/Iris.h"
#include "../include/KNN.h"


using namespace std;
int main() {

    IrisCollection trainData;
    IrisCollection testData;

    trainData.loadCSV("data_train.csv");
    testData.loadCSV("data_test.csv");

    KNN knn(&trainData,&testData);
    knn.calculateDistances(testData.getIris(0),70,1,1,1,1);
    for(int i=0;i<70;i++)
    {
        cout<<i<<"  "<<knn.getTrainData()->getIris(i)->getDistance()<<endl;

    }
    knn.getTrainData()->sortTrainData();
    cout<<endl;
    for(int i=0;i<70;i++)
    {
        cout<<i<<"  "<<knn.getTrainData()->getIris(i)->getDistance()<<endl;

    }


    return 0;
}