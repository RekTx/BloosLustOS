#include <raylib.h>
#include <unistd.h>
#include <cstdlib>
#include <string>
#include <ctime>
#include <chrono>
#include <pthread.h>
#include <vector>
#include <fstream>
#include <iostream>
#include "json.hpp"

using json = nlohmann::json;

struct ThreadArgs {
    
    std::string compile;
    std::string run;
    std::string name;

    ThreadArgs(std::string p_name) : name(p_name) {
        name = p_name;
        compile = "g++ -o " + name + " " + name + ".cpp -lraylib";
        run = "./" + name;
    }
    
};

std::vector<pthread_t> threads;
std::vector<std::string> waitQueue;

void* appThreadFun(void* arg) {

    ThreadArgs* a = (ThreadArgs*)arg;

    system(a->compile.c_str());
    if (system(a->run.c_str()) != 0) {
        waitQueue.push_back(a->name);
    }

    pthread_exit(NULL);
}

void createThread(std::string name) {

    pthread_t a;
    threads.push_back(a);

    ThreadArgs* arg = new ThreadArgs(name);

    pthread_create(&threads[threads.size() - 1], NULL, appThreadFun, (void*)arg);

}

void* settingThreadFun(void* arg) {

    int * a = (int*)arg;

    std::cout << *a << std::endl;

    if (*a == 1) {
        system("g++ -o Settings Settings.cpp -lraylib");
        system("./Settings 1");
    }
    else {
        system("g++ -o Settings Settings.cpp -lraylib");
        system("./Settings 0");
    }

    pthread_exit(NULL);

}

void FCFS() {

    for (auto a : waitQueue) {
        createThread(a);
        waitQueue.erase(waitQueue.begin());
    }

}

