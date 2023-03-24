#pragma once

#include <iostream>

#include <algorithm>

#include "Plenty.h"

using namespace std;

class Plenty {

    int max_elem = 5;
    int* data;
    int quantity_data = 0;

public:
    Plenty();

    Plenty(int max);
    ~Plenty();

    int* get_data();

    void add_elem(int elem);

    void find_elem(int key);

    void initialization_plenty(int* plenty_1, int* plenty_2, int minimum_size_plenty = 10);


    friend ostream& operator<< (ostream& out, const Plenty& plenty)
    {
        string conclusion = "";
        for (int i = 0; i < plenty.max_elem; i++)
            out << plenty.data[i] << " ";
        return out;
    }

    friend istream& operator>> (istream& in, Plenty& plenty)
    {

        for (int i = 0; i < plenty.max_elem; i++)
            in >> plenty.data[i];
        return in;
    }
    Plenty(const Plenty& other);

    Plenty& operator=(Plenty const& other);

    Plenty operator+(const Plenty& other);

    Plenty operator*(const Plenty& other);

    Plenty operator-(const Plenty& other);

    Plenty operator+(const int other);

    Plenty& operator+= (Plenty const& other);

    Plenty& operator*= (Plenty const& other);
    Plenty& operator-=(const Plenty& other);
    bool operator== (Plenty const& other);

    bool operator!= (Plenty const& other);
};