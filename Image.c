#include <raylib.h>

int main(void) {
    // 1. ตั้งค่าหน้าต่าง
    const int screenWidth = 1920;
    const int screenHeight = 1080;
    InitWindow(screenWidth, screenHeight, "raylib - Draw Texture");

    SetTargetFPS(60);

    // 2. โหลดรูปภาพเข้า VRAM (ต้องเรียกหลัง InitWindow เท่านั้น)
    Texture2D myTexture = LoadTexture("C:/Users/PREDATOR/WEB/DG111_172/pwie.jpg");

    // ตรวจสอบว่าโหลดสำเร็จหรือไม่
    if (myTexture.id == 0) {
        // หากโหลดไม่ติด ให้ตรวจ path หรือนามสกุลไฟล์
    }

    // Main game loop
    while (!WindowShouldClose()) {
        // Update (คำนวณตำแหน่ง/ตรรกะเกมที่นี่)

        // Draw
        BeginDrawing();
            ClearBackground(RAYWHITE);

            // 3. วาดรูปลงบนพิกัด X, Y
            // วาดที่ตำแหน่ง (100, 100) สีปกติคือ WHITE
            DrawTexture(myTexture, 900, 100, WHITE);
            DrawText("PWIE :D", 900, 600, 300, RED);

        EndDrawing();
    }

    // 4. ล้างหน่วยความจำ Texture ออกจาก GPU
    UnloadTexture(myTexture);

    CloseWindow();
    return 0;
}