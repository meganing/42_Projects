*This project has been created as part of the 42 curriculum by tthwe.*

# Minitalk

## Description
Minitalk is a small data exchange program built using UNIX signals. It consists of two programs: a server and a client, that communicate exclusively through SIGUSR1 and SIGUSR2 signals. The client encodes a string into binary and sends it bit by bit to the server, which reconstructs and prints the message.

## Instructions

### Compilation
```bash
make        # builds both server and client
make clean  # removes object files
make fclean # removes object files and binaries
make re     # rebuilds everything from scratch
```

### Usage
Start the server first, it will print its PID:
```bash
./server
```

Then in a second terminal, send a message using the PID printed by the server:
```bash
./client [SERVER_PID] "your message here"
```

### Example
```bash
# Terminal 1
./server
12345

# Terminal 2
./client 12345 "Hello World ! "

# Terminal 1 output
Hello World !
```

### Error handling
The client will print an error message if:
- Wrong number of arguments
- Invalid or non-positive PID

## How it works
1. The server starts and prints its PID, then waits for signals
2. The client takes the server PID and a message as arguments
3. Each character is converted to 8 bits
4. Each bit is sent as a signal — SIGUSR2 for 1, SIGUSR1 for 0
5. The server reconstructs each character from 8 received signals and prints it

## Resources

### Documentation
- [Linux man page — sigaction](https://www.man7.org/linux/man-pages/man2/sigaction.2.html)
- [Linux man page — kill](https://www.man7.org/linux/man-pages/man2/kill.2.html)
- [Linux man page — getpid](https://www.man7.org/linux/man-pages/man2/getpid.2.html)

### Learning materials used
- Julia Evans — signals comic: https://wizardzines.com/comics/signals/
- Beej's Guide — signal handling chapter: https://beej.us/guide/bgc/html/split/signal-handling.html
- CS50 — binary and bits explanation
- CodeVault — signal handlers in C (YouTube)

### AI usage
AI was used during this project for:
- Understanding concepts: UNIX signals, bitwise operations, sigaction vs signal
- Debugging: identifying swapped SIGUSR1/SIGUSR2 in client, fixing usleep timing
- Code review: norminette error fixes, Makefile structure
- All code was written, understood, and validated thoroughly