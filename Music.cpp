#include <raylib.h>
#include <string>
#include <vector>
#include <filesystem>
#include <iostream>

int main(void) {

    system("./allocate_resources 1 250 0");

    std::vector<std::string> musicFiles;
    std::string path = "music/";
    for (const auto & entry : std::filesystem::directory_iterator(path)) {
        musicFiles.push_back(entry.path().string());
    }

    for (int i = 0; i < musicFiles.size(); i++) {
        std::cout << musicFiles[i] << std::endl;
    }

    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Music");

    InitAudioDevice();

    int currMusic = 0;
    Music music = LoadMusicStream(musicFiles[currMusic].c_str()); 

    PlayMusicStream(music);

    float timePlayed = 0.0f;
    bool pause = false;

    SetTargetFPS(30);

    while (!WindowShouldClose()) {
        
        UpdateMusicStream(music);

        if (IsKeyPressed(KEY_RIGHT)) {
            if (currMusic < musicFiles.size() - 1)
                currMusic++;
            else
                currMusic = 0;
            StopMusicStream(music);
            music = LoadMusicStream(musicFiles[currMusic].c_str());
            PlayMusicStream(music);
        }

        if (IsKeyPressed(KEY_LEFT)) {
            if (currMusic > 0)
                currMusic--;
            else
                currMusic = musicFiles.size() - 1;
            StopMusicStream(music);
            music = LoadMusicStream(musicFiles[currMusic].c_str());
            PlayMusicStream(music);
        }
        
        if (IsKeyPressed(KEY_SPACE)) {
            StopMusicStream(music);
            PlayMusicStream(music);
        }

        if (IsKeyPressed(KEY_P)) {
            pause = !pause;

            if (pause)
                PauseMusicStream(music);
            else
                ResumeMusicStream(music);
        }

        timePlayed = GetMusicTimePlayed(music)/GetMusicTimeLength(music);

        if (timePlayed > 1.0f)
            timePlayed = 1.0f;
        
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText(("PLAYING: " + musicFiles[currMusic]).c_str(), 255, 150, 20, LIGHTGRAY);

        DrawRectangle(200, 200, 400, 12, LIGHTGRAY);
        DrawRectangle(200, 200, (int)(timePlayed*400.0f), 12, MAROON);
        DrawRectangleLines(200, 200, 400, 12, GRAY);

        DrawText("PRESS SPACE TO RESTART MUSIC", 215, 250, 20, LIGHTGRAY);
        DrawText("PRESS P TO PAUSE/RESUME MUSIC", 208, 280, 20, LIGHTGRAY);

        EndDrawing();
    }

    UnloadMusicStream(music);
    CloseAudioDevice();
    CloseWindow();

    system("./detach_resources 1 250 0");

    return 0;
}