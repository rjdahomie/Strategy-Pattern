#ifndef __SELECTNOT_HPP__
#define __SELECTNOT_HPP__

#include "select.hpp"

using namespace std;

class Select_And: public Select
{
    public:
        Select* s1;
	Select* s2;

    private:
        Select_And(Select* s1, Select* s2)
        {

        }

        ~Select_And()
        {

        }

        bool select(const Spreadsheet* sheet, int row) const
        {

        }
};





#endif //__SELECTNOT_HPP__

