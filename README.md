#  ⃝ Task Manager CLI

A lightweight, terminal-based task management system written in C++.

## ⃝ Features
* **Todo Management:** Add, show, and complete tasks with simple commands.
* **Clean Interface:** Includes a built-in console clearer and info display.

## ⃝ Commands

### `todo` Mode
| Action | Command | Description |
| :--- | :--- | :--- |
| **Add** | `todo add <task>` | Registers a new task. |
| **Show** | `todo show` | Displays all your current tasks. |
| **Done** | `todo done <id>` | Marks a specific task as finished. |
| **Remove** | `todo remove <id>` | Deletes a task from the list. |

### System Commands
* `info` - Shows version and project info.
* `clear` - Wipes the terminal screen for a fresh start.
* `help` - Opens the command guide.
* `exit` - Saves changes and closes the application.

## 🛠️ Building the Project

Ensure you have a C++ compiler installed (like `g++`).

1. **Navigate to the directory:**
   ```bash
   cd Task_managerCLI
   ```
2. **Create a build directory and navigate to it:**
   ```bash
   mkdir build
   cd build
   ```
3. **Run CMake:**
    ```bash
    cmake..
    ```
4. **build the project:**
    ```bash
    make
    ```
5. **for installation**(optional):
    
    ```bash
     sudo cmake install
    ```
