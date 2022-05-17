#ifndef __SELECTNOT_HPP__
#define __SELECTNOT_HPP__

#include "select.hpp"

using namespace std;

class Select_Not: public Select
{
    protected:
	Select* s;

    private:
	Select_Not(Select *s)
	{
	    s = s;
	}

	~Select_Not()
	{
	    delete s;
	}

	bool select(const Spreadsheet* sheet, int row) const
	{
	    return (!(s->select(sheet, row)));
	}
};





#endif //__SELECTNOT_HPP__
