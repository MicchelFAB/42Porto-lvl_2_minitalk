# 42Porto-lvl_2_minitalk

## Project Overview

The Minitalk project is a small data exchange program using UNIX signals. It consists of a server and a client, where the client sends a string message to the server, and the server displays it.

## Purpose

The purpose of this project is to learn about inter-process communication (IPC) using signals in UNIX. It also helps to understand how to handle signals and how to implement a simple protocol for data exchange.

## Components

- `server.c`: The server program that receives and displays the message sent by the client.
- `client.c`: The client program that sends a string message to the server.
- `server_bonus.c`: The bonus server program that receives and displays the message sent by the client, with additional features.
- `client_bonus.c`: The bonus client program that sends a string message to the server, with additional features.

## How to Use

### Compiling the Programs

To compile the programs, run the following command:

```sh
make
```

This will generate the `server`, `client`, `server_b`, and `client_b` executables.

### Running the Server

To run the server, execute the following command:

```sh
./server
```

The server will display its process ID (PID), which you will need to provide to the client.

### Running the Client

To run the client, execute the following command:

```sh
./client <server_pid> <message>
```

Replace `<server_pid>` with the PID of the server and `<message>` with the string message you want to send.

### Example

1. Open a terminal and run the server:

```sh
./server
```

2. Note the PID displayed by the server.

3. Open another terminal and run the client with the server's PID and a message:

```sh
./client 12345 "Hello, world!"
```

### Bonus Features

The bonus version of the project includes the following additional features:

- The server acknowledges the receipt of each message by sending a signal back to the client.
- The client displays a confirmation message when the server acknowledges the receipt of the message.
- The server and client programs are more robust and handle edge cases better.
