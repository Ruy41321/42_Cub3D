# Cub3D

**Cub3D** is a 3D maze environment developed entirely in C. It uses raycasting and the DDA (Digital Differential Analyzer) algorithm to render the 3D maze, similar to the classic *Wolfenstein 3D*.

![Cub3D Demo](extra/cub.gif)

---

###CONFIG

To run the project on your machine you have to clone this repository: [minilibx](https://github.com/42Paris/minilibx-linux) and place it in the project folder

---

### Collaborators

- **Luigi Argenziano Vagello** ([GitHub Profile](https://github.com/itrustinshell))

---

### Project Overview

This project creates a simple 3D maze game environment where the player can navigate using raycasting techniques. The goal was to simulate the look and feel of early 3D games like *Wolfenstein 3D*, using C and the MiniLibX graphics library.

---

### Responsibilities

This was a team project, and I was responsible for:

- **Game Logic**: Implementing the core mechanics of the game, including movement and rendering logic.
- **Memory Management**: Ensuring efficient memory allocation and deallocation to avoid memory leaks.
- **Map Parsing**: Parsing and loading the maze data for the 3D rendering.
- **Input Handling**: Implementing user controls for player movement and interaction with the game world.

---

### Technologies Used

- **Programming Language**: C
- **Graphics Library**: MiniLibX (for rendering graphics)
- **Algorithms**: Raycasting, DDA (Digital Differential Analyzer)

---

### Challenges Faced

- **Raycasting & DDA Implementation**: One of the main challenges was implementing raycasting and the DDA algorithm, which are essential for rendering the 3D maze.
- **Performance Optimization**: We had to ensure smooth performance by optimizing the rendering loop and minimizing memory usage.
- **Fish-Eye Effect Fix**: Fixing the fish-eye effect caused by the incorrect projection of 3D objects was another key challenge.
- **Memory Management**: Handling memory correctly, especially when dynamically allocating memory for the map and graphics, was a critical aspect.

---

### Outcome

The project successfully implements a functional 3D maze environment with the following features:

- **Player Movement**: The player can move within the maze using the WASD keys.
- **Basic 3D Rendering**: The maze is rendered using raycasting and DDA, creating the illusion of depth.
- **Basic Interaction**: The player can interact with the game environment (e.g., rotating the view).

This project was a great exercise in graphics programming, algorithm implementation, and memory management in C.
