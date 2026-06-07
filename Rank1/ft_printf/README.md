*This project has been created as part of the 42 curriculum by tthwe*

# ft_printf

`ft_printf` recreates the function `printf` function from Libc. This is a good project to learn about **variadic functions** and data type formatting in C.

## Instructions
```bash
# Compile
make

# Clean object files
make clean

# Clean everything
make fclean

# Recompile completely
make re
```
## Algorithm and Data Structures

### Data Structure: `va_list`
The core data structure used in this implementation is **`va_list`** (from the `<stdarg.h>` library).
*   **Justification:** Since `ft_printf` must accept an undefined number of arguments of varying types, standard function parameters cannot be used. The `va_list` structure allows us to traverse the stack of arguments.
*   **Usage:**
    *   `va_start`: Initializes the pointer to the first variadic argument.
    *   `va_arg`: Retrieves the next argument as a specific type (e.g., `int`, `char *`).
    *   `va_end`: Frees the initialized list.

### Algorithm Logic
The function employs a **Linear Parsing Algorithm** combined with **Recursion** for numerical conversions.

1.  **Linear Parsing (O(N)):**
    *   The main loop iterates through the input format string character by character.
    *   **Justification:** This ensures the function processes the string efficiently in a single pass.

2.  **Dispatching System:**
    *   If a character is not `%`, it is written immediately to the output.
    *   If `%` is detected, the algorithm checks the subsequent character (flags: `cspdiuxX%`) and dispatches the corresponding helper function.
    *   **Justification:** A modular dispatch system allows for easy debugging and future expansion if new flags need to be added.

3.  **Recursive Number Printing:**
    *   For numeric types (`%d`, `%i`, `%u`, `%x`, `%p`), the algorithm uses recursion. The number is divided by its base (10 or 16) until a single digit remains, which is then printed.
    *   **Justification:** Recursion avoids the need for `malloc` (dynamic memory allocation) to create string buffers. It naturally handles the order of digits (printing the most significant digit first) without needing to reverse a string array, making the code more memory-efficient and concise.

4.  **Return Value Tracking:**
    *   A global integer `count` is passed (or accumulated) through all helper functions. Every time `write` is called, this counter is incremented.
    *   **Justification:** This strictly mimics the behavior of the real `printf`, which returns the total number of bytes written.

### AI Usage
AI(Gemini) was used during the development of this project for the following tasks:

*   **Logic Debugging:** AI was used to identify recursion base-case errors in the `ft_printnbr` function and to fix logic regarding the return values of helper functions.
*   **Type Clarification:** AI helped explain the specific differences between `int`, `unsigned int`, and `size_t` types, particularly regarding how `%u` (unsigned) and `%p` (pointers) should be handled to avoid overflow or truncation.
*   **README.md Construction:** AI assisted in modifying a `README` to be appropriately styled.

## Resources

A good guide to get started and understand the concept of the subject and logic of the code:
- [gitbook - ft_printf](https://42-cursus.gitbook.io/guide/1-rank-01/ft_printf)

Good testers to test the code:
- [42TESTERS-PRINTF](https://github.com/Mazoise/42TESTERS-PRINTF)
- [ft_printf test](https://github.com/cacharle/ft_printf_testhttps://github.com/cacharle/ft_printf_test)


