#include <boost/test/unit_test.hpp>

#include "Iris.h"
#include "IrisCollection.h"
#include "KNN.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(KNNTest)

    BOOST_AUTO_TEST_CASE(ConstructorTest_KNN_ParametersSetDataFromCSV)
    {
        IrisCollection trainData;
        IrisCollection testData;

        trainData.loadCSV("data_train.csv");
        testData.loadCSV("data_test.csv");

        KNN knn(&trainData,&testData);
        BOOST_CHECK_EQUAL(knn.getTrainData()->getIris(0)->getSl(),5.1);

    }

    BOOST_AUTO_TEST_CASE(SortTest_KNN_SortedAscendingByDistance)
    {
        IrisCollection trainData;
        IrisCollection testData;

        trainData.loadCSV("data_train.csv");
        testData.loadCSV("data_test.csv");

        KNN knn(&trainData,&testData);
        knn.calculateDistances(knn.getTestData()->getIris(0),70,1,1,1,1);
        knn.getTrainData()->sortTrainData();
        for (int i = 0; i < trainData.getSize()-1 ; ++i) {
            BOOST_TEST(trainData.getIris(i)->getDistance() < trainData.getIris(i+1)->getDistance());
        }
    }

    BOOST_AUTO_TEST_CASE(ClassifyTest_KNN_EqualAmountOfVotesChooseClosest)
    {
        IrisCollection trainData;
        IrisCollection testData;

        shared_ptr<Iris> test(new Iris(2.1,2.1,2.1,2.1,2));

        shared_ptr<Iris> i1(new Iris(1,1,1,1,0));
        shared_ptr<Iris> i2(new Iris(2,2,2,2,1));
        shared_ptr<Iris> i3(new Iris(3,3,3,3,2));

        trainData.addIris(i1);
        trainData.addIris(i2);
        trainData.addIris(i3);

        testData.addIris(test);

        KNN knn(&trainData,&testData);
        knn.calculateDistances(testData.getIris(0), trainData.getSize(), 1, 1, 1, 1);
        knn.getTrainData()->sortTrainData();
        knn.classify(3,0);

        BOOST_CHECK_EQUAL(knn.getResult(0),1);
    }

BOOST_AUTO_TEST_SUITE_END()