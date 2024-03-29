//
//  Container.h
//  RSwCF
//
//  Created by Ruben Ticehurst-James on 11/08/2022.
//

#ifndef Container_h
#define Container_h

#include "Generatable.h"

namespace rswcf {
	std::string container(Generatable * head, Generatable * body) {
		std::string view;
		GeneratedResult generated_head = head->generate();
		GeneratedResult generated_body = body->generate();
		
		view = "<!DOCTYPE html><html><head>" + generated_head.view_content + "<style>*{margin:0; box-sizing: border-box;}";
		
		std::string key;
		for (std::pair<const std::string, std::string> & attribute : generated_body.styles) {
			
			view += "." + attribute.first + "{" + attribute.second + "}";
		}
		
		view += "</style></head><body>" + generated_body.view_content + "</body></html>";
		
		return view;
				
	};
	
}

#endif /* Container_h */
