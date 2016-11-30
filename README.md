# mandelbrot-generator
This is a simple project designed to generate and render the Mandelbrot set using SDL. At the moment, I use the escape time algorithm in order to determine whether a particular value is in the set or not, although I plan to switch to a more efficient algorithm at some point. If a point is in the set, it will be colored black. If not, it will be colored according to the number of iterations it took to escape the set.

Fractal geometry has always been particularly interesting to me, so this project serves as a way to both deepen my understanding of the Mandelbrot set and improve my programming skills.

# 11/18/2016
I've made some real progress in the past day on this project, and I finally got my first working image with the program:

![alt tag](http://i.imgur.com/OGuFhS8.png)

At the moment, there are still quite a few bugs that occur when I attempt to change the window dimensions. These are most likely due to errors I made when attempting to normalize the grid of pixels to the complex plane.

# 11/18/2016 (Part 2)
In the interval since producing my first image, I've managed to add color.
As of right now, my program can produce images such as the following:

![alt tag](http://i.imgur.com/s8E1wsJ.png)

![alt tag](http://i.imgur.com/c4Hdzyf.jpg)

# 11/19/2016
Played around with some Julia sets today:

![alt tag](http://i.imgur.com/3TSqg8N.jpg)

# 11/30/2016

Particularly proud of this one:

![alt tag](http://i.imgur.com/MY6BJrB.jpg)

Although it will be a lot of hard work and learning, my goal for the project is to one day produce images such as this:

![alt tag](http://img04.deviantart.net/f515/i/2013/167/0/1/mandelbrot_set_zoom_in_4k__by_seryzone-d698sw7.jpg)


