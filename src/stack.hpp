constexpr int STK_MAX = 1000;
using namespace std;
class Stack
{
	int _top;
	char buf[STK_MAX];
public:
	
	Stack() {

	_top = 0;

	}

	void push(char c) {
		if (isFull()) {
			cout << "already full" << endl;
		}
		else {
			buf[++_top] = c;
		}
	}
			

	char pop() {
		if (isEmpty()) {
			cout << "Empty" << endl;
			return '@';
		}
		else {
			return buf[_top--];
		}
	}


	char top() {
		if (isEmpty()) {
			return '@';
		}
		else {
			return buf[_top];
		}
	}


	bool isEmpty() {
		return _top == 0;
	}

	bool isFull() {
		return _top == STK_MAX;
	}

	

};

void push_all(Stack & stk, string line) {
	for (char c : line) {
		stk.push(c);
	}
}

void pop_all(Stack & stk) {
	char c;
	while (!stk.isEmpty()) {
		char c = stk.pop();
		cout << c;

	}
	cout << endl;

}







