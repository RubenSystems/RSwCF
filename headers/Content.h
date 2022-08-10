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
		Content(core::Text n_text): text(n_text) {}
		
		core::Text generate() {
			return text;
		}
		
	private:
		core::Text text;
	};
	
	Generatable * content(core::Text text) {
		return new Content(text);
	}
}

#endif /* Content_h */
