#ifndef CARD_H_INCLUDED
#define CARD_H_INCLUDED

class Card
{
    public:
        Card();
        Card(std::string, std::string, std::string, std::string, std::string);

        void setFname(std::string);
        std::string getFname();
        void setLname(std::string);
        std::string getLname();
        void setJob(std::string);
        std::string getJob();
        void setAddr(std::string);
        std::string getAddr();
        void setPhone(std::string);
        std::string getPhone();
        std::string getKey();
        void show(std::ostream&);

    private:
        std::string fname;
        std::string lname;
        std::string job;
        std::string addr;
        std::string phone;
        std::string key;


};


#endif // CARD_H_INCLUDED
