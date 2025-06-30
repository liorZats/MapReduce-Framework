MapReduce Framework for Multi-Threaded Processing
This project implements a multi-threaded MapReduce framework in C++, designed for efficient parallel data processing. The framework allows users to define custom map and reduce functions, and execute them concurrently using multiple threads, with built-in thread safety and barrier synchronization.

# Key features
Custom MapReduce Implementation
Supports user-defined map and reduce functions.

Multi-Threading Support
Uses the pthread library to achieve parallel processing.

Barrier Synchronization
Implements a reusable thread barrier to coordinate thread execution.

Flexible Job Management
Handles job state tracking, thread synchronization, and balanced workload distribution.

Continuous Integration with GitHub Actions
Automatically compiles and tests the project on every push to ensure correctness and prevent regressions.

# Project Structure
File	Description
Barrier.h / Barrier.cpp	Barrier implementation for thread synchronization
MapReduceClient.h	Abstract interface for defining MapReduce jobs
MapReduceFramework.h / MapReduceFramework.cpp	Implementation of the MapReduce framework
test1-1_thread_1_process.cpp	Test: 1 thread, 1 process
test4-1_thread_4_process.cpp	Test: 4 processes, 1 thread each

🚀 How to Use
Implement a MapReduce Job:

Create a class inheriting from MapReduceClient.

Define your custom map and reduce functions (see the provided test files for examples).

Prepare Input Data:

Input should be a vector of (K1*, V1*) pairs.

Start a Job:

cpp
Copy
Edit
JobHandle job = startMapReduceJob(client, inputVec, outputVec, numThreads);
waitForJob(job);
Retrieve Results:

Output will be stored in outputVec.

## Testing
Pre-written test cases (test1-1_thread_1_process.cpp and test4-1_thread_4_process.cpp) are provided to verify correctness and performance.

Note: These test files were not written by me but can be used to evaluate thread safety and execution behavior.

Tests are included in the CMake setup but are commented out by default. To enable a test, simply uncomment it in CMakeLists.txt before building.

## GitHub Actions Workflow
This project includes a CI workflow that:

Compiles the framework and test executables on every push.

Runs each test and generates an output file.

Compares the output to expected results.

Fails the build if any differences are detected to ensure immediate regression feedback.

👉 Workflow configuration can be found in the .github/workflows directory.
