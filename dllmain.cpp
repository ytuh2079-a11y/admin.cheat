#include <windows.h>
#include "AdminUI.h"
#include "AdvancedAdminCheat.h"

using namespace AdminAddon;

// Глобальные переменные
static AdminUI* g_adminUI = nullptr;
static AdvancedAdminCheat* g_adminCheat = nullptr;
static bool g_initialized = false;

// Экспортируемые функции
extern "C" {
    __declspec(dllexport) void InitializeAdminCheat() {
        if (g_initialized) return;
        
        g_adminCheat = &AdvancedAdminCheat::GetInstance();
        g_adminUI = &AdminUI::GetInstance();
        
        g_adminCheat->Initialize();
        g_adminUI->Initialize();
        
        g_initialized = true;
        MessageBoxA(nullptr, "AdminAddon v1.0 - INITIALIZED", "Cheat System", MB_OK | MB_ICONINFORMATION);
    }

    __declspec(dllexport) void ShutdownAdminCheat() {
        if (!g_initialized) return;
        
        if (g_adminCheat) g_adminCheat->Shutdown();
        if (g_adminUI) g_adminUI->Shutdown();
        
        g_initialized = false;
    }

    __declspec(dllexport) void RenderUI() {
        if (!g_initialized || !g_adminUI) return;
        g_adminUI->Render();
    }

    __declspec(dllexport) void UpdateCheat(float deltaTime) {
        if (!g_initialized || !g_adminCheat) return;
        g_adminCheat->Update(deltaTime);
    }

    __declspec(dllexport) void ToggleUI() {
        if (!g_initialized || !g_adminUI) return;
        g_adminUI->ToggleVisibility();
    }

    // Speed functions
    __declspec(dllexport) void SetSpeed(float speed) {
        if (!g_initialized || !g_adminCheat) return;
        g_adminCheat->SetSpeed(speed);
    }

    // God mode
    __declspec(dllexport) void SetGodMode(bool enabled) {
        if (!g_initialized || !g_adminCheat) return;
        g_adminCheat->SetGodMode(enabled);
    }

    // Invisibility
    __declspec(dllexport) void SetInvisibility(bool enabled) {
        if (!g_initialized || !g_adminCheat) return;
        g_adminCheat->SetInvisibility(enabled);
    }

    // Fly
    __declspec(dllexport) void SetFly(bool enabled) {
        if (!g_initialized || !g_adminCheat) return;
        g_adminCheat->SetFly(enabled);
    }

    // NoClip
    __declspec(dllexport) void SetNoClip(bool enabled) {
        if (!g_initialized || !g_adminCheat) return;
        g_adminCheat->SetNoClip(enabled);
    }

    // Spawning
    __declspec(dllexport) void SpawnItem(const char* itemName, int quantity) {
        if (!g_initialized || !g_adminCheat) return;
        g_adminCheat->SpawnItem(itemName, quantity, "legendary");
    }

    __declspec(dllexport) void RainItems(const char* itemName, int count) {
        if (!g_initialized || !g_adminCheat) return;
        g_adminCheat->RainItems(itemName, count);
    }

    // Combat
    __declspec(dllexport) void OneHitKill(bool enabled) {
        if (!g_initialized || !g_adminCheat) return;
        g_adminCheat->OneHitKill(enabled);
    }

    __declspec(dllexport) void InfiniteDamage(bool enabled) {
        if (!g_initialized || !g_adminCheat) return;
        g_adminCheat->InfiniteDamage(enabled);
    }

    __declspec(dllexport) void MassKill() {
        if (!g_initialized || !g_adminCheat) return;
        g_adminCheat->MassKill();
    }

    __declspec(dllexport) void ActivateBerserk() {
        if (!g_initialized || !g_adminCheat) return;
        g_adminCheat->ActivateBerserk();
    }

    __declspec(dllexport) void ActivateUltimate() {
        if (!g_initialized || !g_adminCheat) return;
        g_adminCheat->ActivateUltimate();
    }

    // Inventory
    __declspec(dllexport) void FillInventory() {
        if (!g_initialized || !g_adminCheat) return;
        g_adminCheat->FillInventory();
    }

    __declspec(dllexport) void MaxUpgradeAll() {
        if (!g_initialized || !g_adminCheat) return;
        g_adminCheat->MaxUpgradeAll();
    }

    __declspec(dllexport) void GiveAllWeapons() {
        if (!g_initialized || !g_adminCheat) return;
        g_adminCheat->GiveAllWeapons();
    }

    __declspec(dllexport) void GiveAllArmor() {
        if (!g_initialized || !g_adminCheat) return;
        g_adminCheat->GiveAllArmor();
    }

    __declspec(dllexport) void MaxGold(int amount) {
        if (!g_initialized || !g_adminCheat) return;
        g_adminCheat->MaxGold(amount);
    }

    // Environment
    __declspec(dllexport) void RevealMap() {
        if (!g_initialized || !g_adminCheat) return;
        g_adminCheat->RevealMap();
    }

    __declspec(dllexport) void DestroyEnvironment(float radius) {
        if (!g_initialized || !g_adminCheat) return;
        g_adminCheat->DestroyEnvironment(radius);
    }

    // Config
    __declspec(dllexport) void SaveConfig(const char* filename) {
        if (!g_initialized || !g_adminCheat) return;
        g_adminCheat->SaveConfig(filename);
    }

    __declspec(dllexport) void LoadConfig(const char* filename) {
        if (!g_initialized || !g_adminCheat) return;
        g_adminCheat->LoadConfig(filename);
    }

    __declspec(dllexport) bool IsInitialized() {
        return g_initialized;
    }
}

// DLL Entry Point
BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    switch (ul_reason_for_call) {
        case DLL_PROCESS_ATTACH:
            break;

        case DLL_THREAD_ATTACH:
            break;

        case DLL_THREAD_DETACH:
            break;

        case DLL_PROCESS_DETACH:
            if (g_initialized) {
                ShutdownAdminCheat();
            }
            break;
    }
    return TRUE;
}
