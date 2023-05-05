<h1 align=center>MiniRT</h1>

This project was developed by me and cadet  <a href="https://github.com/meritissimo1">Marcelo</a> as part of the curriculum of <a href="https://github.com/42sp">42 São Paulo</a>, with the main pedagogical focus of implementing a Raytracer, a computer graphics algorithm capable of rendering three-dimensional scenes.

## Introduction
Ray tracing is a technique used to render 3D images by calculating the intersection of a ray of light, coming from the viewer's camera, with the objects in the scene. Each ray is fired from the camera, passing through the corresponding pixels in the viewing window, and the color of each pixel is determined by the color of the object intersected by the ray at the point of intersection (or the background color if there is no intersection).
Ray tracing accurately simulates the physical properties of light rays, allowing lights, shadows, and surfaces to be rendered with a reasonable degree of fidelity, even on modest computers.

## About the implementation

This algorithm was implemented based on the book <a href="http://raytracerchallenge.com/">"The Ray Tracing Challenge"</a> using the Test Driven Development (TDD) method. The UNITY Test was used as the testing tool. However, it is important to note that some tests suggested by the book became outdated due to school specifications, which required some implementation details not covered in the book.

## How to Run 

Git clone the project:
```sh
git@github.com:leaozim/42-course-miniRT.git
```
Installing dependencies
```sh
sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev
```
To compile, use make
```sh
cd 42-course-miniRT && make
```
Run the program
```sh
./miniRT scenes/bonitao.rt
```
## Create your own RT File

.rt files need at least one Camera, Ambient Light and Light. The geometric shapes available are planes, cylinders and spheres.

| **Objects**   | **Input**                                            | **Example**                  |
| :----         | :--------------------------------------------------- | :--------------------------- |
| Camera        | C  [coordinate] [vector] [field of view]             | C  -10,0,0 -1,0,0 90         |
| Ambient Light | A  [brightness] [rgb color]                          | A  0.3 0,255,0               |
| Light         | L  [coordinate] [brightness] [rgb color]             | L 0,-10,10 0.13 255,255,255  |
| Plane         | pl [coordinate] [vector] [rgb color]                 | pl 0,0,0 0,1,0 255,0,255     |
| Sphere        | sp [coordinate] [diameter] [rgb color]               | sp 0,0,0 3 0,0,255           |
| Cylinder      | cy [coordinate] [vector] [diameter] [height] [color] | cy 0,0,0 0,0,1 3 5 145,39,79 |



## Examples of rendered images

<p align=center>
<img align="center" src="https://github.com/leaozim/42-course-miniRT/blob/main/images/room.png"</>
</p>

<p align=center>
<img align="center"  src="https://github.com/leaozim/42-course-miniRT/blob/main/images/rodrigo.png"</>
</p>

<p align=center>
<img align="center"  src="https://github.com/leaozim/42-course-miniRT/blob/main/images/man.png"</>
</p>

<p align=center>
<img align="center"  src="https://github.com/leaozim/42-course-miniRT/blob/main/images/lights_in_the_spheres.png"</>
</p>

<p align=center>
<img align="center"  src="hhttps://github.com/leaozim/42-course-miniRT/blob/main/images/brightness2.png"</>
</p>

<p align=center>
<img align="center"  src="https://github.com/leaozim/42-course-miniRT/blob/main/images/doidao.png"</>
</p>

