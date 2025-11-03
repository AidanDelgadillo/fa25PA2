//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    void push(int idx, int weightArr[]) {
        // TODO: insert index at end of heap, restore order using upheap()
        data[size] = idx;
        upheap(size, weightArr);
        size++;
    }

    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        // Replace root with last element, then call downheap()

        // This checks if the heap is empty.
        if (size == 0) {
            return -1; // placeholder
        }

        // This makes the root = to the smallest data.
        // Then it moves the last element to the root.
        int minIdx = data[0];
        data[0] = data[size - 1];
        size--;
        downheap(0,weightArr);
    }

    void upheap(int pos, int weightArr[]) {
        // TODO: swap child upward while smaller than parent

        while (pos > 0) {
            int parent = (pos - 1) / 2;

            // This checks if the child is greater than the parent.
            if (weightArr[data[pos]] > weightArr[data[parent]]) {
                // This swaps the child with the parent.
                swap(data[pos], data[parent]);
                pos = parent;
            }
            else {
                return;
            }

        }

    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
        // This sets the two childs to the correct positiions according to the position of the parent.
        int leftChild = 2 * pos + 1;
        int rightChild = 2 * pos + 2;
        int smallest = pos;

        // This checks if the leftChild is less than size which would check if it exists.
        // Then also needs to check if the data of the left child of is less than the smallest (root).
        if (leftChild < size && weightArr[data[leftChild]] < weightArr[data[smallest]]) {
            // This then sets the smallest equal to the leftChild.
            smallest = leftChild;
        }

        // This does the same as the code above except that its for the right child.
        if (rightChild < size && weightArr[data[rightChild]] < weightArr[data[smallest]]) {
            smallest = rightChild;
        }

        // This checks if smallest is not the initial position we were looking at.
        // If it is not, that means that at least one of the children was smaller, so we can swap the initial parent with the one of the smaller of the two children.
        if (smallest != pos) {
            swap(data[pos], data[smallest]);
            pos = smallest;
        }

    }
};

#endif