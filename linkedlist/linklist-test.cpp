#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Linkedlist

#include <boost/test/unit_test.hpp>

#include "linklist.h"

class LinkedlistTestFixture
{
public:
  LinkedlistTestFixture() {}
  ~LinkedlistTestFixture() {}
};

BOOST_FIXTURE_TEST_SUITE(LinkedlistTest, LinkedlistTestFixture)


BOOST_AUTO_TEST_CASE(linked_list_has_no_elements_on_creation)
{
  Linklist list;
  BOOST_CHECK_EQUAL(true, list.isEmpty());
}

BOOST_AUTO_TEST_SUITE_END()
