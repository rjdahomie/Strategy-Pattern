#ifndef __SELECTNOT_HPP__
#define __SELECTNOT_HPP__

#include "select.hpp"

using namespace std;

class Select_Or: public Select
{
    public:
        Select* s1;
	Select* s2;

    private:
        Select_Or(Select *s1, Select* s2)
        {

        }

        ~Select_Or()
        {

        }

        bool select(const Spreadsheet* sheet, int row) const
        {

        }
};





#endif //__SELECTNOT_HPP__

