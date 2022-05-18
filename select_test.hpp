#ifndef __SELECT_CONTAINS_TEST_HPP__
#define __SELECT_CONTAINS_TEST_HPP__

#include "gtest/gtest.h"

#include<iostream>
#include<sstream>

#include "select.hpp"
#include "select_and.hpp"
#include "select_not.hpp"
#include "select_or.hpp"
#include "select_contains.hpp"
#include "spreadsheet.hpp"

using namespace std;

TEST(selectContains, containsTrue){
    Spreadsheet sheet;
    sheet.set_column_names({"First","Last","Age","Major"});
    sheet.add_row({"Rasa","Jahromi","32","computer science"});
    sheet.add_row({"Alexander","Rabinovich","22","mathematics"});
    sheet.add_row({"Minsoo","Kim","26","computer engineering"});
    sheet.add_row({"Nate","Diaz","9","astrophysics"});

    sheet.set_selection( new Select_Contains(&sheet, "First","Rasa"));

    stringstream ss;
    sheet.print_selection(ss);
    EXPECT_EQ(ss.str(), "Rasa Jahromi 32 computer science \n");
}

TEST(selectContain, containsLetter){
    Spreadsheet sheet;
    sheet.set_column_names({"First","Last","Age","Major"});
    sheet.add_row({"Rasa","Jahromi","32","computer science"});
    sheet.add_row({"Alexander","Rabinovich","22","mathematics"});
    sheet.add_row({"Minsoo","Kim","26","computer engineering"});
    sheet.add_row({"Nate","Diaz","9","astrophysics"});

    stringstream ss;

    sheet.set_selection( new Select_Contains(&sheet, "First","o"));

    sheet.print_selection(ss);
    EXPECT_EQ(ss.str(), "Minsoo Kim 26 computer engineering \n");
}

TEST(selectContain, containsNone){
    Spreadsheet sheet;
    sheet.set_column_names({"First","Last","Age","Major"});
    sheet.add_row({"Rasa","Jahromi","32","computer science"});
    sheet.add_row({"Alexander","Rabinovich","22","mathematics"});
    sheet.add_row({"Minsoo","Kim","26","computer engineering"});
    sheet.add_row({"Nate","Diaz","9","astrophysics"});

    stringstream ss;

    sheet.set_selection( new Select_Contains(&sheet, "First", "*"));

    sheet.print_selection(ss);
    EXPECT_EQ(ss.str(), "");
}

TEST(selectContain, containsNotMatch){
    Spreadsheet sheet;
    sheet.set_column_names({"First","Last","Age","Major"});
    sheet.add_row({"Rasa","Jahromi","32","computer science"});
    sheet.add_row({"Alexander","Rabinovich","22","mathematics"});
    sheet.add_row({"Minsoo","Kim","26","computer engineering"});
    sheet.add_row({"Nate","Diaz","9","astrophysics"});

    stringstream ss;

    sheet.set_selection( new Select_Contains(&sheet, "First","Z"));

    sheet.print_selection(ss);
    EXPECT_EQ(ss.str(), "");
}

TEST(selectAnd, containsNone){
    Spreadsheet sheet;
    sheet.set_column_names({"First","Last","Age","Major"});
    sheet.add_row({"Rasa","Jahromi","32","computer science"});
    sheet.add_row({"Alexander","Rabinovich","22","mathematics"});
    sheet.add_row({"Minsoo","Kim","26","computer engineering"});
    sheet.add_row({"Nate","Diaz","9","astrophysics"});

    sheet.set_selection(new Select_And(new Select_Contains(&sheet, "First","Jack"), 
                                       new Select_Contains(&sheet, "Last","Brown") ));
    stringstream ss;
    sheet.print_selection(ss);
    EXPECT_EQ(ss.str(), "");
}

TEST(selectAnd, containsOne){
    Spreadsheet sheet;
    sheet.set_column_names({"First","Last","Age","Major"});
    sheet.add_row({"Rasa","Jahromi","32","computer science"});
    sheet.add_row({"Alexander","Rabinovich","22","mathematics"});
    sheet.add_row({"Minsoo","Kim","26","computer engineering"});
    sheet.add_row({"Nate","Diaz","9","astrophysics"});

    sheet.set_selection(new Select_And(new Select_Contains(&sheet, "First","Rasa"),
                                       new Select_Contains(&sheet, "Last","Brown") ));
    stringstream ss;
    sheet.print_selection(ss);
    EXPECT_EQ(ss.str(), "");
}

