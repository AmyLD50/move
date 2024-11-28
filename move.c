#include <X11/Xlib.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

void jiggle_mouse(Display *display, Window root) {
    XEvent event;
    int x, y;

    XQueryPointer(display, root, &root, &root, &x, &y, &event.xmotion.x, &event.xmotion.y, &event.xmotion.state);

    XWarpPointer(display, 0, root, 0, 0, 0, 0, x + 1, y + 1);
    XFlush(display);
    usleep(100000);

    XWarpPointer(display, 0, root, 0, 0, 0, 0, x, y);
    XFlush(display);
}

void display_timer(int seconds_left) {
    int minutes = seconds_left / 60;
    int seconds = seconds_left % 60;

    printf("\rtime until next jiggle: %02d:%02d", minutes, seconds);
    fflush(stdout);
}

int main() {
    Display *display;
    Window root;
    int countdown = 299;

    display = XOpenDisplay(NULL);
    if (display == NULL) {
        fprintf(stderr, "could not open x display\n");
        return 1;
    }

    root = DefaultRootWindow(display);

    printf("press ctrl+c to stop.\n");

    while (1) {
        display_timer(countdown);
        sleep(1);
        countdown--;

        if (countdown <= 0) {
            jiggle_mouse(display, root);
            countdown = 299;
        }
    }

    XCloseDisplay(display);
    return 0;
}