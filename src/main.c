#include "raylib.h"
#include "math.h"

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 800

static Vector2 Vector2Scale(Vector2 v, float scale);
static Vector2 Vector2Add(Vector2 v1, Vector2 v2);
struct Ball {
	Vector2 position;
	Vector2 angle;
	float speed;
	int radius;
};
static void Bounce(struct Ball* b);

int main ()
{
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
	SetTargetFPS(60);
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Bouncing Ball Simulation");

	struct Ball ball;
	ball.position = (Vector2){SCREEN_WIDTH/2, SCREEN_HEIGHT/2};
	ball.speed = 4;
	ball.radius = 20;
	ball.angle = (Vector2){0.5,0.5};
	Vector2 disp;

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);
		DrawCircle(ball.position.x, ball.position.y, ball.radius, RED);
		EndDrawing();
		Bounce(&ball);
	}
	CloseWindow();
	return 0;
}
