# Controller2 - Automated Irrigation System

## Project Overview
Controller2 is an automated irrigation system controller based on the ESP32-S3 (specifically for the `esp32s3box` board). The system manages multiple irrigation zones (up to 31) by communicating with relay blocks and a remote control ("pult") via ESP-NOW and LoRa. It features a rich graphical user interface powered by LVGL.

### Key Features
- **Multi-Zone Control:** Manages up to 31 irrigation zones distributed across multiple relay blocks.
- **Communication Layer:** 
  - **ESP-NOW:** Primary low-latency communication for controlling relays and interacting with the remote control and pump sensors.
  - **LoRa:** Secondary communication channel for remote control connectivity.
- **Advanced Irrigation Logic:** Implements sequential zone irrigation with support for "dirty water" (грязная вода) phases and adjustable timing coefficients (`k_dw_time`).
- **Rich UI:** LVGL-based interface for real-time monitoring of irrigation progress, zone status, and system settings.
- **Pump Monitoring:** Integrates a pump current sensor to detect failures (e.g., "pump not pumping").
- **OTA Updates:** Supports wireless firmware updates via ElegantOTA.

## Architecture

### Core Components
- **`src/main.cpp`**: The system entry point. Initializes settings, display, communication protocols (ESP-NOW, LoRa), and pump logic.
- **`src/auto_pumps.cpp` / `include/auto_pumps.h`**: Contains the primary business logic for irrigation. Manages zone timers, sequential execution, and UI synchronization.
- **`src/enow.cpp` / `include/enow.h`**: Implements the ESP-NOW communication protocol. Handles packet routing to relay blocks, the remote control, and processes incoming sensor data.
- **`src/display.cpp` / `include/display.h`**: Manages the LVGL display initialization and loop.
- **`src/ui/`**: Contains generated UI code (screens, styles, images) likely created with EEZ Studio.
- **`src/settings.cpp`**: Handles system configuration and persistent storage of settings.
- **`src/lora.cpp` / `include/lora.h`**: Implements LoRa communication as a fallback for the remote control.
- **`src/elegantota.cpp` / `include/elegantota.h`**: Wraps the ElegantOTA library for remote updates.
- **`include/constants.h`**: Centralized location for system constants (pin assignments, zone counts, default timers, versioning).

### Data Flow
1. **Control Loop**: `pump_loop()` in `main.cpp` calls `periodTick()` and `flowTick()` in `auto_pumps.cpp` to manage the timing of irrigation zones.
2. **Command Execution**: When a zone needs to be activated, `auto_pumps.cpp` calls `send_command()` in `enow.cpp`, which sends an ESP-NOW packet to the corresponding relay block.
3. **Feedback Loop**: 
   - Relays send delivery confirmation back via ESP-NOW.
   - The pump sensor sends current readings to detect dry-running or pump failure.
   - The system periodically sends state updates to the remote control.

## Building and Running

### Environment
- **Framework:** Arduino
- **Platform:** Espressif 32 (custom platform URL used in `platformio.ini`)
- **Board:** `esp32s3box`

### PlatformIO Commands
- **Build:** `pio run`
- **Upload:** `pio run --target upload`
- **Serial Monitor:** `pio device monitor`
- **Clean:** `pio run --target clean`

## Development Conventions

### Coding Style
- **Language:** C++ (Arduino framework).
- **Communication Language:** Russian (Русский).
- **Concurrency:** Utilizes FreeRTOS tasks for asynchronous operations, such as the `SendMessagesToPult` task to avoid blocking the main loop during network I/O.
- **UI Development:** UI is managed via LVGL. The presence of `.eez-project` files suggests that UI layout is designed in EEZ Studio and then exported to the `src/ui/` directory.
- **Constants:** All hardware-specific and tunable parameters are defined in `include/constants.h`.

### Git Conventions
- **Commit Messages:** Must be written in Russian and should not use abbreviations.

### Communication Protocol
- **ESP-NOW:** Uses packed structures (`struct_message`, `struct_message_pult`, etc.) for efficient binary transmission between the controller, relays, and the remote control.
- **Synchronization:** A `SYNC_WORD` (0xABCD) is used to validate messages sent to the remote control.
