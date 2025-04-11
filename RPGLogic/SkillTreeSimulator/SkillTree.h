/*create and manage a skill tree,
where nodes represent skills or abilities, and connections represent dependencies or relationships between skills.*/

#pragma once
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>

class SkillNode {
public:
    std::string name;
    std::string bonus;
    std::vector<SkillNode*> connections;

    SkillNode(std::string name, std::string bonus)
        : name(std::move(name)), bonus(std::move(bonus)) {
    }

    void connect(SkillNode* node) {
        connections.push_back(node);
    }
};

class SkillTree {
private:
    std::unordered_map<std::string, SkillNode*> nodes;

    bool dfs(SkillNode* current, SkillNode* target, std::unordered_map<SkillNode*, bool>& visited, std::vector<SkillNode*>& path);

public:
    ~SkillTree();
    void addNode(const std::string& name, const std::string& bonus);
    void connectNodes(const std::string& node1, const std::string& node2);
    void printTree() const;
    SkillNode* getNode(const std::string& name);
    std::vector<SkillNode*> findPath(const std::string& start, const std::string& end);
};