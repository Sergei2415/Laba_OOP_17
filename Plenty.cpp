#include "Plenty.h"

Plenty::Plenty() {
    data = new int[max_elem];
}
Plenty::Plenty(int max)
{
    max_elem = max;
    data = new int[max_elem];
}
Plenty::~Plenty()
{
    delete[] data;
}
int* Plenty::get_data()
{
    return data;
}
void Plenty::add_elem(int elem)
{
    data[quantity_data] = elem;
    quantity_data++;
}
void Plenty::find_elem(int key)
{
    sort(data, data + max_elem);
    int l = 0;
    int r = max_elem;
    int mid;
    while (l < r) {
        mid = (l + r) / 2;

        if (data[mid] > key)
            r = mid;
        else
            l = mid + 1;
    }
    r--;
    if (data[r] == key)
        cout << "Элемент со значением " << key << " находится в массиве под индексом " << r << " после сортировки." << endl;
    else
        cout << "Извините, но такого элемента в массиве нет." << endl;
}
void Plenty::initialization_plenty(int* plenty_1, int* plenty_2, int minimum_size_plenty)
{
    for (int i = 0; i < minimum_size_plenty; i++) {
        plenty_1[i] = plenty_2[i];
    }
}
 Plenty::Plenty(const Plenty& other)
 {
     delete[] data;
     data = new int[other.max_elem];
     for (int i = 0; i < other.max_elem; i++)
         data[i] = other.data[i];
     max_elem = other.max_elem;
     quantity_data = other.quantity_data;

 }
 Plenty& Plenty::operator=(Plenty const& other)
 {
     delete[] this->data;
     this->data = new int[other.max_elem];
     for (int i = 0; i < other.max_elem; i++)
         this->data[i] = other.data[i];
     this->max_elem = other.max_elem;
     this->quantity_data = other.quantity_data;
     return *this;
 }
 Plenty Plenty::operator+(const Plenty& other) {
     int* mas = new int[other.max_elem + this->max_elem];
     int index = 0;
     bool fl = true;
     for (int i = 0; i < other.max_elem; i++) {
         fl = true;
         for (int j = 0; j < i; j++) {
             if (other.data[i] == other.data[j])
                 fl = false;
         }
         if (fl) {
             mas[index] = other.data[i];
             index++;
         }
     }
     for (int i = 0; i < this->max_elem; i++) {
         fl = true;
         for (int j = 0; j < other.max_elem; j++) {
             if (other.data[j] == this->data[i]) {
                 fl = false;
                 break;
             }
         }
         for (int j = 0; j < i; j++) {
             if (this->data[i] == this->data[j])
                 fl = false;
         }
         if (fl) {
             mas[index] = this->data[i];
             index++;
         }
     }
     Plenty pl(index);
     for (int i = 0; i < index; i++)
         pl.data[i] = mas[i];
     return pl;
 }

 Plenty Plenty::operator*(const Plenty& other) {
     int* mas = new int[other.max_elem + this->max_elem];
     int index = 0;
     bool fl = true;
     for (int i = 0; i < other.max_elem; i++) {
         fl = false;
         for (int j = 0; j < this->max_elem; j++) {
             if (other.data[i] == this->data[j])
                 fl = true;
         }
         for (int j = 0; j < i; j++) {
             if (other.data[i] == other.data[j])
                 fl = false;
         }
         if (fl) {
             mas[index] = other.data[i];
             index++;
         }
     }

     Plenty pl(index);
     for (int i = 0; i < index; i++)
         pl.data[i] = mas[i];
     return pl;
 }
 Plenty Plenty::operator-(const Plenty& other) {
     int* mas = new int[other.max_elem + this->max_elem];
     int index = 0;
     bool fl = true;
     for (int i = 0; i < this->max_elem; i++) {
         fl = true;
         for (int j = 0; j < other.max_elem; j++) {
             if (this->data[i] == other.data[j])
                 fl = false;
         }
         for (int j = 0; j < i; j++) {
             if (this->data[i] == this->data[j])
                 fl = false;
         }
         if (fl) {
             mas[index] = this->data[i];
             index++;
         }
     }

     Plenty pl(index);
     for (int i = 0; i < index; i++)
         pl.data[i] = mas[i];
     return pl;
 }

 Plenty Plenty::operator+(const int other) {
     Plenty pl(this->max_elem + 1);
     for (int i = 0; i < this->max_elem; i++)
         pl.data[i] = this->data[i];
     pl.data[this->max_elem] = other;
     return pl;
 }

 Plenty& Plenty::operator+= (Plenty const& other) {
     int* mas = new int[other.max_elem + this->max_elem];
     int index = 0;
     bool fl = true;
     for (int i = 0; i < other.max_elem; i++) {
         fl = true;
         for (int j = 0; j < i; j++) {
             if (other.data[i] == other.data[j])
                 fl = false;
         }
         if (fl) {
             mas[index] = other.data[i];
             index++;
         }
     }
     for (int i = 0; i < this->max_elem; i++) {
         fl = true;
         for (int j = 0; j < other.max_elem; j++) {
             if (other.data[j] == this->data[i]) {
                 fl = false;
                 break;
             }
         }
         for (int j = 0; j < i; j++) {
             if (this->data[i] == this->data[j])
                 fl = false;
         }
         if (fl) {
             mas[index] = this->data[i];
             index++;
         }
     }
     delete[] this->data;
     this->data = new int[index];
     for (int i = 0; i < index; i++)
         this->data[i] = mas[i];
     this->max_elem = index;
     this->quantity_data = index;
     return *this;
 }

 Plenty& Plenty::operator*= (Plenty const& other) {
     int* mas = new int[other.max_elem + this->max_elem];
     int index = 0;
     bool fl = true;
     for (int i = 0; i < other.max_elem; i++) {
         fl = false;
         for (int j = 0; j < this->max_elem; j++) {
             if (other.data[i] == this->data[j])
                 fl = true;
         }
         for (int j = 0; j < i; j++) {
             if (other.data[i] == other.data[j])
                 fl = false;
         }
         if (fl) {
             mas[index] = other.data[i];
             index++;
         }
     }

     delete[] this->data;
     this->data = new int[index];
     for (int i = 0; i < index; i++)
         this->data[i] = mas[i];
     this->max_elem = index;
     this->quantity_data = index;
     return *this;
 }
 Plenty& Plenty::operator-=(const Plenty& other) {
     int* mas = new int[other.max_elem + this->max_elem];
     int index = 0;
     bool fl = true;
     for (int i = 0; i < this->max_elem; i++) {
         fl = true;
         for (int j = 0; j < other.max_elem; j++) {
             if (this->data[i] == other.data[j])
                 fl = false;
         }
         for (int j = 0; j < i; j++) {
             if (this->data[i] == this->data[j])
                 fl = false;
         }
         if (fl) {
             mas[index] = this->data[i];
             index++;
         }
     }

     delete[] this->data;
     this->data = new int[index];
     for (int i = 0; i < index; i++)
         this->data[i] = mas[i];
     this->max_elem = index;
     this->quantity_data = index;
     return *this;
 }
 bool Plenty::operator== (Plenty const& other) {
     if (this->max_elem == other.max_elem) {
         for (int i = 0; i < other.max_elem; i++)
             if (other.data[i] != this->data[i])
                 return false;
         return true;
     }
     else
         return false;
 }

 bool Plenty::operator!= (Plenty const& other) {
     if (this->max_elem == other.max_elem) {
         for (int i = 0; i < other.max_elem; i++)
             if (other.data[i] != this->data[i])
                 return true;
         return false;
     }
     else
         return true;
 }
