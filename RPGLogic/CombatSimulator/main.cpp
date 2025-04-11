#include "Character.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

void displayMenu() {
    std::cout << "\n=== Combat Simulator ===\n";
    std::cout << "1. Attack\n";
    std::cout << "2. Heal\n";
    std::cout << "3. Shield\n";
    std::cout << "4. Fireball\n";
    std::cout << "5. View Stats\n";
    std::cout << "6. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    Character player("Hero", 100, 20, 0.2);
    Character enemy("Goblin", 50, 10, 0.1);
    int choice;
    std::string filename;

    while (true) {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
        case 1:
            player.attack(enemy);
            if (enemy.isAlive()) {
                enemy.attack(player);
            }
            break;

        case 2:
            player.heal();
            enemy.attack(player);
            break;

        case 3:
            player.shield();
            enemy.attack(player);
            break;

        case 4:
            player.fireball(enemy);
            if (enemy.isAlive()) {
                enemy.attack(player);
            }
            break;

        case 5:
            player.printStats();
            enemy.printStats();
            break;

        case 6:
            std::cout << "Exiting...\n";
            return 0;

        default:
            std::cout << "Invalid choice. Try again.\n";
        }

        if (!enemy.isAlive()) {
            std::cout << enemy.name << " has been defeated!\n";
            player.gainExperience(50);
            enemy = Character("Goblin", 50, 10, 0.1);
        }

        if (!player.isAlive()) {
            std::cout << player.name << " has been defeated!\n";
            break;
        }
    }

    return 0;
}