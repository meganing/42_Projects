# so_long — Notes

## Build & Makefile

- **`-Imlx`** → tells the compiler to look in the `mlx/` folder for header files, so `#include "mlx.h"` works.
- **OS detection (`uname`)** → used to pick different flags for MiniLibX. MiniLibX is built on different graphics systems per OS, so it needs different **linker flags** (e.g. `-framework OpenGL -framework AppKit` on macOS vs `-lXext -lX11 -lm` on Linux).

## MiniLibX

- **`void *` = an opaque pointer.** MiniLibX hands these to us and we just pass them back, we never need to look inside them.

## Memory pages

- A **memory page** is the smallest fixed-size chunk of memory the OS manages as a single unit — usually **4096 bytes (4 KB)**.
- Rather than tracking memory byte-by-byte (huge bookkeeping), the OS divides all memory into equal-sized **pages** and manages everything in whole pages.
- Page size is fundamentally a **hardware (CPU) feature** — the OS picks from what the CPU supports, so it can differ by platform.
  - 4 KB is the common default (x86), but **not universal**: Apple Silicon uses 16 KB, some systems use 64 KB, and "huge pages" go to 2 MB+.

### How paging works (step by step)

When the program touches a memory address:

1. CPU sees a **virtual address** — e.g. virtual byte 5000.
2. Split it into `[page number | offset]`. With 4 KB pages: page = 5000 ÷ 4096 = **page 1**, offset = 5000 − 4096 = **byte 904** within that page.
3. Look up page 1 in the **page table** → "virtual page 1 lives at physical page 7."
4. Combine: physical page 7 + offset 904 = the real RAM location. Data fetched. ✅

- This translation happens in **hardware** — the **MMU** (Memory Management Unit) does it on every memory access, with a small cache called the **TLB** (Translation Lookaside Buffer) to make it fast.
- Summary: a page is the fixed-size unit the OS uses to manage memory, enabling **virtual memory, isolation, and swapping**. The MMU translates virtual → physical addresses one page at a time, using the page table.

## Flood fill (map solvability)

- I used **recursion** for flood fill mainly for convenience and because the map size is small.
- If the map were much bigger (e.g. 2000×2000), it would be better to use a **queue or stack data structure with BFS/DFS**, to avoid too many stack frames piling up and causing a **stack overflow**.

## Rendering

- For future reference: to render big maps, it's better to use **double-buffering** to avoid flickering.
