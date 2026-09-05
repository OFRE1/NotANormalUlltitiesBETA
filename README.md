# NotANormalUllity Beta

**NotANormalUllity (NANM)** is a small Windows command-line utility written in C++.

> Version 1.0 — 2026

## Features

NANM 1.0 currently includes:

* `-about` — Display NANM information
* `-help` — Display available commands
* `-systeminfo` — Display basic Windows system information
* `-download` — Download a file from a URL
* Modular source structure
* Configurable build system
* Custom module build support

## Commands

### About

```text
NANM.exe -about
```

Displays information about NANM and its version.

### Help

```text
NANM.exe -help
```

Displays the commands available in the current build.

### System Information

```text
NANM.exe -systeminfo
```

Displays:

* Username
* Windows Build
* CPU
* Secure Boot State
* TPM

Example:

```text
NotANormalUllity - System Information
======================================

Username          : User
Windows Build     : 19045
CPU               : ...
Secure Boot State : On
TPM               : Present
```

### Download

```text
NANM.exe -download -url:<URL> -destination:<file>
```

Example:

```text
NANM.exe -download -url:https://example.com/file.zip -destination:C:\Downloads\file.zip
```

NANM uses PowerShell's `Invoke-WebRequest` for the download operation.

## Project Structure

```text
NotANormalUllity/
├── main/
│   ├── EXAMPLEMAIN.cpp
│   └── ...
│
├── module/
│   ├── system/
│   │   ├── systeminfo.cpp
│   │   └── systeminfo.h
│   │
│   └── download/
│       ├── download.cpp
│       └── download.h
│
├── tools/
│   └── NANMBuilder.exe
│
├── configbuild.ini
├── build.cmd
│
└── binariesoutput/
    └── NANM.exe
```

## Build Configuration


For building NANM from source:

* Windows
* C++ compiler with C++17 support
* MinGW / GCC or compatible compiler
* PowerShell

To compile, please follow this action
Highly recommend to execute this in source code directory. By do it, in Windows 11 right click and click Open in Terminal, then type cmd, execute tools\build.cmd. If you are using Windows 10, open a cmd and type 'cd /d C:\path\to\NANM\source' no single quote then type tools\build.cmd

## NANM 1.0 Scope

NANM 1.0 focuses on the core utility and build system.

The following features are **not included in 1.0**:

* External mod system
* `-mods`
* `-modmodule`
* `NANMModLoader.exe`
* Runtime plugin loading

These may be considered for a future version.

## License

Copyright © 2026 OFRE-1.

Source code and build instructions are provided with this project.

---

**NotANormalUllity by OFRE-1**
