#include <raylib.h>
#include <string>
#include <cmath>
#include <queue>
#include <stack>

float evalute(std::string equation) {

    std::queue<std::string> tokens;
    std::string token = "";

    for (int i = 0; i < equation.size(); i++) {

        if (equation[i] == '+' || equation[i] == '-' || equation[i] == '*' || equation[i] == '/') {
            tokens.push(token);
            token = "";
            tokens.push(std::string(1, equation[i]));
        } else {
            token += equation[i];
        }
    }

    tokens.push(token);

    std::queue<std::string> postfix;
    std::stack<std::string> operators;

    while (!tokens.empty()) {

        std::string token = tokens.front();
        tokens.pop();

        if (token == "+" || token == "-") {

            while (!operators.empty() && (operators.top() == "*" || operators.top() == "/")) {
                postfix.push(operators.top());
                operators.pop();
            }

            operators.push(token);
        } else if (token == "*" || token == "/") {
            operators.push(token);
        } else {
            postfix.push(token);
        }
    }

    while (!operators.empty()) {
        postfix.push(operators.top());
        operators.pop();
    }

    std::stack<float> operands;

    while (!postfix.empty()) {

        std::string token = postfix.front();
        postfix.pop();

        if (token == "+" || token == "-" || token == "*" || token == "/") {

            float operand2 = operands.top();
            operands.pop();
            float operand1 = operands.top();
            operands.pop();

            if (token == "+")
                operands.push(operand1 + operand2);
            else if (token == "-")
                operands.push(operand1 - operand2);
            else if (token == "*")
                operands.push(operand1 * operand2);
            else if (token == "/")
                operands.push(operand1 / operand2);
        } else {
            operands.push(std::stof(token));
        }
    }

    return operands.top();


}

