Card Game Simulation
This project is a C++ simulation of a card-based game where players compete to achieve the highest score through strategic card selection and exhibition building. Each player is dealt three cards per round, aiming to arrange specific combinations to maximize their score. The game runs in a console environment.

Features:
Player Management: Allows multiple players to join the game, each with a unique name.
Card Management: Deck consists of cards with different types and scores.
Score Tracking: Each player’s score is tracked, with additional rules for exhibition combinations.
Card Shuffling: The deck is shuffled at the start for random card distribution.
Game Restart: Automatically restarts when all players reach or exceed the target score.


How to Play:
Player Setup: Enter the number of players and assign names.
Card Drawing: Each player starts with three random cards.
Round Actions:
Choose cards to play and add them to your exhibition.
Achieve combinations to maximize score.
Winning Condition: The first player to reach the maximum score wins. Scores are then displayed with player ranks.

Code Structure:
Player and Card Structures: Define player and card attributes.
Gameplay Functions:
selectCard(): Draws three cards per player at game start.
addVaragh(): Replaces a card in hand when one is played.
defineCards(): Initializes the deck with card types and scores.
Bor(): Shuffles the deck.
playCard(): Handles each player’s turn.
bubble_sort(): Sorts players by score.

Requirements:
C++ compiler supporting ctime and Windows.h
Windows OS (for system("color 0A"))
