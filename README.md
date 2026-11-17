\# Clinic Simulation



A discrete-event simulation of a multi-branch clinic, written in C++.

Patients check in, wait in emergency or regular queues, and are assigned

to specialist (S) or junior (J) doctors. The project uses its own

Queue, PriorityQueue and LinkedList templates instead of the STL.



\## Features

\- Event-driven engine (check-in, leave and urgent events)

\- Emergency and regular queues with auto-escalation after a waiting limit

\- Doctors with shifts, break rules and per-branch assignment

\- Silent, interactive (console) and GUI modes (raylib)

\- Results written to an output file with average wait and visit times



\## Build

1\. Open `data project.slnx` in Visual Studio (C++ desktop workload).

2\. Download raylib for Windows and place its headers and library

&#x20;  in a `vendor` folder (`vendor/include`, `vendor/lib`).

3\. Build the x64 Debug configuration.



\## Input file format

```

B SU WU PS PJ            branches, setup, wrap-up, per-test time (S and J)

<doctors per branch>

<branch> <S|J> <shift start> <break after> <break duration>   (one per doctor)

<auto-escalation time>

<number of events>

C <R|E> <time> <id> <branch> <tests>    check-in

L <time> <id>                           leave

U <time> <id>                           promote to urgent

```

See the `sample\*.txt` files for examples.



\## About

Started as a university team project; development continues here.



\## Roadmap

\- Fix leave and urgent handling across both queues

\- Free patients still queued at the end of a run

\- Accept input file name as an argument

\- Automated tests for the sample files

\- Statistics report

