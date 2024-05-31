#include <raylib.h>
#include <fstream>
#include <iomanip>
#include "json.hpp"

using json = nlohmann::json;

int main() {

    int screenWidth = 600, screenHeight = 350;

    InitWindow(screenWidth, screenHeight, "Task Manager");

    SetTargetFPS(60);

    Font arialRB = LoadFontEx("resources/ARLRDBD_0.TTF", 25, 0, 250);

    json j;

    int cores, ram, storage;
    int allocatedCores, allocatedRAM, allocatedStorage;

    while (!WindowShouldClose()) {

        std::ifstream i("SystemData.json");
        i >> j;
        i.close();

        cores = j["Resources"]["Cores"];
        ram = j["Resources"]["Memory"];
        storage = j["Resources"]["Disk"];

        allocatedCores = j["Allocated"]["Cores"];
        allocatedRAM = j["Allocated"]["Memory"];
        allocatedStorage = j["Allocated"]["Disk"];

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawTextEx(arialRB, "Task Manager", { 10, 10 }, 25, 0, BLACK);

        DrawTextEx(arialRB, ("Cores: " + std::to_string(cores)).c_str(), { 10, 50 }, 25, 0, BLACK);
        DrawTextEx(arialRB, ("Memory: " + std::to_string(ram)).c_str(), { 10, 90 }, 25, 0, BLACK);
        DrawTextEx(arialRB, ("Disk: " + std::to_string(storage)).c_str(), { 10, 130 }, 25, 0, BLACK);

        DrawTextEx(arialRB, ("Allocated Cores: " + std::to_string(allocatedCores)).c_str(), { 10, 170 }, 25, 0, BLACK);
        DrawTextEx(arialRB, ("Allocated Memory: " + std::to_string(allocatedRAM)).c_str(), { 10, 210 }, 25, 0, BLACK);
        DrawTextEx(arialRB, ("Allocated Disk: " + std::to_string(allocatedStorage)).c_str(), { 10, 250 }, 25, 0, BLACK);

        EndDrawing();

    }
    
    return 0;
}