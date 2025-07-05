# 🚀 MapReduce Framework for Multi-Threaded Processing
This project implements a multi-threaded MapReduce framework in C++, designed for efficient parallel data processing. It allows users to define custom map and reduce functions, and execute them concurrently using multiple threads with built-in thread safety and barrier synchronization.

## ✨ Key Features
Custom MapReduce Implementation
Supports user-defined map and reduce functions for maximum flexibility.

Multi-Threading Support
Utilizes the pthread library to achieve parallel processing across multiple threads.

Barrier Synchronization
Implements a reusable thread barrier to ensure proper coordination between threads.

Flexible Job Management
Handles job state tracking, thread synchronization, and balanced workload distribution.

Continuous Integration with GitHub Actions
Automatically compiles and tests the project on every push to ensure correctness and prevent regressions.

## 🗂️ Project Structure
File	Description
Barrier.h / Barrier.cpp	Barrier implementation for thread synchronization
MapReduceClient.h	Abstract interface for defining MapReduce jobs
MapReduceFramework.h / MapReduceFramework.cpp	Full implementation of the MapReduce framework
test1-1_thread_1_process.cpp	Test case: Single-threaded, single-process execution
test4-1_thread_4_process.cpp	Test case: Multi-process, single-thread execution

## ⚙️ How to Use
1. Implement a MapReduce Job
Create a class that inherits from MapReduceClient.

Define your custom map and reduce functions.

Refer to the provided test files for usage examples.

2. Prepare Input Data
Input should be a std::vector of (K1*, V1*) key-value pairs.

3. Start the Job
cpp
Copy
Edit
JobHandle job = startMapReduceJob(client, inputVec, outputVec, numThreads);
waitForJob(job);
4. Retrieve Results
Output will be stored in outputVec.

## ✅ Testing
Pre-written test cases are provided:

test1-1_thread_1_process.cpp — Single-threaded processing

test4-1_thread_4_process.cpp — Multi-process test

📝 Note: The test files were provided as part of the assignment and are not my own work but can be used to evaluate thread safety and execution behavior.

To Run the Tests:
Tests are included in the CMakeLists.txt but are commented out by default.

Simply uncomment the relevant test file in CMakeLists.txt to enable it before building.
