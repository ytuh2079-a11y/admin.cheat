#pragma once
#include <string>
#include <map>
#include <functional>
#include <vector>

namespace AdminAddon {

class Command {
public:
    virtual ~Command() = default;
    virtual void Execute(const std::vector<std::string>& args) = 0;
    virtual std::string GetName() const = 0;
    virtual std::string GetDescription() const = 0;
};

class AdminCheat {
public:
    static AdminCheat& GetInstance() {
        static AdminCheat instance;
        return instance;
    }

    void Initialize();
    void ProcessCommand(const std::string& command);
    void Update();

    // Admin Commands
    void SetSpeed(float speed);
    void SetGodMode(bool enabled);
    void SpawnItem(const std::string& itemName, int quantity = 1);
    void TeleportToPlayer(const std::string& playerName);
    void HealPlayer(const std::string& playerName, float amount);
    void KillPlayer(const std::string& playerName);
    void GiveAllItems();
    void ClearInventory();
    void SetInvisible(bool enabled);

    bool IsGodModeEnabled() const { return godModeEnabled; }
    float GetCurrentSpeed() const { return currentSpeed; }
    bool IsInvisible() const { return invisibilityEnabled; }

private:
    AdminCheat() = default;
    ~AdminCheat() = default;

    AdminCheat(const AdminCheat&) = delete;
    AdminCheat& operator=(const AdminCheat&) = delete;

    std::map<std::string, std::shared_ptr<Command>> commands;
    bool godModeEnabled = false;
    float currentSpeed = 1.0f;
    bool invisibilityEnabled = false;
    bool initialized = false;

    void RegisterCommands();
    void ParseAndExecute(const std::string& input);
};

// Command implementations
class SpeedCommand : public Command {
public:
    void Execute(const std::vector<std::string>& args) override;
    std::string GetName() const override { return "speed"; }
    std::string GetDescription() const override { return "Set player speed (speed <value>)"; }
};

class GodModeCommand : public Command {
public:
    void Execute(const std::vector<std::string>& args) override;
    std::string GetName() const override { return "godmode"; }
    std::string GetDescription() const override { return "Enable/disable god mode (godmode on/off)"; }
};

class SpawnCommand : public Command {
public:
    void Execute(const std::vector<std::string>& args) override;
    std::string GetName() const override { return "spawn"; }
    std::string GetDescription() const override { return "Spawn item (spawn <item_name> [quantity])"; }
};

class TeleportCommand : public Command {
public:
    void Execute(const std::vector<std::string>& args) override;
    std::string GetName() const override { return "tp"; }
    std::string GetDescription() const override { return "Teleport to player (tp <player_name>)"; }
};

class HealCommand : public Command {
public:
    void Execute(const std::vector<std::string>& args) override;
    std::string GetName() const override { return "heal"; }
    std::string GetDescription() const override { return "Heal player (heal <player_name> [amount])"; }
};

class InvisibilityCommand : public Command {
public:
    void Execute(const std::vector<std::string>& args) override;
    std::string GetName() const override { return "invisible"; }
    std::string GetDescription() const override { return "Toggle invisibility (invisible on/off)"; }
};

class KillCommand : public Command {
public:
    void Execute(const std::vector<std::string>& args) override;
    std::string GetName() const override { return "kill"; }
    std::string GetDescription() const override { return "Kill player (kill <player_name>)"; }
};

class InventoryCommand : public Command {
public:
    void Execute(const std::vector<std::string>& args) override;
    std::string GetName() const override { return "inventory"; }
    std::string GetDescription() const override { return "Manage inventory (inventory fill/clear)"; }
};

} // namespace AdminAddon
