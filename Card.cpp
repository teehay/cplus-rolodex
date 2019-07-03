#include <iostream>
#include <string>
#include "Card.h"

using namespace std;

Card::Card() :
fname(" "), lname(" "), job(" "), addr(" "), phone(" ")
{}

Card::Card(string fir, string lst, string job, string adr, string phn) :
fname(fir), lname(lst), job(job), addr(adr), phone(phn)
{ this -> key = lst + " " + fir; }

void Card::setFname(string fn){ this->fname = fn; }
string Card::getFname() { return this->fname; }
void Card::setLname(string ln) { this->lname = ln; }
string Card::getLname(){ return this->lname; }
void Card::setJob(std::string job){ this->job = job; }
std::string Card::getJob(){ return this->job; }
void Card::setAddr(string adr) { this->addr = adr; }
string Card::getAddr(){ return this->addr; }
void Card::setPhone(string pho) { this-> phone = pho; }
string Card::getPhone(){ return this->phone; }
string Card::getKey(){ return this-> key; }

void Card::show(ostream& os)
{

    os << getFname() << " " << getLname() << "\t"
    << getJob() << "\n" << getAddr() << "\t" << getPhone() << "\n\n";

}

