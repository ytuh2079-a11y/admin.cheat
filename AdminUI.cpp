#include "AdminUI.h"
#include <imgui.h>

namespace AdminAddon {

void AdminUI::Initialize() {
    if (initialized) return;
    
    AdminCheat::GetInstance().Initialize();
    ApplyStyle();
    initialized = true;
}

void AdminUI::Shutdown() {
    // Cleanup if needed
}

void AdminUI::ApplyStyle() {
    ImGuiStyle& style = ImGui::GetStyle();
    ImVec4* colors = style.Colors;

    // Dark theme with neon highlights
    colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.06f, 0.06f, 0.94f);
    colors[ImGuiCol_PopupBg] = ImVec4(0.08f, 0.08f, 0.08f, 0.94f);
    colors[ImGuiCol_Border] = ImVec4(0.00f, 1.00f, 1.00f, 0.30f);
    colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    colors[ImGuiCol_FrameBg] = ImVec4(0.16f, 0.16f, 0.16f, 0.54f);
    colors[ImGuiCol_FrameBgHovered] = ImVec4(0.19f, 0.19f, 0.19f, 0.54f);
    colors[ImGuiCol_FrameBgActive] = ImVec4(0.20f, 0.22f, 0.23f, 1.00f);
    colors[ImGuiCol_TitleBg] = ImVec4(0.04f, 0.04f, 0.04f, 1.00f);
    colors[ImGuiCol_TitleBgActive] = ImVec4(0.00f, 0.80f, 0.80f, 1.00f);
    colors[ImGuiCol_MenuBarBg] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
    colors[ImGuiCol_ScrollbarBg] = ImVec4(0.02f, 0.02f, 0.02f, 0.53f);
    colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.31f, 0.31f, 0.31f, 1.00f);
    colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.41f, 0.41f, 0.41f, 1.00f);
    colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.51f, 0.51f, 0.51f, 1.00f);
    colors[ImGuiCol_CheckMark] = ImVec4(0.00f, 1.00f, 1.00f, 1.00f);
    colors[ImGuiCol_SliderGrab] = ImVec4(0.00f, 1.00f, 1.00f, 0.35f);
    colors[ImGuiCol_SliderGrabActive] = ImVec4(0.00f, 0.86f, 0.87f, 1.00f);
    colors[ImGuiCol_Button] = ImVec4(0.00f, 0.80f, 0.80f, 0.46f);
    colors[ImGuiCol_ButtonHovered] = ImVec4(0.00f, 0.92f, 0.92f, 1.00f);
    colors[ImGuiCol_ButtonActive] = ImVec4(0.00f, 0.60f, 0.80f, 1.00f);
    colors[ImGuiCol_Header] = ImVec4(0.00f, 0.80f, 0.80f, 0.22f);
    colors[ImGuiCol_HeaderHovered] = ImVec4(0.00f, 0.92f, 0.92f, 0.80f);
    colors[ImGuiCol_HeaderActive] = ImVec4(0.00f, 0.80f, 0.80f, 1.00f);
    colors[ImGuiCol_Separator] = ImVec4(0.43f, 0.43f,0.50f, 0.50f);
    colors[ImGuiCol_SeparatorHovered] = ImVec4(0.10f, 0.40f, 0.75f, 0.78f);
    colors[ImGuiCol_SeparatorActive] = ImVec4(0.10f, 0.40f, 0.75f, 1.00f);
    colors[ImGuiCol_ResizeGrip] = ImVec4(0.00f, 1.00f, 1.00f, 0.35f);
    colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.00f, 1.00f, 1.00f, 0.60f);
    colors[ImGuiCol_ResizeGripActive] = ImVec4(0.00f, 1.00f, 1.00f, 0.90f);
    colors[ImGuiCol_Tab] = ImVec4(0.00f, 0.80f, 0.80f, 0.18f);
    colors[ImGuiCol_TabHovered] = ImVec4(0.00f, 0.92f, 0.92f, 0.80f);
    colors[ImGuiCol_TabActive] = ImVec4(0.00f, 0.80f, 0.80f, 1.00f);
    colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
    colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);

    style.WindowRounding = 8.0f;
    style.FrameRounding = 4.0f;
    style.GrabRounding = 4.0f;
    style.TabRounding = 4.0f;
}

void AdminUI::Render() {
    if (!initialized) Initialize();
    if (!isVisible) return;

    ImGui::SetNextWindowSize(ImVec2(550, 680), ImGuiCond_FirstUseEver);
    ImGui::SetNextWindowPos(ImVec2(20, 20), ImGuiCond_FirstUseEver);

    if (ImGui::Begin("##AdminAddon", &isVisible, ImGuiWindowFlags_NoMove)) {
        RenderMainPanel();
    }
    ImGui::End();
}

