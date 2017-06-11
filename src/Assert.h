#ifndef ASSERT_H
#define ASSERT_H

///////////////////////////////////////////////////////////////////////////////////////////
//    MultiNEAT - Python/C++ NeuroEvolution of Augmenting Topologies Library
//
//    Copyright (C) 2012 Peter Chervenski
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU Lesser General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU Lesser General Public License
//    along with this program.  If not, see < http://www.gnu.org/licenses/ >.
//
//    Contact info:
//
//    Peter Chervenski < spookey@abv.bg >
//    Shane Ryan < shane.mcdonald.ryan@gmail.com >
///////////////////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <cassert>
#include <exception>

// kill any existing declarations
#ifdef ASSERT
#undef ASSERT
#endif

#ifdef DEBUG

#if 1

//--------------
//  debug macros
//--------------
#define ASSERT(expr)\
        {\
            if( !(expr) )\
            {\
                std::cout << "\n*** ASSERT! ***\n" << \
                __FILE__ ", line " << __LINE__ << ": " << \
                #expr << " is false\n\n";\
                throw std::exception();\
            }\
        }
#else

#define ASSERT(expr)\
        {\
            if( !(expr) )\
            {\
                std::cout << "\n*** ASSERT ***\n"; \
                assert(expr);\
            }\
        }

#endif

#else // _DEBUG

//--------------
//  release macros
//--------------

// ASSERT gets optimised out completely
#define ASSERT(expr)

#endif

#endif // INCLUDE_GUARD_Assert_h
