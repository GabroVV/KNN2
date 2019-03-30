#include <boost/test/unit_test.hpp>

#include "Iris.h"
#include "IrisCollection.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(IrisCollectionTest)

    BOOST_AUTO_TEST_CASE(GetterSetterTest_IrisCollection_ParametersSet)
    {
        IrisCollection collection;
        shared_ptr<Iris> i1(new Iris(2.0,2.5,2.6,2.7,2));
        collection.addIris(i1);
        BOOST_CHECK_EQUAL(i1->getSl(),collection.getIris(0)->getSl());
    }

    BOOST_AUTO_TEST_CASE(IrisSwapTest_IrisCollection_ParametersSet)
    {
        IrisCollection collection;
        shared_ptr<Iris> i1(new Iris(2.0,2.5,2.6,2.7,2));
        shared_ptr<Iris> i2(new Iris(3,3,3,3,3));

        collection.addIris(i1);
        collection.swapIris(i2,0);
        BOOST_CHECK_EQUAL(i2->getSl(),collection.getIris(0)->getSl());
    }

    BOOST_AUTO_TEST_CASE(IrisSortTest_IrisCollection_ParametersSet)
    {
        IrisCollection collection;
        shared_ptr<Iris> i2(new Iris(2.0,2.5,2.6,2.7,2));
        shared_ptr<Iris> i1(new Iris(3,3,3,3,3));
        i2->setDistance(5);
        i1->setDistance(10);

        collection.addIris(i1);
        collection.addIris(i2);
        collection.sortTrainData();
        BOOST_CHECK_EQUAL(collection.getIris(0)->getDistance(),5);
    }



BOOST_AUTO_TEST_SUITE_END()