#pragma once
#include "AdminCheat.h"
#include <imgui.h>
#include <string>

namespace AdminAddon {

class AdminUI {
public:
    static AdminUI& GetInstance() {
        static AdminUI instance;
        return instance;
    }

    void Initialize();
    void Render();
    void Shutdown();
    
    void SetVisible(bool visible) { isVisible = visible; }
    bool IsVisible() const { return isVisible; }
    void ToggleVisibility() { isVisible = !isVisible; }

private:
    AdminUI() = default;
    ~AdminUI() = default;

    AdminUI(const AdminUI&) = delete;
    AdminUI& operator=(const AdminUI&) = delete;

    bool isVisible = true;
    bool initialized = false;

    // UI State
    float speedValue = 1.0f;
    bool godModeState = false;
    bool invisibilityState = false;
    char spawnItemName[256] = "item";
    int spawnQuantity = 1;
    char playerNameBuffer[256] = "";
    float healAmount = 100.0f;
    
    // Tab state
    int currentTab = 0;

    void RenderMainPanel();
    void RenderSpeedTab();
    void RenderGodModeTab();
    void RenderInventoryTab();
    void RenderPlayerTab();
    void RenderSpawnTab();
    void RenderSettingsTab();

    void ApplyStyle();
};

} // namespace AdminAddon
