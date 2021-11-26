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
    void printCodes(struct MinHeapNode* root, int arr[], int top);
    string HuffmanCodes(char data[], int freq[], int size);
    void printArr(int arr[], int n);

private:
    string createDictionary(struct MinHeapNode* root, string result, string tmp);
    struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size);
    void insertMinHeap(struct MinHeap* minHeap,struct MinHeapNode* minHeapNode);
    struct MinHeap* createAndBuildMinHeap(char data[], int freq[], int size);
    void swapMinHeapNode(struct MinHeapNode** a,struct MinHeapNode** b);
    struct MinHeapNode* extractMin(struct MinHeap* minHeap);
    void minHeapify(struct MinHeap* minHeap, int idx);
    void buildMinHeap(struct MinHeap* minHeap);
    int isSizeOne(struct MinHeap* minHeap);
    int isLeaf(struct MinHeapNode* root);
};


#endif //GALLERYTEC_PROYECTO3_HUFFMANCOMPRESION_H
