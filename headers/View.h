//
//  View.h
//  RSwCF
//
//  Created by Ruben Ticehurst-James on 09/07/2022.
//

#ifndef View_h
#define View_h

#include "Generatable.h"
#include "Style.h"

namespace rswcf {
	class View : public Generatable {
		public:
			View(core::Text && tag, core::Array<Generatable *> && innerContent) : tag(tag), innerContent(innerContent){
				
			}
		
			core::Text generate() {
				return "HI";
			}
		
		private:
			core::Text tag;
			core::Array<Style> styles;
			core::Array<Generatable *> innerContent;
	};
}

#endif /* View_h */
