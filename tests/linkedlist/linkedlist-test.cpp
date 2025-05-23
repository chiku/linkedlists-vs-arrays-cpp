// Author::    Chirantan Mitra
// Copyright:: Copyright (c) 2013-2025. All rights reserved
// License::   MIT


#define CATCH_CONFIG_MAIN
#include "doctest.h"

#include "linkedlist.h"

TEST_CASE("Linked list is empty on creation")
{
	Linkedlist list;

	REQUIRE(list.isEmpty());
}

TEST_CASE("Linked list has reports items as zero before insertion")
{
	Linkedlist list;

	REQUIRE(list[0] == 0);
	REQUIRE(list[1] == 0);
}

TEST_CASE("Linked list has items when first item is inserted")
{
	Linkedlist list;
	list.insert(10, 0);

	REQUIRE(!list.isEmpty());
	REQUIRE(list[0] == 10);
}

TEST_CASE("Linked list has items when second item is inserted at end")
{
	Linkedlist list;
	list.insert(10, 0);
	list.insert(20, 1);

	REQUIRE(!list.isEmpty());
	REQUIRE(list[0] == 10);
	REQUIRE(list[1] == 20);
}

TEST_CASE("Linked list has items when item is inserted beyond end")
{
	Linkedlist list;
	list.insert(10, 0);
	list.insert(20, 2);

	REQUIRE(!list.isEmpty());
	REQUIRE(list[0] == 10);
	REQUIRE(list[1] == 20);
}

TEST_CASE("Linked list has items when second item is inserted at start")
{
	Linkedlist list;
	list.insert(10, 0);
	list.insert(20, 0);

	REQUIRE(!list.isEmpty());
	REQUIRE(list[0] == 20);
	REQUIRE(list[1] == 10);
}

TEST_CASE("Linked list has items when third item is inserted in middle")
{
	Linkedlist list;
	list.insert(10, 0);
	list.insert(20, 1);
	list.insert(30, 1);

	REQUIRE(!list.isEmpty());
	REQUIRE(list[0] == 10);
	REQUIRE(list[1] == 30);
	REQUIRE(list[2] == 20);
}

TEST_CASE("array list has a string representation")
{
	Linkedlist list;
	list.insert(10, 0);
	list.insert(20, 1);
	list.insert(30, 1);

	REQUIRE(list.dump() == std::string("[ <10> -> <30> -> <20> -> NULL ]"));
}
