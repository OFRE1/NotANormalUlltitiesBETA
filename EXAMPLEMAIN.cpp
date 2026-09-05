// (c) 2026, Team OFRE-1
// NotANormalUllity by team OFRE-1
// file : EXAMPLEMAIN.cpp - example for build via NANMBuilder
// If you compile full, you may to use this file as main.cpp

#include <iostream>
#include <string>
#include <windows.h>

#include "../module/system/systeminfo.h"
#include "../module/download/download.h"
#include "../mods/mods.h"
#include "ver.h"

bool fileExists(const char* path) {
    DWORD attributes = GetFileAttributesA(path);

    return (
        attributes != INVALID_FILE_ATTRIBUTES &&
        !(attributes & FILE_ATTRIBUTE_DIRECTORY)
    );
}

int main(int argc, char* argv[]) {

    std::cout
        << "NotANormalUllity Version "
        << VERSION
        << std::endl;

    std::cout
        << "(c) Copyright 2026 by OFRE-1"
        << std::endl;

    if (argc > 1) {

        std::string command = argv[1];

        // =========================
        // ABOUT
        // =========================
        if (command == "-about") {
            std::cout << "NotANormalUllity Version " << VERSION << std::endl;
            return 0;
        }

        // =========================
        // MODS
        // =========================
        if (command == "-mods") {

			std::cout << "This tools will add soon :)" << std::endl;
            return 0;
        }

        // =========================
        // SYSTEM INFO
        // =========================
        if (command == "-systeminfo") {
            systeminfo();
            return 0;
        }

        // =========================
        // DOWNLOAD
        // =========================
        if (command == "-download") {
		std::string url;
		std::string destination;

		for (int i = 2; i < argc; i++) {

			std::string arg = argv[i];

			if (arg.rfind("-url:", 0) == 0) {
				url = arg.substr(5);
			}
			else if (arg.rfind("-destination:", 0) == 0) {
				destination = arg.substr(13);
			}
		}

		if (url.empty() || destination.empty()) {
			std::cout
				<< "Usage:\n"
				<< "NANM.exe -download "
				<< "-url:<URL> "
				<< "-destination:<file>\n";

			return 1;
		}

		downloadFile(url, destination);
		return 0;
        }
    }

    return 0;
}