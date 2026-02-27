*This project has been created as part of the 42 curriculum by dgorceac*

# Philosophers

## Description

The **Philosophers** project is part of the curriculum at 42 School. Its objective is to introduce the fundamentals of concurrent programming, thread management, and synchronization in C.

This project implements the classic Dining Philosophers Problem, a well-known concurrency problem that illustrates synchronization challenges between multiple threads competing for shared resources.

Each philosopher alternates between eating, sleeping, and thinking.  
To eat, a philosopher must acquire two forks (shared resources protected by mutexes).  
The main challenges of this project are:

- Preventing race conditions
- Avoiding deadlocks
- Detecting philosopher death accurately
- Ensuring precise time management in milliseconds

The program is implemented using POSIX **threads** (`pthread`) and **mutexes**.

### The state of a philosopher is formatted as follows:
+ timestamp_in_ms X has taken a fork
+ timestamp_in_ms X is eating
+ timestamp_in_ms X is sleeping
+ timestamp_in_ms X is thinking
+ timestamp_in_ms X died

*timestamp_in_ms* is the current timestamp in milliseconds
and *X*- philosophers number

## Instructions

### Compilation

+ Clone this project :<br>
$ git clone [the path]

+ Compile the program :<br>
$ make

+ Run the project :<br>
$ ./philo  number_of_philosophers  time_to_die  time_to_eat  time_to_sleep [number_of_times_each_philosopher_must_eat]</p>

#### Available Makefile rules:

- compile the project - $ make
- remove object files - $ make clean
- remove object files and executable - $ make fclean
- recompile everything - $ make re
   
## Resources

#### Documentation

- POSIX Threads Programming Guide
- man pthread_create
- man pthread_mutex_init
- The Dining Philosophers Problem (classical concurrency problem description)