# STM32 Bare Metal Drivers

Welcome to the STM32 Bare Metal Drivers repository. This project focuses on creating fundamental drivers for STM32 microcontrollers, with an emphasis on the Nucleo F446ZE development board. The primary objective of this repository is to provide a straightforward and efficient approach for interfacing with hardware on STM32 devices using bare metal programming, without the need for an operating system or external libraries. The repository is designed to facilitate the development of custom, architecture-independent drivers, enabling you to build drivers adaptable to any STM32 board architecture.

## Features

- **Basic Driver Implementation**: This repository includes basic bare metal drivers to control various peripherals on the STM32 Nucleo F446ZE board, such as GPIO, UART, SPI, I2C, and Timer.
- **Modular Design**: The drivers are designed to be modular and easy to extend. Each driver is isolated to allow users to add new peripherals or customize existing ones.
- **Simple and Readable Code**: The code is written in C for simplicity and clarity, making it suitable for developers who are new to embedded systems programming or STM32.
- **Nucleo F446ZE**: The Nucleo F446ZE board is used as the reference platform for demonstrating and testing the drivers. It provides a solid foundation for learning and development in the STM32 ecosystem.

## Getting Started

### Prerequisites

- **STM32 Nucleo F446ZE Board**: You can use the Nucleo F446ZE or any other STM32 board with similar peripherals.
- **Toolchain**: This repository is compatible with the GNU ARM toolchain (ARM GCC) for compiling and flashing the code. Make sure to download ARM GCC from here. [https://launchpad.net/gcc-arm-embedded]
- **JTAG/SWD Debugger**: A JTAG/SWD debugger (such as ST-Link) is required to program the STM32 board and debug the application.
-- **GNU Make**: This repository also requires GNU Make for build automation. You can download it from here.

### Cloning the Repository

```bash
git clone https://github.com/adithya2424/STM32_SERIES.git
```

### Building the Project

1. Open the project in your preferred development environment (e.g., STM32CubeIDE).
2. Select the appropriate toolchain for your setup (e.g., GCC ARM).
3. Build the project using the provided Makefile or IDE build tools.
4. Flash the firmware to the Nucleo F446ZE board using a programmer/debugger.

## Contributing

Contributions are welcome! If you find bugs, have ideas for improvements, or want to add support for additional peripherals, feel free to fork the repository and submit a pull request.

### How to Contribute

1. Fork the repository.
2. Create a new branch for your feature or bug fix.
3. Make your changes and test them.
4. Commit your changes with a clear message describing the modification.
5. Push your changes and submit a pull request.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgements

- **STM32CubeIDE**: A comprehensive IDE for STM32 development.
- **Nucleo F446ZE**: A versatile STM32 development board, providing a solid platform for embedded system projects.

Feel free to explore, learn, and contribute to this project as you embark on your bare-metal development journey with STM32! Happy coding! 🚀