TEST(selectAnd, containsBoth){
    Spreadsheet sheet;
    sheet.set_column_names({"First","Last","Age","Major"});
    sheet.add_row({"Rasa","Jahromi","32","computer science"});
    sheet.add_row({"Alexander","Rabinovich","22","mathematics"});
    sheet.add_row({"Minsoo","Kim","26","computer engineering"});
    sheet.add_row({"Nate","Diaz","9","astrophysics"});

    sheet.set_selection(new Select_And(new Select_Contains(&sheet, "First","Rasa"),
                                       new Select_Contains(&sheet, "Last","Jahromi") ));
    stringstream ss;
    sheet.print_selection(ss);
    EXPECT_EQ(ss.str(), "Rasa Jahromi 32 computer science \n");
}

TEST(selectOr, containsNone){
    Spreadsheet sheet;
    sheet.set_column_names({"First","Last","Age","Major"});
    sheet.add_row({"Rasa","Jahromi","32","computer science"});
    sheet.add_row({"Alexander","Rabinovich","22","mathematics"});
    sheet.add_row({"Minsoo","Kim","26","computer engineering"});
    sheet.add_row({"Nate","Diaz","9","astrophysics"});

    sheet.set_selection(new Select_Or(new Select_Contains(&sheet, "First","Jack"),
                                      new Select_Contains(&sheet, "Last","Brown") ));
    stringstream ss;
    sheet.print_selection(ss);
    EXPECT_EQ(ss.str(), "");
}

TEST(selectOr, containsOne){
    Spreadsheet sheet;
    sheet.set_column_names({"First","Last","Age","Major"});
    sheet.add_row({"Rasa","Jahromi","32","computer science"});
    sheet.add_row({"Alexander","Rabinovich","22","mathematics"});
    sheet.add_row({"Minsoo","Kim","26","computer engineering"});
    sheet.add_row({"Nate","Diaz","9","astrophysics"});

    sheet.set_selection(new Select_Or(new Select_Contains(&sheet, "First","Rasa"),
                                      new Select_Contains(&sheet, "Last","Brown") ));
    stringstream ss;
    sheet.print_selection(ss);
    EXPECT_EQ(ss.str(), "Rasa Jahromi 32 computer science \n");
}

TEST(selectOr, containsBoth){
    Spreadsheet sheet;
    sheet.set_column_names({"First","Last","Age","Major"});
    sheet.add_row({"Rasa","Jahromi","32","computer science"});
    sheet.add_row({"Alexander","Rabinovich","22","mathematics"});
    sheet.add_row({"Minsoo","Kim","26","computer engineering"});
    sheet.add_row({"Nate","Diaz","9","astrophysics"});

    sheet.set_selection(new Select_Or(new Select_Contains(&sheet, "First","Rasa"),
                                      new Select_Contains(&sheet, "Last","Jahromi") ));
    stringstream ss;
    sheet.print_selection(ss);
    EXPECT_EQ(ss.str(), "Rasa Jahromi 32 computer science \n");
}

TEST(selectNot, containsOne){
    Spreadsheet sheet;
    sheet.set_column_names({"First","Last","Age","Major"});
    sheet.add_row({"Rasa","Jahromi","32","computer science"});
    sheet.add_row({"Alexander","Rabinovich","22","mathematics"});
    sheet.add_row({"Minsoo","Kim","26","computer engineering"});
    sheet.add_row({"Nate","Diaz","9","astrophysics"});

    sheet.set_selection(new Select_Not(new Select_Contains(&sheet, "First","Rasa")));
    
    stringstream ss;
    sheet.print_selection(ss);
    EXPECT_EQ(ss.str(), "Alexander Rabinovich 22 mathematics \nMinsoo Kim 26 computer engineering \nNate Diaz 9 astrophysics \n");
}

TEST(selectNot, containsTwo){
    Spreadsheet sheet;
    sheet.set_column_names({"First","Last","Age","Major"});
    sheet.add_row({"Rasa","Jahromi","32","computer science"});
    sheet.add_row({"Alexander","Rabinovich","22","mathematics"});
    sheet.add_row({"Minsoo","Kim","26","computer engineering"});
    sheet.add_row({"Nate","Diaz","9","astrophysics"});

    sheet.set_selection(new Select_And(new Select_Contains(&sheet, "First","Rasa"), new Select_Contains(&sheet, "First","Alexander")));

    stringstream ss;
    sheet.print_selection(ss);
    EXPECT_EQ(ss.str(), "");
}

#endif // __SELECT_CONTAINS_TEST_HPP__

