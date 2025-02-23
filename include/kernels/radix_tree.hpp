#pragma once

#include <memory>

struct BrtNodes {
  explicit BrtNodes(const unsigned int* codes)  // n_nodes
      : morton_codes(codes) {}

  void allocate(const int n) {
    hasLeafLeft = new bool[n];
    hasLeafRight = new bool[n];
    prefixN = new uint8_t[n];
    leftChild = new int[n];
    parent = new int[n];
  }

  void deallocate() const {
    delete[] hasLeafLeft;
    delete[] hasLeafRight;
    delete[] prefixN;
    delete[] leftChild;
    delete[] parent;
  }

  const unsigned int* morton_codes;

  // Flags determining whether the left and right children are leaves
  bool* hasLeafLeft;
  bool* hasLeafRight;

  // The number of bits in the mortonCode this node represents
  // Corresponds to delta_node in [Karras]
  uint8_t* prefixN;

  // Index of left child of this node
  // Right child is leftChild + 1
  int* leftChild;

  // Index of parent
  int* parent;
};

struct RadixTree {
  explicit RadixTree(const unsigned int* sorted_morton_keys,
                     const int n_unique_keys,
                     const float min,
                     const float max)
      : d_tree(sorted_morton_keys),
        n_pts(n_unique_keys),
        n_nodes(n_unique_keys - 1),
        min_coord(min),
        max_coord(max) {
    d_tree.allocate(n_nodes);
  }

  ~RadixTree() { d_tree.deallocate(); }

  // void buildRadixTree();

  BrtNodes d_tree;
  int n_pts;    // number of points (n = number of Unique morton codes)
  int n_nodes;  // number of radix tree nodes (n - 1)
  float min_coord;
  float max_coord;
};

void k_BuildRadixTree(const RadixTree* tree);
