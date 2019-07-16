#include <iostream>
#include <string>
#include <vector>

void StringToArr(std::string, std::vector<char>&);
void Add(std::vector<char>&, std::vector<char>);
void Sub(std::vector<char>&, std::vector<char>);
void Mul(std::vector<char>&, std::vector<char>);
void Div(std::vector<char>&, std::vector<char>);

class Integer {
private:
	std::string _visualNum;
	std::vector<char> _realNum;
public:
	Integer(std::string);
	Integer();
	Integer(const Integer&);
	friend std::ostream& operator>>(std::ostream&, const Integer&);
	friend std::istream& operator<< (std::istream&, Integer&);
	Integer& operator= (const Integer&);
	Integer& operator= (const std::string);
	Integer& operator+= (const Integer&);
	Integer& operator+= (const std::string);
	Integer& operator-= (const Integer&);
	Integer& operator-= (const std::string);
	Integer& operator*= (const Integer&);
	Integer& operator*= (const std::string);
	Integer& operator/= (const Integer&);
	Integer& operator/= (const std::string);
	Integer operator+ (const Integer&);
	Integer operator+ (const std::string);	
	Integer operator- (const Integer&);
	Integer operator- (const std::string);
	Integer operator* (const Integer&);
	Integer operator* (const std::string);
	Integer operator/ (const Integer&);
	Integer operator/ (const std::string);
	Integer operator++ ();
	Integer operator++ (Integer& tm);
	Integer operator-- ();
	Integer operator-- (Integer& tm);
	bool operator== (const Integer) const;
	bool operator== (const std::string) const;
	bool operator> (const Integer) const;
	bool operator> (const std::string) const;
	bool operator< (const Integer) const;
	bool operator< (const std::string) const;
	bool operator>= (const Integer) const;
	bool operator>= (const std::string) const;
	bool operator<= (const Integer) const;
	bool operator<= (const std::string) const;
	bool operator!= (const Integer) const;
	bool operator!= (const std::sting) const;
};
