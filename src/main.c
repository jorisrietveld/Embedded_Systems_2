/**
 * Author: Joris Rietveld <jorisrietveld@gmail.com>
 * Created: 22-022019 17:58
 * Licence: GPLv3 - General Public Licence version 3 
 * Licence url: <https://www.gnu.org/licenses/gpl-3.0.txt>
 */

#include "assingment/assignment_1.h"
#include "assingment/assignment_2.h"
#include "assingment/assignment_3.h"

#define ASSIGNMENT 3

int
main()
{
    switch (ASSIGNMENT) {
    case 1:
        assignment1();
        break;
    case 2:
        assignment2();
        break;
    case 3:
        assignment3();
        break;

    default:
        assignment1();
        break;
    }
}


