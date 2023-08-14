# Port Scanner

This program is a simple C-based port scanner that checks for open ports on a specified IP address. It utilizes socket programming to attempt connections to various ports and identifies which ones are open.

## Prerequisites

Before you begin, ensure you have the following:

- C compiler (e.g., gcc)
- Basic understanding of network protocols and socket programming

## Getting Started

1. Clone the repository or download the `port_scanner.c` file.

2. Compile the program using your C compiler:

    ```bash
    gcc port_scanner.c -o port_scanner
    ```

3. Run the compiled program with the target IP address as an argument:

    ```bash
    ./port_scanner <IP address>
    ```

   Replace `<IP address>` with the actual IP address you want to scan for open ports.

## How It Works

1. Accepts the target IP address as a command-line argument.

2. Creates a socket using the `socket()` function.

3. Initializes the target address structure with the provided IP address and prepares to scan all ports.

4. Iterates through ports from 1 to 65535.

5. For each port, attempts to connect to the port using the `connect()` function.

6. If the connection is successful (i.e., the port is open), it prints a message indicating the open port.

7. Closes the socket for the current iteration and creates a new socket for the next iteration.

## Example

Suppose you want to scan open ports on the IP address `192.168.1.1`. You would run the following command:

```bash
./port_scanner 192.168.1.1
