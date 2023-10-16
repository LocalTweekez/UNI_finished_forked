/*****************************************************************//**
                                                               
 * \file   prgm_project.cpp
 * \brief
 *
 * \author tahak SerdahY
 * \date   May 2023
 *********************************************************************/

/**
 * @mainpage Programmeringsmetodik Projekt - Pong
 .
 */

#include <iostream>
#include "raylib.h"
#include <string>

const char* winnerText = nullptr;

/**
 * @brief The ball object structure
*/
struct Ball {
    float radius;
    Vector2 pos;
    Vector2 speed;
    Color color;

    /**
     * @brief Ball ob default constructor
    */
    Ball() {
        radius = 0;
        pos.x = 0;
        speed.x = 0;
        speed.y = 0;
        color = WHITE;
    }
    /**
     * @brief Ball parametrisized constructor
     * 
     * @param _x 
     * @param _y
     * @param _radius
     * @param color
    */
    Ball(int _x, int _y, float _radius, Color color) {
        pos.x = _x;
        pos.y = _y;
        radius = _radius;
        speed.x = 300;
        speed.y = 300;
        this->color = color;
    }
    /**
     * @brief Draw the circle
    */
    void Draw() {
        DrawCircle((int)pos.x, (int)pos.y, radius, color);
    }
    /**
     * @brief Adjust the ball object to move within the frame
    */
    void ballMovement() {
        pos.x += speed.x * GetFrameTime();
        pos.y += speed.y * GetFrameTime();

        if (pos.y > GetScreenHeight()) {
            pos.y = GetScreenHeight();
            speed.y *= -1;
        }
        if (pos.y < 0) {
            pos.y = 0;
            speed.y *= -1;
        }
    }
};
/**
 * @brief The paddle object structure
*/
struct Paddle {

    Vector2 pos;
    Vector2 size;
    float speed = 0;
    Color color = WHITE;
    int score = 0;
    /**
     * @brief
    */
    Paddle() {
        pos.x = 0;
        pos.y = 0;
    }
    /**
     * 
     * @brief Constructor of the paddle
     * 
     * @param x
     * @param y
     * @param width
     * @param height
     * @param color
    */
    Paddle(float x, float y, float width, float height, Color color) {
        this->pos.x = x;
        this->pos.y = y;
        this->size.x = width;
        this->size.y = height;
        this->color = color;
        this->speed = 500;
        this->score = 0;
    }
    /**
     * @brief Create a rectangle from Raylib
     * 
     * @return the rectangle object
    */
    Rectangle GetRect() {
        return Rectangle{ pos.x - size.x / 2, pos.y - size.y / 2, size.x, size.y };
    }
    /**
     * @brief Spawn (draw) the rectangle from Get Rect function
    */
    void Draw() {
        DrawRectangleRec(GetRect(), color);
    }

};
/**
 * @brief The entire game being an object struct
*/
struct Game {
    Paddle rightPaddle;
    Paddle leftPaddle;
    Ball ball;
    /**
     * @brief Constructor of the game with game property parameters
     * 
     * @param _leftPaddle
     * @param _rightPaddle
     * @param _ball
    */
    Game(Paddle _leftPaddle, Paddle _rightPaddle, Ball _ball) {
        this->leftPaddle = _leftPaddle;

        this->rightPaddle = _rightPaddle;
        this->ball = _ball;
    }
    /**
     * @brief The game menu
    */
    void menu() {
        while (true) {
            // Draw the menu and add text
            BeginDrawing();
            ClearBackground(BLACK);
            DrawText("TWO PLAYER PONG!", GetScreenWidth() / 2 - 100, 30, 30, GREEN);
            DrawText("Press the mouse to begin", GetScreenWidth() / 2 - 150, 100, 24, DARKGREEN);
            
            // Start the game
            if (IsKeyPressed(MOUSE_LEFT_BUTTON) || IsKeyDown(KEY_ENTER)) { return; }
            EndDrawing();
        }
    }

