# Minitalk
Minitalk is that involves creating a client-server application that can transmit messages between two processes using only signals.

## How to Use
To use the Minitalk program, you need to follow these steps:

+ Download or clone the Minitalk repository from GitHub.
+ Compile the program by running make in the root directory of the repository.
+ Start the server by running ./server.
+ Start the client by running ./client [server PID] [message].
+ The client will send the message to the server, and the server will output the received message.

The Minitalk program uses signals to transmit messages between the server and client processes. The client process sends each character in the message to the server by converting it to a binary value and then sending a signal for each bit. The server process receives the signals and reconstructs the original message.

## Conclusion
The Minitalk project is an excellent way to learn about interprocess communication and signals in Unix-based systems. By implementing this program, you will gain experience with signal handling, process synchronization, and binary manipulation.
