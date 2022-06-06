// Huffman.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <stdlib.h>
#include <iostream>
#include <string>
#include <istream>
#include <map>
#include <bitset>

using namespace std;


struct Node {
    char data;
    int weight;
    struct Node* left;
    struct Node* right;
    struct Node* parent;

    Node(char val, int wei) {
        data = val;
        weight = wei;
        left = NULL;
        right = NULL;
        parent = NULL;
    }
    Node() {
        data = NULL;
        weight = 0;
        left = NULL;
        right = NULL;
        parent = NULL;
    }
};

string reverse(string pText) {
    string result = "";
    for (int i = pText.length() - 1; i >= 0; i--) {
        result += pText[i];
    }
    return result;
}
string cutZeros(string pText) {
    string result = "";
    int i = 0;
    while (pText[i] == '0') {
        i++;
    }
    while (i < pText.length()) {
        result += pText[i];
        i++;
    }
    return result;
}
string cutZeros(string pText, bool keep) {
    string result = "";
    int i = 0;
    while (pText[i] == '0' && i < pText.length() - 1) {
        i++;
    }
    while (i < pText.length()) {
        result += pText[i];
        i++;
    }
    return result;
}
string cutTo(string pText, int pLength) {
    string result = "";
    int i = 0;
    while (i < pText.length() - pLength) {
        i++;
    }
    while (i < pText.length()) {
        result += pText[i];
        i++;
    }
    return result;
}
int binToDec(string bin) {
    int result = 0;
    for (int i = 0; i < bin.length(); i++) {
        if (bin[i] == '1') {
            result += pow(2, bin.length() - 1 - i);
        }
    }
    return result;
}

