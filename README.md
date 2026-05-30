# Fract-ol

A graphical fractal rendering project developed in C as part of the 42 curriculum. This project focuses on mathematical visualization, low-level graphics programming, and real-time rendering using MiniLibX.

## Features

* Mandelbrot set rendering
* Julia set rendering
* Interactive zoom with mouse controls
* Keyboard navigation
* Real-time fractal rendering
* Custom Julia parameters support

## Technologies

* **Language:** C
* **Graphics Library:** MiniLibX
* **Environment:** macOS / Linux
* **Concepts:** Complex Numbers, Fractals, Event Handling, Rendering

## Installation

Clone the repository:

```bash
git clone https://github.com/mesalmann/fract-ol.git
cd fract-ol
```

Compile the project:

```bash
make
```

## Usage

### Mandelbrot Set

```bash
./fractol mandelbrot
```

### Julia Set

```bash
./fractol julia -0.8 0.156
```

Example parameters:

```bash
./fractol julia -0.4 0.6
./fractol julia 0.285 0.01
./fractol julia -0.70176 -0.3842
```

## Controls

| Key / Action | Function      |
| ------------ | ------------- |
| Mouse Scroll | Zoom In / Out |
| Arrow Keys   | Navigate      |
| ESC          | Exit Program  |

## Preview

### Mandelbrot

*[Add screenshot here]*

### Julia

*[Add screenshot here]*

## Learning Outcomes

Through this project, I gained experience in:

* Low-level graphics programming in C
* Event-driven programming
* Mathematical visualization and fractal algorithms
* Rendering optimization and debugging
* Working with MiniLibX and graphical interfaces