int main() {

    system(("./allocate_resources 1 50 0"));

    int screenWidth = 250, screenHeight = 330;

    InitWindow(screenWidth, screenHeight, "Calculator");

    SetTargetFPS(60);

    Font arialRB = LoadFontEx("resources/ARLRDBD_0.TTF", 25, 0, 250);

    std::string equation = "";
    float result = 0.0f;

    while (!WindowShouldClose()) {


        if (IsKeyDown(KEY_LEFT_SHIFT) && IsKeyPressed(KEY_EIGHT))
            equation += "*";
        else if (IsKeyPressed(KEY_EQUAL) && IsKeyDown(KEY_LEFT_SHIFT))
            equation += "+";
        else if (IsKeyPressed(KEY_SLASH))
            equation += "/";
        else if (IsKeyPressed(KEY_ONE))
            equation += "1";
        else if (IsKeyPressed(KEY_TWO))
            equation += "2";
        else if (IsKeyPressed(KEY_THREE))
            equation += "3";
        else if (IsKeyPressed(KEY_FOUR))
            equation += "4";
        else if (IsKeyPressed(KEY_FIVE))
            equation += "5";
        else if (IsKeyPressed(KEY_SIX))
            equation += "6";
        else if (IsKeyPressed(KEY_SEVEN))
            equation += "7";
        else if (IsKeyPressed(KEY_EIGHT))
            equation += "8";
        else if (IsKeyPressed(KEY_NINE))
            equation += "9";
        else if (IsKeyPressed(KEY_ZERO))
            equation += "0";
        else if (IsKeyPressed(KEY_PERIOD))
            equation += ".";
        else if (IsKeyPressed(KEY_MINUS))
            equation += "-";
        else if (IsKeyPressed(KEY_BACKSPACE)) {

            if (equation.size() > 0)
                equation = equation.substr(0, equation.size() - 1);
            else
                equation = "";
        }
        else if (IsKeyPressed(KEY_ENTER)) {
            try {
                result = evalute(equation);
            } catch (std::exception e) {
                equation = "Error";
            }
        }

        // check for the click on the buttons

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {

            Vector2 mousePos = GetMousePosition();

            if (CheckCollisionPointRec(mousePos, (Rectangle){10, 70, 50, 50}))
                equation += "1";
            else if (CheckCollisionPointRec(mousePos, (Rectangle){70, 70, 50, 50}))
                equation += "2";
            else if (CheckCollisionPointRec(mousePos, (Rectangle){130, 70, 50, 50}))
                equation += "3";
            else if (CheckCollisionPointRec(mousePos, (Rectangle){10, 130, 50, 50}))
                equation += "4";
            else if (CheckCollisionPointRec(mousePos, (Rectangle){70, 130, 50, 50}))
                equation += "5";
            else if (CheckCollisionPointRec(mousePos, (Rectangle){130, 130, 50, 50}))
                equation += "6";
            else if (CheckCollisionPointRec(mousePos, (Rectangle){10, 190, 50, 50}))
                equation += "7";
            else if (CheckCollisionPointRec(mousePos, (Rectangle){70, 190, 50, 50}))
                equation += "8";
            else if (CheckCollisionPointRec(mousePos, (Rectangle){130, 190, 50, 50}))
                equation += "9";
            else if (CheckCollisionPointRec(mousePos, (Rectangle){10, 250, 50, 50}))
                equation += "0";
            else if (CheckCollisionPointRec(mousePos, (Rectangle){70, 250, 50, 50}))
                equation += ".";
            else if (CheckCollisionPointRec(mousePos, (Rectangle){130, 250, 50, 50}))
                equation += "+";
            else if (CheckCollisionPointRec(mousePos, (Rectangle){190, 70, 50, 50}))
                equation += "-";
            else if (CheckCollisionPointRec(mousePos, (Rectangle){190, 130, 50, 50}))
                equation += "*";
            else if (CheckCollisionPointRec(mousePos, (Rectangle){190, 190, 50, 50}))
                equation += "/";
            else if (CheckCollisionPointRec(mousePos, (Rectangle){190, 250, 50, 50})) {
                try {
                    result = evalute(equation);
                } catch (std::exception e) {
                    equation = "Error";
                }
            }
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawTextEx(arialRB, equation.c_str(), (Vector2){10, 10}, 25, 0, BLACK);

        if (result != 0.0f)
            DrawTextEx(arialRB, std::to_string(result).c_str(), (Vector2){10, 40}, 25, 0, BLACK);

        // draw buttons

        DrawRectangle(10, 70, 50, 50, BLACK);
        DrawTextEx(arialRB, "1", (Vector2){20, 80}, 25, 0, WHITE);

        DrawRectangle(70, 70, 50, 50, BLACK);
        DrawTextEx(arialRB, "2", (Vector2){80, 80}, 25, 0, WHITE);

        DrawRectangle(130, 70, 50, 50, BLACK);
        DrawTextEx(arialRB, "3", (Vector2){140, 80}, 25, 0, WHITE);

        DrawRectangle(10, 130, 50, 50, BLACK);
        DrawTextEx(arialRB, "4", (Vector2){20, 140}, 25, 0, WHITE);

        DrawRectangle(70, 130, 50, 50, BLACK);
        DrawTextEx(arialRB, "5", (Vector2){80, 140}, 25, 0, WHITE);

        DrawRectangle(130, 130, 50, 50, BLACK);
        DrawTextEx(arialRB, "6", (Vector2){140, 140}, 25, 0, WHITE);

        DrawRectangle(10, 190, 50, 50, BLACK);
        DrawTextEx(arialRB, "7", (Vector2){20, 200}, 25, 0, WHITE);

        DrawRectangle(70, 190, 50, 50, BLACK);
        DrawTextEx(arialRB, "8", (Vector2){80, 200}, 25, 0, WHITE);

        DrawRectangle(130, 190, 50, 50, BLACK);
        DrawTextEx(arialRB, "9", (Vector2){140, 200}, 25, 0, WHITE);

        DrawRectangle(10, 250, 50, 50, BLACK);
        DrawTextEx(arialRB, "0", (Vector2){20, 260}, 25, 0, WHITE);

        DrawRectangle(70, 250, 50, 50, BLACK);
        DrawTextEx(arialRB, ".", (Vector2){80, 260}, 25, 0, WHITE);

        DrawRectangle(130, 250, 50, 50, BLACK);
        DrawTextEx(arialRB, "+", (Vector2){140, 260}, 25, 0, WHITE);

        DrawRectangle(190, 70, 50, 50, BLACK);
        DrawTextEx(arialRB, "-", (Vector2){200, 80}, 25, 0, WHITE);

        DrawRectangle(190, 130, 50, 50, BLACK);
        DrawTextEx(arialRB, "*", (Vector2){200, 140}, 25, 0, WHITE);

        DrawRectangle(190, 190, 50, 50, BLACK);
        DrawTextEx(arialRB, "/", (Vector2){200, 200}, 25, 0, WHITE);

        DrawRectangle(190, 250, 50, 50, BLACK);
        DrawTextEx(arialRB, "=", (Vector2){200, 260}, 25, 0, WHITE);

        EndDrawing();

    }

    CloseWindow();

    system(("./detach_resources 1 50 0"));

    return 0;
}