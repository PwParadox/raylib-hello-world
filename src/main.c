#include "raylib.h"

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 800

int main ()
{
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Hello World");
	Vector2 center_pos = MeasureTextEx(GetFontDefault() , "Hello World", 20, 1);
	center_pos = (Vector2) {SCREEN_WIDTH/2 - center_pos.x/2, SCREEN_HEIGHT/2 - center_pos.y/2};

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);
		DrawLineBezier((Vector2){0, SCREEN_HEIGHT/2}, (Vector2){SCREEN_WIDTH, SCREEN_HEIGHT/2}, 3, GREEN);
		DrawLineBezier((Vector2){SCREEN_WIDTH/2, 0}, (Vector2){SCREEN_WIDTH/2, SCREEN_HEIGHT}, 3, RED);

		DrawText("Hello World", center_pos.x, center_pos.y, 20, WHITE);
		EndDrawing();
	}
	CloseWindow();
	return 0;
}