#include "ItemGenerator.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

void displayMenu() {
    std::cout << "\n=== Item Drop Simulator ===\n";
    std::cout << "1. Generate Item\n";
    std::cout << "2. View All Items\n";
    std::cout << "3. Filter Items by Rarity\n";
    std::cout << "4. Exit\n";
    std::cout << "Enter your choice: ";
}

void filterItemsByRarity(const std::vector<Item>& items, Rarity rarity) {
    std::cout << "\nItems with rarity: ";
    switch (rarity) {
    case Rarity::Common: std::cout << "Common\n"; break;
    case Rarity::Magic: std::cout << "Magic\n"; break;
    case Rarity::Rare: std::cout << "Rare\n"; break;
    case Rarity::Unique: std::cout << "Unique\n"; break;
    }

    for (const auto& item : items) {
        if (item.rarity == rarity) {
            item.print();
        }
    }
}


int main() {
    ItemGenerator generator;
    std::vector<Item> items;
    int choice;
    std::string filename;

    while (true) {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
        case 1: {
            Item item = generator.generateItem();
            items.push_back(item);
            std::cout << "Generated item:\n";
            item.print();
            break;
        }

        case 2:
            for (const auto& item : items) {
                item.print();
            }
            break;

        case 3: {
            int rarity;
            std::cout << "Enter rarity (0: Common, 1: Magic, 2: Rare, 3: Unique): ";
            std::cin >> rarity;
            filterItemsByRarity(items, static_cast<Rarity>(rarity));
            break;
        }

        case 4:
            std::cout << "Exiting...\n";
            return 0;

        default:
            std::cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}