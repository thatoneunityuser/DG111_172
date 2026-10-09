#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <raylib.h>

#define MAX_ROUNDS 10
#define MAX_MISTAKES 3

typedef enum
{
    CompileError = 0,
    LogicError,
    Anomaly_Image,
    none
} ErrorEnum;

typedef struct
{
    ErrorEnum error;
} ErrorTypes;

typedef struct
{
   Texture2D CompileError1;
   Texture2D CompileError2;
   Texture2D CompileError3;
} ImageForCompileError;

typedef struct
{
   Texture2D LogicError1;
   Texture2D LogicError2;
   Texture2D LogicError3;
} ImageForForLogicError;

typedef struct
{
   Texture2D AnomalyError1;
   Texture2D AnomalyError2;
   Texture2D AnomalyError3;
} ImageForAnomalyError;

typedef struct
{
    Texture2D normalimage1;
    Texture2D normalimage2;
    Texture2D normalimage3;
} CorrectImage;

typedef enum{
    STATE_MENU,
    STATE_ASK_ERROR,
    STATE_ASK_TYPE,
    STATE_RESULT,
    STATE_END
}GameState;
//ตรงนี้ใช้ในการข้อมูลประเภทรูปภาพ และ State ของเกม

// ตรงนี้ใช้สำหรับเก็บข้อมูลและเอาไว้เรียกใช้
ImageForCompileError compileImgs;
ImageForForLogicError logicImgs;
ImageForAnomalyError anomalyImgs;
CorrectImage normalImgs;

void initGameImage()
{
    // Compile Errors (syntax errors)
    compileImgs.CompileError1 = LoadTexture("CompileError1.png");
    compileImgs.CompileError2 = LoadTexture("CompileError2.png");
    compileImgs.CompileError3 = LoadTexture("CompileError3.png");

    // Logic Errors (runs, but logic is wrong)
    logicImgs.LogicError1 = LoadTexture("LogicError1.png");
    logicImgs.LogicError2 = LoadTexture("LogicError2.png");
    logicImgs.LogicError3 = LoadTexture("LogicError3.png");

    // Anomaly Errors (horror / glitch / weird errors)
    anomalyImgs.AnomalyError1 = LoadTexture("AnomalyImage1.jpg");
    anomalyImgs.AnomalyError2 = LoadTexture("AnomalyImage2.jpg");
    anomalyImgs.AnomalyError3 = LoadTexture("AnomalyImage3.jpg");

    // Correct Code (clean code)
    normalImgs.normalimage1 = LoadTexture("NormalImage1.jpg");
    normalImgs.normalimage2 = LoadTexture("NormalImage2.png");
    normalImgs.normalimage3 = LoadTexture("NormalImage3.png");
}
//ตรงนี้เอาไว้เรียกใช้รูปภาพ


Texture2D getDisplayImage(ErrorEnum errorKind)
{
    int pick = rand() % 3;
    switch (errorKind)
    {
    case CompileError:
        if (pick == 0)
            return compileImgs.CompileError1;
        if (pick == 1)
            return compileImgs.CompileError2;
        return compileImgs.CompileError3;
    case LogicError:
        if (pick == 0)
            return logicImgs.LogicError1;
        if (pick == 1)
            return logicImgs.LogicError2;
        return logicImgs.LogicError3;
    case Anomaly_Image:
        if (pick == 0)
            return anomalyImgs.AnomalyError1;
        if (pick == 1)
            return anomalyImgs.AnomalyError2;
        return anomalyImgs.AnomalyError3;
    case none:
    default:
        if (pick == 0)
            return normalImgs.normalimage1;
        if (pick == 1)
            return normalImgs.normalimage2;
        return normalImgs.normalimage3;
    }
}
//ตรงนี้เอาไว้สุ่มเลือกรูปภาพ

ErrorTypes RandomErrorAndErrorImage(void)
{
    ErrorTypes errorType;
    // 0 = CompileError, 1 = LogicError, 2 = Anomaly_Image, 3 = none (no error)
    int randomChoice = rand() % 4;
    errorType.error = (ErrorEnum)randomChoice;
    return errorType;
}
//ตรงนี้เอาไว้สุ่มเลือกประเภทของรูปภาพและerror


