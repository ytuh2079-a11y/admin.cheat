# 🎮 AdminAddon - Профессиональный чит DLL

**Версия:** 1.0.0  
**Язык:** C++ 17  
**Тип:** Windows DLL  
**Статус:** Production Ready ✓

---

## 📋 Содержание

- [Особенности](#особенности)
- [Быстрая компиляция](#быстрая-компиляция)
- [Функционал](#функционал)
- [Использование](#использование)
- [Клавиши](#горячие-клавиши)

---

## 🌟 Особенности

✅ **Полнофункциональная админ-панель** с графическим интерфейсом  
✅ **Система боевых эффектов** с длительностью  
✅ **Режим berserker и ultimate** для максимального урона  
✅ **Спавн предметов и мобов** на любой стадии  
✅ **God mode, невидимость, полет, no-clip**  
✅ **Система макросов** для автоматизации  
✅ **Сохранение и загрузка конфигов**  
✅ **Статистика убийств и урона**

---

## 🚀 Быстрая компиляция

### Windows (easiest way)

```bash
# Двойной клик на build.bat (или в CMD)
cd AdminAddon
build.bat
```

### Manual CMake

```bash
mkdir build
cd build
cmake .. -G "Visual Studio 16 2019"
cmake --build . --config Release
```

**Результат:** `build\bin\Release\cheat.dll`

---

## ⚡ Функционал

### Движение & Скорость
- 🏃 `SetSpeed(float)` - множитель скорости (1.0 = норма)
- 🚀 `SetFly(bool)` - режим полета
- 🎮 `SetNoClip(bool)` - проход сквозь стены

### Защита
- 🛡️ `SetGodMode(bool)` - бессмертие
- 👻 `SetInvisibility(bool)` - невидимость

### Боевые приемы
- ⚔️ `ActivateBerserk()` - берсерк (x500 урон на 30сек)
- 💥 `ActivateUltimate()` - ультимативная сила (x999 урон на 60сек)
- 💀 `OneHitKill(bool)` - один удар = смерть
- ∞ `InfiniteDamage(bool)` - бесконечный урон
- 🔫 `MassKill()` - уничтожить всех врагов

### Спавн
- ✨ `SpawnItem(name, qty)` - спавн предметов
- 🌧️ `RainItems(name, count)` - дождь предметов с неба
- 👹 `SpawnNPC(name, count)` - спавн мобов

### Инвентарь
- 📦 `FillInventory()` - заполнить инвентарь
- 📈 `MaxUpgradeAll()` - все на макс уровень
- ⚔️ `GiveAllWeapons()` - все оружие
- 🔰 `GiveAllArmor()` - полная броня
- 💰 `MaxGold(amount)` - максимум золота

### Окружение
- 🗺️ `RevealMap()` - открыть всю карту
- 💣 `DestroyEnvironment(radius)` - разрушить окружение

### UI
- 🖥️ `RenderUI()` - отрисовка меню
- ⌨️ `F10` - показать/скрыть меню

---

## 💻 Использование в коде

### Простой вариант (Wrapper)

```cpp
#include "CheatDLLWrapper.h"

int main() {
    AdminAddon::CheatDLL cheat("cheat.dll");
    
    if (cheat.Initialize()) {
        cheat.SetGodMode(true);
        cheat.SetSpeed(3.0f);
        cheat.ActivateUltimate();
        cheat.FillInventory();
        cheat.RenderUI();
    }
    
    return 0;
}
```

### Продвинутый вариант (Direct Load)

```cpp
#include <windows.h>

typedef void (*InitFunc)();
typedef void (*SetSpeedFunc)(float);

int main() {
    HMODULE dll = LoadLibraryA("cheat.dll");
    
    if (dll) {
        // Инициализация
        ((InitFunc)GetProcAddress(dll, "InitializeAdminCheat"))();
        
        // Установка скорости
        ((SetSpeedFunc)GetProcAddress(dll, "SetSpeed"))(5.0f);
        
        // Бесплатное бессмертие!
        ((void(*)(bool))GetProcAddress(dll, "SetGodMode"))(true);
        
        FreeLibrary(dll);
    }
    
    return 0;
}
```

---

## 📁 Структура проекта

```
AdminAddon/
├── AdminCheat.h/cpp              # Базовая система
├── AdminUI.h/cpp                 # ImGui интерфейс
├── AdvancedAdminCheat.h/cpp      # Расширенные функции
├── CheatDLLWrapper.h             # C++ Wrapper класс
├── dllmain.cpp                   # DLL Entry Point
├── cheat.def                     # Таблица экспорта
├── CMakeLists.txt                # CMake конфиг
├── build.bat                     # Скрипт сборки
├── BUILD_INSTRUCTIONS.md         # Полные инструкции
└── README.md                     # Этот файл
```

---

## 🎯 Примеры использования

### Пример 1: God Mode + Speed Run
```cpp
cheat.SetGodMode(true);
cheat.SetSpeed(10.0f);
cheat.FillInventory();
```

### Пример 2: Берсерк боец
```cpp
cheat.SetGodMode(true);
cheat.ActivateBerserk();
cheat.OneHitKill(true);
cheat.MassKill();
```

### Пример 3: Невидимый разведчик
```cpp
cheat.SetInvisibility(true);
cheat.SetNoClip(true);
cheat.RevealMap();
cheat.SetSpeed(5.0f);
```

### Пример 4: Лутер
```cpp
cheat.FillInventory();
cheat.MaxUpgradeAll();
cheat.GiveAllWeapons();
cheat.GiveAllArmor();
cheat.MaxGold(999999);
cheat.RainItems("Gold", 1000);
```

---

## ⌨️ Горячие клавиши

| Клавиша | Действие |
|---------|----------|
| F10 | Показать/скрыть меню |
| F11 | God Mode ON/OFF |
| F12 | Невидимость ON/OFF |

---

## 🔧 Требования для компиляции

- **Visual Studio 2019+** (с C++ поддержкой)
- **CMake** 3.10+
- **Windows SDK**
- **ImGui** (входит в сборку)

---

## 📝 Лицензия

Используется в образовательных целях.

---

## 🎬 Быстрый старт

```bash
# 1. Распаковать архив
unzip AdminAddon.zip
cd AdminAddon

# 2. Скомпилировать
./build.bat
# или для Linux/Mac через WSL:
# bash build.sh

# 3. Интегрировать в игру
# Скопировать cheat.dll в её папку

# 4. Загрузить и использовать!
```

---

**Автор:** AdminAddon Team  
**Дата создания:** 2026  
**Версия:** 1.0.0 Production
