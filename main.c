#include "raylib.h"
#include <stdlib.h>
#include <time.h>

#define SCREEN_WIDTH 900
#define SCREEN_HEIGHT 600
#define WIN_SCORE 100

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Lucky Doors - A Game of Chance");
    SetTargetFPS(60);
    srand((unsigned int)time(NULL));

    int score = 0;
    int lives = 3;
    int gameOver = 0;
    int won = 0;
    int round = 0;
    const int maxRounds = 10;

    const char *message = "Choose a door to reveal your luck!";
    Color doorColors[3] = { BLUE, PURPLE, ORANGE };

    Rectangle doors[3] = {
        { 105, 235, 190, 210 },
        { 355, 235, 190, 210 },
        { 605, 235, 190, 210 }
    };

    while (!WindowShouldClose())
    {
        Vector2 mouse = GetMousePosition();

        if (!gameOver && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            for (int i = 0; i < 3; i++)
            {
                if (CheckCollisionPointRec(mouse, doors[i]))
                {
                    int result = rand() % 3;
                    round++;

                    if (result == 0)
                    {
                        score += 20;
                        message = "Lucky! You earned 20 points!";
                    }
                    else if (result == 1)
                    {
                        score += 40;
                        message = "SUPER LUCKY! You earned 40 points!";
                    }
                    else
                    {
                        lives--;
                        message = "Oh no! You lost one life.";
                    }

                    if (score >= WIN_SCORE)
                    {
                        gameOver = 1;
                        won = 1;
                    }
                    else if (lives <= 0 || round >= maxRounds)
                    {
                        gameOver = 1;
                        won = 0;
                    }
                    break;
                }
            }
        }

        if (gameOver && IsKeyPressed(KEY_R))
        {
            score = 0;
            lives = 3;
            round = 0;
            gameOver = 0;
            won = 0;
            message = "Choose a door to reveal your luck!";
        }

        BeginDrawing();
        ClearBackground((Color){ 22, 24,  50, 255 });

        DrawText("LUCKY DOORS", 300, 45, 42, GOLD);
        DrawText(TextFormat("SCORE: %d / %d", score, WIN_SCORE),
                 95, 125, 25, RAYWHITE);
        DrawText(TextFormat("LIVES: %d", lives),
                 665, 125, 25, RAYWHITE);
        DrawText(TextFormat("ROUND: %d / %d", round, maxRounds),
                 365, 165, 20, LIGHTGRAY);

        if (!gameOver)
        {
            DrawText("Pick one of the mystery doors!", 260, 200, 24, WHITE);

            for (int i = 0; i < 3; i++)
            {
                Color color = doorColors[i];

                if (CheckCollisionPointRec(mouse, doors[i]))
                    color = ColorBrightness(color, 0.25f);

                DrawRectangleRounded(doors[i], 0.12f, 8, color);
                DrawRectangleRoundedLines(doors[i], 0.12f, 8, 4, GOLD);

                DrawCircle((int)(doors[i].x + doors[i].width / 2),
                           (int)(doors[i].y + 65), 12, GOLD);

                DrawText(TextFormat("DOOR %d", i + 1),
                         (int)doors[i].x + 48,
                         (int)doors[i].y + 125, 25, WHITE);
            }
        }
        else
        {
            if (won)
            {
                DrawText("YOU WIN!", 345, 275, 55, GREEN);
                DrawText("Amazing luck! You reached 100 points.",
                         205, 345, 24, WHITE);
            }
            else
            {
                DrawText("GAME OVER", 315, 275, 55, RED);
                DrawText("Better luck next time!",
                         320, 345, 24, WHITE);
            }

            DrawText("Press R to play again", 315, 405, 25, GOLD);
        }

        DrawText(message, 190, 500, 23, YELLOW);
        DrawText("Reach 100 points to win. You have 3 lives and 10 rounds.",
                 125, 555, 18, LIGHTGRAY);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
