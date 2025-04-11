//create and manage items in the game

#pragma once
#include <vector>
#include <string>
#include <random>
#include <unordered_map>

enum class Rarity { Common, Magic, Rare, Unique };
enum class ItemType { Weapon, Armor, Jewelry };

class Item {
public:
    std::string name;
    Rarity rarity;
    ItemType type;
    std::vector<std::string> affixes;

    Item(std::string name, Rarity rarity, ItemType type)
        : name(std::move(name)), rarity(rarity), type(type) {
    }

    void addAffix(const std::string& affix) {
        affixes.push_back(affix);
    }

    void print() const;
};

class ItemGenerator {
private:
    std::vector<std::string> commonAffixes = { "+10 Life", "+5 Mana" };
    std::vector<std::string> magicAffixes = { "+20% Fire Resistance", "+15% Attack Speed" };
    std::vector<std::string> rareAffixes = { "+30% Critical Strike Chance", "+50% Elemental Damage" };
    std::vector<std::string> uniqueAffixes = { "Grants Level 15 Summon Skeletons", "100% Increased Spell Damage" };

    std::vector<std::string> prefixes = { "Sharp", "Heavy", "Ancient", "Mystic", "Cursed" };
    std::vector<std::string> suffixes = { "Sword", "Shield", "Amulet", "Ring", "Armor" };

    std::random_device rd;
    std::mt19937 gen;

    std::string generateItemName();
    std::vector<std::string> generateAffixes(Rarity rarity);

public:
    ItemGenerator() : gen(rd()) {}
    Item generateItem();
};