#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
		return -1'
	}

	bool done = false;

	while(!done){
	}

	al_destroy_display(display);
}

