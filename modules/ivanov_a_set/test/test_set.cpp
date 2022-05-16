// Copyright 2022 Ivanov Arkady

#include <gtest/gtest.h>
#include <vector>

#include "include/ivanov_a_set.h"

// {5, 9, 13}
Set prepare_1() {
    Set s;
    s.add(5);
    s.add(9);
    s.add(13);
    return s;
}

// {1, 5, 8, 9, 11, 13, 15}
Set prepare_2() {
    Set s;
    s.add(1);
    s.add(5);
    s.add(8);
    s.add(9);
    s.add(11);
    s.add(13);
    s.add(15);
    return s;
}

TEST(ivanov_a_set, empty_constructor) {
    ASSERT_NO_THROW(Set());
    ASSERT_EQ(static_cast<size_t>(0), Set().getSize());
}

TEST(ivanov_a_set, can_add_and_get) {
    Set s;
    for (int i = 0; i < 9; i++) {
        ASSERT_NO_THROW(s.add(i));
        ASSERT_EQ(static_cast<size_t>(i + 1), s.getSize());
        ASSERT_EQ(i, s.getValueAt(static_cast<size_t>(i)));
    }
    ASSERT_ANY_THROW(s.getValueAt(static_cast<size_t>(9)));
}

TEST(ivanov_a_set, can_remove_values_1) {
    Set s;
    s.add(1);
    s.add(5);
    s.add(9);

    ASSERT_NO_THROW(s.removeAt(static_cast<size_t>(1)));
    ASSERT_EQ(static_cast<size_t>(2), s.getSize());
    ASSERT_EQ(1, s.getValueAt(static_cast<size_t>(0)));
    ASSERT_EQ(9, s.getValueAt(static_cast<size_t>(1)));
    ASSERT_NO_THROW(s.removeAt(static_cast<size_t>(1)));
    ASSERT_EQ(static_cast<size_t>(1), s.getSize());
    ASSERT_EQ(1, s.getValueAt(static_cast<size_t>(0)));
}

TEST(ivanov_a_set, can_remove_values_2) {
    Set s;
    s.add(1);
    s.add(5);
    s.add(9);

    ASSERT_NO_THROW(s.removeValue(5));
    ASSERT_EQ(static_cast<size_t>(2), s.getSize());
    ASSERT_EQ(1, s.getValueAt(static_cast<size_t>(0)));
    ASSERT_EQ(9, s.getValueAt(static_cast<size_t>(1)));
    ASSERT_NO_THROW(s.removeValue(9));
    ASSERT_EQ(static_cast<size_t>(1), s.getSize());
    ASSERT_EQ(1, s.getValueAt(static_cast<size_t>(0)));
}

TEST(ivanov_a_set, copy_constructor) {
    Set s1;
    s1.add(5);
    s1.add(9);
    s1.add(1);
    Set s2(s1);

    ASSERT_EQ(s1.getSize(), s2.getSize());
    for (size_t i = 0; i < s1.getSize(); i++) {
        ASSERT_EQ(s1.getValueAt(i), s2.getValueAt(i));
    }
}

TEST(ivanov_a_set, can_union_1) {
    Set s1, s2;
    for (int i = 0; i < 3; i++) {
        s1.add(i);
        s2.add(3 + i);
    }
    Set s3(s1.unionWith(s2));
    ASSERT_EQ(s3.getSize(), static_cast<size_t>(6));
    for (size_t i = 0; i < s3.getSize(); i++) {
        ASSERT_EQ(s3.getValueAt(static_cast<size_t>(i)),
            static_cast<int>(i));
    }
}

TEST(ivanov_a_set, can_union_2) {
    Set s1(prepare_1());
    Set s2(prepare_2());
    Set s3(s1.unionWith(s2));
    Set s4(s2.unionWith(s1));
    ASSERT_EQ(s3.getSize(), s2.getSize());
    ASSERT_EQ(s4.getSize(), s2.getSize());
}

TEST(ivanov_a_set, can_intersect_1) {
    Set s1(prepare_1());
    Set s2(prepare_2());
    Set s3(s1.intersectWith(s2));
    ASSERT_EQ(s3.getSize(), s1.getSize());
}

