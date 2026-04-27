# philosophers — Dining Philosophers Problem

> **42KL Core — Module 3**

A simulation of the classic **Dining Philosophers** concurrency problem. `N` philosophers sit at a round table with `N` forks between them. Each philosopher alternates between **thinking**, **eating** (needs both adjacent forks), and **sleeping**. The simulation ends when a philosopher starves or all philosophers have eaten the required number of times.

Two implementations are provided:

- **`philo/`** — Mandatory: uses **POSIX threads** (`pthread`) with **mutexes**.
- **`philo_bonus/`** — Bonus: uses **processes** (`fork`) with **POSIX semaphores**.

---

## 📁 Project Structure

```
m3/philosophers/
├── philo/               # Mandatory — threads + mutexes
│   ├── include/
│   │   └── philo.h
│   ├── src/
│   │   ├── philo.c          # Entry point
│   │   ├── init.c           # Data and mutex initialisation
│   │   ├── table.c          # Monitor thread (death / meal-count check)
│   │   ├── input_check.c    # Argument validation
│   │   ├── utils.c–3        # Timer, status printing, helpers
│   └── Makefile
└── philo_bonus/         # Bonus — processes + semaphores
    ├── include/
    │   └── philo_bonus.h
    ├── src/
    │   ├── philo.c          # Entry point, process spawning
    │   ├── init.c           # Data and semaphore initialisation
    │   ├── table.c          # Per-philosopher routine
    │   ├── death_exit.c     # Death detection and clean exit
    │   ├── print_timer.c    # Status output with timestamps
    │   ├── input_check.c    # Argument validation
    │   └── utils.c–2        # Helpers
    └── Makefile
```

---

## 🚀 Usage

```bash
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
```

| Argument | Description | Unit |
|---|---|---|
| `number_of_philosophers` | Number of philosophers (and forks). Range: 1–200 | count |
| `time_to_die` | Time from last meal (or start) before a philosopher dies | ms |
| `time_to_eat` | Time a philosopher spends eating (holds both forks) | ms |
| `time_to_sleep` | Time a philosopher spends sleeping | ms |
| `[must_eat]` | *(Optional)* Stop simulation when all philosophers have eaten this many times | count |

### Examples

```bash
# 5 philosophers, die after 800ms, eat for 200ms, sleep for 200ms
./philo 5 800 200 200

# Stop after each philosopher has eaten 7 times
./philo 4 410 200 200 7

# Single philosopher (can never eat — only one fork)
./philo 1 800 200 200
```

---

## 🧵 Mandatory — `philo/` (Threads + Mutexes)

Each philosopher runs in its own **pthread**. A dedicated **monitor thread** (`table_routine`) continuously checks whether any philosopher has starved or whether the meal-count target has been reached.

### Synchronisation

| Resource | Protection |
|---|---|
| Forks | Individual mutex per fork |
| Status printing | `lock_print` mutex (prevents garbled output) |
| Simulation end flag | `lock_end` mutex |
| Last-meal timestamp | Per-philosopher `lock_eat` mutex |

### Lifecycle per Philosopher Thread

```
while (not dead and not done):
    think  → try to acquire left fork, then right fork
    eat    → hold both forks for tt_eat milliseconds
    release both forks
    sleep  → sleep for tt_sleep milliseconds
```

---

## 🔀 Bonus — `philo_bonus/` (Processes + Semaphores)

Each philosopher is a separate **process** (`fork`). Semaphores replace mutexes for cross-process synchronisation.

### Semaphores Used

| Semaphore | Purpose |
|---|---|
| `lock_forks` | Counting semaphore initialised to `N` (total forks) |
| `lock_print` | Binary semaphore for protected printing |
| `lock_end` | Signals simulation end to all processes |
| `lock_eat` | Per-philosopher eat-count tracking |
| `lock_dead` | Signals philosopher death to monitor |
| `lock_wait` | Synchronises process-level monitoring |
| `lock_monitor` | Coordinates internal monitor threads |

---

## 📤 Output Format

Each state change is printed as:

```
[timestamp_ms] [philosopher_id] [status]
```

| Status message | Meaning |
|---|---|
| `has taken a fork` | Philosopher picked up one fork |
| `is eating` | Philosopher is eating |
| `is sleeping` | Philosopher is sleeping |
| `is thinking` | Philosopher is thinking |
| `died` | Philosopher has starved |

Colour-coded by status in the terminal:
- **Cyan** — fork taken
- **Green** — eating
- **Blue** — sleeping
- **Yellow** — thinking
- **Red** — died

---

## ⚠️ Rules & Constraints

- A philosopher **must not die** if they can eat in time.
- No data races — every shared resource is protected.
- `died` must be printed **within 10 ms** of actual starvation.
- The simulation ends immediately when a philosopher dies or the optional meal-count is reached.
- With a single philosopher, they can never eat (only one fork available) and will always die.

---

## 🛠️ Build

```bash
# Mandatory (threads)
cd philo && make

# Bonus (processes)
cd philo_bonus && make

# Clean
make clean / make fclean / make re
```

---

## 📝 Notes

- All time values are in **milliseconds**.
- `usleep` precision limitations on Linux are mitigated by a busy-wait loop (`delay_ms`) that checks elapsed time against a high-resolution `gettimeofday` timer.
- Maximum supported philosopher count is **200** (defined by `MAX_PHILO`).
