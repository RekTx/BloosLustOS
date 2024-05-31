#include <raylib.h>
#include <string>
#include <vector>

std::string currLine = "";

int main() {

    system("./allocate_resources 1 40 0");

    // creating notepad
    int screenWidth = 1280, screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "Notepad");
    SetTargetFPS(60);

    std::vector<std::string> textLines;
    float textX = 10, textY = 10;

    currLine = "HELLo";

    Font arialRB = LoadFontEx("resources/ARLRDBD_0.TTF", 20, 0, 250);

    while (!WindowShouldClose()) {

        if (IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT)) {
            if (IsKeyPressed(KEY_A)) {
                currLine += "A";
            } else if (IsKeyPressed(KEY_B)) {
                currLine += "B";
            } else if (IsKeyPressed(KEY_C)) {
                currLine += "C";
            } else if (IsKeyPressed(KEY_D)) {
                currLine += "D";
            } else if (IsKeyPressed(KEY_E)) {
                currLine += "E";
            } else if (IsKeyPressed(KEY_F)) {
                currLine += "F";
            } else if (IsKeyPressed(KEY_G)) {
                currLine += "G";
            } else if (IsKeyPressed(KEY_H)) {
                currLine += "H";
            } else if (IsKeyPressed(KEY_I)) {
                currLine += "I";
            } else if (IsKeyPressed(KEY_J)) {
                currLine += "J";
            } else if (IsKeyPressed(KEY_K)) {
                currLine += "K";
            } else if (IsKeyPressed(KEY_L)) {
                currLine += "L";
            } else if (IsKeyPressed(KEY_M)) {
                currLine += "M";
            } else if (IsKeyPressed(KEY_N)) {
                currLine += "N";
            } else if (IsKeyPressed(KEY_O)) {
                currLine += "O";
            } else if (IsKeyPressed(KEY_P)) {
                currLine += "P";
            } else if (IsKeyPressed(KEY_Q)) {
                currLine += "Q";
            } else if (IsKeyPressed(KEY_R)) {
                currLine += "R";
            } else if (IsKeyPressed(KEY_S)) {
                currLine += "S";
            } else if (IsKeyPressed(KEY_T)) {
                currLine += "T";
            } else if (IsKeyPressed(KEY_U)) {
                currLine += "U";
            } else if (IsKeyPressed(KEY_V)) {
                currLine += "V";
            } else if (IsKeyPressed(KEY_W)) {
                currLine += "W";
            } else if (IsKeyPressed(KEY_X)) {
                currLine += "X";
            } else if (IsKeyPressed(KEY_Y)) {
                currLine += "Y";
            } else if (IsKeyPressed(KEY_Z)) {
                currLine += "Z";
            } else if (IsKeyPressed(KEY_ZERO)) {
                currLine += ")";
            } else if (IsKeyPressed(KEY_ONE)) {
                currLine += "!";
            } else if (IsKeyPressed(KEY_TWO)) {
                currLine += "@";
            } else if (IsKeyPressed(KEY_THREE)) {
                currLine += "#";
            } else if (IsKeyPressed(KEY_FOUR)) {
                currLine += "$";
            } else if (IsKeyPressed(KEY_FIVE)) {
                currLine += "%";
            } else if (IsKeyPressed(KEY_SIX)) {
                currLine += "^";
            } else if (IsKeyPressed(KEY_SEVEN)) {
                currLine += "&";
            } else if (IsKeyPressed(KEY_EIGHT)) {
                currLine += "*";
            } else if (IsKeyPressed(KEY_NINE)) {
                currLine += "()";
            } else if (IsKeyPressed(KEY_COMMA)) {
                currLine += "<";
            } else if (IsKeyPressed(KEY_PERIOD)) {
                currLine += ">";
            } else if (IsKeyPressed(KEY_SEMICOLON)) {
                currLine += ":";
            } else if (IsKeyPressed(KEY_APOSTROPHE)) {
                currLine += "\"";
            } else if (IsKeyPressed(KEY_LEFT_BRACKET)) {
                currLine += "{";
            } else if (IsKeyPressed(KEY_RIGHT_BRACKET)) {
                currLine += "}";
            } else if (IsKeyPressed(KEY_BACKSLASH)) {
                currLine += "|";
            } else if (IsKeyPressed(KEY_GRAVE)) {
                currLine += "~";
            } else if (IsKeyPressed(KEY_MINUS)) {
                currLine += "_";
            } else if (IsKeyPressed(KEY_EQUAL)) {
                currLine += "+";
            } else if (IsKeyPressed(KEY_SLASH)) {
                currLine += "?";
            }

        } else {
            if (IsKeyPressed(KEY_A)) {
                currLine += "a";
            } else if (IsKeyPressed(KEY_B)) {
                currLine += "b";
            } else if (IsKeyPressed(KEY_C)) {
                currLine += "c";
            } else if (IsKeyPressed(KEY_D)) {
                currLine += "d";
            } else if (IsKeyPressed(KEY_E)) {
                currLine += "e";
            } else if (IsKeyPressed(KEY_F)) {
                currLine += "f";
            } else if (IsKeyPressed(KEY_G)) {
                currLine += "g";
            } else if (IsKeyPressed(KEY_H)) {
                currLine += "h";
            } else if (IsKeyPressed(KEY_I)) {
                currLine += "i";
            } else if (IsKeyPressed(KEY_J)) {
                currLine += "j";
            } else if (IsKeyPressed(KEY_K)) {
                currLine += "k";
            } else if (IsKeyPressed(KEY_L)) {
                currLine += "l";
            } else if (IsKeyPressed(KEY_M)) {
                currLine += "m";
            } else if (IsKeyPressed(KEY_N)) {
                currLine += "n";
            } else if (IsKeyPressed(KEY_O)) {
                currLine += "o";
            } else if (IsKeyPressed(KEY_P)) {
                currLine += "p";
            } else if (IsKeyPressed(KEY_Q)) {
                currLine += "q";
            } else if (IsKeyPressed(KEY_R)) {
                currLine += "r";
            } else if (IsKeyPressed(KEY_S)) {
                currLine += "s";
            } else if (IsKeyPressed(KEY_T)) {
                currLine += "t";
            } else if (IsKeyPressed(KEY_U)) {
                currLine += "u";
            } else if (IsKeyPressed(KEY_V)) {
                currLine += "v";
            } else if (IsKeyPressed(KEY_W)) {
                currLine += "w";
            } else if (IsKeyPressed(KEY_X)) {
                currLine += "x";
            } else if (IsKeyPressed(KEY_Y)) {
                currLine += "y";
            } else if (IsKeyPressed(KEY_Z)) {
                currLine += "z";
            } else if (IsKeyPressed(KEY_BACKSPACE)) {
                currLine = currLine.substr(0, currLine.size() - 1);
            } else if (IsKeyPressed(KEY_ZERO)) {
                currLine += "0";
            } else if (IsKeyPressed(KEY_ONE)) {
                currLine += "1";
            } else if (IsKeyPressed(KEY_TWO)) {
                currLine += "2";
            } else if (IsKeyPressed(KEY_THREE)) {
                currLine += "3";
            } else if (IsKeyPressed(KEY_FOUR)) {
                currLine += "4";
            } else if (IsKeyPressed(KEY_FIVE)) {
                currLine += "5";
            } else if (IsKeyPressed(KEY_SIX)) {
                currLine += "6";
            } else if (IsKeyPressed(KEY_SEVEN)) {
                currLine += "7";
            } else if (IsKeyPressed(KEY_EIGHT)) {
                currLine += "8";
            } else if (IsKeyPressed(KEY_NINE)) {
                currLine += "9";
            } else if (IsKeyPressed(KEY_SPACE)) {
                currLine += " "; // Space
            } else if (IsKeyPressed(KEY_COMMA)) {
                currLine += ",";
            } else if (IsKeyPressed(KEY_PERIOD)) {
                currLine += ".";
            } else if (IsKeyPressed(KEY_SEMICOLON)) {
                currLine += ";";
            } else if (IsKeyPressed(KEY_APOSTROPHE)) {
                currLine += "'";
            } else if (IsKeyPressed(KEY_LEFT_BRACKET)) {
                currLine += "[";
            } else if (IsKeyPressed(KEY_RIGHT_BRACKET)) {
                currLine += "]";
            } else if (IsKeyPressed(KEY_BACKSLASH)) {
                currLine += "\\";
            } else if (IsKeyPressed(KEY_GRAVE)) {
                currLine += "`";
            } else if (IsKeyPressed(KEY_MINUS)) {
                currLine += "-";
            } else if (IsKeyPressed(KEY_EQUAL)) {
                currLine += "=";
            } else if (IsKeyPressed(KEY_SLASH)) {
                currLine += "/";
            } else if (IsKeyPressed(KEY_TAB)) {
                currLine += "\t";
            } else if (IsKeyPressed(KEY_ENTER)) {
                textLines.push_back(currLine);
                currLine = "";
            } else if (IsKeyPressed(KEY_LEFT)) {
                // Handle left arrow action
            } else if (IsKeyPressed(KEY_RIGHT)) {
                // Handle right arrow action
            } else if (IsKeyPressed(KEY_UP)) {
                // Handle up arrow action
            } else if (IsKeyPressed(KEY_DOWN)) {
                // Handle down arrow action
            }

        }

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTextEx(arialRB, currLine.c_str(), {textX, textY}, 20, 2, BLACK);

        for (int i = 0; i < textLines.size(); i++) {
            DrawTextEx(arialRB, textLines[i].c_str(), {textX, textY + 20 * (i + 1)}, 20, 2, BLACK);
        }

        EndDrawing();
    }

    CloseWindow();

    system("./detach_resources 1 40 0");

    return 0;
}