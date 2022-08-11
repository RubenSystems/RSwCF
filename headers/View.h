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

#include <unordered_map>
#include <vector>


namespace rswcf {
	class View : public Generatable {
		public:
			View(std::string && n_tag, std::vector<Generatable *> && n_inner_content, bool close = true) :
				tag(std::move(n_tag)), inner_content(std::move(n_inner_content)), close(close) {
				
			}
		

		
			std::string generate() {
				std::string res = "<" + tag;
				
				// Attributes
				
				res += close ? ">" : "/>";
				
				// Subviews 
				for (Generatable * sub_view : inner_content) {
					res += sub_view->generate();	
				}
				
				if (close) {
					res += "</";
					res += tag;
					res += ">";
				}
				return res;
			}
		
			View * attr(Attribute && attribute) {
				attributes.insert({attribute.name, attribute.value});
				return this;
			}
		
		
		private:
			std::string tag;
			std::unordered_multimap <std::string, std::string> attributes; // attribute -> [attribute value] e.g class -> [green]
			std::vector<Generatable *> inner_content;
			bool close;
	};
	
	
	// convienence init
	View * view(std::string && tag, std::initializer_list<Generatable *> view_init, bool close = true) {
		return new View(std::move(tag), std::vector<Generatable *>(view_init), close);
	}
}


#endif /* View_h */
