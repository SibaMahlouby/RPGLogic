#include "gtest/gtest.h"
#include "../include/SkillTree.h"

TEST(SkillTreeTest, NodeConnection) {
    SkillTree tree;
    tree.addNode("Strength", "+10 Strength");
    tree.addNode("Life", "+20 Life");
    tree.connectNodes("Strength", "Life");

    auto* strengthNode = tree.getNode("Strength");
    auto* lifeNode = tree.getNode("Life");
    EXPECT_NE(strengthNode, nullptr);
    EXPECT_NE(lifeNode, nullptr);
    EXPECT_EQ(strengthNode->connections.size(), 1);
    EXPECT_EQ(lifeNode->connections.size(), 1);
    EXPECT_EQ(strengthNode->connections[0], lifeNode);
    EXPECT_EQ(lifeNode->connections[0], strengthNode);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}