int main()
{
    cout << " _   _        __  __ \n";
    cout << "| | | |      / _|/ _|\n";
    cout << "| |_| |_   _| |_| |_ _ __ ___   __ _ _ __ ______\n";
    cout << "|  _  | | | |  _|  _| '_ ` _ \\ / _` | '_ \\______\n";
    cout << "| | | | |_| | | | | | | | | | | (_| | | | |\n";
    cout << "\\_| |_/\\__,_|_| |_| |_| |_| |_|\\__,_|_| |_|\n";
    cout << "\n";
    cout << "  _______            __  _  __                          _           _\n";
    cout << " / /  __ \\           \\ \\| |/ /                         (_)         (_)\n";
    cout << "| || |  | | ___ ______| | ' / ___  _ __ ___  _ __  _ __ _ _ __ ___  _  ___ _ __ ___ _ __ \n";
    cout << "| || |  | |/ _ \\______| |  < / _ \\| '_ ` _ \\| '_ \\| '__| | '_ ` _ \\| |/ _ \\ '__/ _ \\ '__|\n";
    cout << "| || |__| |  __/      | | . \\ (_) | | | | | | |_) | |  | | | | | | | |  __/ | |  __/ |\n";
    cout << "| ||_____/ \\___|      | |_|\\_\\___/|_| |_| |_| .__/|_|  |_|_| |_| |_|_|\\___|_|  \\___|_|\n";
    cout << " \\_\\                 /_/                    | |\n";
    cout << "                                            |_|\n";
    cout << "\n";
    cout << "   _______ _        __  __             __  __       _ _ _           __\n";
    cout << "  / / ____| |      / _|/ _|           |  \\/  |     | (_) |          \\ \\\n";
    cout << " | | (___ | |_ ___| |_| |_ ___ _ __   | \\  / | ___ | |_| |_ ___  _ __| |\n";
    cout << " | |\\___ \\| __/ _ \\  _|  _/ _ \\ '_ \\  | |\\/| |/ _ \\| | | __/ _ \\| '__| |\n";
    cout << " | |____) | ||  __/ | | ||  __/ | | | | |  | | (_) | | | || (_) | |  | |\n";
    cout << " | |_____/ \\__\\___|_| |_| \\___|_| |_| |_|  |_|\\___/|_|_|\\__\\___/|_|  | |\n";
    cout << "  \\_\\                                                               /_/\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    string kd;
    string text;
    struct Node* root = new Node();
    do {
        cout << "Komprimieren, dekomprimieren, oder Fenster schließen? k/d/e\n";
        getline(cin, kd);
        if (kd == "k") {
            cout << "Zu komprimierender Text: ";
            getline(cin, text);
            map<int, Node*> charMap;
            for (string::size_type i = 0; i < text.size(); i++) {
                int found = charMap.size();
                for (string::size_type j = 0; j < charMap.size(); j++) {
                    if (charMap[j]->data == (char) text.at(i)) {
                        found = j;
                    }
                }
                if (found == charMap.size()) {
                    charMap[found] = new Node(text.at(i),1);
                }
                else {
                    charMap[found]->weight = charMap[found]->weight + 1;
                }
            }
            const int chars = charMap.size();
            bool flag = true;
            int zo = 1;
            struct Node* topNode = new Node();;
            int lowest;
            int parentless;
            if (chars > 2) {
                while (flag) {
                    flag = false;
                    lowest = -1;
                    parentless = 0;
                    for (string::size_type i = 0; i < charMap.size(); i++) {
                        if (charMap[i]->parent == NULL) {
                            if (lowest == -1 || charMap[i]->weight < charMap[lowest]->weight) {
                                lowest = i;
                            }
                            parentless++;
                        }
                    }
                    if (zo == 1) {
                        zo = 0;
                        topNode = new Node();
                    }
                    else {
                        zo = 1;
                    }
                    if (zo == 0) {
                        topNode->left = charMap[lowest];
                        topNode->weight += charMap[lowest]->weight;
                        charMap[lowest]->parent = topNode;
                        parentless--;
                    }
                    else {
                        topNode->right = charMap[lowest];
                        topNode->weight += charMap[lowest]->weight;
                        charMap[lowest]->parent = topNode;
                        charMap[charMap.size()] = topNode;
                    }
                    /*for (string::size_type i = 0; i < charMap.size(); i++) {
                        cout << i << ": " << charMap[i]->data << "(" << charMap[i]->weight << ") - " << charMap[i]->parent << endl;
                    }
                    cout << "---" << endl;*/
                    if (parentless > 2 || parentless == 2 && zo == 0) {
                        flag = true;
                    }
                }
            }
            zo = 0;
            for (string::size_type i = 0; i < charMap.size(); i++) {
                if (charMap[i] != NULL && charMap[i]->parent == NULL) {
                    if (zo == 0) {
                        root->left = charMap[i];
                        charMap[i]->parent = root;
                        zo = 1;
                    }
                    else {
                        root->right = charMap[i];
                        charMap[i]->parent = root;
                    }
                }
            }
            /*for (string::size_type i = 0; i < charMap.size(); i++) {
                cout << i << ": " << charMap[i]->data << "(" << charMap[i]->weight << ") - " << charMap[i]->parent << endl;
            }*/

            map<int, string[2]> codes;
            map<char, string> codetable;
            string code;
            int longest = 0;
            for (int i = 0; i < chars; i++) {
                codes[i][0] = charMap[i]->data;
                code = "";
                struct Node* temp = charMap[i];
                struct Node* parent;
                while (temp->parent != NULL || temp->parent == root) {
                    parent = temp->parent;
                    if (parent->left == temp) {
                        code += "0";
                    }
                    else {
                        code += "1";
                    }
                    temp = parent;
                }
                code = reverse(code);
                codes[i][1] = code;
                codetable[charMap[i]->data] = code;
                if (code.length() > longest) {
                    longest = code.length();
                }
                //cout << charMap[i]->data << ": " << code << endl;
            }
            string header;
            string binlongest = bitset<8>(longest).to_string();
            binlongest = cutZeros(binlongest);
            for (int i = 1; i < binlongest.length(); i++) {
                header += "0";
            }
            header += "1";
            
            for (string::size_type i = 0; i < codes.size(); i++) {
                header += cutTo(bitset<8>(codes[i][1].length()).to_string(), binlongest.length());
                header += codes[i][1];
                header += bitset<8>((int)codes[i][0][0]).to_string();
            }
            for (int i = 0; i < binlongest.length(); i++) {
                header += "0";
            }

            /*cout << "0/1 zum Navigieren zum Beenden e \n";
            string testin;
            struct Node* current = root;
            while (testin != "e") {
                getline(cin, testin);
                if (testin == "0" || testin == "1") {
                    if (testin == "0" && current->left != NULL) {
                        current = current->left;
                    }
                    else if(current->right != NULL) {
                        current = current->right;
                    }
                    else {
                        current = NULL;
                    }
                    if (current == NULL) {
                        cout << "NULL - nicht erlaubt - Zurück zu den Wurzeln! :)" << endl;
                        current = root;
                    }
                    else if (current->data == NULL) {
                        cout << "NODE (" << current->weight << ")" << endl;
                    }
                    else {
                        cout << current->data << " (" << current->weight << ")" << endl;
                        current = root;
                    }
                }
            }*/
            string finaltext = "";
            for (int i = 0; i < text.length(); i++) {
                finaltext += codetable[text.at(i)];
            }

            cout << "Komprimierter Text: " << header << finaltext << "\n\n" << endl;
        }
        else if (kd == "d") {
            cout << "Zu dekomprimierender Text: ";
            getline(cin, text);
            int lenlen = 0;
            int i = 0;
            while (text[i] == '0') {
                i++;
            }
            lenlen = i + 1;
            string zeroEnd = "";
            for (int j = 0; j < lenlen; j++) {
                zeroEnd += "0";
            }
            bool flag = true;
            string codelen = "";
            string code = "";
            map<string, char> chartable;
            while (flag) {
                code = "";
                codelen = "";
                for (int j = 0; j < lenlen; j++) {
                    i++;
                    codelen += text[i];
                }
                if(codelen != zeroEnd) {
                    for (int j = 0; j < binToDec(codelen); j++) {
                        i++;
                        code += text[i];
                    }
                    string charNum = "";
                    for (int j = 0; j < 8; j++) {
                        i++;
                        charNum += text[i];
                    }
                    chartable[code] = binToDec(charNum);
                }
                else {
                    flag = false;
                }
            }
            i++;
            string dektext = "";
            code = "";
            for (int j = i; j < text.length(); j++) {
                code += text[j];
                if (chartable[code] != NULL) {
                    dektext += chartable[code];
                    code = "";
                }
            }
            cout << "Dekomprimierter Text: " << dektext << "\n\n" << endl;
        }
        else if (kd != "e") {
            cout << "\n\n###Falsche Eingabe, bitte erneut eingeben!###\n\n";
            kd;
        }
    } while (kd != "e");
};

// Programm ausführen: STRG+F5 oder Menüeintrag "Debuggen" > "Starten ohne Debuggen starten"
// Programm debuggen: F5 oder "Debuggen" > Menü "Debuggen starten"

// Tipps für den Einstieg: 
//   1. Verwenden Sie das Projektmappen-Explorer-Fenster zum Hinzufügen/Verwalten von Dateien.
//   2. Verwenden Sie das Team Explorer-Fenster zum Herstellen einer Verbindung mit der Quellcodeverwaltung.
//   3. Verwenden Sie das Ausgabefenster, um die Buildausgabe und andere Nachrichten anzuzeigen.
//   4. Verwenden Sie das Fenster "Fehlerliste", um Fehler anzuzeigen.
//   5. Wechseln Sie zu "Projekt" > "Neues Element hinzufügen", um neue Codedateien zu erstellen, bzw. zu "Projekt" > "Vorhandenes Element hinzufügen", um dem Projekt vorhandene Codedateien hinzuzufügen.
//   6. Um dieses Projekt später erneut zu öffnen, wechseln Sie zu "Datei" > "Öffnen" > "Projekt", und wählen Sie die SLN-Datei aus.
