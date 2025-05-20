#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>
#include <stdlib.h>

ALLEGRO_COLOR shapeColor();
void draw_rectangle(ALLEGRO_COLOR color, const int W, const int H);
void draw_triangle(ALLEGRO_COLOR color, const int W, const int H);
void draw_filled_rectangle(ALLEGRO_COLOR color, const int W, const int H);

int main()
{
	ALLEGRO_DISPLAY* display = NULL;
	int width = 800;
	int height = 600;

	if (!al_init()) {
		fprintf(stderr, "failed to initialize allegro! \n");
		return -1;
	}

	display = al_create_display(width, height);
	if (!display) {
		fprintf(stderr, "failed to create display! \n");
		return -1;
	}
	al_init_primitives_addon();

	bool done = false;

	al_clear_to_color(al_map_rgb(255, 255, 255));
	al_flip_display();

	while(!done){
		al_clear_to_color(al_map_rgb(255, 255, 255));
		draw_rectangle(shapeColor(), width, height);
		draw_triangle(shapeColor(), width, height);
		draw_filled_rectangle(shapeColor(), width, height);
		al_flip_display();
	}

	al_destroy_display(display);
}

ALLEGRO_COLOR shapeColor() {
	return (al_map_rgb(0, 0, 0));
}

void draw_rectangle(ALLEGRO_COLOR color, const int W, const int H) {
	int x1 = W / 2 -100;
	int y1 = H / 2 - 100;
	int x2 = W / 2 + 100;
	int y2 = H / 2 + 100;
	float thickness = 2;
	al_draw_rectangle(x1, y1, x2, y2, color, thickness);
}

void draw_triangle(ALLEGRO_COLOR color, const int W, const int H) {
	int x1 = W / 2 - 130;
	int y1 = H / 2 - 100;
	int x2 = W / 2 + 130;
	int y2 = H / 2 - 100;
	int x3 = H / 2 + 100;
	int y3 = H / 6;
	float thickness = 2;
	al_draw_triangle(x1, y1, x2, y2, x3, y3, color, thickness);
}

void draw_filled_rectangle(ALLEGRO_COLOR color, const int W, const int H) {
	int x1 = W / 2 - 30;
	int y1 = H / 2 - 20;
	int x2 = W / 2 + 30;
	int y2 = H / 2 + 100;
	al_draw_filled_rectangle(x1, y1, x2, y2, color);
}