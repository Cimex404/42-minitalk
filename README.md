#  Minitalk 42

Minitalk is a 42 project that teaches about signals and Process ID's.

##  Mandatory Part

This project requires two executables: "server" and "client".
The Makefile can compile both executables using the "make" command on the terminal.
The server and client must be run in separate terminals.

First start the server using "./server", the server will now print it's own process ID.
The client is run as follows "./client 'Process ID of the server' 'Any string'"
The client will throw an error if there are more or less than those three arguments.

The client will send the string that is entered to the server. The server will interpret them and print out the corelating string character by character.
This project only allows two signals, SIGUSR1 and SIGUSR2. These two signals corelate to a 1 and 0 respectively.


##  Bonus

The Bonus part of the project is the acknowledgement of the signal received by the server. The server sends the received signal back to the client, who then prints a message.
Additionally, the server needs to be able to handle unicode characters, in this implementation the sever does this automatically, so there is no need for extra code.
