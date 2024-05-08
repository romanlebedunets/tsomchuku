#pragma once
#include "Art.h"

template <typename typeCost, template <typename> class typeCont>
class ContArt {
private:
    int size;
    deque<typeCont<typeCost>> objects;
public:
    ContArt() : size(0) {}
    ContArt(int s) : size(s) {
        objects.resize(size);
    }
    ContArt(const ContArt<typeCost, typeCont>& C) : size(C.size), objects(C.objects) {}

    deque<string> countGenre() const {
        deque<string> g;
        g.push_back(objects[0].getGenre());
        for (int i = 1; i < size; i++) {
            for (int j = 0; j < g.size(); j++) {
                if (objects[i].getGenre() != g[j]) g.push_back(objects[i].getGenre());
            }
        }

        return g;
    }

    typeCont<typeCost> min() const {
        if (size == 0) exit(-2);

        typeCont<typeCost> temp = objects[0];
        for (int i = 1; i < size; i++) {
            if (temp > objects[i]) temp = objects[i];
        }

        return temp;
    }

    int countOb() const {
        int temp = 0;
        for (int i = 0; i < size; i++) {
            temp += objects[i].getCount();
        }

        return temp;
    }

    friend istream& operator>>(istream& is, ContArt& C) {
        is >> C.size;
        typeCont<typeCost> temp;
        for (int i = 0; i < C.size; i++) {
            is >> temp;
            C.objects.push_back(temp);
        }

        return is;
    }

    friend ostream& operator<<(ostream& os, const ContArt& C) {
        for (int i = 0; i < C.size; i++) {
            os << C.objects[i];
        }

        return os;
    }
};
