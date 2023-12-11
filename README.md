# Elevator-Control-System
This C program simulates an elevator system, modeling passenger requests and floor movements. It utilizes structures for elevator and requests, handling input for floors and passengers. The simulation efficiently serves requests, showcasing a fundamental elevator algorithm in a concise C implementation.
# Elevator Simulation in C

This C program simulates the operation of an elevator system. The elevator serves requests from passengers to move to different floors. The simulation takes user input for the number of floors and the number of people, and then simulates passengers entering the elevator and making floor requests.

## Features

- Elevator Structure: The program defines a simple elevator structure with a current floor and a request queue implemented as a linked list.
- Request Handling: Requests are inserted into the elevator's request queue in ascending order of the target floor. The elevator moves to each floor in the request queue, serving the passengers.
- Simulation Loop: The main program includes a simulation loop that allows the user to run multiple simulations with different input parameters.

## Usage

1. Compile the Code: Use a C compiler to compile the source code.

2. Run the Executable: Execute the compiled program.

3. Follow On-Screen Instructions: Enter the number of floors, the number of people, and the target floors for each person as prompted.

4. Simulation Output: The program outputs the elevator's movement, floor requests, and simulation completion.

## Example

Here's a brief example of a simulation run:

Enter the number of floors: 5
Enter the number of people: 3
Person 1: Enter the target floor (0 to 4): 2
Person 2: Enter the target floor (0 to 4): 0
Person 3: Enter the target floor (0 to 4): 4
Moving from Floor 0 to Floor 2
Opening doors on Floor 2
Serving request on Floor 2
Closing doors on Floor 2
Moving from Floor 2 to Floor 0
Opening doors on Floor 0
Serving request on Floor 0
Closing doors on Floor 0
Moving from Floor 0 to Floor 4
Opening doors on Floor 4
Serving request on Floor 4
Closing doors on Floor 4
Simulation completed.
