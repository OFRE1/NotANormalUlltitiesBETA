#include <windows.h>
#include <iostream>
#include <string>

#include "mods.h"

void mods()
{
    std::cout << "Starting NANM Mod Loader...\n";

    // NANM.exe và NANMModLoader.exe nằm cùng thư mục
    std::string command = "NANMModLoader.exe";

    STARTUPINFOA si = {};
    PROCESS_INFORMATION pi = {};

    si.cb = sizeof(si);

    if (!CreateProcessA(
        nullptr,
        command.data(),
        nullptr,
        nullptr,
        FALSE,
        0,
        nullptr,
        nullptr,
        &si,
        &pi
    )) {
        std::cout
            << "Failed to start NANMModLoader.exe\n";

        std::cout
            << "Error code: "
            << GetLastError()
            << "\n";

        return;
    }

    // Chờ ModLoader hoàn thành
    WaitForSingleObject(
        pi.hProcess,
        INFINITE
    );

    DWORD exitCode = 0;

    GetExitCodeProcess(
        pi.hProcess,
        &exitCode
    );

    CloseHandle(pi.hThread);
    CloseHandle(pi.hProcess);

    if (exitCode != 0) {
        std::cout
            << "NANMModLoader exited with code "
            << exitCode
            << ".\n";
    }
}