# Calculator_Backend

## Table of contents
1. [Description](#Description)
- [List of technologies used](#ListOfTech)
- [Implementation key parts](#KeyImplParts)
2. [Project setup and run](#ProjectSetupAndRun)
- [Build](#Build)

## Description
Calculator backend part implementation written in C++17.
This project is dedicated to gain more practical knowledge of separated development of
backend and frontend.

Dedicated UI implementations:
1. [Calculator_Frontend_Vue](https://github.com/YarikMamykin/Calculator_Frontend_Vue)
2. [Calculator_Frontend_X11](https://github.com/YarikMamykin/Calculator_Frontend_X11)

### Implementation key parts <a name="KeyImplParts"/>
- Parsing of string input into numbers and operations to be made
- Structuring of operations sequences and relations between operations
- Connection within websocket
- Unit testing

### List of technologies used <a name="ListOfTech"/>
1. [C++17](https://en.cppreference.com/w/cpp/17) - for business logic implementation
2. [GoogleTest](https://github.com/google/googletest) - for unit tests
3. [Boost](https://www.boost.org/) - for websocket connection

## Project setup

### Build

1. Build the application
- `cmake -S . -B build -DBUILD_TESTS=<ON|OFF> -DCMAKE_INSTALL_PREFIX=install -DBOOST_BUILD_CPU_THREADS=<1...N>`
- `cmake --build build -- -j <1...N>`
- `cmake --install build` 

### Run

1. `export LD_LIBRARY_PATH=${PWD}/install/lib` - specify path to shared libraries

2. To run the application go to `<installation_path>/bin` specified in previous steps and run `./calculator`.
	 By default application uses `127.0.0.1:8081` to communicate with frontend. 
	 To specify another address and port run: `CALC_HOST=<your_host> CALC_PORT=<your_port> ./calculator`

3. To run the unit tests from project root run:
	`ctest --test-dir build/tests --output-on-failure`
