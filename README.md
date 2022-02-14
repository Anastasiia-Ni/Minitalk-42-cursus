# Minitalk-42-cursus

Server - Client mini chat written on C, using only 2 signals (SIGUSR1 and SIGUSR2) to send a message.

Subject is presented in the [subject.pdf](https://github.com/Anastasiia-Ni/Minitalk-42-cursus/blob/main/en.subject.pdf)

## Usage

- **`make`** to compile mandatory part.

- **`make bonus`** to compile with bonus.
- **`make fclean`** to remove executable files.
- **`make re`** to recompile this project.

## Run 
run commands in different terminals:

$> ./server

$> ./client [server_pid] [message]
