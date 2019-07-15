#include <iostream>
#include <string>
#include <vector>

void StringToArr(std::string visualNum, std::vector<char>& realNum);
void Add(std::vector<char>& main, std::vector<char> other);
void Sub(std::vector<char>& main, std::vector<char> other);
void Mul(std::vector<char>& main, std::vector<char> other);
void Div(std::vector<char>& main, std::vector<char> other);

class Integer {
private:
	std::string _visualNum;
	std::vector<char> _realNum;
public:
	Integer(std::string visualNum) {
		_visualNum = visualNum;
		StringToArr(visualNum, _realNum);
	}
	Integer() {
		_visualNum = "0";
		StringToArr(_visualNum, _realNum);
	}
	Integer(const Integer& other) {
		_visualNum = other._visualNum;
		_realNum = other._realNum;
	}
	friend std::ostream& operator<< (std::ostream& out, const Integer& prnt) {
		os << prnt._visualNum;
		return os;
	}
	friend std::istream& operator<< (std::istream& in, Integer& get) {
		in >> get._visualNum;
		StringToArr(get._visualNum, get._realNum);
	}
	Integer& operator= (const Integer& other) {
		_realNum = other._realNum;
		_visualNum = other._visualNum;
		return *this;
	}
	Integer& operator+= (const Integer& other) {
		Add(_realNum, other._realNum);
		return *this;
	}
	Integer& operator-= (const Integer& other) {
		Sub(_realNum, other._realNum);
		return *this;
	}
	Integer& operator*= (const Integer& other) {
		Mul(_realNum, other._realNum);
		return *this;
	}
	Integer& operator/= (const Integer& other) {
		Div(_realNum, other._realNum);
		return *this;
	}
	Integer operator+ (const Integer& other) {
		Integer temp(*this);
		Add(temp._realNum, other._realNum);

	}
};

int main() {

	return 0;
}
