#ifndef __SELECTNOT_HPP__
#define __SELECTNOT_HPP__

#include "select.hpp"

using namespace std;

class Select_Or: public Select
{
    protected:
        Select* s1 = nullptr;
	Select* s2 = nullptr;

    private:
        Select_Or(Select *s1, Select* s2)
        {
	    s1 = s1;
	    s2 = s2;
        }

        ~Select_Or()
        {
	    delete s1;
	    delete s2;
        }

        bool select(const Spreadsheet* sheet, int row) const
        {
	    return (s1->select(sheet, row) || s2->select(sheet,row));
        }
};

#endif //__SELECTNOT_HPP__