TEST(ivanov_a_set, can_intersect_2) {
    Set s1, s2;
    s1.add(1);
    s1.add(2);
    s2.add(2);
    s2.add(3);
    Set s3(s1.intersectWith(s2));
    ASSERT_EQ(s3.getSize(), static_cast<size_t>(1));
    ASSERT_EQ(s3.getValueAt(static_cast<size_t>(0)), 2);
}

TEST(ivanov_a_set, difference_from) {
    Set s1(prepare_2());
    Set s2(prepare_1());
    Set s3(s1.differenceFrom(s2));
    Set s4(s2.differenceFrom(s1));
    ASSERT_EQ(s3.getSize(), s1.getSize() - s2.getSize());
    ASSERT_EQ(s4.getSize(), static_cast<size_t>(0));
}

TEST(ivanov_a_set, belongs_to) {
    Set s1(prepare_1());
    Set s2(prepare_2());
    Set s3(prepare_1());
    ASSERT_TRUE(s1.belongsTo(s3));
    ASSERT_TRUE(s1.belongsTo(s2));
    ASSERT_FALSE(s2.belongsTo(s1));
}

TEST(ivanov_a_set, includes) {
    Set s1(prepare_1());
    Set s2(prepare_2());
    ASSERT_TRUE(s2.includes(s1));
    ASSERT_FALSE(s1.includes(s2));
}

TEST(ivanov_a_set, eq_operator) {
    Set s1(prepare_2());
    Set s2(prepare_2());
    Set s3(prepare_1());
    ASSERT_TRUE(s1 == s2);
    ASSERT_FALSE(s1 == s3);
}

TEST(ivanov_a_set, strictly_belongs_to) {
    Set s1(prepare_1());
    Set s2(prepare_2());
    Set s3(prepare_1());
    ASSERT_FALSE(s1.strictlyBelongsTo(s3));
    ASSERT_TRUE(s1.strictlyBelongsTo(s2));
}

TEST(ivanov_a_set, strictly_includes) {
    Set s1(prepare_1());
    Set s2(prepare_1());
    Set s3(prepare_2());
    ASSERT_FALSE(s1.strictlyIncludes(s2));
    ASSERT_TRUE(s3.strictlyIncludes(s1));
}

TEST(ivanov_a_set, init_constr) {
    std::vector<int> v;
    v.push_back(5);
    v.push_back(13);
    v.push_back(9);
    ASSERT_NO_THROW(Set(v));
    Set s1(v);
    Set s2(prepare_1());
    ASSERT_TRUE(s1 == s2);
}

TEST(ivanov_a_set, throws_when_add_already_existing_value) {
    Set s;
    s.add(4);
    ASSERT_ANY_THROW(s.add(4));
    s.add(9);
    ASSERT_ANY_THROW(s.add(9));
}

TEST(ivanov_a_set, can_remove_head_value) {
    Set s;
    s.add(4);
    ASSERT_NO_THROW(s.removeAt(static_cast<size_t>(0)));
    s.add(0);
    s.add(1);
    ASSERT_NO_THROW(s.removeAt(static_cast<size_t>(0)));
}

TEST(ivanov_a_set, can_remove_values_3) {
    Set s;
    ASSERT_NO_THROW(s.removeValue(4));
    s.add(4);
    ASSERT_NO_THROW(s.removeValue(3));
    ASSERT_NO_THROW(s.removeValue(4));
    ASSERT_NO_THROW(s.add(4));
    s.add(5);
    ASSERT_NO_THROW(s.removeValue(8));
}

TEST(ivanov_a_set, belongs_to_2) {
    Set s1;
    Set s2;
    s1.add(4);
    s2.add(5);
    ASSERT_FALSE(s1.belongsTo(s2));
}

TEST(ivanov_a_set, eq_opertor_test_2) {
    Set s1;
    Set s2;
    s1.add(4);
    s2.add(5);
    ASSERT_FALSE(s1 == s2);
}
