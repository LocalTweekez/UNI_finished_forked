#include "raylib.h"
#include <iostream>
#include <vector>
#include <cmath>





static bool gameover = false;
static int blockSize = 15;
int framecounter = 0;

struct Player {
    Vector2 pos;
    Vector2 size;
    Vector2 speed;
    int score = 0;
    Color color;
    std::vector<Rectangle> path;

    Player(float posX, float posY, Color color) {
        pos.y = posY;
        pos.x = posX;
        this->color = color;
        size.y = 15;
        size.x = 15;
        speed.y = 0;
        speed.x = 0;
    }

    Rectangle GetRect() {
        return Rectangle{ pos.x - size.x / 2, pos.y - size.y / 2, size.x, size.y };
    }

    void Draw() {
        
        DrawRectangleRec(GetRect(), color);
        DrawPath();
    }

    void move() {
        if (remainder(pos.x, blockSize) == 0 && remainder(pos.y, blockSize)) {
            path.push_back(GetRect());
            if (speed.x != 0) {
                pos.x += speed.x * GetFrameTime();

            }
            else if (speed.y != 0) {
                pos.y += speed.y * GetFrameTime();

            }
        }
        
    }
    void DrawPath() {
        for(int i= 0; i<path.size();i++){
            DrawRectangleRec(path[i], color);
        
        }
    }

    bool hasCollided(std::vector<Rectangle> SecondPlayerPath) {
        for (int i = 0; i < path.size(); i++) {
            if ((CheckCollisionRecs(this->GetRect(), path[i]))) {
                return true;
            }
            if (CheckCollisionRecs(this->GetRect(), SecondPlayerPath[i])) {
                return true;

            }
        }
        return false;
    }
};

class Game {
private:
    Player player1;
    Player player2;


public:
    Game(Player _player1, Player _player2)  : player1(_player1), player2(_player2) {
        player1.speed.y = -15;
        player2.speed.y = 15;

    }

    bool UpdateGame() {
        /*if (player1.hasCollided(player2.path)) {
            player2.score++;
            player1.speed.x = 0;
            player1.speed.y = 0;
            player2.speed.x = 0;
            player2.speed.y = 0;
        }
        if (player2.hasCollided(player1.path)) {
            player1.score++;
            player1.speed.x = 0;
            player1.speed.y = 0;
            player2.speed.x = 0;
            player2.speed.y = 0;
        }
        */
        checkMovment();
        
        player1.move();
        player2.move();
        

        return 1;
    }
    void DrawGame() {
        player1.Draw();
        player2.Draw();


    }
    void checkMovment() {
        if (IsKeyDown(KEY_UP) && player1.speed.y == 0) {
            player1.speed.y = -15;
            player1.speed.x = 0;
        }
        if (IsKeyDown(KEY_DOWN) && player1.speed.y == 0) {
            player1.speed.y = 15;
            player1.speed.x = 0;
        }
        if (IsKeyDown(KEY_RIGHT) && player1.speed.x == 0) {
            player1.speed.x = 15;
            player1.speed.y = 0;
        }
        if (IsKeyDown(KEY_LEFT) && player1.speed.x == 0) {
            player1.speed.x = -15;
            player1.speed.y = 0;
        }
        if (IsKeyDown(KEY_W) && player2.speed.y == 0) {
            player2.speed.y = -15;
            player2.speed.x = 0;
        }
        if (IsKeyDown(KEY_S) && player2.speed.y == 0) {
            player2.speed.y = 15;
            player2.speed.x = 0;
        }
        if (IsKeyDown(KEY_D) && player2.speed.x == 0) {
            player2.speed.x = 15;
            player2.speed.y = 0;
        }
        if (IsKeyDown(KEY_A) && player2.speed.x == 0) {
            player2.speed.x = -15;
            player2.speed.y = 0;
        }
    }
};




    



/*bool Game::UpdateGame() {
    if(!)
}*/


int main(){

     
    InitWindow(900, 900, "Domination");
    SetTargetFPS(60);

    Player bluePlayer(GetScreenHeight() / 4, GetScreenWidth() / 4 / 2, BLUE);
    Player redPlayer(GetScreenHeight() * 0.75, GetScreenWidth() * 0.75, RED);
    Game game(redPlayer,bluePlayer);
    


    while (!WindowShouldClose()){

        game.UpdateGame();
        

        BeginDrawing();
         //GameField
            ClearBackground(BLACK);
            DrawRectangle(0, 0, 30, GetScreenHeight(), DARKGREEN);
            DrawRectangle(0, 0, GetScreenWidth(),30, DARKGREEN);
            DrawRectangle(GetScreenWidth()- 30, 0, 30, GetScreenHeight(), DARKGREEN);
            DrawRectangle(0, GetScreenHeight() - 30, GetScreenWidth(), 30, DARKGREEN);
         //GameField
            game.DrawGame();

            //if()


        EndDrawing();
        framecounter++;
        
    }
    
}

