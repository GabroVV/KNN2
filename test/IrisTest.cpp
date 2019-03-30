#include <boost/test/unit_test.hpp>

#include "Iris.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(IrisTest)

    BOOST_AUTO_TEST_CASE(ConstructorTest_Iris_ParametersSet)
    {
        Iris i1(2.0,2.5,2.6,2.7,2);
        BOOST_CHECK_EQUAL(i1.getSl(),2.0);
        BOOST_CHECK_EQUAL(i1.getSw(),2.5);
        BOOST_CHECK_EQUAL(i1.getPl(),2.6);
        BOOST_CHECK_EQUAL(i1.getPw(),2.7);
        BOOST_CHECK_EQUAL(i1.getSpecies(),2);
    }

    BOOST_AUTO_TEST_CASE(SetterTest_Iris_ParametersSet)
    {
        Iris i1(2.0,2.5,2.6,2.7,2);
        i1.setDistance(30.0);
        BOOST_CHECK_EQUAL(i1.getDistance(),30.0);
    }


BOOST_AUTO_TEST_SUITE_END()
