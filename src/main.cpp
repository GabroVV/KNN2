#include <iostream>
#include "../include/IrisCollection.h"
#include "../include/Iris.h"
#include "../include/KNN.h"
using namespace std;

using namespace std;
int main() {

    IrisCollection trainData;
    IrisCollection testData;

    trainData.loadCSV("data_train.csv");
    testData.loadCSV("data_test.csv");

    KNN knn(&trainData,&testData);

    knn.executeAlgorithm(1,1,1,1);
    knn.executeAlgorithm(1,1,1,0);
    knn.executeAlgorithm(0,1,1,1);
    knn.executeAlgorithm(1,1,0,0);
    knn.executeAlgorithm(0,1,0,1);



    return 0;
}