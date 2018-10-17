cmake_minimum_required(VERSION 3.12)
project(Data_Structure)

set(CMAKE_CXX_STANDARD 14)

add_executable(Data_Structure main.cpp SortAlgorithm/SortTestHelper.h SortAlgorithm/SelectionSort.h SortAlgorithm/InsertionSort.h SortAlgorithm/MergeSort.h SortAlgorithm/QuickSort.h DataStucture/Heap/MaxHeap.h SortAlgorithm/HeapSort.h DataStucture/Heap/IndexHeap.h DataStucture/Tree/BinarySearchTree.h DataStucture/UnionFind/UnionFind.h DataStucture/Graph/DenseGraph.h DataStucture/Graph/SparseGraph.h)