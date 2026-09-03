# Week 8 — Functions Reference

**Function Reference — `ex02_game_utils.c`**

| Function                                    | ทำหน้าที่                                                 | Returns                      |
| ------------------------------------------- | ------------------------------------------------------------------ | ---------------------------- |
| `int clamp(int value, int min, int max)`  | จำกัดค่า value ให้อยู่ระหว่าง min และ max | ค่าที่ clamp แล้ว  |
| `float lerp(float a, float b, float t)`   | Linear interpolation ระหว่าง a และ b ตาม t            | ค่าที่คำนวณได้ |
| `int randomRange(int min, int max)`       | สุ่มตัวเลขระหว่าง min และ max                  | ค่าสุ่ม               |
| `float percentOf(int current, int total)` | คำนวณเปอร์เซ็นต์                                   | ค่าเปอร์เซ็นต์ |

## คำถาม Reflection — Exercise 2

### 2.1 `clamp` — Pass by Value

**คำถาม:** ทำไม `hp` ใน `main()` ถึงยังเป็น 150 ทั้งที่ `value` ใน `clamp()` ถูกเขียนทับเป็น 100 ไปแล้ว?

**คำตอบ:เพราะ safe hp คือค่าที่ clamp แล้ว ไม่ใช่ hp เราแค่เอา  hp มาใช้เป็น value  ในการเข้าไป clamp**

### 2.2 `lerp` — Local Scope

**คำถาม:**ทำไม `main()` ถึงมองไม่เห็นตัวแปร `result` ทั้งที่มันถูกประกาศไว้ในไฟล์เดียวกัน?

**คำตอบ: เพราะมันไม่อยู่ใน  int main แต่แรก**

### 2.3 `randomRange` — Pass by Value

**คำถาม:** ทำไม `diceMin` ใน `main()` ถึงยังเป็น 1 ทั้งที่ `min` ใน `randomRange()` ถูกบวกเพิ่มเป็น 101 ไปแล้ว?

**คำตอบ: การแสดงผลของ random range  มันแสดงผลลัพธ์แค่ค่าที่สุ่มจาก min / max   ซึ่งการเติม  min ไป 101 ไม่มีผลกับ  dicemin  เพราะ dicemin  เป็นแค่เลขที่ตั้งต้นให้่  min ไปใช้สุ่มเท่านั้น**

### 2.4 `percentOf` — Pass by Value

**คำถาม:** ทำไม `score` ใน `main()` ถึงไม่เปลี่ยนเป็น 0 ตาม `current` ทั้งที่ `percentOf()` แก้ `current = 0;` ไปแล้ว?

**คำตอบ: เช่นเดียวกับข้ออื่นๆ ที่เราเอา _ int มาเป็น base ในการคำนวน**
