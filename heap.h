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
        int leftChild = 2 * pos + 1;
        int rightChild = 2 * pos + 2;
        int smallest = pos;

        if (leftChild < size && weightArr[data[leftChild]] < weightArr[data[smallest]]) {
            smallest = leftChild;
        }

        if (rightChild < size && weightArr[data[rightChild]] < weightArr[data[smallest]]) {
            smallest = rightChild;
        }

        if (smallest != pos) {
            swap(data[pos], data[smallest]);
            pos = smallest;
        }

    }
};

#endif