#!/usr/bin/env python3
import sys
from collections import defaultdict

# Define the states we want to track.
# We ignore instantaneous events like "has taken a fork".
valid_states = {"is eating", "is sleeping", "is thinking"}

# Dictionary to hold events for each philosopher:
#   key: philosopher id (as a string)
#   value: list of tuples (timestamp, state)
philo_events = defaultdict(list)

# Dictionary to count the number of occurrences for each state per philosopher.
#   key: philosopher id (as a string)
#   value: dict mapping state to count
philo_counts = defaultdict(lambda: defaultdict(int))

# Read the log file (each line is expected to have tab-separated fields:
# timestamp, philosopher id, and the message)
with open("out.txt", "r") as f:
    for line in f:
        parts = line.strip().split("\t")
        if len(parts) < 3:
            continue
        try:
            timestamp = int(parts[0])
        except ValueError:
            continue
        philo_id = parts[1]
        message = parts[2]
        if message in valid_states:
            philo_events[philo_id].append((timestamp, message))
            philo_counts[philo_id][message] += 1

# For each philosopher, sort the events by timestamp.
for philo_id in philo_events:
    philo_events[philo_id].sort(key=lambda x: x[0])

# Compute the durations:
# For each philosopher, calculate the time spent in a state as the difference between
# the timestamp of the current event and the next event.
philo_durations = {}
for philo_id, events in philo_events.items():
    durations = defaultdict(int)
    # Loop through each event (except the last one) to compute the duration spent in that state.
    for i in range(len(events) - 1):
        t_current, state_current = events[i]
        t_next, _ = events[i + 1]
        duration = t_next - t_current
        durations[state_current] += duration
    philo_durations[philo_id] = durations

# Print the results sorted by philosopher id.
print("Total time (in ms) and count of each state per philosopher:")
for philo_id in sorted(philo_durations, key=lambda x: int(x)):
    print(f"\nPhilosopher {philo_id}:")
    for state in valid_states:
        time_spent = philo_durations[philo_id].get(state, 0)
        count = philo_counts[philo_id].get(state, 0)
        print(f"  {state}: {time_spent} ms, occurred {count} times")

