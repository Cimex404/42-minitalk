#  Minitalk 42

Minitalk is a 42 project that teaches about signals and Process ID's.

This project requires to executables: "server" and "client".
The Makefile can compile both executables using the "make" command on the terminal.
The server and client must be run in separe terminals.

First start the server using "./server", the server will now print it's own process ID.
The client is run as follows "./client 'Process ID of the server' 'Any string'"
The client will throw an error if there are more or less arguments provided to the client as needed.

The client will send the string that is entered to the server. The server will interpret them and print out the corrolating string character by character.
This project only allows two signals, SIGUSR1 and SIGUSR2.
The server will acknowledge the recieved signal by sending back the same signal to the client, who will then print an acknowledgement message.


#  Bonus

The Bonus part of the project is the acknowledgement of the signal recieved by the server. The server sends the recieved signal back to the client, who then prints a message.
Additionally, the server needs to be able to handle unicode characters, in this implementation the sever does this automatically, so there is no need for extra code.
