#include "Types/hdr/Integer.hpp"
#include <cassert>

void StringToArr(std::string visualNum, std::vector<char>& realNum);
void Add(std::vector<char>& main, std::vector<char> other);
void Sub(std::vector<char>& main, std::vector<char> other);
void Mul(std::vector<char>& main, std::vector<char> other);
void Div(std::vector<char>& main, std::vector<char> other);

Integer::Integer(std::string visualNum) {
	_visualNum = visualNum;
	StringToArr(visualNum, _realNum);
}

Integer::Integer() {
	_visualNum = "0";
	StringToArr(_visualNum, _realNum);
}

Integer::Integer(const Integer& other) {
	_visualNum = other._visualNum;
	_realNum = other._realNum;
}

friend std::ostream& Integer::operator>> (std::ostream& out, const Integer& prnt) {
	os << prnt._visualNum;
	return os;
}

friend std::istream& Integer::operator<< (std::istream& in, Integer& get) {
	in >> get._visualNum;
	StringToArr(get._visualNum, get._realNum);
}

Integer& Integer::operator= (const Integer& other) {
	_realNum = other._realNum;
	_visualNum = other._visualNum;
	return *this;
}

Integer& Integer::operator= (const std::string visualnum){
	_visualNum = visualnum;
	StringToArr(_visualNum, _realNum);
	return *this;
}

Integer& Integer::operator+= (const Integer& other) {
	Add(_realNum, other._realNum);
	return *this;
}

Integer& Integer::operator+= (const std::string visualnum){
	Add(
}

Integer& Integer::operator-= (const Integer& other) {
	Sub(_realNum, other._realNum);
	return *this;
}

Integer& Integer::operator-= (const std::string visualnum){

}

Integer& Integer::operator*= (const Integer& other) {
	Mul(_realNum, other._realNum);
	return *this;
}

Integer& Integer::operator*= (const std::string visualnum){

}

Integer& Integer::operator/= (const Integer& other) {
	Div(_realNum, other._realNum);
	return *this;
}

Integer& Integer::operator/= (const std::string visualnum){

}

Integer Integer::operator+ (const Integer& other) {
	Integer temp(*this);
	Add(temp._realNum, other._realNum);
}

Integer Integer::operator+ (const std::string visualnum){
	
}

Integer Integer::operator- (const Integer& other){

}

Integer Integer::operator- (const std::string visualnum){

}

Integer Integer::operator* (const Integer& other){

}

Integer Integer::operator* (const std::string visualnum){

}

Integer Integer::operator/ (const Integer& other){

}

Integer Integer::operator/ (const std::string visualnum){

}

Integer Integer::operator++ (){

}

Integer Integer::operator++ (Integer& tm){

}

Integer Integer::operator-- (){

}

Integer Integer::operator-- (Integer& tm){

}

bool Integer::operator== (const Integer& other) const {

}

bool Integer::operator== (const std::string visualnum) const{

}

bool Integer::operator> (const Integer& other) const{

}

bool Integer::operator> (const std::string visualnum) const{

}

bool Integer::operator< (const Integer& other) const{

}

bool Integer::operator< (const std::string visualnum) const{

}

bool Integer::operator>= (const Integer& other) const{
	
}

bool Integer::operator>= (const std::string visualnum) const{

}

bool Integer::operator<= (const Integer& other) const{

}

bool Integer::operator<= (const std::string visualnum) const{

}

bool Integer::operator!= (const Integer& other) const{

}

bool Integer::operator!= (const std::sting visualnum) const{

}
