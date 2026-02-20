*This project has been created as part of the 42 curriculum by dgorceac*

#Philosophers

##Description

The **Philosophers** project is part of the curriculum at 42 School. Its objective is to introduce the fundamentals of concurrent programming, thread management, and synchronization in C.

This project implements the classic Dining Philosophers Problem, a well-known concurrency problem that illustrates synchronization challenges between multiple threads competing for shared resources.

Each philosopher alternates between eating, sleeping, and thinking.  
To eat, a philosopher must acquire two forks (shared resources protected by mutexes).  
The main challenges of this project are:

- Preventing race conditions
- Avoiding deadlocks
- Detecting philosopher death accurately
- Ensuring precise time management in milliseconds

The program is implemented using POSIX threads (`pthread`) and mutexes.


##Instructions

### Compilation

Clone the repository and compile the project using:

`bash
make

This will generate the executable:
./philo

Available Makefile rules:
make        # compile the project
make clean  # remove object files
make fclean # remove object files and executable
make re     # recompile everything

./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]

##Resources

Documentation

-POSIX Threads Programming Guide
-man pthread_create
-man pthread_mutex_init
-The Dining Philosophers Problem (classical concurrency problem description)
