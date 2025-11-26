# Philosophers

A multithreaded simulation of the classic Dining Philosophers problem, implemented in C using POSIX threads and mutexes.

## Table of Contents
- [About](#about)
- [The Problem](#the-problem)
- [Usage](#usage)
- [Arguments](#arguments)
- [Implementation Details](#implementation-details)
- [Features](#features)
- [Example](#example)

##  About

This project is a solution to the classic **Dining Philosophers Problem**, a synchronization challenge in concurrent programming. The simulation demonstrates how to manage multiple threads competing for shared resources while preventing deadlock and race conditions.

## The Problem

One or more philosophers sit at a round table with a large bowl of spaghetti in the center. The philosophers alternate between three states: **eating**, **thinking**, and **sleeping**.

**Rules:**
- There are as many forks as philosophers on the table
- A philosopher needs **two forks** (left and right) to eat
- Philosophers cannot communicate with each other
- Philosophers must not starve
- The simulation stops when a philosopher dies or all have eaten enough times

##  Usage

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_must_eat]
```

### Arguments

| Argument | Description | Unit |
|----------|-------------|------|
| `number_of_philosophers` | Number of philosophers (and forks) | - |
| `time_to_die` | Time before a philosopher dies without eating | milliseconds |
| `time_to_eat` | Time it takes for a philosopher to eat | milliseconds |
| `time_to_sleep` | Time a philosopher spends sleeping | milliseconds |
| `[number_of_times_each_must_eat]` | (Optional) Simulation stops after each philosopher eats this many times | - |

### Example

```bash
# 5 philosophers, die after 800ms, eat for 200ms, sleep for 200ms
./philo 5 800 200 200

# Same as above, but simulation ends after each philosopher eats 7 times
./philo 5 800 200 200 7
```

##  Implementation Details

### Thread Management
- Each philosopher is represented as a **separate thread**
- Forks are protected by **mutexes** to prevent race conditions
- Additional mutexes protect shared data (print, death checks, last meal time)

### Deadlock Prevention
- Even-numbered philosophers start eating with a slight delay
- Ensures not all philosophers grab their left fork simultaneously

### Death Detection
- Continuous monitoring checks if any philosopher hasn't eaten within `time_to_die`
- Death is detected and reported within **10ms** of occurrence

### Output Format
```
[timestamp_ms] philosopher_number has taken a fork🍴
[timestamp_ms] philosopher_number is eating🍝
[timestamp_ms] philosopher_number is sleeping😴
[timestamp_ms] philosopher_number is thinking🤔
[timestamp_ms] philosopher_number died😵
```

## Example Output

```bash
$ ./philo 5 800 200 200
0 philo 1 has taken the left fork🍴
0 philo 1 has taken the right fork🍴
0 philo 1 is eating🍝
15 philo 2 has taken the left fork🍴
15 philo 2 has taken the right fork🍴
15 philo 2 is eating🍝
200 philo 1 is sleeping😴
215 philo 2 is sleeping😴
400 philo 1 is thinking🤔
...
```

## Testing

```bash
# No philosopher should die
./philo 5 800 200 200

# A philosopher should die
./philo 4 310 200 100

# No philosopher should die, stops after 7 meals each
./philo 5 800 200 200 7

# Edge case: 1 philosopher (should die)
./philo 1 800 200 200
```

## Cleanup

```bash
# Remove object files
make clean

# Remove object files and executable
make fclean

# Recompile everything
make re
```
