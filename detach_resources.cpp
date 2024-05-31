#include <fstream>
#include <string>
#include "json.hpp"

using json = nlohmann::json;

int main(int argc, char* argv[]) {

    if (argc < 4) {
        return 1;
    }

    std::ifstream i("SystemData.json");
    json j;
    i >> j;

    int cores = std::stoi(argv[1]);
    int ram = std::stoi(argv[2]);
    int storage = std::stoi(argv[3]);

    int allocatedCores = j["Allocated"]["Cores"];
    int allocatedRAM = j["Allocated"]["Memory"];
    int allocatedStorage = j["Allocated"]["Disk"];

    int totalCores = j["Resources"]["Cores"];
    int totalRAM = j["Resources"]["Memory"];
    int totalStorage = j["Resources"]["Disk"];

    if (
        allocatedCores - cores >= 0 &&
        allocatedRAM - ram >= 0 &&
        allocatedStorage - storage >= 0
        ) {
        j["Allocated"]["Cores"] = allocatedCores - cores;
        j["Allocated"]["Memory"] = allocatedRAM - ram;
        j["Allocated"]["Disk"] = allocatedStorage - storage;

        std::ofstream o("SystemData.json");
        o << std::setw(4) << j << std::endl;

        return 1;
    }

    std::ofstream o("SystemData.json");
    o << std::setw(4) << j << std::endl;

    return 0;
}