#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <random>

class Buyer{
public:
std::vector<int> check;
explicit Buyer(std::vector<int> _check);
};
class Supermarket{
private:
std::vector<std::thread*> threads;
std::vector<std::queue<Buyer*>*> buyerQueues;
int maxProducts;
int maxPrice;
int maxBuyers;
int queueLen;
std::mutex myMutex;
public:
Supermarket(int _maxProducts, int _maxPrice, int _maxBuyers, int _queueLen);
Buyer* createBuyer();
void run();
void serveBuyer(Buyer* _buyer, int _number);
void serveQueue(std::queue <Buyer*>* _buyers);
void serveSupermarket();
};