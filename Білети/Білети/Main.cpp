#include "Conteiner.h"

int main() {
    ContArt<int, UniqueArt> a;
    ifstream in("text.txt");
    if (!in.is_open())
    {
        cout << "Error open file!" << endl;
        return -1;
    }

    in >> a;
    in.close();

    ofstream out("text.txt", ios::app);
    if (!out.is_open())
    {
        cout << "Error open file!" << endl;
        return -1;
    }

    out << a;

    out << "\nCheapest art:\n" << a.min() << "\nCount of predmets: " << a.countOb() << endl;

    deque<string> genres = a.countGenre();
    out << "\nNon repeated genres: ";
    for (auto i = genres.begin(); i < genres.end(); i++) {
        out << *i << "\t";
    }

    out.close();

    return 0;
}
