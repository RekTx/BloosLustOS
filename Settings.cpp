#include <raylib.h>
#include <fstream>
#include "json.hpp"

using json = nlohmann::json;

int main(int argc, char* argv[]) {

    if (argc < 2) {
        return 1;
    }

    bool isAdmin = false;
    if (std::stoi(argv[1]) == 1)
        isAdmin = true;


    InitWindow(400, 400, "Settings");
    SetTargetFPS(60);

    Font arialRB = LoadFontEx("resources/ARLRDBD_0.TTF", 20, 0, 250);

    while (!WindowShouldClose()) {

        std::ifstream i("settings.json");
        json j;
        i >> j;

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawTextEx(arialRB, "Dark Theme", { 10, 13 }, 20, 0, BLACK);
        DrawTextEx(arialRB, "Dark Theme", { 12, 13 }, 20, 0, BLACK);
        DrawTextEx(arialRB, "Dark Theme", { 11, 12 }, 20, 0, BLACK);
        DrawTextEx(arialRB, "Dark Theme", { 11, 14 }, 20, 0, BLACK);
        DrawTextEx(arialRB, "Dark Theme", { 11, 13 }, 20, 0, WHITE);

        DrawRectangle(129, 12, 22, 22, BLACK);

        if (isAdmin) {

            // let the admin change opacity of the lockscreen
            DrawTextEx(arialRB, "Desktop Opacity", { 10, 50 }, 20, 0, BLACK);
            DrawTextEx(arialRB, "Desktop Opacity", { 12, 50 }, 20, 0, BLACK);
            DrawTextEx(arialRB, "Desktop Opacity", { 11, 49 }, 20, 0, BLACK);
            DrawTextEx(arialRB, "Desktop Opacity", { 11, 51 }, 20, 0, BLACK);
            DrawTextEx(arialRB, "Desktop Opacity", { 11, 50 }, 20, 0, WHITE);

            DrawRectangle(175, 50, 22, 22, BLACK);
            DrawTextEx(arialRB, "+", { 180, 50 }, 20, 0, WHITE);

            DrawRectangle(220, 50, 22, 22, BLACK);
            DrawTextEx(arialRB, "-", { 228, 50 }, 20, 0, WHITE);

            if (CheckCollisionPointRec(GetMousePosition(), { 175, 50, 22, 22 }) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                float a = j["Opacity"];
                a += 0.1;
                j["Opacity"] = a;
                std::ofstream o("settings.json");
                o << std::setw(4) << j << std::endl;
            }

            if (CheckCollisionPointRec(GetMousePosition(), { 220, 50, 22, 22 }) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                float b = j["Opacity"];
                b -= 0.1;
                j["Opacity"] = b;
                std::ofstream o("settings.json");
                o << std::setw(4) << j << std::endl;
            }

        }

        if (j["DarkTheme"] == true) {
            DrawRectangle(130, 13, 20, 20, BLACK);
        }
        else {
            DrawRectangle(130, 13, 20, 20, WHITE);
        }

        if (CheckCollisionPointRec(GetMousePosition(), { 11, 13, 200, 20 }) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {

            if (j["DarkTheme"] == true) {
                j["DarkTheme"] = false;
                std::ofstream o("settings.json");
                o << std::setw(4) << j << std::endl;
            }
            else {
                j["DarkTheme"] = true;
                std::ofstream o("settings.json");
                o << std::setw(4) << j << std::endl;
            }
        }

        EndDrawing();

    }

    CloseWindow();

    return 0;
}