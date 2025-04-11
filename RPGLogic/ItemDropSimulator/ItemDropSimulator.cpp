/* It provides the logic for generating random items with unique names,
rarities, types, and affixes, as well as printing item details.*/

#include "ItemGenerator.h"
#include <iostream>
#include <algorithm>

std::string ItemGenerator::generateItemName() {
    std::uniform_int_distribution<> prefixDist(0, prefixes.size() - 1);
    std::uniform_int_distribution<> suffixDist(0, suffixes.size() - 1);
    return prefixes[prefixDist(gen)] + " " + suffixes[suffixDist(gen)];
}

std::vector<std::string> ItemGenerator::generateAffixes(Rarity rarity) {
    std::vector<std::string> affixes;
    switch (rarity) {
    case Rarity::Common:
        affixes.push_back(commonAffixes[0]);
        break;
    case Rarity::Magic:
        affixes.push_back(magicAffixes[0]);
        affixes.push_back(magicAffixes[1]);
        break;
    case Rarity::Rare:
        for (const auto& affix : rareAffixes) {
            affixes.push_back(affix);
        }
        break;
    case Rarity::Unique:
        for (const auto& affix : uniqueAffixes) {
            affixes.push_back(affix);
        }
        break;
    }
    return affixes;
}

Item ItemGenerator::generateItem() {
    std::uniform_int_distribution<> rarityDist(0, 3);
    Rarity rarity = static_cast<Rarity>(rarityDist(gen));

    std::uniform_int_distribution<> typeDist(0, 2);
    ItemType type = static_cast<ItemType>(typeDist(gen));

    std::string name = generateItemName();
    Item item(name, rarity, type);

    std::vector<std::string> affixes = generateAffixes(rarity);
    for (const auto& affix : affixes) {
        item.addAffix(affix);
    }

    return item;
}

void Item::print() const {
    std::cout << "====================\n";
    std::cout << "Name: " << name << "\n";
    std::cout << "Type: ";
    switch (type) {
    case ItemType::Weapon: std::cout << "Weapon\n"; break;
    case ItemType::Armor: std::cout << "Armor\n"; break;
    case ItemType::Jewelry: std::cout << "Jewelry\n"; break;
    }
    std::cout << "Rarity: ";
    switch (rarity) {
    case Rarity::Common: std::cout << "Common\n"; break;
    case Rarity::Magic: std::cout << "Magic\n"; break;
    case Rarity::Rare: std::cout << "Rare\n"; break;
    case Rarity::Unique: std::cout << "Unique\n"; break;
    }
    std::cout << "Affixes:\n";
    for (const auto& affix : affixes) {
        std::cout << "- " << affix << "\n";
    }
    std::cout << "====================\n";
}