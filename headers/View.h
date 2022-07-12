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
			View(const core::Text & n_tag, const core::Array<Generatable *> & n_innerContent = core::Array<Generatable *>(), bool close = true) :
				tag(std::move(n_tag)), innerContent(std::move(n_innerContent)), close(close) {
				
			}
		
			core::Text generate() {
				core::Text res = "<";
				res += tag;
				res += close ? ">" : "/>";
				
				if (close) {
					res += "</";
					res += tag;
					res += ">";
				}
				
				
				
				return res;
			}
		
		private:
			core::Text tag;
			core::Array<Style> styles;
			core::Array<Generatable *> innerContent;
			bool close;
	};
	
	
	// convienence init
	Generatable * view(core::Text && tag, const core::Array<Generatable *> & n_innerContent = core::Array<Generatable *>(), bool close = true) {
		return new View(tag, n_innerContent, close);
	}
}


#endif /* View_h */
