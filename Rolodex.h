#ifndef ROLODEX_H_INCLUDED
#define ROLODEX_H_INCLUDED

class Rolodex
{
    public:
        Rolodex();
        Rolodex(std::multimap<std::string, Card*>);
        ~Rolodex();
        void add(Card* card);
        void remove();
        Card getCurrentCard();
        Card flip();
        bool search(const std::string& lst, const std::string& fst);
        void show(std::ostream& os);

    private:
        std::multimap<std::string, Card*> cards;
        std::multimap<std::string, Card*>::iterator curr;
};

#endif // ROLODEX_H_INCLUDED
