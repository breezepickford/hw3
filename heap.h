#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector> //added this (allowed)

template <typename T, typename PComparator = std::less<T>>
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   *
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   * //^^^ lowkey confusing?? read up more on functors
   */
  Heap(int m = 2, PComparator c = PComparator());

  /**
   * @brief Destroy the Heap object
   *
   */
  ~Heap();

  /**
   * @brief Push an item to the heap
   *
   * @param item item to heap
   */
  void push(const T &item);

  /**
   * @brief Returns the top (priority) item
   *
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const &top() const;

  /**
   * @brief Remove the top priority item
   *
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  // returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   *
   */
  bool empty() const;

  /**
   * @brief Returns size of the heap
   *
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> heap; // da heap
  int ary;             // holds # of kids possible
  PComparator compare; // compares whether better

  void heapifyUp(int index);
  void heapifyDown(int index);
  int parent(int index) const;
  int child(int index, int k) const;
};

// Add implementation of member functions here
// constructor
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) : ary(m), compare(c) {}
// destructor
template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap() {}
// push
template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T &item)
{
  heap.push_back(item);
  heapifyUp(heap.size() - 1);
}

// size
template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const
{
  return heap.size();
}

// empty
template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const
{
  return heap.empty();
}

// heapify up (new ele added to heap)
template <typename T, typename PComparator>
void Heap<T, PComparator>::heapifyUp(int index)
{
  // while not at top of tree (id 0)
  // comparing curr index to its parent returns true (less than for min heap, greater than for max heap)
  while (index > 0 && compare(heap[index], heap[parent(index)]))
  {
    std::swap(heap[index], heap[parent(index)]); // swap w/ par if true
    index = parent(index);                       // move up tree
  }
}

// heapify down (root removed from heap)
template <typename T, typename PComparator>
void Heap<T, PComparator>::heapifyDown(int index)
{
  // init best val to curr id
  int best = index;
  // go thru all kids of curr node (it has ary # of kids) and find whether any one of them vios heap propert (is better)
  for (int i = 1; i <= ary; ++i)
  {
    // get index of child
    int c = child(index, i);
    // if index less than heap size (valid index)
    // AND compare returns true for kid and curr best (aka kid is better than curr)
    if (c < heap.size() && compare(heap[c], heap[best]))
    {
      // if true set best to be the kid
      best = c;
    }
  }
  // if best not init node
  if (best != index)
  {
    // swap curr with best
    std::swap(heap[index], heap[best]);
    // recursive call down to go thru rest of tree
    heapifyDown(best);
  }
}

// We will start top() for you to handle the case of
// calling top on an empty heap
template <typename T, typename PComparator>
T const &Heap<T, PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if (empty())
  {
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element - this is just the first index aka 0
  return heap[0];
}

// We will start pop() for you to handle the case of
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T, PComparator>::pop()
{
  if (empty())
  {
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");
  }
  std::swap(heap[0], heap.back()); // swap top and last
  heap.pop_back();                 // remove last
  heapifyDown(0);                  // heapify
}

// parent
template <typename T, typename PComparator>
int Heap<T, PComparator>::parent(int index) const
{
  return (index - 1) / ary;
}

// child
template <typename T, typename PComparator>
int Heap<T, PComparator>::child(int index, int k) const
{
  return ary * index + k;
}

#endif
