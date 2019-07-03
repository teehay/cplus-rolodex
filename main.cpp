#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <algorithm>

#include "Card.h"
#include "Rolodex.h"
#include "main.h"


using namespace std;

int main()
{

    int hardcodedelems = 10;
    std::multimap<string, Card*> cardPack; // Multimap of card pointers to
                // be loaded into the Rolodex constructor. The multimap uses
                // a string key made up of the person's last name + first name.

    Card * cards[hardcodedelems] = {
    new Card("Tony", "Hansen", "Writer", "12 E. St. NY, NY 33333", "555-9999"),
    new Card("Jon", "Smyth", "Computer Hardware", "Computer Services Pittsburgh, PA", "555-1324"),
    new Card("Alonza", "Heard", "Mechanic", "123 Anyplace Ave Malden, MA", "555-5678"),
    new Card("Jen", "Reyes", "Graphic artist", "325 Oak Rd. Wilmington, MA", "555-4950"),
    new Card("Alan", "Lupine", "Vet", "1 Bigelow Ave. Lawrence, MA", "555-7654"),
    new Card("Jewel", "Proverb", "Landscaper", "34 Washington St. Waltham, MA", "555-3333"),
    new Card("Paul", "Revere", "Radical Revolutionary", "45 Commonwealth Ave. Boston, MA", "555-1776"),
    new Card("Adolf", "Coors", "Beer Manufacturer", "Boston, MA", "555-2337"),
    new Card("Seymour", "Papert", "Lego Professor", "MIT", "555-1111"),
    new Card("Fred", "Milton", "Sales", "12 Freedom Way Nashua, NH", "555-9981")
    }; // Array fpr loading data sequentially into multimap.

    for (int i = 0; i < hardcodedelems; i++) // Insert elements, sorted by key.
        cardPack.insert(pair<string, Card*>(cards[i]->getKey(), cards[i]));

    Rolodex rd(cardPack); // Instantiate a rolodex, loaded with the card pack.
    Rolodex *roloDex = &rd; // Pointer to rolodex.

    cout << "Listing rolodex:" << "\n\n";
    listCards(roloDex, cout);

    cout << "\n\n" << "Searching for Alonza Heard:" << "\n\n";
    searchForCard(roloDex, cout);

    cout << "\n\n" << "View current card:" << "\n\n";
    viewCard(roloDex, cout);

    cout << "\n\n" << "Flip to next card:" << "\n\n";
    flipCard(roloDex, cout);

    cout << "\n\n" << "Searching for Jon Smyth:" << "\n\n";
    searchForCard(roloDex, cout);

    cout << "\n\n" << "View current card:" << "\n\n";
    viewCard(roloDex, cout);

    cout << "\n\n" << "Removing current card:" << "\n\n";
    removeCard(roloDex, cout);

    cout << "\n\n" << "View current card:" << "\n\n";
    viewCard(roloDex, cout);

    cout << "\n\n" << "Adding Matthew Williams:" << "\n\n";
    addCard(roloDex);

    cout << "\n\n" << "View current card:" << "\n\n";
    viewCard(roloDex, cout);

    cout << "\n\n" << "Flip to next card:" << "\n\n";
    flipCard(roloDex, cout);

    cout << "\n\n" << "Removing current card:" << "\n\n";
    removeCard(roloDex, cout);

    cout << "\n\n" << "View current card:" << "\n\n";
    viewCard(roloDex, cout);

    cout << "\n\n" << "Adding Jim Butler:" << "\n\n";
    addCard(roloDex);

    cout << "\n\n" << "View current card:" << "\n\n";
    viewCard(roloDex, cout);

    cout << "\n\n" << "Searching for Jewel Proverb:" << "\n\n";
    searchForCard(roloDex, cout);

    cout << "\n\n" << "View current card:" << "\n\n";
    viewCard(roloDex, cout);

    cout << "\n\n" << "Removing current card:" << "\n\n";
    removeCard(roloDex, cout);

    cout << "\n\n" << "View current card:" << "\n\n";
    viewCard(roloDex, cout);

    cout << "\n\n" << "Adding second Jim Butler:" << "\n\n";
    addCard(roloDex);

    cout << "\n\n" << "Adding Dan Butler:" << "\n\n";
    addCard(roloDex);

    cout << "\n\n" << "Listing rolodex:" << "\n\n";
    listCards(roloDex, cout);

    quit();
}

void addCard(Rolodex * rd) // Adds a card to a rolodex. Queries user,
            // then creates and adds card with data.
{
    string fst, lst, job, add, pho;

    cout << "What is the person's first name?" << endl;
    cin >> fst;

    cout << "What is the person's last name?" << endl;
    cin >> lst;

    cout << "What is the person's job?" << endl;
    cin >> job;

    cout << "What is the person's address?" << endl;
    cin.ignore();
    getline(cin, add);  // Gets a full string line.

    cout << "What is the person's phone number? (xxx-xxxx)" << endl;
    cin >> pho;

    Card* newCard = new Card(fst, lst, job, add, pho); // Create new card with data.

    rd->add(newCard);   // Add card to rolodex.
}

void flipCard(Rolodex* roloDex, ostream& os) // Calls rolodex functions to flip to next card,
                        // make it current, then show card data.
{
    roloDex->flip().show(os);

}

void listCards(Rolodex* roloDex, ostream& os) // Calls the rolodex show function to
                        // list all cards in rolodex.
{
    roloDex->show(os);

}

void quit() // Exits program.
{
    exit(0);
}

void removeCard(Rolodex* roloDex, ostream& os) // Shows card, then queries user.
            // If user agrees, remove card.
{
    string confirm; // Takes user's answer.
    viewCard(roloDex, os); // Shows current card.
    os << "Remove this card? ( yes / no )" << "\n\n";
    cin >> confirm;
    if (confirm == "yes")
        roloDex->remove(); // Remove card.
    else
        os << "No changes made." << endl;
}

void searchForCard(Rolodex* roloDex, ostream& os) // Queries for target names
            // and calls Rolodex's search function, then shows card if available.
{
    string ln, fn;
    os << "Enter last name:" << endl;   // Queries for names...
    cin >> ln;
    os << "Enter first name:" << endl;
    cin >> fn;                          // ------------------ //

    if (roloDex->search(ln, fn))        // If found, view.
        viewCard(roloDex, os);
    else                                // Otherwise, notify.
        os << "Card not found." << endl;


}

void viewCard(Rolodex* roloDex, ostream& os) // Calls the current card's show function
                            // to display card info.
{
    roloDex->getCurrentCard().show(os);

}
