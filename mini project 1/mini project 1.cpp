#include <iostream>
#include <string>
#include "ctime"
#include <Windows.h>
using namespace std;
const int numberOfCards = 90;
const int maxExhibitionSize = 6;
struct Card {
    string type;
    int score;
    int cardSize = 0;
};

struct Player {
    string name;
    int score = 0;
    Card hand[3];
    Card namayeshgah[maxExhibitionSize];
    int exhibitionSize = 0;
};

void selectCard(Player player[], Card card[], int size) { // این تابع صرفا برای دادن سه کارت در ابتدای بازی است
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < 3; j++) {
            player[i].hand[j] = card[card->cardSize];
            card->cardSize++;
        }
    }
}

void addVaragh(Player* player, Card* card, int i, int choose) { // این تابع برای این است که وقتی کارتی بازی شد یه کارت جدید بیاد جاش
    player[i].hand[choose] = card[card->cardSize];
    card->cardSize++;
}

void defineCards(Card card[]) {
    for (int i = 0; i < 30; i++)
        card[i].type = "Kale_Kedoo";
    for (int j = 0; j < 6; j++)
        card[j].score = 1;
    for (int j = 6; j < 12; ++j)
        card[j].score = 9;
    for (int j = 12; j < 18; ++j)
        card[j].score = 11;
    for (int j = 18; j < 24; ++j)
        card[j].score = 15;
    for (int j = 24; j < 30; ++j)
        card[j].score = 4;

    for (int i = 30; i < 60; i++)
        card[i].type = "Kohne_Pich";
    for (int j = 30; j < 36; j++)
        card[j].score = 2;
    for (int j = 36; j < 42; ++j)
        card[j].score = 5;
    for (int j = 42; j < 48; ++j)
        card[j].score = 7;
    for (int j = 48; j < 54; ++j)
        card[j].score = 14;
    for (int j = 54; j < 60; ++j)
        card[j].score = 12;

    for (int i = 60; i < 90; i++)
        card[i].type = "Goor_be_Goor";
    for (int j = 60; j < 66; j++)
        card[j].score = 3;
    for (int j = 66; j < 72; ++j)
        card[j].score = 6;
    for (int j = 72; j < 78; ++j)
        card[j].score = 10;
    for (int j = 78; j < 84; ++j)
        card[j].score = 8;
    for (int j = 84; j < 90; ++j)
        card[j].score = 13;

    //حالا تابعی میخوام که کارت ها را بر بزنه
}

void Bor(Card card[]) // برای مخلوط کردن(بر زدن) ورق ها
{
    for (int i = 0; i < 90; i++) {
        int j = rand() % 90;
        swap(card[i], card[j]);
    }
}

void showCards(Player player[], int i) {
    cout << "Player " << player[i].name << "'s hand:" << endl;
    for (int j = 0; j < 3; ++j) {
        cout << "Card " << j + 1 << ": ";
        cout << "Type: " << player[i].hand[j].type << ", Score: " << player[i].hand[j].score << endl;
    }
}

void checkNamayeshgah(Player *player, int i) { //برسی اینکه اگر در نمایشگاه دو کارت شبیه بهم وجود داشت یکی شوند
    for (int j = 0; j < player[i].exhibitionSize; j++) {
        for (int k = j+1; k < player[i].exhibitionSize; k++) {
            if ((player[i].namayeshgah[j].type == player[i].namayeshgah[k].type) && (player[i].namayeshgah[j].score == player[i].namayeshgah[k].score)) {
                //player[i].namayeshgah[j] = player[i].namayeshgah[k];
                player[i].namayeshgah[k].type = "";
                player[i].namayeshgah[k].score = 0;
                for (int y = 1; y < player[i].exhibitionSize-1; y++) {
                    if ((player[i].namayeshgah[y].type == "") && (player[i].namayeshgah[y].score == 0)) {
                        swap(player[i].namayeshgah[y], player[i].namayeshgah[y+1]);
                    }
                }
                player[i].exhibitionSize--;
            }
        }
    }
}

