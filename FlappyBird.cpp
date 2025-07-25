#include <iostream>
#include "raylib.h"

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

#define MAX_TUBES 100
#define FLOPPY_RADIUS 24
#define TUBES_WIDTH 80

typedef struct Floppy {
    Vector2 position;
    int radius;
    Color color;
} Floppy;

typedef struct Tubes {
    Rectangle rec;
    Color color;
    bool active;
} Tubes;

static const int screenWidth = 800;
static const int screenHeight = 450;

static bool gameOver = false;
static bool pause = false;
static int score = 0;
static int hiScore = 0;

static Floppy floppy = { 0 };
static Tubes tubes[MAX_TUBES*2] = { 0 };
static Vector2 tubesPos[MAX_TUBES] = { 0 };
static int tubesSpeedX = 0;
static bool superfx = false;

static void InitGame(void);
static void UpdateGame(void);
static void DrawGame(void);
static void UnloadGame(void);
static void UpdateDrawFrame(void); 

int main(void) {

    if (system("./allocate_resources 1, 200, 0") != 0)
        return 1;

    InitWindow(screenWidth, screenHeight, "classic game: floppy");
    InitGame();

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        UpdateDrawFrame();
    }
    UnloadGame();

    CloseWindow();
    system("./detach_resources 1, 200, 0");

    return 0;
}
void InitGame(void) {

    floppy.radius = FLOPPY_RADIUS;
    floppy.position = (Vector2){80, screenHeight/2 - floppy.radius};
    tubesSpeedX = 2;

    for (int i = 0; i < MAX_TUBES; i++) {
        tubesPos[i].x = 400 + 280*i;
        tubesPos[i].y = -GetRandomValue(0, 120);
    }

    for (int i = 0; i < MAX_TUBES*2; i += 2) {
        tubes[i].rec.x = tubesPos[i/2].x;
        tubes[i].rec.y = tubesPos[i/2].y;
        tubes[i].rec.width = TUBES_WIDTH;
        tubes[i].rec.height = 255;

        tubes[i+1].rec.x = tubesPos[i/2].x;
        tubes[i+1].rec.y = 600 + tubesPos[i/2].y - 255;
        tubes[i+1].rec.width = TUBES_WIDTH;
        tubes[i+1].rec.height = 255;

        tubes[i/2].active = true;
    }

    score = 0;

    gameOver = false;
    superfx = false;
    pause = false;
}

void UpdateGame(void) {
    if (!gameOver)
    {
        if (IsKeyPressed('P'))
            pause = !pause;

        if (!pause) {
            for (int i = 0; i < MAX_TUBES; i++)
                tubesPos[i].x -= tubesSpeedX;

            for (int i = 0; i < MAX_TUBES*2; i += 2) {
                tubes[i].rec.x = tubesPos[i/2].x;
                tubes[i+1].rec.x = tubesPos[i/2].x;
            }

            if (IsKeyDown(KEY_SPACE) && !gameOver)
                floppy.position.y -= 3;
            else
                floppy.position.y += 1;

            for (int i = 0; i < MAX_TUBES*2; i++) {
                if (CheckCollisionCircleRec(floppy.position, floppy.radius, tubes[i].rec)) {
                    gameOver = true;
                    pause = false;
                }
                else if ((tubesPos[i/2].x < floppy.position.x) && tubes[i/2].active && !gameOver) {
                    score += 100;
                    tubes[i/2].active = false;

                    superfx = true;

                    if (score > hiScore)
                        hiScore = score;
                }
            }
        }
    }
    else {
        if (IsKeyPressed(KEY_ENTER)) {
            InitGame();
            gameOver = false;
        }
    }
}

void DrawGame(void) {
    BeginDrawing();

        ClearBackground(RAYWHITE);

        if (!gameOver) {
            DrawCircle(floppy.position.x, floppy.position.y, floppy.radius, DARKGRAY);

            for (int i = 0; i < MAX_TUBES; i++) {
                DrawRectangle(tubes[i*2].rec.x, tubes[i*2].rec.y, tubes[i*2].rec.width, tubes[i*2].rec.height, GRAY);
                DrawRectangle(tubes[i*2 + 1].rec.x, tubes[i*2 + 1].rec.y, tubes[i*2 + 1].rec.width, tubes[i*2 + 1].rec.height, GRAY);
            }

            if (superfx) {
                DrawRectangle(0, 0, screenWidth, screenHeight, WHITE);
                superfx = false;
            }

            DrawText(TextFormat("%04i", score), 20, 20, 40, GRAY);
            DrawText(TextFormat("HI-SCORE: %04i", hiScore), 20, 70, 20, LIGHTGRAY);

            if (pause)
                DrawText("GAME PAUSED", screenWidth/2 - MeasureText("GAME PAUSED", 40)/2, screenHeight/2 - 40, 40, GRAY);
        }
        else
            DrawText("PRESS [ENTER] TO PLAY AGAIN", GetScreenWidth()/2 - MeasureText("PRESS [ENTER] TO PLAY AGAIN", 20)/2, GetScreenHeight()/2 - 50, 20, GRAY);

    EndDrawing();
}

void UnloadGame(void) {

}

void UpdateDrawFrame(void) {
    UpdateGame();
    DrawGame();
}