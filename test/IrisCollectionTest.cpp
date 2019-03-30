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



BOOST_AUTO_TEST_SUITE_END()