bool checkNamayeshgahChooseOwn(Player player[], int i, int choose, int num) {
    // اون انتخابی که کردی ببیند انتخاب درستی بوده یا چی
    if (player[i].namayeshgah[num - 1].type == "Kale_Kedoo" || player[i].namayeshgah[num - 1].type == "Kohne_Pich" || player[i].namayeshgah[num - 1].type == "Goor_be_Goor"){
        if (player[i].hand[choose].type != player[i].namayeshgah[num - 1].type) {
            return false;
        }
    }
    return true;
}

bool checkNamayeshgahChooseOther(Player player[], int i,int j, int choose, int num) {
    // اون انتخابی که کردی ببیند انتخاب درستی بوده یا چی
    if (player[j].namayeshgah[num - 1].type == "Kale_Kedoo" || player[j].namayeshgah[num - 1].type == "Kohne_Pich" || player[j].namayeshgah[num - 1].type == "Goor_be_Goor") {
        if (player[i].hand[choose].type != player[j].namayeshgah[num - 1].type) {
            return false;
        }
    }
    return true;
}

void addToExhibitionToOwn(Player player[], int choose, int i) {
    int num;
    cout << "Enter the location of the card : ";
    cin >> num;
    bool b3 = checkNamayeshgahChooseOwn(player, i, choose, num);
    if (!b3) {
        cout << "Each card can only be on the same card!\nFind the right place.\n";
        addToExhibitionToOwn(player, choose, i);
    }
    else{
        if (player[i].exhibitionSize < num)
            player[i].exhibitionSize++;
        player[i].namayeshgah[num - 1] = player[i].hand[choose];
    }
    checkNamayeshgah(player, i);

}

void addToExhibitionToOther(Player* player, int choose, int i, int size, string strName) {
    for (int j = 0; j < size; j++) {
        if (strName == player[j].name) {
            cout << "Enter the location of the card : ";
            int num;
            cin >> num;
            bool b3 = checkNamayeshgahChooseOther(player,i, j, choose, num);
            if (!b3) {
                cout << "Each card can only be on the same card!\nFind the right place.\n";
                addToExhibitionToOther(player, choose, i, size, strName);
            }
            else{
                //player[i].hand[choose] = player[j].hand[num];
                if (player[j].exhibitionSize < num)
                    player[j].exhibitionSize++;
                player[j].namayeshgah[num - 1] = player[i].hand[choose];
                checkNamayeshgah(player, j);
            }
        }
        else continue;
    }
}

bool namayeshgah(Player player[], int size) {
    for (int i = 0; i < size; i++) {
        if (player[i].exhibitionSize >= maxExhibitionSize)
            return false;
    }
    return true;
}

void showNamayeshgah(Player* player, int size) {
    for (int i = 0; i < size; ++i) {
        cout << "Player " << player[i].name << "'s Namayeshgah:" << endl;
        for (int j = 0; j < player[i].exhibitionSize; ++j) {
            cout << "the type : " << player[i].namayeshgah[j].type << "\t  the score : " << player[i].namayeshgah[j].score << endl;
        }
        cout << endl;
    }
}

bool checkEmtiaz(Player player[], int j) {
    int x = 0, y = 0, z = 0;
    for (int i = 0; i < player[j].exhibitionSize; i++) {
        if (player[j].namayeshgah[i].type == "Kale_Kedoo")
            x += 1;
        if (player[j].namayeshgah[i].type == "Goor_be_Goor")
            y += 1;
        if (player[j].namayeshgah[i].type == "Kohne_Pich")
            z += 1;
    }
    if (x >= 1 && y >= 1 && z >= 1) {
        return true;
    }
    return false;

}

void Emtiaz(Player* player, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < player[i].exhibitionSize; ++j) {
            player[i].score += player[i].namayeshgah[j].score;
        }

        bool b4 = checkEmtiaz(player, i);
        if (!b4) {     // یه تابع میخوایم که اگر هر بازیکن از سه نوع کارت رو نداشت امتیازش رو صفر کنه
            for (int k = 0; k < player[i].exhibitionSize; k++) {
                player[i].score -= player[i].namayeshgah[k].score;
            }
        }
    }     
}