void AdminUI::RenderMainPanel() {
    ImGui::TextColored(ImVec4(0.0f, 1.0f, 1.0f, 1.0f), "ADMIN ADDON v1.0");
    ImGui::Separator();

    if (ImGui::BeginTabBar("##AdminTabs", ImGuiTabBarFlags_None)) {
        // Speed Tab
        if (ImGui::BeginTabItem("Speed")) {
            RenderSpeedTab();
            ImGui::EndTabItem();
        }

        // God Mode Tab
        if (ImGui::BeginTabItem("God Mode")) {
            RenderGodModeTab();
            ImGui::EndTabItem();
        }

        // Spawn Tab
        if (ImGui::BeginTabItem("Spawn")) {
            RenderSpawnTab();
            ImGui::EndTabItem();
        }

        // Inventory Tab
        if (ImGui::BeginTabItem("Inventory")) {
            RenderInventoryTab();
            ImGui::EndTabItem();
        }

        // Player Tab
        if (ImGui::BeginTabItem("Players")) {
            RenderPlayerTab();
            ImGui::EndTabItem();
        }

        // Settings Tab
        if (ImGui::BeginTabItem("Settings")) {
            RenderSettingsTab();
            ImGui::EndTabItem();
        }

        ImGui::EndTabBar();
    }

    ImGui::Separator();
    ImGui::TextColored(ImVec4(0.5f, 0.5f, 0.5f, 1.0f), "Press F10 to hide/show this panel");
}

void AdminUI::RenderSpeedTab() {
    ImGui::Text("Player Speed Control");
    ImGui::Separator();

    ImGui::SliderFloat("Speed Multiplier", &speedValue, 0.1f, 10.0f);
    ImGui::SameLine();
    if (ImGui::Button("Apply##speed")) {
        AdminCheat::GetInstance().SetSpeed(speedValue);
    }

    ImGui::Spacing();
    ImGui::TextColored(ImVec4(0.7f, 0.7f, 0.7f, 1.0f), "Current Speed: %.1fx", speedValue);

    ImGui::Spacing();
    ImGui::Text("Preset Speeds:");
    if (ImGui::Button("Normal (1.0x)")) {
        speedValue = 1.0f;
        AdminCheat::GetInstance().SetSpeed(1.0f);
    }
    ImGui::SameLine();
    if (ImGui::Button("Fast (2.0x)")) {
        speedValue = 2.0f;
        AdminCheat::GetInstance().SetSpeed(2.0f);
    }
    ImGui::SameLine();
    if (ImGui::Button("Super (5.0x)")) {
        speedValue = 5.0f;
        AdminCheat::GetInstance().SetSpeed(5.0f);
    }
}

void AdminUI::RenderGodModeTab() {
    ImGui::Text("God Mode & Invulnerability");
    ImGui::Separator();

    if (ImGui::Checkbox("God Mode Enabled", &godModeState)) {
        AdminCheat::GetInstance().SetGodMode(godModeState);
    }

    ImGui::Spacing();
    if (ImGui::Checkbox("Invisibility", &invisibilityState)) {
        AdminCheat::GetInstance().SetInvisible(invisibilityState);
    }

    ImGui::Spacing();
    ImGui::TextColored(ImVec4(0.0f, 1.0f, 0.0f, 1.0f), "God Mode: %s", 
                      godModeState ? "ENABLED" : "DISABLED");
    ImGui::TextColored(ImVec4(0.0f, 1.0f, 0.0f, 1.0f), "Invisibility: %s", 
                      invisibilityState ? "ENABLED" : "DISABLED");

    ImGui::Spacing();
    ImGui::Separator();
    ImGui::Text("Status Effects:");
    
    if (ImGui::Button("Heal Full Health")) {
        AdminCheat::GetInstance().HealPlayer("self", 999.0f);
    }
    ImGui::SameLine();
    if (ImGui::Button("Restore Mana/Energy")) {
        AdminCheat::GetInstance().HealPlayer("self", 999.0f);
    }
}

void AdminUI::RenderSpawnTab() {
    ImGui::Text("Item Spawner");
    ImGui::Separator();

    ImGui::InputText("Item Name##spawn", spawnItemName, sizeof(spawnItemName));
    ImGui::SliderInt("Quantity", &spawnQuantity, 1, 999);

    if (ImGui::Button("Spawn Item", ImVec2(150, 0))) {
        AdminCheat::GetInstance().SpawnItem(spawnItemName, spawnQuantity);
    }

    ImGui::Spacing();
    ImGui::Separator();
    ImGui::Text("Quick Spawn Presets:");

    static const char* items[] = {"Sword", "Shield", "Potion", "Gold", "Ammo", "Key", "Scroll"};
    
    for (int i = 0; i < 7; ++i) {
        if (ImGui::Button(items[i], ImVec2(80, 0))) {
            AdminCheat::GetInstance().SpawnItem(items[i], 1);
        }
        if ((i + 1) % 3 != 0) ImGui::SameLine();
    }

    ImGui::Spacing();
    ImGui::TextColored(ImVec4(0.7f, 0.7f, 0.7f, 1.0f), "Last Spawn: %s x%d", spawnItemName, spawnQuantity);
}

