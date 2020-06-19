#include <iostream>
#include "sequence1.h"
#include <cstdlib>    // Provides size_t.
using namespace std;
using namespace weimin_csc212;

sequence1::sequence1()
{
	this->current_index = 0;
	*this->data = {};
	this->used = 0;
}

void sequence1::start()
{
	this->current_index = 0;
}

void sequence1::advance()
{
	try
	{
		if(is_item()){
			this->current_index++;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void sequence1::insert(const value_type& entry)
{
	if(this->used < 1){
		this->data[this->current_index] = entry;
		this->current_index = 0;
	}else{
		if(!is_item()){
			this->current_index = 0;
		}
		for(size_type i = this->used; i > this->current_index; i--){
			this->data[i] = this->data[i - 1];
		}
		this->data[this->current_index] = entry;
	}
	addOneToSize();
}

void sequence1::attach(const value_type& entry)
{
	if(this->used < 1){
		this->data[this->current_index] = entry;
		this->current_index = 0;
	}else{
		if(!is_item()){
			this->current_index = this->used - 1;
		}
		if(this->used - 1 == this->current_index){
			this->data[this->used] = entry;
			this->current_index = this->used;
		}else{
			for(size_type i = this->used; i > this->current_index+1; i--){
				this->data[i] = this->data[i - 1];
			}
			this->data[this->current_index+1] = entry;
			this->current_index = this->current_index+1;
		}
	}
	addOneToSize();
}

void sequence1::remove_current()
{
	this->data[current_index] = 0;
	if (this->current_index != this->used-1) {
		for(size_type i = this->current_index; i < this->used-1; i++){
			this->data[i] = this->data[i + 1];

		}
	}
	this->used--;
}

sequence1::size_type sequence1::size() const
{
	return this->used;
}

bool sequence1::is_item() const
{
	if (this->current_index < this->used) return true;
	else return false;
}

sequence1::value_type sequence1::current() const
{
	return this->data[this->current_index];
}