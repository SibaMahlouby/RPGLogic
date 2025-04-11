/*It provides the logic for managing a skill tree, including adding nodes,
connecting nodes, printing the tree, and finding paths between nodes*/

#include "SkillTree.h"
#include <iostream>

SkillTree::~SkillTree() {
    for (auto& pair : nodes) {
        delete pair.second;
    }
}

void SkillTree::addNode(const std::string& name, const std::string& bonus) {
    nodes[name] = new SkillNode(name, bonus);
}

void SkillTree::connectNodes(const std::string& node1, const std::string& node2) {
    if (nodes.find(node1) != nodes.end() && nodes.find(node2) != nodes.end()) {
        nodes[node1]->connect(nodes[node2]);
        nodes[node2]->connect(nodes[node1]);
    }
}

void SkillTree::printTree() const {
    for (const auto& pair : nodes) {
        std::cout << "Node: " << pair.second->name << " (Bonus: " << pair.second->bonus << ")\n";
        std::cout << "Connections: ";
        for (const auto& conn : pair.second->connections) {
            std::cout << conn->name << " ";
        }
        std::cout << "\n\n";
    }
}

SkillNode* SkillTree::getNode(const std::string& name) {
    return nodes[name];
}

bool SkillTree::dfs(SkillNode* current, SkillNode* target, std::unordered_map<SkillNode*, bool>& visited, std::vector<SkillNode*>& path) {
    if (current == target) {
        path.push_back(current);
        return true;
    }

    visited[current] = true;
    path.push_back(current);

    for (auto& neighbor : current->connections) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, target, visited, path)) {
                return true;
            }
        }
    }

    path.pop_back();
    return false;
}

std::vector<SkillNode*> SkillTree::findPath(const std::string& start, const std::string& end) {
    std::vector<SkillNode*> path;
    std::unordered_map<SkillNode*, bool> visited;

    SkillNode* startNode = getNode(start);
    SkillNode* endNode = getNode(end);

    if (startNode && endNode) {
        dfs(startNode, endNode, visited, path);
    }

    return path;
}