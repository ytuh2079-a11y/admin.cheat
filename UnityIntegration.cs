// UnityIntegration.cs - Пример интеграции cheat.dll в Unity (C#)

using System;
using System.Runtime.InteropServices;
using UnityEngine;

public class AdminAddonUnity : MonoBehaviour {
    
    // Импорт DLL функций
    [DllImport("cheat")]
    private static extern void InitializeAdminCheat();
    
    [DllImport("cheat")]
    private static extern void ShutdownAdminCheat();
    
    [DllImport("cheat")]
    private static extern void RenderUI();
    
    [DllImport("cheat")]
    private static extern void UpdateCheat(float deltaTime);
    
    [DllImport("cheat")]
    private static extern void SetGodMode(bool enabled);
    
    [DllImport("cheat")]
    private static extern void SetSpeed(float speed);
    
    [DllImport("cheat")]
    private static extern void SetInvisibility(bool enabled);
    
    [DllImport("cheat")]
    private static extern void SetFly(bool enabled);
    
    [DllImport("cheat")]
    private static extern void ActivateUltimate();
    
    [DllImport("cheat")]
    private static extern void FillInventory();
    
    [DllImport("cheat")]
    private static extern bool IsInitialized();
    
    private static AdminAddonUnity instance;
    private bool godModeOn = false;
    private float currentSpeed = 1.0f;
    
    void Awake() {
        if (instance != null && instance != this) {
            Destroy(gameObject);
            return;
        }
        
        instance = this;
        DontDestroyOnLoad(gameObject);
        
        // Инициализация чита
        try {
            InitializeAdminCheat();
            Debug.Log("[AdminAddon] Cheat system initialized!");
        } catch (Exception e) {
            Debug.LogError("[AdminAddon] Failed to load DLL: " + e.Message);
        }
    }
    
    void Update() {
        // Обновление чита каждый фрейм
        if (IsInitialized()) {
            UpdateCheat(Time.deltaTime);
        }
        
        // Горячие клавиши
        if (Input.GetKeyDown(KeyCode.F10)) {
            ToggleGodMode();
        }
        
        if (Input.GetKeyDown(KeyCode.F11)) {
            ToggleSpeed();
        }
        
        if (Input.GetKeyDown(KeyCode.F12)) {
            ToggleInvisibility();
        }
    }
    
    void OnGUI() {
        // Рендер ImGui
        if (IsInitialized()) {
            RenderUI();
        }
    }
    
    // Команды из UI или горячих клавиш
    public void ToggleGodMode() {
        godModeOn = !godModeOn;
        SetGodMode(godModeOn);
        Debug.Log("[Cheat] God Mode: " + (godModeOn ? "ON" : "OFF"));
    }
    
    public void ToggleSpeed() {
        if (currentSpeed == 1.0f) {
            currentSpeed = 5.0f;
        } else {
            currentSpeed = 1.0f;
        }
        SetSpeed(currentSpeed);
        Debug.Log("[Cheat] Speed: " + currentSpeed + "x");
    }
    
    public void ToggleInvisibility() {
        SetInvisibility(!godModeOn); // Toggle
    }
    
    public void ActivateCombatMode() {
        SetGodMode(true);
        ActivateUltimate();
        Debug.Log("[Cheat] ULTIMATE MODE ACTIVATED!");
    }
    
    public void FillAllInventory() {
        FillInventory();
        Debug.Log("[Cheat] Inventory filled!");
    }
    
    void OnDestroy() {
        if (IsInitialized()) {
            ShutdownAdminCheat();
        }
    }
}

/*
ИНСТРУКЦИЯ ПО ИНТЕГРАЦИИ:

1. Поместить cheat.dll в папку проекта (Assets/Plugins/ или корень)

2. Создать пустой GameObject и прикрепить этот скрипт

3. В Update цикле будут проверяться F10/F11/F12 для активации читов

4. Использование:
   - GetComponent<AdminAddonUnity>().ToggleGodMode();
   - GetComponent<AdminAddonUnity>().ActivateCombatMode();
   - GetComponent<AdminAddonUnity>().FillAllInventory();

5. DLL будет автоматически загружена при старте сцены
*/
