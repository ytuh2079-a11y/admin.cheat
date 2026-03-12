@echo off
title AdminAddon Compiler
echo ========================================
echo   ADMIN ADDON DLL BUILDER v1.0
echo ========================================

:: 1. Перевірка наявності компілятора
where g++ >nul 2>nul
if %errorlevel% neq 0 (
    echo [!] ПОМИЛКА: Компілятор g++ (MinGW) не знайдено!
    echo [?] Що робити: Тобі треба встановити MinGW або вказати шлях до нього.
    echo.
    pause
    exit
)

:: 2. Спроба компіляції
echo [*] Компіляція... Зачекайте кілька секунд...
g++ -shared -o cheat.dll *.cpp -I./ -lgdi32 -ldwmapi -luser32 -static-libgcc -static-libstdc++

:: 3. Перевірка результату
if exist cheat.dll (
    echo.
    echo [+++] ПЕРЕМОГА! Файл cheat.dll успішно створено.
    echo [!] Тепер ти можеш запакувати його в архів та інжектувати.
) else (
    echo.
    echo [!] ПОМИЛКА: Код не вдалося зібрати. Подивись на червоні написи вище.
)

echo.
pause