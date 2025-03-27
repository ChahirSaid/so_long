# So Long 🎮
## And thanks for all the fish! 🐟

This project is a small 2D game that challenges you to explore the intricacies of game development using C and the Minilibx graphics library. Players navigate through a map, collecting items and finding the exit while managing their movements strategically. 🕹️

## [Download the Project PDF](https://github.com/ChahirSaid/so_long/blob/main/so_long.pdf)

### Game Features 🌟
- 2D tile-based map navigation 🗺️
- Collectible item mechanics 🧩
- Movement tracking 🚶
- Basic game state management 🎲
- Optional bonus version with additional gameplay elements 🚀

## Prerequisites 📋
- Linux Operating System (Ubuntu/Debian recommended) 🐧
- GCC or Clang compiler 💻
- Make 🛠️
- X11 development libraries 🖥️

## Installation Steps 🔧

### 1. Clone the Repository
```bash
git clone https://github.com/ChahirSaid/so_long.git
cd so_long
```

### 2. Install System Dependencies
```bash
sudo apt-get update
sudo apt-get install -y build-essential xorg libxext-dev libbsd-dev
```

### 3. Prepare Minilibx Library
```bash
cd requirements
tar -xvzf minilibx-linux.tgz
cd minilibx-linux
make
sudo cp libmlx.a /usr/include/
sudo cp mlx.h /usr/include/
cd ../..
```

### 4. Compile the Project
Compile the main version:
```bash
make
```
Or compile the bonus version:
```bash
make bonus
```

### 5. Run the Game 🎮
For the main version:
```bash
./so_long maps/mapname.ber
```
For the bonus version:
```bash
./so_long_bonus maps/mapname.ber
```

## Gameplay Controls 🕹️
- `W` or `↑`: Move Up ⬆️
- `A` or `←`: Move Left ⬅️
- `S` or `↓`: Move Down ⬇️
- `D` or `→`: Move Right ➡️
- `ESC`: Exit Game ❌

## Map Requirements 🗺️
- Must be in `.ber` format 📄
- Rectangular shape 📐
- Walls around the border 🧱
- At least one collectible 💎
- One player start position 🏁
- One exit 🚪

## Troubleshooting 🛠️
- Ensure all dependencies are installed 🔌
- Check that the Minilibx library is correctly compiled and copied 📦
- Verify you have the necessary graphics drivers 🖥️
- Validate map file integrity 🕵️

## Additional Notes 📝
- Requires X11 graphics support 🖥️
- Developed and tested on Linux systems 🐧
- Minimum recommended system: Linux with X11 graphics 💻

## Contributing 🤝
1. Fork the repository 🍴
2. Create your feature branch (`git checkout -b feature/AmazingFeature`) 🌿
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`) 💾
4. Push to the branch (`git push origin feature/AmazingFeature`) 🚀
5. Open a Pull Request 📬

## License 📄
Distributed under the 42 School License. See `LICENSE` for more information. ⚖️
