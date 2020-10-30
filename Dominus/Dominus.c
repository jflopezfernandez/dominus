
#include "Dominus.h"

int main(int argc, char *argv[])
{
	al_init();
	al_install_keyboard();

	ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60.0);
	ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
	ALLEGRO_DISPLAY* display = al_create_display(1600, 1200);

	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	int redraw = 1;

	ALLEGRO_EVENT event;

	al_start_timer(timer);

	while (1) {
		al_wait_for_event(event_queue, &event);

		switch (event.type) {
			case ALLEGRO_EVENT_TIMER: {
				redraw = 1;
			} break;

			case ALLEGRO_EVENT_DISPLAY_CLOSE: {
				goto exit_game;
			} break;

			case ALLEGRO_EVENT_KEY_DOWN: {
				
				switch (event.keyboard.keycode) {
					case ALLEGRO_KEY_ESCAPE: {
						goto exit_game;
					} break;
				}
			} break;
		}

		if ((!redraw) || (!al_is_event_queue_empty(event_queue))) {
			continue;
		}

		al_clear_to_color(al_map_rgb(40, 40, 40));
		al_flip_display();

		redraw = 0;
	}

exit_game:
	al_destroy_display(display);
	al_destroy_timer(timer);
	al_destroy_event_queue(event_queue);

	return EXIT_SUCCESS;
}
