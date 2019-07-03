#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <iostream>

void addCard(Rolodex * rd); // Calls rolodex's add function.
void flipCard(Rolodex* roloDex, std::ostream& os); // Calls rolodex's flip function,
                            // then the card's show function.
void listCards(Rolodex* roloDex, std::ostream& os); // Calls rolodex's show function.
void quit();                // Exits program.
void removeCard(Rolodex* roloDex, std::ostream& os); // Calls rolodex's remove function.
void searchForCard(Rolodex* roloDex, std::ostream& os); // Calls rolodex's search function.
void viewCard(Rolodex* roloDex, std::ostream& os); // Calls rolodex's function for
                            // calling the current card.

#endif // MAIN_H_INCLUDED
