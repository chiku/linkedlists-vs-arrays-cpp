#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Arraylist

#include <boost/test/unit_test.hpp>

#include "arraylist.h"

class ArraylistTestFixture
{
public:
	ArraylistTestFixture() {}
	~ArraylistTestFixture() {}
};

BOOST_FIXTURE_TEST_SUITE(ArraylistTest, ArraylistTestFixture)

BOOST_AUTO_TEST_CASE(array_list_is_empty_on_creation)
{
	Arraylist list(3);

	BOOST_CHECK_EQUAL(true, list.isEmpty());
}

BOOST_AUTO_TEST_CASE(array_list_has_reports_items_as_zero_before_insertion)
{
	Arraylist list(3);

	BOOST_CHECK_EQUAL(0, list[0]);
	BOOST_CHECK_EQUAL(0, list[1]);
}

BOOST_AUTO_TEST_CASE(array_list_has_items_when_first_item_is_inserted)
{
	Arraylist list(3);
	list.insert(10, 0);

	BOOST_CHECK_EQUAL(false, list.isEmpty());
	BOOST_CHECK_EQUAL(10, list[0]);
}

BOOST_AUTO_TEST_CASE(array_list_has_items_when_second_item_is_inserted_at_end)
{
	Arraylist list(3);
	list.insert(10, 0);
	list.insert(20, 1);

	BOOST_CHECK_EQUAL(false, list.isEmpty());
	BOOST_CHECK_EQUAL(10, list[0]);
	BOOST_CHECK_EQUAL(20, list[1]);
}

BOOST_AUTO_TEST_CASE(array_list_has_items_when_item_is_inserted_beyond_end)
{
	Arraylist list(3);
	list.insert(10, 0);
	list.insert(20, 2);

	BOOST_CHECK_EQUAL(false, list.isEmpty());
	BOOST_CHECK_EQUAL(10, list[0]);
	BOOST_CHECK_EQUAL(20, list[1]);
}

BOOST_AUTO_TEST_CASE(array_list_has_items_when_second_item_is_inserted_at_start)
{
	Arraylist list(3);
	list.insert(10, 0);
	list.insert(20, 0);

	BOOST_CHECK_EQUAL(false, list.isEmpty());
	BOOST_CHECK_EQUAL(20, list[0]);
	BOOST_CHECK_EQUAL(10, list[1]);
}

BOOST_AUTO_TEST_CASE(array_list_has_items_when_third_item_is_inserted_in_middle)
{
	Arraylist list(3);
	list.insert(10, 0);
	list.insert(20, 1);
	list.insert(30, 1);

	BOOST_CHECK_EQUAL(false, list.isEmpty());
	BOOST_CHECK_EQUAL(10, list[0]);
	BOOST_CHECK_EQUAL(30, list[1]);
	BOOST_CHECK_EQUAL(20, list[2]);
}

BOOST_AUTO_TEST_CASE(array_list_has_a_string_representation)
{
	Arraylist list(3);
	list.insert(10, 0);
	list.insert(20, 1);
	list.insert(30, 1);

	BOOST_CHECK_EQUAL(std::string("[ <10> -> <30> -> <20> -> NULL ]"), list.dump());
}

BOOST_AUTO_TEST_SUITE_END()
