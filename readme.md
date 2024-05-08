Please find the programs of all the questions. I've included the required test cases, and each program is written in C++.

Ans 1
This C++ program checks if two line segments overlap. It defines a function overlapLineCheck to perform this check and a test function to verify its correctness with different inputs. The main function takes input for two line segments, checks for overlap, and runs test cases. The program ensures proper ordering of endpoints and covers various scenarios like overlapping, non-overlapping, negative coordinates, and more.

Ans2
This code compares two version strings, extracting version numbers separated by dots ('.'). It then compares each number pair-wise, determining if one version is greater than the other or if they are equal. The test function verifies the correctness of the compareVersion function with various test cases.

Ans3
In this code we have to implement LRU cache. I have done this by Doubly linked list and unordered map. This approach efficiently manages key-value pairs while ensuring that the least recently accessed items are evicted from the cache when it reaches its capacity or expiry time.
It has following functions
Node Class: Structures nodes in the doubly linked list, holding key, value, and timestamp data.
Insertion Function: Adds a new node after the list head.
Deletion Function: Removes a specified node from the list.
Expiration Check Function: Deletes expired cache entries based on timestamps.
Get Function: Retrieves a value by key, moving the corresponding node to the front for recent use.
Put Function: Inserts or updates key-value pairs, removing the least recently used node if the cache is full.
Print Function: Displays cache contents.
Main Function: Drives user interaction, allowing operations like insertion, retrieval, printing, or exit.

