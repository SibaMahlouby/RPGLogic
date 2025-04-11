/*This class represents a character in the Combat Simulator.
It has all the attributes and behaviors of a character, such as health, damage, abilities, and leveling up.
It provides a foundation for implementing combat mechanics, abilities, and leveling systems.*/

#pragma once
#include <string>
#include <vector>
#include <random>
#include <unordered_map>

enum class Ability { Attack, Heal, Shield, Fireball };

class Character {
public:
    std::string name;
    int health;
    int maxHealth;
    int damage;
    double criticalChance;
    int level;
    int experience;
    bool shieldActive;
    std::unordered_map<Ability, int> cooldowns;

    Character(std::string name, int health, int damage, double criticalChance)
        : name(std::move(name)), health(health), maxHealth(health), damage(damage),
        criticalChance(criticalChance), level(1), experience(0), shieldActive(false) {
    }

    void attack(Character& target);
    void heal();
    void shield();
    void fireball(Character& target);
    void takeDamage(int amount);
    void gainExperience(int exp);
    void levelUp();
    bool isAlive() const;
    void printStats() const;
};