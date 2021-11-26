#ifndef GALLERYTEC_PROYECTO3_HUFFMANCOMPRESION_H
#define GALLERYTEC_PROYECTO3_HUFFMANCOMPRESION_H

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

struct MinHeapNode;
struct MinHeap;
struct page;
struct CompressedImage;

class HuffmanCompresion {
public:
    /**
     * Prints the contents of the heap
     * @param root
     * @param arr
     * @param top
     */
    void printCodes(struct MinHeapNode* root, int arr[], int top);

    /**
     * Initializes the huffman and returns the tree
     * @param data
     * @param freq
     * @param size
     * @return
     */
    string HuffmanCodes(char data[], int freq[], int size);

    /**
     * Prints the tree into a more comprehensive  human readible way
     * @param arr
     * @param n
     */
    void printArr(int arr[], int n);

private:
    /**
     * This method creates the used dictionaty
     * @param root
     * @param result
     * @param tmp
     * @return
     */
    string createDictionary(struct MinHeapNode* root, string result, string tmp);

    /**
     * This method initializes the tree and populates it
     * @param data
     * @param freq
     * @param size
     * @return
     */
    struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size);

    /**
     * Inserts the given minHeap into the tree
     * @param minHeap
     * @param minHeapNode
     */
    void insertMinHeap(struct MinHeap* minHeap,struct MinHeapNode* minHeapNode);

    /**
     * Creates the MinHeap and its leafs
     * @param data
     * @param freq
     * @param size
     * @return
     */
    struct MinHeap* createAndBuildMinHeap(char data[], int freq[], int size);

    /**
     * The method receives 2 nodes and  swaps them
     * @param a
     * @param b
     */
    void swapMinHeapNode(struct MinHeapNode** a,struct MinHeapNode** b);

    /**
     * Returns the minimun node from the tree
     * @param minHeap
     * @return
     */
    struct MinHeapNode* extractMin(struct MinHeap* minHeap);

    /**
     * Sorts the elements from the tree
     * @param minHeap
     * @param idx
     */
    void minHeapify(struct MinHeap* minHeap, int idx);

    /**
     * This method recieves a node and initializes it to the tree
     * @param minHeap
     */
    void buildMinHeap(struct MinHeap* minHeap);

    /**
     * Returns a boolean weather or not the hepa is size one
     * @param minHeap
     * @return
     */
    int isSizeOne(struct MinHeap* minHeap);

    /**
     * If the root has no children returns true
     * @param root
     * @return
     */
    int isLeaf(struct MinHeapNode* root);
};


#endif //GALLERYTEC_PROYECTO3_HUFFMANCOMPRESION_H
