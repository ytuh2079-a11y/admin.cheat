cmake_minimum_required(VERSION 3.10)
project(AdminAddon CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Paths to ImGui and dependencies
set(IMGUI_DIR "${CMAKE_CURRENT_SOURCE_DIR}/imgui" CACHE PATH "ImGui directory")

# Add ImGui source files
set(IMGUI_SOURCES
    ${IMGUI_DIR}/imgui.cpp
    ${IMGUI_DIR}/imgui_demo.cpp
    ${IMGUI_DIR}/imgui_draw.cpp
    ${IMGUI_DIR}/imgui_widgets.cpp
    ${IMGUI_DIR}/imgui_tables.cpp
    ${IMGUI_DIR}/backends/imgui_impl_win32.cpp
)

# Main DLL target
add_library(cheat SHARED
    AdminCheat.cpp
    AdminCheat.h
    AdminUI.cpp
    AdminUI.h
    AdvancedAdminCheat.cpp
    AdvancedAdminCheat.h
    dllmain.cpp
    cheat.def
    ${IMGUI_SOURCES}
)

# Include directories
target_include_directories(cheat PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${IMGUI_DIR}
    ${IMGUI_DIR}/backends
)

# Link Windows libraries
target_link_libraries(cheat PRIVATE
    kernel32
    user32
    gdi32
    winspool
    comdlg32
    advapi32
    shell32
    ole32
    oleaut32
    uuid
    odbc32
    odbccp32
)

# Set output directory
set_target_properties(cheat PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

# Define export macro
target_compile_definitions(cheat PRIVATE IMGUI_USER_CONFIG="imconfig_custom.h")

message(STATUS "Building AdminAddon DLL: cheat.dll")
