#include "market.h"
Buyer::Buyer(std::vector<int> _check) {
	check = _check;
}
Supermarket::Supermarket(int _maxProducts, int _maxPrice,
		int _maxBuyers, int _queueLen) :
		maxProducts(_maxProducts), maxPrice(_maxPrice),
		maxBuyers(_maxBuyers), queueLen(_queueLen) {}
	Buyer* Supermarket::createBuyer() {
		int count = std::rand() % maxProducts + 1;
		std::vector<int> check(count);
		for (int i = 0; i < count; i++) {
			check[i] = std::rand() % maxPrice + 1;
		}
		return new Buyer(check);
	}
	void Supermarket::run() {
		serveSupermarket();
		for (auto currQueue : threads) {
			currQueue->join();
		}
	}
	void Supermarket::serveBuyer(Buyer* _buyer, int _number) {
		for (auto i = 0; i < _buyer->check.size(); i++) {
			int time = std::rand() % 1000;
			std::this_thread::sleep_for(std::chrono::milliseconds(time));
			std::unique_lock<std::mutex> unqLock(myMutex);
			std::cout << "Cashbox " << std::this_thread::get_id()
				<< ": buyer " << _number << " gets product " << i + 1 << '\n';
			unqLock.unlock();
		}
	}
	void Supermarket::serveQueue(std::queue <Buyer*>*_buyers) {
			int number = 1;
			while (!_buyers->empty()){
				auto buyer = _buyers->front();
			_buyers->pop();
			serveBuyer(buyer, number);
			number++;
		}
		delete _buyers;
}
	void Supermarket::serveSupermarket() {
		for (int i = 0; i < maxBuyers; i++) {
			bool findQueue = false;
			for (auto it = buyerQueues.begin(); it != buyerQueues.end(); it++) {
				int time = std::rand() % 500;
				std::this_thread::sleep_for(std::chrono::milliseconds(time));
				if ((*it) == nullptr) {
					buyerQueues.erase(it);
					continue;
				}
				if ((*it)->size() < queueLen) {
					(*it)->push(createBuyer());
					findQueue = true;
					break;
				}
			}
			if (!findQueue) {
				auto ptrQ = new std::queue <Buyer*>;
				ptrQ->push(createBuyer());
				buyerQueues.push_back(ptrQ);
				threads.push_back(new std::thread(&Supermarket::serveQueue, this, ptrQ));
			}
		}
	}