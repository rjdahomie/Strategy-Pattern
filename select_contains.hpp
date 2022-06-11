#ifndef __SELECTCONTAINS_HPP__
#define __SELECTCONTAINS_HPP__

#include "select.hpp"

using namespace std;

class Select_Contains: public Select_Column
{
    private:
	string input;

    public:
	Select_Contains(const Spreadsheet* sheet, const string& name, const string& s)
	    {

	    }
	
	bool select(const string& s) const
	    {

	    }
};

#endif //__SELECT_HPP__
