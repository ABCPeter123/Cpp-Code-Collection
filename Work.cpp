#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class MaxHeap { 
public:
    vector<int> heap_list;
    int count;

    MaxHeap() {
        heap_list = {};
        count = 0
    }

    int parent_idx(int idx) {
        return idx / 2;
    }

    int left_child_idx(int idx) {
        return idx * 2;
    }
    
    int right_child_idx(int idx) {
        return idx * 2 + 1;
    }

    bool child_present(int idx) {
        return left_child_idx(idx) <= count;
    }

    void add(int element) {
        count++;
        heap_list.push_back(element);
        heapify_up();
    }

    void heapify_up() {
        int idx = count;
        while (parent_idx(idx) > 0) {
            int child = heap_list[idx];
            int parent = heap_list[parent_idx(idx)];
            if (parent < child) {
                heap_list[idx] = parent;
                heap_list[parent_idx(idx)] = child;
            }
            idx = parent_idx(idx);
        }
    }

    int retrieve_max() {
        if (count == 0) return NULL;
        int max_value = heap_list[1];
        heap_list[1] = heap_list[count];
        count--;
        heap_list.erase(heap_list.back());
        heapify_down();
        return max_value;
    }

  def heapify_down(self):
    idx = 1
    while self.child_present(idx):
      print("Heapifying down!")
      larger_child_idx = self.get_larger_child_idx(idx)
      child = self.heap_list[larger_child_idx]
      parent = self.heap_list[idx]
      if parent < child:
        self.heap_list[idx] = child
        self.heap_list[larger_child_idx] = parent
      idx = larger_child_idx
    print("HEAP RESTORED! {0}".format(self.heap_list))
    print("") 

  def get_larger_child_idx(self, idx):
    if self.right_child_idx(idx) > self.count:
      print("There is only a left child")
      return self.left_child_idx(idx)
    else:
      left_child = self.heap_list[self.left_child_idx(idx)]
      right_child = self.heap_list[self.right_child_idx(idx)]
      if left_child > right_child:
        print("Left child "+ str(left_child) + " is larger than right child " + str(right_child))
        return self.left_child_idx(idx)
      else:
        print("Right child " + str(right_child) + " is larger than left child " + str(left_child))
        return self.right_child_idx(idx)

def heapsort(lst):
  sort = []
  max_heap = MaxHeap()
  for idx in lst:
    max_heap.add(idx)
  while max_heap.count > 0:
    max_value = max_heap.retrieve_max()
    sort.insert(0, max_value)
  return sort




int main() {
    
}