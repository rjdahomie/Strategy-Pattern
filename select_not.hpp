#ifndef __SELECTNOT_HPP__
#define __SELECTNOT_HPP__

#include "select.hpp"

using namespace std;

class Select_Not: public Select
{
    public:
	Select* s;

    private:
	Select_Not(Select *s)
	{

	}

	~Select_Not()
	{

	}

	bool select(const Spreadsheet* sheet, int row) const
	{

	}
};





#endif //__SELECTNOT_HPP__