    /**
     * @brief Function to move the paddles by pressing the up-down movement keys
    */
    void paddleMovement() {
        if (IsKeyDown(KEY_W)) {
            if (leftPaddle.pos.y > 0 + leftPaddle.size.y / 2)
                leftPaddle.pos.y -= leftPaddle.speed * GetFrameTime();
        }
        if (IsKeyDown(KEY_S)) {
            if (leftPaddle.pos.y < GetScreenHeight() - leftPaddle.size.y / 2)
                leftPaddle.pos.y += leftPaddle.speed * GetFrameTime();
        }
        if (IsKeyDown(KEY_UP)) {
            if (rightPaddle.pos.y > 0 + rightPaddle.size.y / 2)
                rightPaddle.pos.y -= rightPaddle.speed * GetFrameTime();
        }
        if (IsKeyDown(KEY_DOWN)) {
            if (rightPaddle.pos.y < GetScreenHeight() - rightPaddle.size.y / 2)
                rightPaddle.pos.y += rightPaddle.speed * GetFrameTime();
        }
    }
    /**
     * @brief Enable change of time and space in paddle universe
    */
    void movement() {
        paddleMovement();
        ball.ballMovement();
    }
    /**
     * @brief Draw the properties into the frame
    */
    void drawGame() {

        DrawScoreLine();
        DrawRectangle(GetScreenWidth() / 2 - 2.5, 0, 5, GetScreenHeight(), WHITE);
        ball.Draw();
        rightPaddle.Draw();
        leftPaddle.Draw();
    }
    /**
     * @brief Create rules by calculating point system and adjust speed by amount of ball hits. If one of the players gains 10 points the match ends and the game be played again
    */
    void pointSystem() {

        if (rightPaddle.score == 10)
            winnerText = "Right Player Wins";
        if (leftPaddle.score == 10)
            winnerText = "Left Player Wins";

        if (ball.pos.x < 0) {
            rightPaddle.score++;
            ball.pos.x = GetScreenWidth() / 2;
            ball.pos.y = GetScreenHeight() / 2;
            ball.speed.x = 300;
            ball.speed.y = 300;
        }
        if (ball.pos.x > GetScreenWidth()) {
            ball.pos.x = GetScreenWidth() / 2;
            ball.pos.y = GetScreenHeight() / 2;
            leftPaddle.score++;
            ball.speed.x = -300;
            ball.speed.y = -300;
        }
        if (winnerText) {

            const char* text;
            text = "To Play Again press Enter Or esc to exit";
            DrawText(winnerText, GetScreenWidth() / 2 - MeasureText(winnerText, 40) / 2, GetScreenHeight() / 2 - 30, 40, PURPLE);
            DrawText(text, GetScreenWidth() / 2 - MeasureText(text, 40) / 2, GetScreenHeight() * 0.75, 40, PURPLE);

            ball.pos.x = GetScreenWidth() / 2;
            ball.pos.y = GetScreenHeight() / 2;
            ball.speed.x = 0;
            ball.speed.y = 0;
            if (IsKeyDown(KEY_ENTER)) {
                RestartGame();
            }
        }
    }
    /**
     * @brief Draw a scoreline and display the score
    */
    void DrawScoreLine() {
        const char* score1 = TextFormat("SCORE %3i", rightPaddle.score);
        const char* score2 = TextFormat("SCORE %3i", leftPaddle.score);
        DrawText(score1, GetScreenWidth() / 2 + 10, 10, 30, rightPaddle.color);
        DrawText(score2, GetScreenWidth() / 2 - MeasureText(score2, 30) - 10, 10, 30, leftPaddle.color);
    }
    /**
     * @brief Check if the paddles got rect with a collision with the ball
    */
    void checkCollsion() {
        if (CheckCollisionCircleRec(ball.pos, ball.radius, leftPaddle.GetRect())) {
            if (ball.speed.x < 0) {
                ball.speed.x *= -1.1;
                ball.speed.y = (ball.pos.y - leftPaddle.pos.y) / (leftPaddle.size.y / 2) * ball.speed.x;
                ball.color = leftPaddle.color;
            }
        }
        if (CheckCollisionCircleRec(ball.pos, ball.radius, rightPaddle.GetRect())) {
            if (ball.speed.x > 0) {
                ball.speed.x *= -1.1;
                ball.speed.y = (ball.pos.y - rightPaddle.pos.y) / (rightPaddle.size.y / 2) * ball.speed.x;
                ball.color = rightPaddle.color;
            }
        }
    }
    /**
     * @brief Start the game
    */
    void playGame() {
        movement();
        pointSystem();
        checkCollsion();

    }
    /**
     * @brief Restart the game
    */
    void RestartGame() {
        leftPaddle.score = 0;
        rightPaddle.score = 0;
        winnerText = nullptr;
        ball.speed.x = 300;
        ball.speed.y = 300;

    }
};


/** 
 * \mainpage
 * @brief Main function
 * 
 * @return zero
 * \return
*/
int main()
{
    /**
     * \mainpage
     * @brief create window
     * 
     */
    
    InitWindow(1000, 700, "Pong");
    SetWindowState(FLAG_VSYNC_HINT);

    
    /**
     * \mainpage
     * 
     * @brief ball and paddles
     * 
     */
    Ball ball(GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f, 10, PINK);
    Paddle leftPaddle(30, GetScreenHeight() / 2, 10, 100, RED);
    Paddle rightPaddle(GetScreenWidth() - 30, GetScreenHeight() / 2, 10, 100, BLUE);

     /**
      * 
      * 
     * @brief Create game object and open menu
     * 
     */
    
    Game game(leftPaddle, rightPaddle, ball);
    game.menu();

     /**
     * @brief While the game still runs
     * 
     */
    
    while (!WindowShouldClose()) {
    /**
     * @brief Menu screen
     * 
     */
        
        game.playGame();
         /**
     *  @brief Draw a frame until finished
     * 
     */
        
        BeginDrawing();
        ClearBackground(BLACK);
        game.drawGame();
        EndDrawing();
    }
 /**
     * @brief The game is terminated
     * 
     */
    
    CloseWindow();
}

