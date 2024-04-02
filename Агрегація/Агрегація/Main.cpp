#include "Shapes.h";

int main() {
   Shapes s;

    ifstream in("text.txt");
    if (!in.is_open()) {
        cout << "File not found!" << endl;
        return -1;
    }

    in >> s;

    in.close();

    Cylinder* c = new Cylinder(22, 3);

    ofstream out("text.txt", ios::app);
    if (!out.is_open()) {
        cout << "File not found!" << endl;
        return -1;
    }

    out << s << endl;

    s.add(0, c);
    out << "Container after add:\n" << s << endl;
    s.pop(1);
    out << "Container after remove:\n" << s << endl;

    s.deleteAll();
    out << s << endl;

    out.close();

    return 0;
}
