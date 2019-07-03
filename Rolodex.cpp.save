#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <iterator>
#include <utility>

#include "Card.h"
#include "Rolodex.h"

using namespace std;

Rolodex::Rolodex()
{
    this->curr = this->cards.begin();
}

Rolodex::Rolodex(multimap<string, Card*> crdpak) :
cards(crdpak)
{
    this->curr = this->cards.begin();

}

Rolodex::~Rolodex()
{
    this->curr = this->cards.begin();
    while (this->cards.begin() != this->cards.end())
        this->remove();

}

void Rolodex::add(Card* card)
{
    this->curr = this->cards.insert(pair<string, Card*>(card->getKey(), card));

}

void Rolodex::remove()
{
    //remove current card
    Card * cardlocation;
    std::multimap<std::string, Card*>::iterator oldcurr;



    oldcurr = this->curr;
    cardlocation = oldcurr->second;
    delete cardlocation;

    if (++this->curr == this->cards.end())
        this->curr = this->cards.begin();

    this->cards.erase(oldcurr);

}

Card Rolodex::getCurrentCard()
{
    Card* cardcopy;
    cardcopy = this->curr->second;
    return *cardcopy;

}

Card Rolodex::flip()
{
    if (++this->curr == this->cards.end())
    {
        this->curr = this->cards.begin();
        return *this->curr->second;
    }
    else
        return *this->curr->second;
}

bool Rolodex::search(const string& lst, const string& fst)
{
    string findname = lst + " " + fst;
    multimap<std::string, Card*>::iterator hold;

    hold = this->cards.find(findname);

    if ( hold != this->cards.end())
    {
        this->curr = hold;
        return true;
    }
    else
        return false;

}

void Rolodex::show(ostream& os)
{
    multimap<string,Card*>::iterator iter = this->cards.begin();
    while (iter != this->cards.end())
    {
        iter->second->show(os);
        ++iter;
    }


}
