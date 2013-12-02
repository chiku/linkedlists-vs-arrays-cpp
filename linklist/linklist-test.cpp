#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Linklist

#include <boost/test/unit_test.hpp>

#include "linklist.h"

class LinklistTestFixture
{
public:
	LinklistTestFixture() {}
	~LinklistTestFixture() {}
};

BOOST_FIXTURE_TEST_SUITE(LinklistTest, LinklistTestFixture)

BOOST_AUTO_TEST_CASE(link_list_is_empty_on_creation)
{
	Linklist list;
	BOOST_CHECK_EQUAL(true, list.isEmpty());
}

BOOST_AUTO_TEST_CASE(link_list_has_reports_items_as_zero_before_insertion)
{
	Linklist list;
	BOOST_CHECK_EQUAL(0, list[0]);
	BOOST_CHECK_EQUAL(0, list[1]);
}

BOOST_AUTO_TEST_CASE(link_list_has_items_when_first_item_is_inserted)
{
	Linklist list;
	list.insert(10, 0);
	BOOST_CHECK_EQUAL(false, list.isEmpty());
	BOOST_CHECK_EQUAL(10, list[0]);
}

BOOST_AUTO_TEST_CASE(link_list_has_items_when_second_item_is_inserted_at_end)
{
	Linklist list;
	list.insert(10, 0);
	list.insert(20, 1);
	BOOST_CHECK_EQUAL(false, list.isEmpty());
	BOOST_CHECK_EQUAL(10, list[0]);
	BOOST_CHECK_EQUAL(20, list[1]);
}

BOOST_AUTO_TEST_CASE(link_list_has_items_when_second_item_is_inserted_at_start)
{
	Linklist list;
	list.insert(10, 0);
	list.insert(20, 0);
	BOOST_CHECK_EQUAL(false, list.isEmpty());
	BOOST_CHECK_EQUAL(20, list[0]);
	BOOST_CHECK_EQUAL(10, list[1]);
}

BOOST_AUTO_TEST_CASE(link_list_has_items_when_third_item_is_inserted_in_middle)
{
	Linklist list;
	list.insert(10, 0);
	list.insert(20, 1);
	list.insert(30, 1);
	BOOST_CHECK_EQUAL(false, list.isEmpty());
	BOOST_CHECK_EQUAL(10, list[0]);
	BOOST_CHECK_EQUAL(30, list[1]);
	BOOST_CHECK_EQUAL(20, list[2]);
}

BOOST_AUTO_TEST_SUITE_END()
