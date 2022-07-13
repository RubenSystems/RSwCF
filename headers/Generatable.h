//
//  Generatable.h
//  RSwDE
//
//  Created by Ruben Ticehurst-James on 29/06/2022.
//

#ifndef Generatable_h
#define Generatable_h

#include "../RSCore/Text.h"

// Abstract class to define any object that can be generated(and by extension sent over to browser.)
class Generatable {
	public:
		virtual core::Text generate() = 0;
	
};

#endif /* Generatable_h */
