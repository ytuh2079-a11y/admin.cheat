// imconfig_custom.h - кастомные настройки ImGui для чита

#pragma once

// Размер шрифта по умолчанию
#define IMGUI_DEFAULT_FONT_SIZE 14.0f

// Отключить imgui.ini (конфиг файл)
#define IMGUI_DISABLE_DEFAULT_FILE_FUNCTIONS

// Включить клавиатурные шорткаты
#define IMGUI_DISABLE_OBSOLETE_FUNCTIONS 0

// Цветовая схема
#define IMGUI_HAS_IMPLOT 0

// Дополнительные defines для оптимизации
#define IMGUI_DEFINE_MATH_OPERATORS
#define IMGUI_DISABLE_OBSOLETE_KEYIO

// Использовать шрифты по умолчанию (нет подгрузки файлов)
#define IMGUI_DISABLE_FILE_FUNCTIONS
