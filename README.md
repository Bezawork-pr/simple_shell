SIMPLE SHELL PROJECT

#DAY ONE

Read about the neccessary function calls to create a simple shell


#DAY TWO

Structure the project

GENERAL OUTLOOK OF THE PROJECT AT THE MOMENT
1. Make an executable file
2. Create a soft link in the bin directory to add it to the list of programs
3. Change chmod to executable so that we can execute the shell
4. User parser to get necesary functions
5. Get PATH set to find the paths in your shell project
6. Use gitpid() and gitppid() to get process ids of parent and child process
7. Use fork() function to create child process
8. Use excecve to run the program
9. Get input from the keyboard using getline() function
9. Wait(NULL) for the child process to be executed not to enter zombie state
10. OUTPUT the return

AFTER GETTING SOMEONE BIG PICTURE OF THE SIMPLE SHELL NOW FOCUS ON INDIVIDUAL TASKS


TASK NUMBER ONE

Write a UNIX command line interpreter.

1. Usage: simple shell
2. Displays a prompt
3. Wait for user to enter
4. End with new line
5. No argument passed
6. Print error message if executable is not found
7. Handle end of file condition
8. Build both interactive and non interactive shell

#DAY THREE

1. Make loop that is always true except exit is typed
2. Handle getline function newline character added return
3. Separate files in to input, output, write
4. Add process
5. Ingeneral implementation of DAYTWO

#DAY FIVE

1. Make the prompt return when no value is entered
2. Assign empty "" to buffcopy when no value is entered
3. Make  separte files for tasks just in case
4. Handle the path
5. Handle non interactive mode by not showing prompt and getline return

#DAY SIX AND SEVEN
1. more work on path
2. Save PATH from the envp argument in main
3. SAVE PWD from the envp argument in main
4. Get different file directories by saving PATH up to : use strkto
6. Append command to different directories
7. check if command exist using access
8. print envp element when env is typed
9. print path to current directory  when pwd is typed
10. Add exit(98) when exit is typed
11. fix Betty errors
12. check for memory leaks (2 days allocated)

#DAY EIGHT

1. make similar function like getline()
2. Make similar function like stktok()
3. Make cd command work
4. build a struct for cd
