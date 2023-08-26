# Fractol - Fractal Visualization Program

Fractol is a program for visualizing various fractal sets, including Mandelbrot, Julia, and Burning Ship sets. It allows you to explore these fascinating mathematical structures and observe their intricate patterns and details.

## Usage

To run the Fractol program, follow these steps:

1. Clone the repository:

git clone https://github.com/gkrusta/fractol.git
cd fractol

2. Compile the program:

make

3. Run the program with the desired fractal set:

./fractol <fractal_set> [optional_arguments]

Available fractal sets:

- `1`: Mandelbrot
- `2`: Julia
- `3`: Burning Ship

For the Julia set, you can provide additional arguments for customizing the layout:

./fractol 2 <c_real> <c_imag>

- `<c_real>`: Real part of the constant `c` for the Julia set
- `<c_imag>`: Imaginary part of the constant `c` for the Julia set

## Controls

Use the following keyboard commands to interact with the program:

- **Arrow keys**: Move the fractal
- **Scroll wheel**: Zoom in and out
- **I/O keys**: Increase/decrease zoom at the center only
- **U/D keys**: Increase/decrease iterations
- **1/2/3 keys**: Change color set
- **4/5/6/7 keys (only for Julia)**: Change Julia layout
- **Space key**: Reset to default state
- **Esc key**: Quit the program

## Examples

- To show the Mandelbrot set:

./fractol 1

- To show the Julia set:

./fractol 2 <c_real> <c_imag>

- To show the Burning Ship set:

./fractol 3

## Stuff and sources I used

- Video which explains the concept of complex numbers on a coordinate plane and Mandelbrot set:
https://www.youtube.com/watch?v=6IWXkV82oyY

- To study, compare Mandelbrot and Julia fractals:
https://www.dynamicmath.xyz/mandelbrot-julia/

- Burning Ship:
https://robotmoon.com/burning-ship-fractal/

- Leo's from 42 Malaga work who has a cute little guide:
https://github.com/leogaudin/fract-ol
