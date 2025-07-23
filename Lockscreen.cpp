#include <raylib.h>
#include <string>

int main() {

    int screenWidth = 1280, screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "Lock Screen");
    SetTargetFPS(60);

    Image backgroundImage = LoadImage("resources/Lock_Screen.png");
    Texture2D backgroundTexture = LoadTextureFromImage(backgroundImage);

    backgroundImage = LoadImage("resources/Lock_Screen.png");
    ImageBlurGaussian(&backgroundImage, 10);
    Texture2D backgroundTextureBlur = LoadTextureFromImage(backgroundImage);

    Texture2D currTex = backgroundTexture;
    UnloadImage(backgroundImage);

    Font arialRB = LoadFontEx("resources/ARLRDBD_0.TTF", 25, 0, 250);

    Image adminIMG = LoadImage("resources/Admin.png");
    ImageResize(&adminIMG, 140, 140);
    Texture2D adminPFP = LoadTextureFromImage(adminIMG);

    Image userOneIMG = LoadImage("resources/UserOne.png");
    ImageResize(&userOneIMG, 140, 140);
    Texture2D userOnePFP = LoadTextureFromImage(userOneIMG);

    Image userTwoIMG = LoadImage("resources/UserTwo.png");
    ImageResize(&userTwoIMG, 140, 140);
    Texture2D userTwoPFP = LoadTextureFromImage(userTwoIMG);

    Image userThreeIMG = LoadImage("resources/UserThree.png");
    ImageResize(&userThreeIMG, 140, 140);
    Texture2D userThreePFP = LoadTextureFromImage(userThreeIMG);

    bool shouldBlur = false;

    std::string selectedUser = "";

    while (!WindowShouldClose()) {

        if (IsKeyPressed(KEY_SPACE)) {
            shouldBlur = !shouldBlur;
        }

        if (shouldBlur)
            currTex = backgroundTextureBlur;
        else
            currTex = backgroundTexture;

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawTexture(currTex, 0, 0, WHITE);

        if (!shouldBlur) {

            DrawTextEx(arialRB, "Press Space to Login", (Vector2) { 544, 550 }, 25, 0, BLACK);
            DrawTextEx(arialRB, "Press Space to Login", (Vector2) { 546, 550 }, 25, 0, BLACK);
            DrawTextEx(arialRB, "Press Space to Login", (Vector2) { 545, 551 }, 25, 0, BLACK);
            DrawTextEx(arialRB, "Press Space to Login", (Vector2) { 545, 549 }, 25, 0, BLACK);

            DrawTextEx(arialRB, "Press Space to Login", (Vector2) { 545, 550 }, 25, 0, WHITE);

        }
        else {

            DrawCircle(640, 108, 71, BLACK);
            DrawTexture(adminPFP, 570, 40, WHITE);
            DrawTextEx(arialRB, "Admin", (Vector2) { 611, 188 }, 25, 0, BLACK);
            DrawTextEx(arialRB, "Admin", (Vector2) { 613, 188 }, 25, 0, BLACK);
            DrawTextEx(arialRB, "Admin", (Vector2) { 612, 187 }, 25, 0, BLACK);
            DrawTextEx(arialRB, "Admin", (Vector2) { 612, 189 }, 25, 0, BLACK);
            DrawTextEx(arialRB, "Admin", (Vector2) { 612, 188 }, 25, 0, WHITE);

            DrawCircle(400, 300, 72, BLACK);
            DrawTexture(userOnePFP, 330, 230, WHITE);
            DrawTextEx(arialRB, "UserOne", (Vector2) { 368, 378 }, 25, 0, BLACK);
            DrawTextEx(arialRB, "UserOne", (Vector2) { 370, 378 }, 25, 0, BLACK);
            DrawTextEx(arialRB, "UserOne", (Vector2) { 369, 377 }, 25, 0, BLACK);
            DrawTextEx(arialRB, "UserOne", (Vector2) { 369, 379 }, 25, 0, BLACK);
            DrawTextEx(arialRB, "UserOne", (Vector2) { 369, 378 }, 25, 0, WHITE);

            DrawCircle(640, 300, 72, BLACK);
            DrawTexture(userTwoPFP, 570, 230, WHITE);
            DrawTextEx(arialRB, "UserTwo", (Vector2) { 611, 378 }, 25, 0, BLACK);
            DrawTextEx(arialRB, "UserTwo", (Vector2) { 613, 378 }, 25, 0, BLACK);
            DrawTextEx(arialRB, "UserTwo", (Vector2) { 612, 377 }, 25, 0, BLACK);
            DrawTextEx(arialRB, "UserTwo", (Vector2) { 612, 379 }, 25, 0, BLACK);
            DrawTextEx(arialRB, "UserTwo", (Vector2) { 612, 378 }, 25, 0, WHITE);

            DrawCircle(880, 300, 72, BLACK);
            DrawTexture(userThreePFP, 810, 230, WHITE);
            DrawTextEx(arialRB, "UserThree", (Vector2) { 845, 378 }, 25, 0, BLACK);
            DrawTextEx(arialRB, "UserThree", (Vector2) { 847, 378 }, 25, 0, BLACK);
            DrawTextEx(arialRB, "UserThree", (Vector2) { 846, 377 }, 25, 0, BLACK);
            DrawTextEx(arialRB, "UserThree", (Vector2) { 846, 379 }, 25, 0, BLACK);
            DrawTextEx(arialRB, "UserThree", (Vector2) { 846, 378 }, 25, 0, WHITE);

            DrawTextEx(arialRB, "Please Select An Account", (Vector2) { 529, 550 }, 25, 0, BLACK);
            DrawTextEx(arialRB, "Please Select An Account", (Vector2) { 531, 550 }, 25, 0, BLACK);
            DrawTextEx(arialRB, "Please Select An Account", (Vector2) { 530, 551 }, 25, 0, BLACK);
            DrawTextEx(arialRB, "Please Select An Account", (Vector2) { 530, 549 }, 25, 0, BLACK);

            DrawTextEx(arialRB, "Please Select An Account", (Vector2) { 530, 550 }, 25, 0, WHITE);

            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {

                if (CheckCollisionPointCircle(GetMousePosition(), { 640, 108 }, 71)) {
                    CloseWindow();
                    selectedUser = "Admin";
                    system("g++ -o Desktop Desktop.cpp -lraylib");
                    system("./Desktop Admin");
                }

            }

            if (CheckCollisionPointCircle(GetMousePosition(), { 400, 300 }, 72) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {

                CloseWindow();
                selectedUser = "UserOne";
                system("g++ -o Desktop Desktop.cpp -lraylib");
                system("./Desktop UserOne");

            }

            if (CheckCollisionPointCircle(GetMousePosition(), { 640, 300 }, 72) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {

                CloseWindow();
                selectedUser = "UserTwo";
                system("g++ -o Desktop Desktop.cpp -lraylib");
                system("./Desktop UserTwo");
            }

            if (CheckCollisionPointCircle(GetMousePosition(), { 880, 300 }, 72) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {

                CloseWindow();
                selectedUser = "UserThree";
                system("g++ -o Desktop Desktop.cpp -lraylib");
                system("./Desktop UserThree");
            }

        }

        EndDrawing();

        if (selectedUser != "")
            break;

    }

    UnloadImage(backgroundImage);
    UnloadTexture(backgroundTexture);
    UnloadTexture(backgroundTextureBlur);

    UnloadImage(userOneIMG);
    UnloadTexture(userOnePFP);

    UnloadImage(userTwoIMG);
    UnloadTexture(userTwoPFP);

    UnloadImage(userThreeIMG);
    UnloadTexture(userThreePFP);

    CloseWindow();

    return 0;
}