int main(int argc, char* argv[]) {

    if (argc != 2) {
        return 1;
    }

    system("g++ -o allocate_resources allocate_resources.cpp");

    // storage for OS itself
    system("./allocate_resources 0, 0, 12");
    // storage for calculator
    system("./allocate_resources 0, 0, 2");
    // storage for notepad
    system("./allocate_resources 0, 0, 3");
    // storage for settings
    system("./allocate_resources 0, 0, 2");
    // storage for flappy bird
    system("./allocate_resources 0, 0, 20");
    // storage for snake
    system("./allocate_resources 0, 0, 30");
    // storage for music
    system("./allocate_resources 0, 0, 10");
    // storage for task manager
    system("./allocate_resources 0, 0, 5");

    int screenWidth = 1280, screenHeight = 720;
    int fiveSeconds = 5;
    int counter = 0;

    bool DarkTheme = true;
    bool isAdmin = false;

    InitWindow(screenWidth, screenHeight, "Desktop");

    SetTargetFPS(60);

    Font arialRB = LoadFontEx("resources/ARLRDBD_0.TTF", 20, 0, 250);
    Font digitalFont = LoadFontEx("resources/square_sans.ttf", 50, 0, 250);

    std::string username = argv[1];
    Image userPfp = LoadImage(("resources/" + username + ".png").c_str());
    ImageResize(&userPfp, 40, 40);
    Texture2D userPfpTexture = LoadTextureFromImage(userPfp);

    if (username == "Maam") {
        std::ifstream i("settings.json");
        json j;
        i >> j;
        DarkTheme = false;
        j["DarkTheme"] = false;
        isAdmin = true;
    }

    Image backgroundImage = LoadImage("resources/Desktop.png");
    ImageResize(&backgroundImage, screenWidth, screenHeight);
    Texture2D backgroundTexture = LoadTextureFromImage(backgroundImage);

    Image backgroundImageLight = LoadImage("resources/DesktopLight.png");
    ImageResize(&backgroundImageLight, screenWidth, screenHeight);
    Texture2D backgroundTextureLight = LoadTextureFromImage(backgroundImageLight);

    Image calculatorIcon = LoadImage("resources/Calculator.png");
    ImageResize(&calculatorIcon, 70, 70);
    Texture2D calculatorIconTexture = LoadTextureFromImage(calculatorIcon);

    Image notepadIcon = LoadImage("resources/Notepad.png");
    ImageResize(&notepadIcon, 70, 70);
    Texture2D notepadIconTexture = LoadTextureFromImage(notepadIcon);


    Image settingsIcon = LoadImage("resources/Settings.png");
    ImageResize(&settingsIcon, 70, 70);
    Texture2D settingsIconTexture = LoadTextureFromImage(settingsIcon);

    Image flappyBirdIcon = LoadImage("resources/FlappyBird.png");
    ImageResize(&flappyBirdIcon, 70, 70);
    Texture2D flappyBirdIconTexture = LoadTextureFromImage(flappyBirdIcon);

    Image snakeIcon = LoadImage("resources/Snake.png");
    ImageResize(&snakeIcon, 70, 70);
    Texture2D snakeIconTexture = LoadTextureFromImage(snakeIcon);

    Image taskmanagerIcon = LoadImage("resources/TaskManager.png");
    ImageResize(&taskmanagerIcon, 70, 70);
    Texture2D taskmanagerIconTexture = LoadTextureFromImage(taskmanagerIcon);

    Image musicIcon = LoadImage("resources/Music.png");
    ImageResize(&musicIcon, 70, 70);
    Texture2D musicIconTexture = LoadTextureFromImage(musicIcon);

    while (!WindowShouldClose()) {

        std::ifstream i;
        i.open(("settings.json"));
        json j;
        i >> j;
        i.close();

        if (isAdmin) {

            //SetWindowOpacity(j["Opacity"]);

        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DarkTheme = j["DarkTheme"];

        if (DarkTheme)
            DrawTexture(backgroundTexture, 0, 0, WHITE);
        else
            DrawTexture(backgroundTextureLight, 0, 0, WHITE);

        time_t now = time(0);
        tm* ltm = localtime(&now);
        std::string time = std::to_string(ltm->tm_hour) + ":" + std::to_string(ltm->tm_min) + ":" + std::to_string(ltm->tm_sec);

        DrawTextEx(digitalFont, time.c_str(), { 559, 300 }, 50, 0, RED);
        DrawTextEx(digitalFont, time.c_str(), { 561, 300 }, 50, 0, RED);
        DrawTextEx(digitalFont, time.c_str(), { 560, 299 }, 50, 0, RED);
        DrawTextEx(digitalFont, time.c_str(), { 560, 301 }, 50, 0, RED);
        DrawTextEx(digitalFont, time.c_str(), { 560, 300 }, 50, 0, WHITE);

        DrawCircle(45, 685, 21, RED);
        DrawTexture(userPfpTexture, 25, 665, WHITE);
        
        DrawTextEx(arialRB, username.c_str(), { 73, 677 }, 20, 0, RED);
        DrawTextEx(arialRB, username.c_str(), { 75, 677 }, 20, 0, RED);
        DrawTextEx(arialRB, username.c_str(), { 74, 678 }, 20, 0, RED);
        DrawTextEx(arialRB, username.c_str(), { 74, 676 }, 20, 0, RED);
        DrawTextEx(arialRB, username.c_str(), { 74, 677 }, 20, 0, WHITE);

        DrawTexture(calculatorIconTexture, 25, 25, WHITE);
        DrawTextEx(arialRB, "Calculator", {18, 100 }, 20, 0, BLACK);
        DrawTextEx(arialRB, "Calculator", {20, 100 }, 20, 0, BLACK);
        DrawTextEx(arialRB, "Calculator", {19, 99 }, 20, 0, BLACK);
        DrawTextEx(arialRB, "Calculator", {19, 101 }, 20, 0, BLACK);
        DrawTextEx(arialRB, "Calculator", {19, 100 }, 20, 0, WHITE);

        DrawTexture(notepadIconTexture, 25, 150, WHITE);
        DrawTextEx(arialRB, "Notepad", { 24,225 } ,20,  0, BLACK);
        DrawTextEx(arialRB, "Notepad", { 26,225 } ,20,  0, BLACK);
        DrawTextEx(arialRB, "Notepad", { 25,224 } ,20,  0, BLACK);
        DrawTextEx(arialRB, "Notepad", { 25,226 } ,20,  0, BLACK);
        DrawTextEx(arialRB, "Notepad", { 25,225 } ,20,  0, WHITE);

        DrawTexture(settingsIconTexture, 25, 275, WHITE);
        DrawTextEx(arialRB, "Settings", { 24, 350 }, 20, 0, BLACK);
        DrawTextEx(arialRB, "Settings", { 25, 350 }, 20, 0, BLACK);
        DrawTextEx(arialRB, "Settings", { 25, 349 }, 20, 0, BLACK);
        DrawTextEx(arialRB, "Settings", { 25, 351 }, 20, 0, BLACK);
        DrawTextEx(arialRB, "Settings", { 25, 350 }, 20, 0, WHITE);

        DrawTexture(flappyBirdIconTexture, 25, 400, WHITE);
        DrawTextEx(arialRB, "Flappy Bird", { 15, 475 }, 20, 0, BLACK);
        DrawTextEx(arialRB, "Flappy Bird", { 17, 475 }, 20, 0, BLACK);
        DrawTextEx(arialRB, "Flappy Bird", { 16, 474 }, 20, 0, BLACK);
        DrawTextEx(arialRB, "Flappy Bird", { 16, 476 }, 20, 0, BLACK);
        DrawTextEx(arialRB, "Flappy Bird", { 16, 475 }, 20, 0, WHITE);

        DrawTexture(snakeIconTexture, 25, 525, WHITE);
        DrawTextEx(arialRB, "Snake", { 32, 600 }, 20, 0, BLACK);
        DrawTextEx(arialRB, "Snake", { 34, 600 }, 20, 0, BLACK);
        DrawTextEx(arialRB, "Snake", { 33, 599 }, 20, 0, BLACK);
        DrawTextEx(arialRB, "Snake", { 33, 601 }, 20, 0, BLACK);
        DrawTextEx(arialRB, "Snake", { 33, 600 }, 20, 0, WHITE);

        DrawTexture(musicIconTexture, 1185, 525, WHITE);
        DrawTextEx(arialRB, "Music", { 1197, 600 }, 20, 0, BLACK);
        DrawTextEx(arialRB, "Music", { 1199, 600 }, 20, 0, BLACK);
        DrawTextEx(arialRB, "Music", { 1198, 599 }, 20, 0, BLACK);
        DrawTextEx(arialRB, "Music", { 1198, 601 }, 20, 0, BLACK);
        DrawTextEx(arialRB, "Music", { 1198, 600 }, 20, 0, WHITE);

        DrawTexture(taskmanagerIconTexture, 1185, 25, WHITE);
        DrawTextEx(arialRB, "    Task\nManager", { 1184, 100 }, 20, 0, BLACK);
        DrawTextEx(arialRB, "    Task\nManager", { 1186, 100 }, 20, 0, BLACK);
        DrawTextEx(arialRB, "    Task\nManager", { 1185, 99 }, 20, 0, BLACK);
        DrawTextEx(arialRB, "    Task\nManager", { 1185, 101 }, 20, 0, BLACK);
        DrawTextEx(arialRB, "    Task\nManager", { 1185, 100 }, 20, 0, WHITE);

        EndDrawing();

        if (CheckCollisionPointRec(GetMousePosition(), { 25, 25, 70, 70 }) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            createThread(std::string("Calculator").c_str());
        }

        if (CheckCollisionPointRec(GetMousePosition(), { 25, 150, 70, 70 }) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            createThread(std::string("Notepad").c_str());
        }

        if (CheckCollisionPointRec(GetMousePosition(), { 25, 275, 70, 70 }) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            //createThread(std::string("Settings").c_str());

            pthread_t a;
            threads.push_back(a);
            int *a1 = new int;

            if (isAdmin)
                *a1 = 1;
            else
                *a1 = 0;
            pthread_create(&threads[threads.size() - 1], NULL, settingThreadFun, (void*)a1);

        }

        if (CheckCollisionPointRec(GetMousePosition(), { 25, 400, 70, 70 }) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            createThread(std::string("FlappyBird").c_str());
        }

        if (CheckCollisionPointRec(GetMousePosition(), { 25, 525, 70, 70 }) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            createThread(std::string("Snake").c_str());
        }

        if (CheckCollisionPointRec(GetMousePosition(), { 1185, 525, 70, 70 }) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            createThread(std::string("Music").c_str());
        }

        if (CheckCollisionPointRec(GetMousePosition(), { 1185, 25, 70, 70 }) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            createThread(std::string("TaskManager").c_str());
        }

        counter++;

        if (counter == fiveSeconds * 60) {
            counter = 0;

            if (!waitQueue.empty())
                FCFS();
        }

    }

    for (auto t : threads) {
        pthread_join(t, NULL);
    }

    UnloadImage(backgroundImage);
    UnloadTexture(backgroundTexture);

    UnloadImage(calculatorIcon);
    UnloadTexture(calculatorIconTexture);

    UnloadImage(notepadIcon);
    UnloadTexture(notepadIconTexture);

    UnloadImage(settingsIcon);
    UnloadTexture(settingsIconTexture);

    UnloadImage(flappyBirdIcon);
    UnloadTexture(flappyBirdIconTexture);

    UnloadImage(snakeIcon);
    UnloadTexture(snakeIconTexture);

    CloseWindow();

    // deallocate resources
    system("./detach_resources 0, 0, 5");
    system("./detach_resources 0, 0, 10");
    system("./detach_resources 0, 0, 30");
    system("./detach_resources 0, 0, 20");
    system("./detach_resources 0, 0, 2");
    system("./detach_resources 0, 0, 3");
    system("./detach_resources 0, 0, 2");
    system("./detach_resources 0, 0, 12");

    return 0;
}