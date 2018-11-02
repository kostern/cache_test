#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "cache.cpp"
#include <cstdlib>
#include <iostream>

// looks at construction of cache
TEST_CASE("construction", "[constructor]") {
    Cache* cache = new Cache(10);
}


TEST_CASE("setting", "[set]") {
    Cache* cache = new Cache(10);
    
    cache->set("a", "a", 3);
    cache->set("b", "b", 1);
}

TEST_CASE("setting, and memory", "[constructor, set, memused, maxmem]") {
    Cache* cache = new Cache(10);
    REQUIRE(cache->space_used() == 0);
    
    cache->set("a", "a", 1);
    cache->set("c", "c", 4);
    REQUIRE(cache->space_used() == 5);

    cache->set("b", "b", 2);
    REQUIRE(cache->space_used() == 7);

    cache->set("a", "a", 5);
    REQUIRE(cache->space_used() == 10);
}

TEST_CASE("getting", "[constructor, set, get]"){
    Cache* cache = new Cache(10);
    Cache::index_type size;

    SECTION("get one"){
        cache->set("a", "a", 1);
        cache->get("a", size);
        REQUIRE(size == 1);
    }
    
    SECTION("set two, then get two"){
        cache->set("d", "d", 2);
        cache->set("a", "a", 1);
        cache->get("d", size);
        REQUIRE(size == 2);
        cache->get("a", size);
        REQUIRE(size == 1);
    }

    SECTION("set one, get one - different size"){
        cache->set("c", "c", 3);
        cache->get("c", size);
        REQUIRE(size == 3);
    }
}

TEST_CASE("delete", "[constructor, set, del]"){
    Cache* cache = new Cache(10);
    Cache::index_type size;

    cache->set("a", "a", 1);
    cache->del("a");
    REQUIRE(cache->get("a", size) == NULL);

    SECTION("re-adding value then delete") {
        cache->set("a", "a", 1);
        cache->del("a"); 
        REQUIRE(cache->get("a", size) == NULL);
    }

    SECTION("delete two values") {
        cache->set("f", "f", 2);
        cache->set("e", "e", 4);
        cache->del("f");
        cache->del("e");
        REQUIRE(cache->get("f", size) == NULL);
        REQUIRE(cache->get("e", size) == NULL);
    }
}

    
TEST_CASE("Size check", "[constructor, set, get, size]"){
    Cache* cache = new Cache(10);
    Cache::index_type size;

    SECTION("retrieve size of cache"){
        cache->set("a", "a", 1);
        cache->get("a", size);
        REQUIRE(size == 1);
    }
    
    SECTION("rewriting size of cache"){
        cache->set("a", "b", 6);
        cache->get("a", size);
        REQUIRE(size == 6);
    }
}
