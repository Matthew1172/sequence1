#include <iostream>
#include "sequence1.h"

int main()
{
    std::cout << "Hello World!\n";
}

weimin_csc212::sequence1::sequence1()
{
    this->current_index = 0;
    *this->data = {};
    this->used = 0;
}

void weimin_csc212::sequence1::start()
{
    if (this->current_index != 0) this->current_index = this->data[0];
}

void weimin_csc212::sequence1::advance()
{
    if (this->current_index != this->used) {
        this->data[this->current_index];
    }
}

void weimin_csc212::sequence1::insert(const value_type& entry)
{
}

void weimin_csc212::sequence1::attach(const value_type& entry)
{
}

void weimin_csc212::sequence1::remove_current()
{
}

weimin_csc212::sequence1::size_type weimin_csc212::sequence1::size() const
{
    return size_type();
}

bool weimin_csc212::sequence1::is_item() const
{
    return false;
}

weimin_csc212::sequence1::value_type weimin_csc212::sequence1::current() const
{
    return value_type();
}


