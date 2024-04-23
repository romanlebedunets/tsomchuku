#include "Shapes.h";

void printVolume(volumeShape* shape) {
    cout << "Volume of the shape: " << shape->volume() << endl;
}

bool checkSurfaceArea(volumeShape* shape) {
    return shape->surfaceArea() > 1000;
}

int main() {
    Shapes s;

    ifstream in("text.txt");
    if (!in.is_open()) {
        cout << "File not found!" << endl;
        return -1;
    }

    in >> s;

    in.close();

    ofstream out("text.txt", ios::app);
    if (!out.is_open()) {
        cout << "File not found!" << endl;
        return -1;
    }

    s.doEach(printVolume);
    int i = s.detectFirst(checkSurfaceArea);
    cout << "Shape with surface area > 1000:\n" << s[i] << endl;

    out << "\nContainer:\n" << s << endl;

    Cylinder* c = new Cylinder(22, 3);
    s.add(0, c);
    out << "Container after add:\n" << s << endl;

    s.pop(2);
    out << "Container after pop:\n" << s << endl;

    s.deleteAll();
    out << s << endl;

    out << s[10] << endl;

    out.close();

    return 0;
}
