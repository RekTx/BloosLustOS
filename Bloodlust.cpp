#include <iostream>
#include <pthread.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <iomanip>

#include "json.hpp"

using json = nlohmann::json;
using namespace std;

const int winWidth = 1280, winHeight = 720;
const char* osName = "Bloodlust";

// initializing
bool initSystemResources(int p_cores, int p_ram, int p_storage);

// Main Os Functions
bool initLayout();
bool startOS();

int main(int argc, char* argv[]) {

    if (!initSystemResources(stoi(argv[1]), stoi(argv[2]), stoi(argv[3]))) {
        cout << "System failure while initializing system resources!!!\n";
        return 1;
    }

    if (!startOS()) {
        cout << "Error starting Operating System!!!\n";
        return 1;
    }

    return 0;
}

// initializing
bool initSystemResources(int p_cores, int p_ram, int p_storage) {

    try {

        std::ifstream i("SystemData.json");
        json j;
        i >> j;

        j["Resources"]["Cores"] = p_cores;
        j["Resources"]["Memory"] = p_ram;
        j["Resources"]["Disk"] = p_storage;

        std::ofstream o("SystemData.json");
        o << std::setw(4) << j << std::endl;        

    }
    catch (...) {
        return false;
    }
    
    return true;
}

bool lockScreen() {

    try {
        const char* programPath = "/home/f223078/Documents/Project/MiniOS/Lockscreen";
        system("./g++ -o Lockscreen Lockscreen.cpp -lraylib");
        system(programPath);
    }
    catch(...) {
        return false;
    }

    return true;
}
bool startOS() {

    if (!lockScreen()) {
        cout << "Error locking screen!!!\n";
        return false;
    }

    return true;
}