void playCard(Player player[], int size, Card card[]) {
    for (int i = 0; i < size; ++i) {
        cout << "Player turn " << i + 1 << ", choose one of them." << endl;
        showCards(player, i);
        int choose;
        cin >> choose;
        // اینجا یه چیزی بنویس که بیاد اون کارت های قبلی رو از ترمینال پاک کنه
        
        //showNamayeshgah(player, size);

        cout << "Do you want to put your card in your exhibition?(Y/N) : ";
        string str;
        cin >> str;
        switch (choose) {
        case 1: {
            if (str == "Y") {
                addToExhibitionToOwn(player, choose - 1, i);
            }
            else if (str == "N") {
                cout << "Exhibition of which player?";
                string strName;
                cin >> strName;
                addToExhibitionToOther(player, choose - 1, i, size, strName);
            }
            break;
        }
        case 2: {
            if (str == "Y") {
                addToExhibitionToOwn(player, choose - 1, i);
            }
            else if (str == "N") {
                cout << "Exhibition of which player?";
                string strName;
                cin >> strName;
                addToExhibitionToOther(player, choose - 1, i, size,strName);
            }
            break;
        }
        case 3: {
            if (str == "Y") {
                addToExhibitionToOwn(player, choose - 1, i);
            }
            else if (str == "N") {
                cout << "Exhibition of which player?";
                string strName;
                cin >> strName;
                addToExhibitionToOther(player, choose - 1, i, size, strName);
            }
            break;
        }
        }
        addVaragh(player, card, i, choose - 1);
        cout << endl;
        cout << "-----------------------------------------------------------------------------------------------------------------------\n\n";
        showNamayeshgah(player, size);
        cout << endl;
        bool b2 = namayeshgah(player, size);
        if (!b2) {
            Emtiaz(player, size);
            break;
        }
    }
}

void zeroEmtiaz(Player* player, int size) {
    for (int i = 0; i < size; ++i) {
        player[i].score = 0;
    }
}

void bubble_sort(Player* player, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (player[j].score < player[j + 1].score)
            {
                swap(player[j], player[j + 1]);
            }
        }
    }
}

int main() {
    srand(time(NULL));
    //cout << rand() %100;
    Card card[numberOfCards];
    int number;
    cout << "Enter the number of players: ";
    cin >> number;
    Player *player = new Player [number];
    //cout << "Enter each player's name: " << endl;
    for (int i = 0; i < number; i++) {
        cout << "Enter the name of player " << i + 1 << ": ";
        cin >> player[i].name;
    }
    int MAX_SCORE;
    //system("color 0A");
    
    cout << "Enter the maximum player score: ";
    cin >> MAX_SCORE;
    //تعریف کردن کارت ها. اینکه چه نوعی با چه امتیازی
    defineCards(card);
    Bor(card);
    //الان باید ب صورت رندم به هر بازیکن سه تا کارت بدی
    selectCard(player, card, number);
    bool b = true;
    int j = 0;
    while (b) {
        playCard(player, number, card);
        for (j = 0; j < number; ++j) {
            if (player[j].score >= MAX_SCORE)
            {
                b = false;
                break;
            }
        }
        if (!b)
            break;
        bool b2 = namayeshgah(player, number);
        if (!b2)
        {
            cout << "-------------------------------------------------------------------------------------\n";
            cout << "The game max score is " << MAX_SCORE << endl;
            for (int i = 0; i < number; i++)
            {
                cout << player[i].name << ":\tscore : " << player[i].score << endl;
                
                for (int j = 0; j < player[i].exhibitionSize; j++)
                {
                    player[i].namayeshgah[j].type = "";
                    player[i].namayeshgah[j].score= 0;
                }
                player[i].exhibitionSize = 0;
                
            }
            cout << "game restart.\n\n";
            
            defineCards(card);
            Bor(card);
            card->cardSize = 0;
            selectCard(player, card, number);
            //zeroEmtiaz(player, number);
        }
    }
    //cout << "the winner is : " << player[j].name<< ". score : "<< player[j].score << endl;
    for (int i = 0; i < number; ++i) {
        bubble_sort(player, number);
        if (i == 0)
            cout << "the winner is : " << player[i].name << ":\tscore : " << player[i].score << endl;

        cout << "Rank " << i + 1 << " is : " << player[i].name << ":\t score : " << player[i].score << endl;
    }
    return 0;
}