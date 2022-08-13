//
//  Content.h
//  RSwCF
//
//  Created by Ruben Ticehurst-James on 14/07/2022.
//

#ifndef Content_h
#define Content_h

#include "Generatable.h"


namespace rswcf {
	class Content : public Generatable {
		
	public:
		Content(std::string n_text): text(n_text) {}
		
		~Content () {}
		
		GeneratedResult generate() {
			return {text, std::unordered_map<std::string, std::string>()};
		}
		
	private:
		std::string text;
	};
	
	Generatable * content(std::string && text) {
		return new Content(std::move(text));
	}
}

#endif /* Content_h */
