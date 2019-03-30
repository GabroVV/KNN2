#include <boost/test/unit_test.hpp>

#include "Iris.h"
#include "IrisCollection.h"
#include "KNN.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(KNNTest)

    BOOST_AUTO_TEST_CASE(ConstructorTest_KNN_ParametersSet)
    {
        IrisCollection trainData;
        IrisCollection testData;

        trainData.loadCSV("data_train.csv");
        testData.loadCSV("data_test.csv");

        KNN knn(trainData,testData);
        BOOST_CHECK_EQUAL(knn.getTrainData().getIris(0)->getSl(),5.1);

    }

    BOOST_AUTO_TEST_CASE(SortTest_KNN_ParametersSet)
    {
        IrisCollection trainData;
        IrisCollection testData;

        trainData.loadCSV("data_train.csv");
        testData.loadCSV("data_test.csv");

        KNN knn(trainData,testData);
        knn.calculateDistances(knn.getTestData().getIris(0),);
        knn.getTrainData().sortTrainData();

        BOOST_CHECK_EQUAL(knn.getTrainData().getIris(100)->getSpecies(),5.1);

    }



BOOST_AUTO_TEST_SUITE_END()