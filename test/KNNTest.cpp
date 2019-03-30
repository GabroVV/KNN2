#include <boost/test/unit_test.hpp>

#include "Iris.h"
#include "IrisCollection.h"
#include "KNN.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(KNNTest)

    BOOST_AUTO_TEST_CASE(ConstructorTest_KNN_ParametersSet)
    {
        shared_ptr<IrisCollection> trainData;
        shared_ptr<IrisCollection> testData;

        trainData->loadCSV("data_train.csv");
        testData->loadCSV("data_test.csv");
     //   cout<<trainData->getIris(0)->getSl();

     //   KNN knn(trainData,testData);
    }



BOOST_AUTO_TEST_SUITE_END()