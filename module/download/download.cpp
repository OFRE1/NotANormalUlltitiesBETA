#include <iostream>
#include <cstdlib>
#include <string>

#include "download.h"

void downloadFile(
    const std::string& url,
    const std::string& destination
) {
    std::string command =
        "powershell -NoProfile -Command "
        "\"Invoke-WebRequest "
        "-Uri '" + url + "' "
        "-OutFile '" + destination + "'\"";

    int result = system(command.c_str());

    if (result == 0) {
        std::cout
            << "Download completed successfully.\n";
    }
    else {
        std::cout
            << "Download failed.\n";
    }
}