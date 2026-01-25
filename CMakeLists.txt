cmake_minimum_required(VERSION 3.10)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(TaskManagerCLI)

# 1. Tell the editor/compiler where the .h files are
include_directories(include)

# 2. List all your .cpp files
# (Add more files here as you create them!)
set(SOURCES 
    app/main.cpp 
    src/utils.cpp
    ./src/core.cpp
    ./src/tasks.cpp
    ./src/filesystem.cpp
    ./src/input.cpp
)

# 3. Create the final program
add_executable(taskmanager ${SOURCES})
install(TARGETS taskmanager DESTINATION bin)
