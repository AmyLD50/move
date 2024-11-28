to compile and run the program, you'll need A Linux system with the X11 library installed (most Linux distributions, including Linux Mint, come with it by default), and
the libx11-dev package installed to compile the program. so to get those, youre gonna use:


```sudo apt-get install libx11-dev```

cool good job almost done!!


now navigate to the directory containing the move.c file.

run the following command to compile the program:

gcc -o move move.c -lX11

```./move```

didn't work? submit an issue.
