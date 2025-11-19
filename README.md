# STM32_timersync

## Prerequisites
1. [CMake](https://cmake.org/download/)
2. [ninja](https://github.com/ninja-build/ninja/releases)
3. [Arm GNU Toolchain](https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads)
4. [openocd](https://gnutoolchains.com/arm-eabi/openocd/)

## How to use
- In VSCode, use the shortcut key `Ctrl+Shift+P` to select `CMake Configure` option under `Task: Run Build Task` for compilation settings.
- use the shortcut key `Ctrl+Shift+P` to select `CMake Build` option under `Task: Run Build Task` for compilation the program.
- use the shortcut key `Ctrl+Shift+P` to select `Flash` option under `Task: Run Build Task` to download the program to the MCU. The download option involves transferring the *.elf* file from the **./build** folder.
- Tasks related to compilation and downloads are configured in the *tasks.json* file located within the **./.vscode** folder.

