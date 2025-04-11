#include "SkillTree.h"
#include <iostream>

void displayMenu() {
    std::cout << "\n=== Skill Tree Simulator ===\n";
    std::cout << "1. Add Node\n";
    std::cout << "2. Connect Nodes\n";
    std::cout << "3. Print Tree\n";
    std::cout << "4. Find Path Between Nodes\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    SkillTree tree;
    int choice;
    std::string name, bonus, node1, node2;

    while (true) {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter node name: ";
            std::cin >> name;
            std::cout << "Enter node bonus: ";
            std::cin.ignore();
            std::getline(std::cin, bonus);
            tree.addNode(name, bonus);
            break;

        case 2:
            std::cout << "Enter first node name: ";
            std::cin >> node1;
            std::cout << "Enter second node name: ";
            std::cin >> node2;
            tree.connectNodes(node1, node2);
            break;

        case 3:
            tree.printTree();
            break;

        case 4: {
            std::cout << "Enter start node name: ";
            std::cin >> node1;
            std::cout << "Enter end node name: ";
            std::cin >> node2;
            auto path = tree.findPath(node1, node2);
            if (!path.empty()) {
                std::cout << "Path: ";
                for (const auto& node : path) {
                    std::cout << node->name << " -> ";
                }
                std::cout << "End\n";
            }
            else {
                std::cout << "No path found.\n";
            }
            break;
        }

        case 5:
            std::cout << "Exiting...\n";
            return 0;

        default:
            std::cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}