*This project has been created as part of the 42 curriculum by tthwe.*

# so_long

A small 2D game built with the school's graphical library, **MiniLibX**. The player navigates a tile-based map, collects every item, and escapes through the exit.

---

## Description

`so_long` takes a `.ber` map file as its only argument, validates the map, opens a window, and lets the player walk around using **W/A/S/D** (or the arrow keys). Each move is printed to the shell. The game ends when the player reaches the exit after collecting every collectible — or when the user presses `ESC`/`Q` or clicks the close button.

A valid map must:
- Be rectangular and enclosed by walls (`1`)
- Contain exactly **1 player** (`P`), exactly **1 exit** (`E`), and **at least 1 collectible** (`C`)
- Use only the five characters `0 1 P E C`
- Have a reachable path from the player to every collectible and to the exit (checked with flood fill)

If any rule is broken, the program exits cleanly after printing `Error\n` followed by an explicit message to stderr.

---

## Instructions

### Requirements

- C compiler
- **MiniLibX** — the matching source archive is bundled in the repo:
  - Linux: `minilibx-linux.tgz` (links `-lXext -lX11 -lm`)
  - macOS: `minilibx_macos_opengl.tgz` or `minilibx_macos_metal.tgz` (links `-framework OpenGL -framework AppKit`)

### MiniLibX setup 

```bash
# On Linux (e.g. the 42 evaluation machines):
tar -xzf minilibx-linux.tgz
mv minilibx-linux mlx

# On macOS:
tar -xzf minilibx_macos_opengl.tgz
mv minilibx_opengl_20191021 mlx
```

The OS is auto-detected by the Makefile (`uname`) to pick the correct linker flags.

### Build

```bash
make          # builds Libft, then so_long
make clean    # removes .o files
make fclean   # removes .o files and the so_long binary
make re       # fclean + make
```

### Run

```bash
./so_long maps/valid.ber
```

The argument must be a path ending in `.ber`. 

### Test Maps

Valid maps:

| Map | Notes |
|-----|-------|
| `maps/valid.ber` | Standard map with several collectibles |
| `maps/minimal_valid.ber` | Smallest possible valid map (`1PCE1`) |

Invalid maps:

| Map / input | Expected output |
|-------------|-----------------|
| *(no argument)* or *(too many)* | `Error\nUsage: ./so_long map.ber\n` |
| `maps/wrong_extension.map` | `Error\nInvalid file extension\n` |
| *(nonexistent path)* | `Error\nInvalid map file\n` |
| `maps/empty.ber` | `Error\nInvalid map file\n` (empty file) |
| `maps/invalid_char.ber` | `Error\nInvalid map\n` (contains `X`) |
| `maps/not_rectangular.ber` | `Error\nInvalid map\n` |
| `maps/not_enclosed.ber` | `Error\nInvalid map\n` (border not all walls) |
| `maps/no_player.ber` | `Error\nInvalid map\n` (no `P`) |
| `maps/no_exit.ber` | `Error\nInvalid map\n` (no `E`) |
| `maps/no_collectible.ber` | `Error\nInvalid map\n` (no `C`) |
| `maps/two_players.ber` | `Error\nInvalid map\n` (duplicate `P`) |
| `maps/two_exits.ber` | `Error\nInvalid map\n` (duplicate `E`) |
| `maps/no_path.ber` | `Error\nInvalid map\n` (exit/collectible unreachable) |


### Controls

| Key | Action |
|-----|--------|
| `W` / `↑` | Move up |
| `A` / `←` | Move left |
| `S` / `↓` | Move down |
| `D` / `→` | Move right |
| `ESC`/`Q` | Quit |
| Window close button | Quit |

Each successful move prints `Moves: N` to the shell. Reaching the exit after collecting every `C` prints `You win!` and closes the window cleanly.

### Map format (`.ber`)

```
1111111
1P0C0E1
1001001
10C00C1
1111111
```

Legend: `0` empty, `1` wall, `P` player start, `C` collectible, `E` exit.

---

## Resources

### Documentation & references used

- [Mlx function collection](https://42-fran-byte-f94097.gitlab.io/docs/so_long/so_long-approach-en/#/) — a very easy-follow guide 
- [MiniLibX guide](https://harm-smits.github.io/42docs/libs/minilibx) — Harm Smits' documentation
- [MiniLibX official source](https://github.com/42Paris/minilibx-linux) — official guide
- [So_long/Building the thing](https://42-cursus.gitbook.io/guide/2-rank-02/so_long/building-the-thing#final-word) — a great guide & check list to start the project and keep it on track
- [XPM Guide](https://www.fileformat.info/format/xpm/egff.htm) — very detailed explanation and good examples to follow
- [Flood fill algo guide](https://www.geeksforgeeks.org/dsa/flood-fill-algorithm/) — algorithm explanation with visual examples

### Use of AI

AI was used as a review and debugging assistant.Specifically:

- verifying that every mandatory rule (map validation, error format, cleanup, etc.) was covered.
- Identifying bugs and resource leaks in the original draft, for example, a missing `NAME` definition in the Makefile, missing `mlx_destroy_display` on Linux, and missing cleanup paths when `mlx_new_window` or `load_textures` fail.
- splitting functions over 25 lines into helpers, reducing argument counts (e.g., passing `t_game *` instead of separate `rows`/`cols`), and fixing tab alignment in struct and function declarations.

Every change suggested by AI was read, understood, and tested manually before being kept. 

---

## Project layout

```
so_long/
├── Makefile
├── so_long.h
├── main.c          # arg check, init pipeline, mlx loop
├── parsing.c       # read .ber file → char **map
├── validate.c      # rectangular, walls, element counts, find player
├── flood_fill.c    # copy_map, flood_fill, check_path, check_walls
├── render.c        # load_textures, draw_cell, render_map
├── movement.c      # move_player, print_moves
├── events.c        # handle_keypress, cleanup_game, close_game
├── utils.c         # error_exit, free_map
├── Libft/          # custom libc subset (built by the main Makefile)
├── minilibx-*.tgz  # MiniLibX sources (extract one → mlx/, see setup above)
├── textures/       # wall.xpm, floor.xpm, player.xpm, collect.xpm, exit.xpm
└── maps/           # sample .ber files (valid + invalid cases)
```

---

## Author

**tthwe** — 42 Bangkok
