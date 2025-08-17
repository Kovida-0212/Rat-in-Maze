# Rat-in-Maze security agents
## Project Overview:
This project simulates four private security agents navigating complex and hazardous environments to reach their designated destinations safely and securely. Inspired by the classic "rat in a maze" problem, the agents employ a backtracking algorithm to systematically explore secure paths in mazes representing security zones. The main objective is to ensure the agents only traverse safe areas while dynamically adapting to obstacles and threats.
## Problem Statement
The agents work for A.P. Securitas Pvt. Ltd. and are assigned missions in environments modeled as mazes with varying levels of security and safety. Each maze cell is represented by a number, with secure positions being those divisible by 3. The agents must find paths through these secure zones, avoiding obstacles and unsafe areas, to successfully complete their missions.
## Approach and Algorithms
- Backtracking Algorithm: The primary approach used to explore possible paths recursively and backtrack upon reaching dead-ends, ensuring the safest route is found.
- Secondary Approaches Discussed:
   - Dijkstra’s Algorithm: For shortest path calculation in weighted scenarios.
   - A Search Algorithm:* Heuristic-based pathfinding considering security priorities.
   - Minimax Algorithm: For strategic decision-making in adversarial environments.
   - Ant Colony Optimization: A nature-inspired technique for finding optimal paths via pheromone trails.
## Key Features
- Binary-coded maze representation indicating security and obstacles.
- Path selection restricted to secure cells (numbers divisible by 3).
- Real-time mapping and logging of visited paths.
- Adaptation to dynamic security changes within the environment.
- Clear visualization of agent paths via symbolic and binary output formats.
- Identification of nearest reachable location if a complete path to the destination does not exist.
## Getting Started
### Prerequisites
 - A C++ compiler such as GCC or Clang.
 - Basic familiarity with running commands in a terminal or command prompt.
### How to Run
1. Clone the repository:
    ```
    git clone <your-repo-url>
    cd <repository-folder>
    ```
2. Compile the code:
    ```
    g++ -o agent_maze main.cpp
    ```
3. Run the program:
    ```
    ./agent_maze
    ```
## Example input
  ```
    Enter the size of the maze: 4
    Enter the maze elements (0 for obstacles, any number for open paths):
    3 6 0 3
    0 0 0 6
    3 0 0 9
    6 3 3 3
  ```
## Output
