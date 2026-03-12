# Building cheat.dll

## Система сборки: AdminAddon DLL

### Требования:
- Visual Studio 2019+ (или компилятор C++ с поддержкой C++17)
- CMake 3.10+
- Windows SDK

### Быстрая компиляция:

#### Метод 1: Командная строка (CMD/PowerShell)

```bash
# Перейти в директорию проекта
cd AdminAddon

# Создать build директорию
mkdir build
cd build

# Сгенерировать проект для Visual Studio
cmake .. -G "Visual Studio 16 2019"

# Собрать (Release конфиг)
cmake --build . --config Release
```

#### Метод 2: Visual Studio

1. Откройте `CMakeLists.txt` в Visual Studio
2. Нажмите `Ctrl + Shift + B` для компиляции
3. DLL будет в `build/bin/Release/cheat.dll`

### Структура файлов:
```
AdminAddon/
├── AdminCheat.h/cpp          # Базовая система чита
├── AdminUI.h/cpp             # ImGui интерфейс
├── AdvancedAdminCheat.h/cpp  # Расширенные функции
├── dllmain.cpp               # DLL Entry Point (экспорт функций)
├── cheat.def                 # Таблица экспорта
└── CMakeLists.txt            # Конфиг сборки
```

### Использование DLL в коде:

```cpp
#include <windows.h>

typedef void (*InitFunc)();
typedef void (*RenderFunc)();
typedef void (*SpeedFunc)(float);

HMODULE hDll = LoadLibraryA("cheat.dll");
if (hDll) {
    InitFunc Init = (InitFunc)GetProcAddress(hDll, "InitializeAdminCheat");
    RenderFunc Render = (RenderFunc)GetProcAddress(hDll, "RenderUI");
    SpeedFunc SetSpeed = (SpeedFunc)GetProcAddress(hDll, "SetSpeed");

    Init();
    SetSpeed(3.0f);
    Render();

    FreeLibrary(hDll);
}
```

### Основные экспортируемые функции:

- `InitializeAdminCheat()` - инициализация
- `RenderUI()` - рендер графического меню
- `SetGodMode(bool)` - бессмертие
- `SetSpeed(float)` - скорость
- `SetInvisibility(bool)` - невидимость
- `SetFly(bool)` - полет
- `SpawnItem(char*, int)` - спавн предметов
- `ActivateBerserk()` - берсерк режим
- `ActivateUltimate()` - ультимативная сила
- `MassKill()` - уничтожить врагов
- `FillInventory()` - заполнить инвентарь
- `MaxGold(int)` - максимум золота

### Версия: 1.0.0
### Статус: Production Ready ✓
