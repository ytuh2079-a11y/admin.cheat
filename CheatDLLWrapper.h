#pragma once
#include <windows.h>
#include <functional>
#include <map>

namespace AdminAddon {

// Интерфейс для работы с DLL
class CheatDLL {
public:
    CheatDLL(const char* dllPath = "cheat.dll") : hDll(nullptr) {
        LoadDLL(dllPath);
    }

    ~CheatDLL() {
        UnloadDLL();
    }

    // Инициализация
    bool Initialize() {
        if (!hDll) return false;
        auto func = (void(*)())GetProcAddress(hDll, "InitializeAdminCheat");
        if (func) {
            func();
            return true;
        }
        return false;
    }

    // UI
    void RenderUI() {
        auto func = (void(*)())GetProcAddress(hDll, "RenderUI");
        if (func) func();
    }

    void ToggleUI() {
        auto func = (void(*)())GetProcAddress(hDll, "ToggleUI");
        if (func) func();
    }

    void Update(float deltaTime) {
        auto func = (void(*)(float))GetProcAddress(hDll, "UpdateCheat");
        if (func) func(deltaTime);
    }

    // Движение и скорость
    void SetSpeed(float speed) {
        auto func = (void(*)(float))GetProcAddress(hDll, "SetSpeed");
        if (func) func(speed);
    }

    void SetFly(bool enabled) {
        auto func = (void(*)(bool))GetProcAddress(hDll, "SetFly");
        if (func) func(enabled);
    }

    void SetNoClip(bool enabled) {
        auto func = (void(*)(bool))GetProcAddress(hDll, "SetNoClip");
        if (func) func(enabled);
    }

    // Защита
    void SetGodMode(bool enabled) {
        auto func = (void(*)(bool))GetProcAddress(hDll, "SetGodMode");
        if (func) func(enabled);
    }

    void SetInvisibility(bool enabled) {
        auto func = (void(*)(bool))GetProcAddress(hDll, "SetInvisibility");
        if (func) func(enabled);
    }

    // Спавн
    void SpawnItem(const char* itemName, int quantity = 1) {
        auto func = (void(*)(const char*, int))GetProcAddress(hDll, "SpawnItem");
        if (func) func(itemName, quantity);
    }

    void RainItems(const char* itemName, int count = 100) {
        auto func = (void(*)(const char*, int))GetProcAddress(hDll, "RainItems");
        if (func) func(itemName, count);
    }

    // Боевые приемы
    void ActivateBerserk() {
        auto func = (void(*)())GetProcAddress(hDll, "ActivateBerserk");
        if (func) func();
    }

    void ActivateUltimate() {
        auto func = (void(*)())GetProcAddress(hDll, "ActivateUltimate");
        if (func) func();
    }

    void MassKill() {
        auto func = (void(*)())GetProcAddress(hDll, "MassKill");
        if (func) func();
    }

    void OneHitKill(bool enabled) {
        auto func = (void(*)(bool))GetProcAddress(hDll, "OneHitKill");
        if (func) func(enabled);
    }

    void InfiniteDamage(bool enabled) {
        auto func = (void(*)(bool))GetProcAddress(hDll, "InfiniteDamage");
        if (func) func(enabled);
    }

    // Инвентарь
    void FillInventory() {
        auto func = (void(*)())GetProcAddress(hDll, "FillInventory");
        if (func) func();
    }

    void MaxUpgradeAll() {
        auto func = (void(*)())GetProcAddress(hDll, "MaxUpgradeAll");
        if (func) func();
    }

    void GiveAllWeapons() {
        auto func = (void(*)())GetProcAddress(hDll, "GiveAllWeapons");
        if (func) func();
    }

    void GiveAllArmor() {
        auto func = (void(*)())GetProcAddress(hDll, "GiveAllArmor");
        if (func) func();
    }

    void MaxGold(int amount = 999999) {
        auto func = (void(*)(int))GetProcAddress(hDll, "MaxGold");
        if (func) func(amount);
    }

    // Окружение
    void RevealMap() {
        auto func = (void(*)())GetProcAddress(hDll, "RevealMap");
        if (func) func();
    }

    void DestroyEnvironment(float radius = 50.0f) {
        auto func = (void(*)(float))GetProcAddress(hDll, "DestroyEnvironment");
        if (func) func(radius);
    }

    // Статус
    bool IsInitialized() const {
        if (!hDll) return false;
        auto func = (bool(*)())GetProcAddress(hDll, "IsInitialized");
        return func ? func() : false;
    }

    bool IsLoaded() const { return hDll != nullptr; }

private:
    HMODULE hDll;

    void LoadDLL(const char* path) {
        hDll = LoadLibraryA(path);
        if (hDll) {
            MessageBoxA(nullptr, "AdminAddon DLL loaded successfully!", "Success", MB_OK);
        } else {
            MessageBoxA(nullptr, "Failed to load AdminAddon DLL!", "Error", MB_OK | MB_ICONERROR);
        }
    }

    void UnloadDLL() {
        if (hDll) {
            auto func = (void(*)())GetProcAddress(hDll, "ShutdownAdminCheat");
            if (func) func();
            FreeLibrary(hDll);
            hDll = nullptr;
        }
    }
};

} // namespace AdminAddon

// ПРИМЕР ИСПОЛЬЗОВАНИЯ:
/*
int main() {
    AdminAddon::CheatDLL cheat("cheat.dll");
    
    if (cheat.Initialize()) {
        // Активировать все читы
        cheat.SetGodMode(true);
        cheat.SetSpeed(5.0f);
        cheat.SetInvisibility(true);
        cheat.FillInventory();
        cheat.ActivateUltimate();
        
        // Основной цикл игры
        while (/* игра запущена */) {
            cheat.Update(0.016f); // 60 FPS
            cheat.RenderUI();
        }
    }
    
    return 0;
}
*/