int main()
{
    srand((unsigned int)time(NULL));

    InitWindow(1920, 1080, "Anomaly Detection");
    initGameImage();

    SetTargetFPS(60);

    int round = 0;
    int correct_count = 0;
    int incorrect_count = 0;

    ErrorTypes errorType;
    GameState gameState = STATE_MENU;
    Texture2D currentImage = {0};
    bool lastCorrect = false;

    while (!WindowShouldClose())
    {
        switch(gameState){
            case STATE_MENU:
                if(IsKeyPressed(KEY_ENTER)){
                    round++;
                    errorType = RandomErrorAndErrorImage();
                    currentImage = getDisplayImage(errorType.error);
                    gameState = STATE_ASK_ERROR;
                }
                break;
            case STATE_ASK_ERROR:
                if(IsKeyPressed(KEY_Y)){
                    gameState = STATE_ASK_TYPE;
                }
                else if(IsKeyPressed(KEY_N)){
                    if(errorType.error == none){
                        correct_count++;
                        lastCorrect = true;
                    }
                    else{
                        incorrect_count++;
                        lastCorrect = false;
                    }
                    gameState = STATE_RESULT;
                }
                break;
            case STATE_ASK_TYPE:
                if(IsKeyPressed(KEY_ONE)){
                    if(errorType.error == CompileError){
                        correct_count++;
                        lastCorrect = true;
                    }
                    else{
                        incorrect_count++;
                        lastCorrect = false;
                    }
                    gameState = STATE_RESULT;
                }
                else if(IsKeyPressed(KEY_TWO)){
                    if(errorType.error == LogicError){
                        correct_count++;
                        lastCorrect = true;
                    }
                    else{
                        incorrect_count++;
                        lastCorrect = false;
                    }
                    gameState = STATE_RESULT;
                }
                else if(IsKeyPressed(KEY_THREE)){
                    if(errorType.error == Anomaly_Image){
                        correct_count++;
                        lastCorrect = true;
                    }
                    else{
                        incorrect_count++;
                        lastCorrect = false;
                    }
                    gameState = STATE_RESULT;
                }
                break;
            case STATE_RESULT:
                if(IsKeyPressed(KEY_SPACE)){
                    if(correct_count >= MAX_ROUNDS || incorrect_count >= MAX_MISTAKES){
                        gameState = STATE_END;
                    }
                    else{
                        round++;
                        errorType = RandomErrorAndErrorImage();
                        currentImage = getDisplayImage(errorType.error);
                        gameState = STATE_ASK_ERROR;
                    }
                }
                break;
            case STATE_END:
                if(IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_Y)){
                    round = 0;
                    correct_count = 0;
                    incorrect_count = 0;
                    gameState = STATE_MENU;
                }
                break;
        }

        BeginDrawing();
        ClearBackground((Color){18, 20, 28, 255});

        if (gameState == STATE_MENU)
        {
            // เมนูกลางหน้าจอ (1920 x 1080)
            DrawText("Anomaly Detection Games", 440, 360, 80, RED);
            DrawText("Press Enter to Start The Game", 720, 520, 32, GREEN);
        }
        else if (gameState == STATE_END)
        {
            // หน้าจบเกม จัดตำแหน่งกึ่งกลางหน้าจอ
            if (correct_count >= MAX_ROUNDS)
            {
                DrawText("YOU WIN!", 760, 280, 80, GREEN);
                DrawText(TextFormat("Final Score: %d / %d", correct_count, MAX_ROUNDS), 740, 410, 40, GREEN);
            }
            else
            {
                DrawText("GAME OVER", 710, 280, 80, RED);
                DrawText(TextFormat("Mistakes: %d / %d", incorrect_count, MAX_MISTAKES), 770, 410, 40, RED);
            }

            DrawText(TextFormat("Total Rounds: %d", round), 820, 490, 30, WHITE);
            DrawText("Press Enter to play again", 740, 580, 32, SKYBLUE);
        }
        else
        {
            // แถบ HUD ด้านบน จัดระยะห่างเท่าๆ กัน
            DrawText(TextFormat("Round : %d", round), 100, 50, 36, WHITE);
            DrawText(TextFormat("Correct: %d / %d", correct_count, MAX_ROUNDS), 500, 55, 28, GREEN);
            DrawText(TextFormat("Errors: %d / %d", incorrect_count, MAX_MISTAKES), 820, 55, 28, RED);

            // ฝั่งซ้าย: รูปภาพ ปรับสัดส่วนพอดีกรอบ 800 x 750
            if (currentImage.width > 0 && currentImage.height > 0)
            {
                float scale = fminf(800.0f / currentImage.width, 750.0f / currentImage.height);//fminf คือการหาค่าที่น้อยกว่าใน 2 ตัวเลือก
                float imgW = currentImage.width * scale;//ตรงนี้ใช้ในการกำหนดความกว้าง
                float imgH = currentImage.height * scale;//ตรงนี้ใช้ในการกำหนดความสูง
                float imgX = 100.0f + (800.0f - imgW) / 2.0f;//ที่ใช้ 100 เพราะกำหนดขอบซ้ายไว้ที่ x=100
                float imgY = 160.0f + (750.0f - imgH) / 2.0f;//ที่ใช้ 160 เพราะกำหนดขอบบนไว้ที่ y=160

                DrawRectangleLines(98, 158, 804, 754, (Color){60, 65, 80, 255});//เส้นขอบ
                Rectangle src = { 0.0f, 0.0f, (float)currentImage.width, (float)currentImage.height };//ตรงนี้ใช้บอกว่าเอาเท่าไหร่
                Rectangle dest = { imgX, imgY, imgW, imgH };//ตรงนี้ใช้ในการกำหนดตำแหน่งของรูปภาพ
                DrawTexturePro(currentImage, src, dest, (Vector2){0, 0}, 0.0f, WHITE);
            }

            // ฝั่งขวา: คำถามและตัวเลือก เริ่มที่ X = 1050 ตรงกันทั้งหมด
            if (gameState == STATE_ASK_ERROR)
            {
                DrawText("Is this image error?", 1050, 340, 40, WHITE);
                DrawText("Press [ Y ] : YES", 1050, 450, 32, GREEN);
                DrawText("Press [ N ] : NO", 1050, 520, 32, RED);
            }
            else if (gameState == STATE_ASK_TYPE)
            {
                DrawText("Which Error Do You Think Then?", 1050, 320, 38, WHITE);
                DrawText("1 : CompileError", 1050, 420, 32, SKYBLUE);
                DrawText("2 : LogicError",   1050, 480, 32, YELLOW);
                DrawText("3 : AnomalyError", 1050, 540, 32, PURPLE);
            }
            else if (gameState == STATE_RESULT)
            {
                DrawText(lastCorrect ? "Correct!" : "Wrong!", 1050, 340, 56, lastCorrect ? GREEN : RED);
                DrawText("Press SPACE to continue", 1050, 450, 32, WHITE);
            }
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
