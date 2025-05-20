// Alexander Young
// Lab 1

#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>
#include <stdlib.h>
#include <thread>
#include <chrono>

//functions for defining the color for shapes and for drawing outlines of rectangles, triangles, circles, and filled-in rectangles
ALLEGRO_COLOR shapeColor();
void draw_rectangle(ALLEGRO_COLOR color, const int W, const int H);
void draw_triangle(ALLEGRO_COLOR color, const int W, const int H);
void draw_filled_rectangle(ALLEGRO_COLOR color, const int W, const int H);
void draw_circle(ALLEGRO_COLOR color, const int W, const int H);

int main()
{

	ALLEGRO_DISPLAY* display = NULL;
	//defines the width and height of the display
	int width = 800;
	int height = 600;

	if (!al_init()) {
		fprintf(stderr, "failed to initialize allegro! \n");
		return -1;
	}

	//creates a display using the width and height from above
	display = al_create_display(width, height);
	if (!display) {
		fprintf(stderr, "failed to create display! \n");
		return -1;
	}

	//initializes the Allegro primitives addon
	al_init_primitives_addon();

	bool done = false;

	//sets the background color to white and flips the buffer
	al_clear_to_color(al_map_rgb(255, 255, 255));
	al_flip_display();

	//game loop
	while(!done){
		//sets background to white and draws a clear rectangle, triangle, circle, and filled rectangle - then flips the buffer
		al_clear_to_color(al_map_rgb(255, 255, 255));
		draw_rectangle(shapeColor(), width, height);
		draw_triangle(shapeColor(), width, height);
		draw_filled_rectangle(shapeColor(), width, height);
		draw_circle(shapeColor(), width, height);
		al_flip_display();
	}

	//destroys the display and clears up the memory when we are done
	al_destroy_display(display);
}

//Function to define the color for shapes to be drawn
//Takes no parameters
//Returns the Allegro rgb map for the color black
ALLEGRO_COLOR shapeColor() {
	return (al_map_rgb(0, 0, 0));
}

//Function to draw the outline of a rectangle
//Takes an ALLEGRO_COLOR and two integers as parameters where W is the width of the display and H is the width
//Return type void, draws a shape on the display
void draw_rectangle(ALLEGRO_COLOR color, const int W, const int H) {
	int x1 = W / 2 -100;
	int y1 = H / 2 - 100;
	int x2 = W / 2 + 100;
	int y2 = H / 2 + 100;
	float thickness = 2;
	al_draw_rectangle(x1, y1, x2, y2, color, thickness);
}

//Function to draw the outline of a triangle
//Takes an ALLEGRO_COLOR and two integers as parameters where W is the width of the display and H is the width
//Return type void, draws a shape on the display
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

//Function to draw a filled-in rectangle
//Takes an ALLEGRO_COLOR and two integers as parameters where W is the width of the display and H is the width
//Return type void, draws a shape on the display
void draw_filled_rectangle(ALLEGRO_COLOR color, const int W, const int H) {
	int x1 = W / 2 - 50;
	int y1 = H / 2 - 20;
	int x2 = W / 2 + 10;
	int y2 = H / 2 + 100;
	al_draw_filled_rectangle(x1, y1, x2, y2, color);
}

//Function to draw the outline of a circle
//Takes an ALLEGRO_COLOR and two integers as parameters where W is the width of the display and H is the width
//Return type void, draws a shape on the display
void draw_circle(ALLEGRO_COLOR color, const int W, const int H) {
	int cx = W / 2 + 55;
	int cy = H / 2 + 10;
	int r = 35;
	float thickness = 2;
	al_draw_circle(cx, cy, r, color, thickness);
}