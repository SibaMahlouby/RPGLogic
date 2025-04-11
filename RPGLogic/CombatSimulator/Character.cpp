/*Defines the behavior of a character in the Combat Simulator,
including attacking, healing, shielding, casting spells, taking damage, gaining experience, leveling up, and displaying stats.*/

#include "Character.h"
#include <iostream>
#include <random>

void Character::attack(Character& target) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    bool isCritical = dis(gen) < criticalChance;
    int finalDamage = isCritical ? damage * 2 : damage;

    target.takeDamage(finalDamage);

    std::cout << name << " attacks " << target.name << " for " << finalDamage << " damage!";
    if (isCritical) {
        std::cout << " (Critical Strike!)";
    }
    std::cout << "\n";
}

void Character::heal() {
    int healAmount = maxHealth / 4;
    health = std::min(health + healAmount, maxHealth);
    std::cout << name << " heals for " << healAmount << " health.\n";
}

void Character::shield() {
    shieldActive = true; 
    std::cout << name << " raises a shield, reducing damage taken by 50% for the next attack.\n";
}

void Character::fireball(Character& target) {
    int fireballDamage = damage * 1.5;
    target.takeDamage(fireballDamage);
    std::cout << name << " casts Fireball on " << target.name << " for " << fireballDamage << " damage!\n";
}

void Character::takeDamage(int amount) {
    if (shieldActive) {
        amount = amount / 2; 
        shieldActive = false; 
        std::cout << name << "'s shield reduces the damage to " << amount << "!\n";
    }
    health -= amount;
    if (health < 0) health = 0;
}

void Character::gainExperience(int exp) {
    experience += exp;
    if (experience >= 100) {
        levelUp();
    }
}

void Character::levelUp() {
    level++;
    maxHealth += 20;
    health = maxHealth;
    damage += 5;
    criticalChance += 0.05;
    experience = 0;
    std::cout << name << " leveled up to level " << level << "!\n";
}

bool Character::isAlive() const {
    return health > 0;
}

void Character::printStats() const {
    std::cout << "====================\n";
    std::cout << "Name: " << name << "\n";
    std::cout << "Level: " << level << "\n";
    std::cout << "Health: " << health << "/" << maxHealth << "\n";
    std::cout << "Damage: " << damage << "\n";
    std::cout << "Critical Chance: " << criticalChance * 100 << "%\n";
    std::cout << "Experience: " << experience << "/100\n";
    std::cout << "Shield: " << (shieldActive ? "Active" : "Inactive") << "\n"; 
    std::cout << "====================\n";
}