# Linear Search

#### Time Complexity: **O(n)**

Linear Search is a brute-force search algorithm.  
It's mechanism is to iterating through all elements, one by one, until the value is found.

## Empirical Test

Empirical Test in worst-case scenario.

| Elements      | Iterations    | Time (ms)  |
|--------------:|--------------:|-----------:|
| 100 000       | 100 000       | 0          |
| 1 000 000     | 1 000 000     | 2          |
| 10 000 000    | 10 000 000    | 20         |
| 100 000 000   | 100 000 000   | 204        |
| 1 000 000 000 | 1 000 000 000 | 2 046      |

![Graph](/src/linear-search/graph/linear-search-graph.png)

#### Hardware and Software used:
* **Processor:** Intel® Core™ i5-9400F CPU @ 2.90GHz ×6
* **Memory:** 16GB
* **OS:** Ubuntu 18.04.4 LTS (x64)
* **Programming Language:** C++
