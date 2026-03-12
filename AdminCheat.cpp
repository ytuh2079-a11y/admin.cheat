#include "AdminCheat.h"
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cctype>

namespace AdminAddon {

void AdminCheat::Initialize() {
    if (initialized) return;

    RegisterCommands();
    initialized = true;
    
    std::cout << "[AdminAddon] Initialized successfully" << std::endl;
}

void AdminCheat::RegisterCommands() {
    commands["speed"] = std::make_shared<SpeedCommand>();
    commands["godmode"] = std::make_shared<GodModeCommand>();
    commands["spawn"] = std::make_shared<SpawnCommand>();
    commands["tp"] = std::make_shared<TeleportCommand>();
    commands["heal"] = std::make_shared<HealCommand>();
    commands["invisible"] = std::make_shared<InvisibilityCommand>();
    commands["kill"] = std::make_shared<KillCommand>();
    commands["inventory"] = std::make_shared<InventoryCommand>();
}

void AdminCheat::ProcessCommand(const std::string& command) {
    if (!initialized) Initialize();
    ParseAndExecute(command);
}

void AdminCheat::ParseAndExecute(const std::string& input) {
    std::istringstream iss(input);
    std::vector<std::string> args;
    std::string word;

    while (iss >> word) {
        args.push_back(word);
    }

    if (args.empty()) return;

    std::string commandName = args[0];
    std::transform(commandName.begin(), commandName.end(), commandName.begin(),
                   [](unsigned char c) { return std::tolower(c); });

    auto it = commands.find(commandName);
    if (it != commands.end()) {
        try {
            it->second->Execute(args);
        } catch (const std::exception& e) {
            std::cerr << "[AdminAddon] Error: " << e.what() << std::endl;
        }
    } else {
        std::cout << "[AdminAddon] Unknown command: " << commandName << std::endl;
        std::cout << "Available commands:" << std::endl;
        for (const auto& cmd : commands) {
            std::cout << "  " << cmd.second->GetName() << " - " 
                      << cmd.second->GetDescription() << std::endl;
        }
    }
}

void AdminCheat::Update() {
    // Periodic updates for active effects
    if (godModeEnabled) {
        // Apply god mode effects
    }
    if (invisibilityEnabled) {
        // Apply invisibility effects
    }
}

void AdminCheat::SetSpeed(float speed) {
    if (speed > 0) {
        currentSpeed = speed;
        std::cout << "[AdminAddon] Speed set to: " << speed << "x" << std::endl;
    }
}

void AdminCheat::SetGodMode(bool enabled) {
    godModeEnabled = enabled;
    std::cout << "[AdminAddon] God mode: " << (enabled ? "ENABLED" : "DISABLED") << std::endl;
}

void AdminCheat::SpawnItem(const std::string& itemName, int quantity) {
    if (quantity <= 0) quantity = 1;
    std::cout << "[AdminAddon] Spawned " << quantity << "x " << itemName << std::endl;
}

void AdminCheat::TeleportToPlayer(const std::string& playerName) {
    std::cout << "[AdminAddon] Teleported to player: " << playerName << std::endl;
}

void AdminCheat::HealPlayer(const std::string& playerName, float amount) {
    std::cout << "[AdminAddon] Healed " << playerName << " for " << amount << " HP" << std::endl;
}

void AdminCheat::KillPlayer(const std::string& playerName) {
    std::cout << "[AdminAddon] Killed player: " << playerName << std::endl;
}

void AdminCheat::GiveAllItems() {
    std::cout << "[AdminAddon] Gave all items" << std::endl;
}

void AdminCheat::ClearInventory() {
    std::cout << "[AdminAddon] Inventory cleared" << std::endl;
}

void AdminCheat::SetInvisible(bool enabled) {
    invisibilityEnabled = enabled;
    std::cout << "[AdminAddon] Invisibility: " << (enabled ? "ENABLED" : "DISABLED") << std::endl;
}

// ==================== Command Implementations ====================

void SpeedCommand::Execute(const std::vector<std::string>& args) {
    if (args.size() < 2) {
        std::cout << "Usage: speed <value>" << std::endl;
        return;
    }
    try {
        float speed = std::stof(args[1]);
        AdminCheat::GetInstance().SetSpeed(speed);
    } catch (const std::exception& e) {
        std::cerr << "Invalid speed value" << std::endl;
    }
}

void GodModeCommand::Execute(const std::vector<std::string>& args) {
    bool enabled = true;
    if (args.size() > 1) {
        std::string state = args[1];
        std::transform(state.begin(), state.end(), state.begin(),
                      [](unsigned char c) { return std::tolower(c); });
        enabled = (state == "on" || state == "1" || state == "true");
    }
    AdminCheat::GetInstance().SetGodMode(enabled);
}

void SpawnCommand::Execute(const std::vector<std::string>& args) {
    if (args.size() < 2) {
        std::cout << "Usage: spawn <item_name> [quantity]" << std::endl;
        return;
    }
    int quantity = 1;
    if (args.size() > 2) {
        try {
            quantity = std::stoi(args[2]);
        } catch (...) {}
    }
    AdminCheat::GetInstance().SpawnItem(args[1], quantity);
}

void TeleportCommand::Execute(const std::vector<std::string>& args) {
    if (args.size() < 2) {
        std::cout << "Usage: tp <player_name>" << std::endl;
        return;
    }
    AdminCheat::GetInstance().TeleportToPlayer(args[1]);
}

void HealCommand::Execute(const std::vector<std::string>& args) {
    if (args.size() < 2) {
        std::cout << "Usage: heal <player_name> [amount]" << std::endl;
        return;
    }
    float amount = 100.0f;
    if (args.size() > 2) {
        try {
            amount = std::stof(args[2]);
        } catch (...) {}
    }
    AdminCheat::GetInstance().HealPlayer(args[1], amount);
}

void InvisibilityCommand::Execute(const std::vector<std::string>& args) {
    bool enabled = true;
    if (args.size() > 1) {
        std::string state = args[1];
        std::transform(state.begin(), state.end(), state.begin(),
                      [](unsigned char c) { return std::tolower(c); });
        enabled = (state == "on" || state == "1" || state == "true");
    }
    AdminCheat::GetInstance().SetInvisible(enabled);
}

void KillCommand::Execute(const std::vector<std::string>& args) {
    if (args.size() < 2) {
        std::cout << "Usage: kill <player_name>" << std::endl;
        return;
    }
    AdminCheat::GetInstance().KillPlayer(args[1]);
}

void InventoryCommand::Execute(const std::vector<std::string>& args) {
    if (args.size() < 2) {
        std::cout << "Usage: inventory fill/clear" << std::endl;
        return;
    }
    std::string action = args[1];
    std::transform(action.begin(), action.end(), action.begin(),
                  [](unsigned char c) { return std::tolower(c); });
    
    if (action == "fill") {
        AdminCheat::GetInstance().GiveAllItems();
    } else if (action == "clear") {
        AdminCheat::GetInstance().ClearInventory();
    }
}

} // namespace AdminAddon
