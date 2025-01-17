# So Long  
_And thanks for all the fish! But, dont forget to treat yourself everyday🦉🔑!_
![image](https://github.com/user-attachments/assets/0ce25e82-3354-4217-852a-b414ca5a9464)

## Summary
**So Long** is a small 2D game designed to practice sprites, and basic gameplay elements. The player collects items and escapes the map while navigating obstacles.

---

## Features
- **Game Mechanics**:
  - Move using `W`, `A`, `S`, `D`.
  - Collect all items to unlock the exit.
  - The number of movements is displayed in the terminal.
- **Graphics**:
  - 2D top-down view using the MiniLibX library.
  - Window displays the game.
- **Map Validation**:
  - Maps use `.ber` format with:
    - `0`: Empty space.
    - `1`: Walls.
    - `C`: Collectibles.
    - `E`: Exit.
    - `P`: Player's start position.
  - Maps must have valid paths and be rectangular.

---

## Requirements
- Written in **C**.
- Uses the **MiniLibX** library.
- Compatible with Linux and macOS.
   
Ensure the `mlx` directory contains the extracted files before building the project.

---

## How to Build and Run

1. **Clone the repository**:
   ```bash
   git clone git@github.com:liocle/so_long.git
2. **Navigate to the project directory**:
   ```bash
   cd so_long
   
3. **Set Up MiniLibX**:
This project uses MiniLibX for graphics. Depending on your system architecture, follow these steps to extract the appropriate MiniLibX files:
  - **For Linux**:
     ```bash
     tar --strip-components=1 -xvf minilibx-linux.tgz -C mlx/
  - **For macOS**:
     ```bash
     tar --strip-components=1 -xvf minilibx_mms_20200219_beta.tgz -C mlx/
     
4. **Build the game**:
   ```bash
   make
   
5. **Run the game with a valid map**:
   Use maps in `maps/` for valid and invalid .ber maps
    ```bash
    ./so_long maps/valid/map1.ber