void AdminUI::RenderInventoryTab() {
    ImGui::Text("Inventory Management");
    ImGui::Separator();

    if (ImGui::Button("Fill Inventory", ImVec2(200, 40))) {
        AdminCheat::GetInstance().GiveAllItems();
    }
    ImGui::SameLine();
    if (ImGui::Button("Clear Inventory", ImVec2(200, 40))) {
        AdminCheat::GetInstance().ClearInventory();
    }

    ImGui::Spacing();
    ImGui::Separator();
    ImGui::Text("Display Inventory Contents:");
    ImGui::TextColored(ImVec4(0.7f, 0.7f, 0.7f, 1.0f), "Sword x2");
    ImGui::TextColored(ImVec4(0.7f, 0.7f, 0.7f, 1.0f), "Health Potion x10");
    ImGui::TextColored(ImVec4(0.7f, 0.7f, 0.7f, 1.0f), "Gold x500");
    ImGui::TextColored(ImVec4(0.7f, 0.7f, 0.7f, 1.0f), "Magic Scroll x3");
}

void AdminUI::RenderPlayerTab() {
    ImGui::Text("Player Management");
    ImGui::Separator();

    ImGui::InputText("Player Name", playerNameBuffer, sizeof(playerNameBuffer));

    ImGui::Spacing();
    ImGui::TextColored(ImVec4(1.0f, 1.0f, 0.0f, 1.0f), "Teleportation:");
    if (ImGui::Button("Teleport to Player", ImVec2(200, 0))) {
        AdminCheat::GetInstance().TeleportToPlayer(playerNameBuffer);
    }

    ImGui::Spacing();
    ImGui::TextColored(ImVec4(0.0f, 1.0f, 1.0f, 1.0f), "Healing:");
    ImGui::SliderFloat("Heal Amount", &healAmount, 1.0f, 999.0f);
    if (ImGui::Button("Heal Player", ImVec2(200, 0))) {
        AdminCheat::GetInstance().HealPlayer(playerNameBuffer, healAmount);
    }

    ImGui::Spacing();
    ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "Dangerous Actions:");
    if (ImGui::Button("Kill Player", ImVec2(200, 0))) {
        ImGui::OpenPopup("KillConfirm");
    }

    if (ImGui::BeginPopupModal("KillConfirm", nullptr, ImGuiWindowFlags_AlwaysAutoResize)) {
        ImGui::Text("Are you sure you want to kill this player?");
        ImGui::Separator();

        if (ImGui::Button("Yes, Kill", ImVec2(120, 0))) {
            AdminCheat::GetInstance().KillPlayer(playerNameBuffer);
            ImGui::CloseCurrentPopup();
        }
        ImGui::SameLine();
        if (ImGui::Button("Cancel", ImVec2(120, 0))) {
            ImGui::CloseCurrentPopup();
        }

        ImGui::EndPopup();
    }

    ImGui::Spacing();
    ImGui::Separator();
    ImGui::TextColored(ImVec4(0.7f, 0.7f, 0.7f, 1.0f), "Connected Players:");
    ImGui::TextColored(ImVec4(0.5f, 0.5f, 0.5f, 1.0f), "Player1, Player2, Player3");
}

void AdminUI::RenderSettingsTab() {
    ImGui::Text("Addon Settings");
    ImGui::Separator();

    ImGui::TextColored(ImVec4(1.0f, 1.0f, 0.0f, 1.0f), "General Settings:");
    
    static bool soundEnabled = true;
    ImGui::Checkbox("Enable Sound Effects", &soundEnabled);
    
    static bool notificationsEnabled = true;
    ImGui::Checkbox("Show Notifications", &notificationsEnabled);

    ImGui::Spacing();
    ImGui::TextColored(ImVec4(1.0f, 1.0f, 0.0f, 1.0f), "UI Settings:");
    
    static float windowOpacity = 0.94f;
    ImGui::SliderFloat("Window Opacity", &windowOpacity, 0.4f, 1.0f);

    ImGui::Spacing();
    ImGui::Separator();
    ImGui::TextColored(ImVec4(0.7f, 0.7f, 0.7f, 1.0f), "Addon Version: 1.0.0");
    ImGui::TextColored(ImVec4(0.7f, 0.7f, 0.7f, 1.0f), "Status: Active");

    ImGui::Spacing();
    if (ImGui::Button("Reset to Defaults", ImVec2(200, 0))) {
        speedValue = 1.0f;
        godModeState = false;
        invisibilityState = false;
    }
}

} // namespace AdminAddon
