cmake_minimum_required(VERSION 3.20)
project(Algorithms)

set(CMAKE_CXX_STANDARD 17)

add_executable(Algorithms main.cpp)

# 01. Algebra
add_executable(Binary-exponentiation "01. Algebra/Binary exponentiation.cpp")

# 02. Data Structures
add_executable(Minimum-stack "02. Data Structures/Minimum stack.cpp")
add_executable(Minimum-queue "02. Data Structures/Minimum queue.cpp")
add_executable(Sparse-table "02. Data Structures/Sparse table.cpp")
add_executable(Fenwick-tree "02. Data Structures/Fenwick tree.cpp")

# 03. String Processing
add_executable(Z-function "03. String Processing/Z function.cpp")
add_executable(Hash "03. String Processing/Hash.cpp")
add_executable(KMP "03. String Processing/KMP.cpp")
add_executable(Rabin-Karp "03. String Processing/Rabin-Karp.cpp")

# 04.Linear Algebra

# 05. Combinatorics

# 06. Numerical Methods

# 07. Geometry

# 08. Graphs
add_executable(BFS "08. Graphs/BFS.cpp")
add_executable(DFS "08. Graphs/DFS.cpp" "08. Graphs/DFS.cpp")
add_executable(Connected-components "08. Graphs/Connected components.cpp")
add_executable(Bridges "08. Graphs/Bridges.cpp")
add_executable(Cutpoints "08. Graphs/Cutpoints.cpp")
add_executable(Strongly-connected-components "08. Graphs/Strongly connected components.cpp")
add_executable(Strong-orientation "08. Graphs/Strong orientation.cpp")
add_executable(Dijkstra "08. Graphs/Dijkstra.cpp")
add_executable(Sparse-Dijkstra "08. Graphs/Sparse dijkstra.cpp")
add_executable(Bellman-Ford "08. Graphs/Bellman-Ford.cpp")
add_executable(Improved-Bellman-Ford "08. Graphs/Improved Bellman Ford.cpp")
add_executable(0-1-BFS "08. Graphs/0-1 BFS.cpp")
add_executable(DEsopo-Pape "08. Graphs/D´Esopo-Pape.cpp")
add_executable(Floyd-Warshall "08. Graphs/Floyd-Warshall.cpp")
add_executable(Prim "08. Graphs/Prim.cpp")

# 09. Miscellaneous
