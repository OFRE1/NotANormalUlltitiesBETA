// Write by CnC-367

#include <windows.h>
#include <iostream>
#include <string>

#include "systeminfo.h"

// ============================================================
// Registry helpers
// ============================================================

std::string readRegistryString(
    HKEY root,
    const char* subKey,
    const char* valueName
) {
    HKEY hKey;

    if (RegOpenKeyExA(
        root,
        subKey,
        0,
        KEY_READ,
        &hKey
    ) != ERROR_SUCCESS) {
        return "Unknown";
    }

    char buffer[1024] = {};
    DWORD bufferSize = sizeof(buffer);
    DWORD type = 0;

    LONG result = RegQueryValueExA(
        hKey,
        valueName,
        nullptr,
        &type,
        reinterpret_cast<LPBYTE>(buffer),
        &bufferSize
    );

    RegCloseKey(hKey);

    if (result != ERROR_SUCCESS || type != REG_SZ) {
        return "Unknown";
    }

    return std::string(buffer);
}


bool readRegistryDWORD(
    HKEY root,
    const char* subKey,
    const char* valueName,
    DWORD& value
) {
    HKEY hKey;

    if (RegOpenKeyExA(
        root,
        subKey,
        0,
        KEY_READ,
        &hKey
    ) != ERROR_SUCCESS) {
        return false;
    }

    DWORD type = 0;
    DWORD size = sizeof(DWORD);

    LONG result = RegQueryValueExA(
        hKey,
        valueName,
        nullptr,
        &type,
        reinterpret_cast<LPBYTE>(&value),
        &size
    );

    RegCloseKey(hKey);

    return (
        result == ERROR_SUCCESS &&
        type == REG_DWORD
    );
}


bool registryKeyExists(
    HKEY root,
    const char* subKey
) {
    HKEY hKey;

    LONG result = RegOpenKeyExA(
        root,
        subKey,
        0,
        KEY_READ,
        &hKey
    );

    if (result == ERROR_SUCCESS) {
        RegCloseKey(hKey);
        return true;
    }

    return false;
}


// ============================================================
// Username
// ============================================================

std::string getUsername() {
    char username[256] = {};
    DWORD size = sizeof(username);

    if (GetUserNameA(username, &size)) {
        return std::string(username);
    }

    return "Unknown";
}


// ============================================================
// Windows Build
// ============================================================

std::string getWindowsBuild() {
    return readRegistryString(
        HKEY_LOCAL_MACHINE,
        "SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion",
        "CurrentBuild"
    );
}


// ============================================================
// CPU
// ============================================================

std::string getCPU() {
    return readRegistryString(
        HKEY_LOCAL_MACHINE,
        "HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0",
        "ProcessorNameString"
    );
}


// ============================================================
// Secure Boot
// ============================================================

std::string getSecureBootState() {
    DWORD secureBoot = 0;

    if (!readRegistryDWORD(
        HKEY_LOCAL_MACHINE,
        "SYSTEM\\CurrentControlSet\\Control\\SecureBoot\\State",
        "UEFISecureBootEnabled",
        secureBoot
    )) {
        return "Unsupported / Unknown";
    }

    if (secureBoot == 1) {
        return "On";
    }

    return "Off";
}


// ============================================================
// TPM
// ============================================================

std::string getTPMState() {
    if (registryKeyExists(
        HKEY_LOCAL_MACHINE,
        "SYSTEM\\CurrentControlSet\\Services\\TPM"
    )) {
        return "Present";
    }

    return "Not detected";
}


// ============================================================
// System Information
// ============================================================

void systeminfo() {

    std::cout
        << "System Information\n";

    std::cout
        << "======================================\n\n";

    std::cout
        << "Username          : "
        << getUsername()
        << "\n";

    std::cout
        << "Windows Build     : "
        << getWindowsBuild()
        << "\n";

    std::cout
        << "CPU               : "
        << getCPU()
        << "\n";

    std::cout
        << "Secure Boot State : "
        << getSecureBootState()
        << "\n";

    std::cout
        << "TPM               : "
        << getTPMState()
        << "\n";

    std::cout << "\n";

    std::cout
        << "NotANormalUllity by OFRE-1\n";
}