//
//  Generatable.h
//  RSwDE
//
//  Created by Ruben Ticehurst-James on 29/06/2022.
//

#ifndef Generatable_h
#define Generatable_h

#include <string>
#include <unordered_map>

// Abstract class to define any object that can be generated(and by extension sent over to browser.)
namespace rswcf {
	struct GeneratedResult {
		std::string view_content;
		std::unordered_map<std::string, std::string> styles;
	};
	
	class Generatable {
		public:
			virtual GeneratedResult generate() = 0;
		
	};
}

#endif /* Generatable_h */
