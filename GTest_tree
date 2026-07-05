#include <gtest/gtest.h>
#include <set>
#include <vector>
#include <iterator>

// ==================== ТЕСТЫ ДЛЯ std::set (Бинарное дерево поиска) ====================
class BinaryTreeTest : public ::testing::Test {
protected:
    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(BinaryTreeTest, NewSetIsEmpty) {
    std::set<int> tree;
    EXPECT_TRUE(tree.empty());
    EXPECT_EQ(tree.size(), 0);
}

TEST_F(BinaryTreeTest, InsertIncreasesSize) {
    std::set<int> tree;
    auto result = tree.insert(10);
    EXPECT_TRUE(result.second); // Вставка успешна
    EXPECT_EQ(tree.size(), 1);
    
    result = tree.insert(5);
    EXPECT_TRUE(result.second);
    EXPECT_EQ(tree.size(), 2);
}

TEST_F(BinaryTreeTest, InsertDoesNotAddDuplicates) {
    std::set<int> tree;
    tree.insert(10);
    auto result = tree.insert(10);
    
    EXPECT_FALSE(result.second); // Вставка не выполнена
    EXPECT_EQ(tree.size(), 1);
}

TEST_F(BinaryTreeTest, SearchFindsExistingElements) {
    std::set<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    
    EXPECT_TRUE(tree.find(10) != tree.end());
    EXPECT_TRUE(tree.find(5) != tree.end());
    EXPECT_TRUE(tree.find(15) != tree.end());
    EXPECT_TRUE(tree.find(3) != tree.end());
    EXPECT_TRUE(tree.find(7) != tree.end());
}

TEST_F(BinaryTreeTest, SearchReturnsFalseForNonExistingElements) {
    std::set<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    
    EXPECT_TRUE(tree.find(20) == tree.end());
    EXPECT_TRUE(tree.find(1) == tree.end());
    EXPECT_TRUE(tree.find(8) == tree.end());
}

TEST_F(BinaryTreeTest, CountReturnsCorrectNumberOfElements) {
    std::set<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    
    EXPECT_EQ(tree.count(10), 1);
    EXPECT_EQ(tree.count(5), 1);
    EXPECT_EQ(tree.count(20), 0);
}

TEST_F(BinaryTreeTest, EraseRemovesElement) {
    std::set<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    
    EXPECT_EQ(tree.erase(5), 1); // Удалено 1 элемент
    EXPECT_EQ(tree.size(), 4);
    EXPECT_TRUE(tree.find(5) == tree.end());
    EXPECT_TRUE(tree.find(10) != tree.end());
    EXPECT_TRUE(tree.find(15) != tree.end());
}

TEST_F(BinaryTreeTest, EraseNonexistentElementReturnsZero) {
    std::set<int> tree;
    tree.insert(10);
    
    EXPECT_EQ(tree.erase(20), 0);
    EXPECT_EQ(tree.size(), 1);
}

TEST_F(BinaryTreeTest, LowerBoundReturnsFirstNotLess) {
    std::set<int> tree = {1, 3, 5, 7, 9};
    
    auto it = tree.lower_bound(5);
    EXPECT_EQ(*it, 5);
    
    it = tree.lower_bound(6);
    EXPECT_EQ(*it, 7);
    
    it = tree.lower_bound(10);
    EXPECT_TRUE(it == tree.end());
}

TEST_F(BinaryTreeTest, UpperBoundReturnsFirstGreater) {
    std::set<int> tree = {1, 3, 5, 7, 9};
    
    auto it = tree.upper_bound(5);
    EXPECT_EQ(*it, 7);
    
    it = tree.upper_bound(6);
    EXPECT_EQ(*it, 7);
    
    it = tree.upper_bound(9);
    EXPECT_TRUE(it == tree.end());
}

TEST_F(BinaryTreeTest, EqualRangeReturnsRange) {
    std::set<int> tree = {1, 3, 5, 7, 9};
    
    auto range = tree.equal_range(5);
    EXPECT_EQ(*range.first, 5);
    EXPECT_EQ(*range.second, 7);
}

TEST_F(BinaryTreeTest, SetIsSortedAutomatically) {
    std::set<int> tree;
    tree.insert(5);
    tree.insert(1);
    tree.insert(8);
    tree.insert(3);
    tree.insert(6);
    
    std::vector<int> expected = {1, 3, 5, 6, 8};
    std::vector<int> actual(tree.begin(), tree.end());
    
    EXPECT_EQ(actual, expected);
}

TEST_F(BinaryTreeTest, PopFrontUsingIterator) {
    std::set<int> tree = {1, 2, 3, 4, 5};
    
    // Удаляем первый элемент (минимальный)
    tree.erase(tree.begin());
    EXPECT_EQ(tree.size(), 4);
    EXPECT_TRUE(tree.find(1) == tree.end());
    EXPECT_EQ(*tree.begin(), 2);
}

TEST_F(BinaryTreeTest, PopBackUsingIterator) {
    std::set<int> tree = {1, 2, 3, 4, 5};
    
    // Удаляем последний элемент (максимальный)
    tree.erase(std::prev(tree.end()));
    EXPECT_EQ(tree.size(), 4);
    EXPECT_TRUE(tree.find(5) == tree.end());
    EXPECT_EQ(*tree.rbegin(), 4);
}

