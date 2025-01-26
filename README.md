Minitalk is a 42 project that teaches about signals and Process ID's.

This project contains two executables: "server" and "client"
The Makefile can compile bath executables using the "make" command on the terminal.
The server and client must be run in separe terminals.

First start the server using "./server", the server will now print it's own process ID.
The client is run as follows "./client <Process ID of the server> <The string the is sent to the server>"
The client will throw an error if there are more or less arguments provided to the client as needed.

The client will send the bits of all characters to the server using SIGUSR1 and SIGUSR2, these corrolate to 1 and 0.
The value of SIGUSR1 and SIGUSR2 does not matter, the only thing that matters is that the client sends SIGUSR1 if
it encounters a 1 and the server will interpret the recieved SIGUSR1 as a 1.

The server will acknowledge the recieved signal by sending back the recieved signal to the client, the client will
then print the an acknowledgement message.


