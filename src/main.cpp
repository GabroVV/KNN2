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

    for (int k = 1; k <= 11; k += 2) {
        cout << endl << "k =" << k << endl;
        for (int i = 0; i < testData.getSize(); i++) {
            knn.calculateDistances(testData.getIris(i), trainData.getSize(), 1, 1, 0, 0);
            knn.getTrainData()->sortTrainData();
            knn.Classify(k, i);
        }
        knn.DisplayConfusionMatrix();
        cout << " Dokladnosc:" << knn.getAccuracy() << endl;
        knn.clearResult();
    }



    return 0;
}