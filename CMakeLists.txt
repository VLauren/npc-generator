cmake_minimum_required(VERSION 3.16)
project(NPCGenerator VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Qt6 components
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

# Executable with all source files
add_executable(npc-generator
    src/main.cpp
    src/mainwindow.cpp
    src/npcgenerator.cpp
    include/mainwindow.h
    include/npcgenerator.h
)

# Include directories
target_include_directories(npc-generator PRIVATE include)

# Link Qt
target_link_libraries(npc-generator Qt6::Core Qt6::Gui Qt6::Widgets)

# Qt settings
set_target_properties(npc-generator PROPERTIES
    AUTOMOC ON
    AUTORCC ON
    AUTOUIC ON
)

# Windows-specific: Copy Qt DLLs to build folder
if(WIN32)
    set_property(TARGET npc-generator PROPERTY WIN32_EXECUTABLE TRUE)
endif()
