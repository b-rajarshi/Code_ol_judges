/*
 * Singleton Design pattern
 * Eliminate option for instantiating more than one object.
 * Static: https://www.geeksforgeeks.org/static-keyword-cpp/
 * Concept: https://stackoverflow.com/questions/270947/can-any-one-provide-me-a-sample-of-singleton-in-c/271104#271104
 * Video: https://www.youtube.com/watch?v=NZaXM67fxbs&list=PLF206E906175C7E07&index=7
 *
 */
#include <iostream>
using namespace std;

class Singleton {
	private:
		 Singleton() {}
		 Singleton(Singleton const&);              // Don't Implement.
		 void operator=(Singleton const&); // Don't implement
	public:
		static Singleton& getInstance() {
			static Singleton firstInstance;
			return firstInstance;
		}
};

int main() {
	// use the singleton
	Singleton::getInstance();
	return 0;
}
