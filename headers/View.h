//
//  View.h
//  RSwCF
//
//  Created by Ruben Ticehurst-James on 09/07/2022.
//

#ifndef View_h
#define View_h

#include "Generatable.h"
#include "Attribute.h"
#include "../rscore/Dictionary.h"


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
				
				
				
				for (int i = 0; i < innerContent.size(); i ++) {
					core::Text child_content = innerContent[i]->generate();
					res += child_content;
					
				}
				
				
				if (close) {
					res += "</";
					res += tag;
					res += ">";
				}
				
				
				
				return res;
			}
		
			View * attr(Attribute && attribute) {
//				attributes[attribute.name].add(attribute.value);
				return this;
			}
		
		
		private:
			core::Text tag;
			core::Dictionary <core::Text, core::Array<core::Text>> attributes;
			core::Array<Generatable *> innerContent;
			bool close;
	};
	
	
	// convienence init
	View * view(core::Text && tag, std::initializer_list<Generatable *> view_init, bool close = true) {
		return new View(std::move(tag), core::Array<Generatable *>(view_init), close);
	}
}


#endif /* View_h */
