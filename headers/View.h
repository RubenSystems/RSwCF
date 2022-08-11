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
#include <random>


namespace rswcf {
	class View : public Generatable {
		public:
			View(std::string && n_tag, std::vector<Generatable *> && n_inner_content, bool close = true) :
				tag(std::move(n_tag)), inner_content(std::move(n_inner_content)), close(close), class_name(generate_class_name()) {
				attr({"class", class_name});
			}
		

		
			GeneratedResult generate() {
				GeneratedResult res;
				res.view_content = "<" + tag;
				
				// Attributes
				std::string key;
				for (auto & attribute_keys : attributes) {
					key = attribute_keys.first;
					res.view_content += " " + key + "='";
					auto values = attributes.equal_range(key);
					for (auto it = values.first; it != values.second; ++it) {
						res.view_content += (it->second + " ");
					}
					res.view_content += "' ";
				}
				
				res.view_content += close ? ">" : "/>";
				
				// Subviews
				for (Generatable * subview : inner_content) {
					GeneratedResult generated_subview = subview->generate();
					res.view_content += generated_subview.view_content;
					res.styles.merge(styles);
					res.styles.merge(generated_subview.styles);
				}
				
				if (close) {
					res.view_content += "</";
					res.view_content += tag;
					res.view_content += ">";
				}
				return res;
			}
		
			View * attr(Attribute && attribute) {
				attributes.insert({attribute.name, attribute.value});
				return this;
			}
			
			View * style(Attribute && attribute) {
				std::string new_style = attribute.name + ": " +attribute.value+";";
				styles.insert({new_style, class_name});
				return this;
			}
		
		
		private:
			std::string generate_class_name() {
				static std::random_device dev;
				static std::mt19937 rng(dev());

				std::uniform_int_distribution<int> dist(0, 15);

				const char *v = "0123456789abcdef";
				const bool dash[] = { 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 };

				std::string res;
				for (int i = 0; i < 5; i++) {
					if (dash[i]) res += "-";
					res += v[dist(rng)];
					res += v[dist(rng)];
				}
				return res;
			}
		
		
		private:
			std::string tag, class_name;
			std::unordered_multimap <std::string, std::string> attributes; // attribute -> [attribute value] e.g class -> [green]
			std::unordered_multimap <std::string, std::string> styles; // style -> classes with that style
			std::vector<Generatable *> inner_content;
			bool close;
	};
	
	
	// convienence init
	View * view(std::string && tag, std::initializer_list<Generatable *> view_init, bool close = true) {
		return new View(std::move(tag), std::vector<Generatable *>(view_init), close);
	}
}


#endif /* View_h */
