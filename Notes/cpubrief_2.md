# Understanding the Flashing Concept

In the previous discussion (`cpubrief_1`), we explored the idea of abstract models. By understanding that the CPU follows a **load-store architecture**, we can see that two essential files are required for the microcontroller (MCU) to boot, especially in ARM processors:

1. **Startup Code**
2. **Linker Script**

## Role of Startup Code and Linker Script
- When examining the memory regions of the CPU, the **startup code** defines the **entry point** and is responsible for copying data from **Flash to RAM**.
- The **linker script** determines the exact **start address** of the firmware and organizes the memory layout.

## Building a Complete Firmware
To produce a fully functional firmware file, we need both:
- A **startup code** to handle the boot process.
- A **linker script** to define memory regions and startup operations.

## Abstract Model Perspective
From an abstract viewpoint, the CPU loads data into **RAM** and utilizes it for execution. This approach is necessary for **faster code execution**, as RAM access is significantly faster than Flash. The **ARM Cortex-M series MCUs** are specifically designed to handle code execution in this manner efficiently.

